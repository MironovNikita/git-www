#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QFileSystemModel (this);
    model->setFilter(QDir::QDir::AllEntries);
    model->setRootPath(""); //что в системе делать видимым для модели
    ui->Source->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Работа с окном источника копирования
void MainWindow::on_Source_doubleClicked(const QModelIndex &index)
{
    QListView* listView = (QListView*)sender(); //указатель на элемент списка, приводящий к выходу "наверх"
        QFileInfo fileInfo = model->fileInfo(index);
        QDir dir = fileInfo.dir();

        ui->PathField->setText(dir.path());
        if(fileInfo.fileName()=="..") //реализация выхода "наверх" в списке файлов
        {
            dir.cdUp();
            listView->setRootIndex(model->index(dir.absolutePath())); //получение нового индекса в "родительской" папке, когда вышли "наверх"
            ui->PathField->setText(dir.path());
            fromCommitPath = dir.path();
        }
        else if(fileInfo.fileName()==".") //реализация перехода в исходную (корневую) папку
        {
            ui->PathField->setText("My Computer");
            listView->setRootIndex(model->index(""));
            fromCommitPath = "";

        }
        else if(fileInfo.isDir()) //реализация входа в папку
            {
                if(fileInfo.fileName()==".copy")copyPath = fromCommitPath; //запись отслеживаемого пути, если при запуске программы мы не делали коммит, либо же папка .сору уже существовала
                listView->setRootIndex(index);
                if (dir.path()[dir.path().size()-1]=="/")
                {
                    ui->PathField->setText(dir.path()+fileInfo.fileName());
                    fromCommitPath = dir.path()+fileInfo.fileName();
                }
                else
                {
                    ui->PathField->setText(dir.path()+"/"+fileInfo.fileName());
                    fromCommitPath = dir.path()+"/"+fileInfo.fileName();
                }
            }
}

//Составляет список отличных вложенных папок и файлов исходной папки и папки последнего коммита
void contentDifference(QDir &fromDir, QDir &toDir, QFileInfoList &diffList, QString timeCurrent)
{
    foreach(QFileInfo fromInfo, fromDir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name|QDir::DirsFirst))//сортировка по имени и составление списка файлов в исходной папке
    {
        bool objectExists = false;
        foreach(QFileInfo toInfo, toDir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name|QDir::DirsFirst))
        {
            if (fromInfo.fileName() == toInfo.fileName() && fromInfo.fileName()!=".copy")
            {
                if (fromInfo.isFile()&&fromInfo.lastModified() <= toInfo.lastModified())
                {
                    objectExists = true;
                    break;
                }
            }
            if (!objectExists && fromInfo.fileName()!=".copy") diffList.append(fromInfo);
            if (fromInfo.isFile()) continue;
            if (objectExists && fromInfo.fileName()!=".copy")
            {
                fromDir.cd(fromInfo.fileName());
                toDir.cd(fromInfo.fileName());
                contentDifference(fromDir,toDir,diffList, timeCurrent);
                fromDir.cdUp();
                toDir.cdUp();
            }
            else
            {
                if (fromInfo.fileName()==".copy") continue;
                else fromDir.cd(fromInfo.fileName());
                contentList(fromDir, diffList, timeCurrent);
                fromDir.cdUp();
            }
        }
    }
}

//Перегруженная функция contentDifference
void contentDifference(QDir &fromDir, QDir &toDir, QFileInfoList &diffList)
{
    foreach(QFileInfo fromInfo, fromDir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name|QDir::DirsFirst))//сортировка по имени и составление списка файлов в исходной папке
    {
        bool objectExists = false;
        foreach(QFileInfo toInfo, toDir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name|QDir::DirsFirst))
        {
            if (fromInfo.fileName() == toInfo.fileName() && fromInfo.fileName()!=".copy")
            {
                if (fromInfo.isFile()&&fromInfo.lastModified() <= toInfo.lastModified())
                {
                    objectExists = true;
                    break;
                }
            }
            if (!objectExists && fromInfo.fileName()!=".copy") diffList.append(fromInfo);
            if (fromInfo.isFile()) continue;
            if (objectExists && fromInfo.fileName()!=".copy")
            {
                fromDir.cd(fromInfo.fileName());
                toDir.cd(fromInfo.fileName());
                contentDifference(fromDir,toDir,diffList);
                fromDir.cdUp();
                toDir.cdUp();
            }
            else
            {
                if (fromInfo.fileName()==".copy") continue;
                else fromDir.cd(fromInfo.fileName());
                contentList(fromDir, diffList);
                fromDir.cdUp();
            }
        }
    }
}

//Составляет список всех вложенных папок и файлов
void contentList(QDir &dir, QFileInfoList &conList, QString timeCurrent)
{
    foreach(QFileInfo info, dir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name|QDir::DirsFirst)) //сортировка по имени и составление списка файлов в исходной папке
    {
        if (info.fileName()==".copy" || info.fileName()==".copy/Commit from "+timeCurrent)
        {
            continue;
        }
        conList.append(info);
        if(info.isDir() && dir.cd(info.fileName())) //проверка, если элемент списка является папкой
        {
            contentList(dir, conList, timeCurrent);
            dir.cdUp();
        }
    }
}

//Перегруженная функция contentList
void contentList(QDir &dir, QFileInfoList &conList)
{
    foreach(QFileInfo info, dir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name|QDir::DirsFirst)) //сортировка по имени и составление списка файлов в исходной папке
    {
        conList.append(info);
        if(info.isDir() && dir.cd(info.fileName())) //проверка, если элемент списка является папкой
        {
            contentList(dir, conList);
            dir.cdUp();
        }
    }
}

//Cоздание папки .copy для коммитов
void createCopyFolder(QString fromCommitPath)
{
    if (!QDir(fromCommitPath+"/.copy").exists())//проверка, была ли уже до этого создана папка с таким названием
    {
        QDir().mkdir(fromCommitPath+"/.copy");  //создание папки по нужному пути
    }
}

//Создание пути для нового коммита (черновая функция)
/*QString commDir (QString fromCommitPath, QString toCommitPath)
{
    QString timeCurrent = QDateTime::currentDateTime().toString("dd.MM.yyyy HH-mm");    //текущее время системы для создания папок с коммитами
    toCommitPath = fromCommitPath+"/.copy/Commit from "+timeCurrent;
    return toCommitPath;
}*/

//Реализация кнопки создания коммита
void MainWindow::on_CommitButton_clicked()
{
    QString timeCurrent = QDateTime::currentDateTime().toString("dd.MM.yyyy HH-mm");    //текущее время системы для создания папок с коммитами
    toCommitPath = fromCommitPath+"/.copy/Commit from "+timeCurrent;
    ui->PathField_2->setText(toCommitPath);
    createCopyFolder(fromCommitPath);

    //copyPath = fromCommitPath; //Сохраняем путь папки .сору

    QDir().mkdir(toCommitPath);  //создаём папку с именем текущего времени системы для нового коммита

    QDir fromDir = QDir (model->filePath(ui->Source->rootIndex()));//Откуда копируем
    QDir toDir = QDir(toCommitPath);    //Куда копируем

    //Проверка, сколько файлов содержится в исходной и конечной папках
    /*QFileInfoList conList = QFileInfoList();
    contentList(fromDir, conList, timeCurrent);
    QFileInfoList conToDirList = QFileInfoList();
    contentList(toDir, conToDirList, timeCurrent);*/

    if (toDir.isEmpty())
    {
        QFileInfoList conList = QFileInfoList(); //список того, что содержится в исходной папке
        contentList(fromDir, conList, timeCurrent);

        foreach(QFileInfo diffInfo, conList)
        {
            QString backupPath = diffInfo.filePath().replace(fromDir.absolutePath(), toDir.absolutePath()); //путь для копирования каждого файла - у каждого свой :)
            if(diffInfo.isFile())
            {
                QFile::remove(backupPath);//т.к. сору() не удаляет файл, если он там уже есть с таким же именем
                QFile::copy(diffInfo.absoluteFilePath(), backupPath);//копируем файл
            }
            if(diffInfo.isDir())
            {
                toDir.mkdir(backupPath); //копируем папку
            }
        }
    }
    else
    {
        QFileInfoList diffList = QFileInfoList();
        contentDifference(fromDir,toDir,diffList, timeCurrent);
        foreach(QFileInfo diffInfo, diffList)
        {
            QString backupPath = diffInfo.filePath().replace(fromDir.absolutePath(), toDir.absolutePath()); //путь для копирования каждого файла - у каждого свой :)
            if(diffInfo.isFile())
            {
                QFile::remove(backupPath);//т.к. сору() не удаляет файл, если он там уже есть с таким же именем
                QFile::copy(diffInfo.absoluteFilePath(), backupPath); //копируем файл
            }
            if(diffInfo.isDir())
            {
                toDir.mkdir(backupPath); //копируем папку
            }
        }
    }
    QMessageBox::information(this, "Успешно!", "Коммит успешно создан в папке:\n"+toCommitPath);
}

void MainWindow::on_DeleteButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Внимание!", "Вы уверены, что хотите удалить папку \n"+fromCommitPath+"?", QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        QDir delDir = QDir (fromCommitPath);
        delDir.removeRecursively();

        ui->PathField->setText("My computer");
        ui->PathField_2->setText("My Computer");
        QMessageBox::information(this, "Удаление", "Папка " + fromCommitPath + "\nуспешно удалена!");
    }
    else
    {
        return;
    }
}

void MainWindow::on_ChooseButton_clicked()
{
    QDir fromDir = QDir (model->filePath(ui->Source->rootIndex()));//Откуда копируем - выбранный коммит
    QDir toDir = QDir(model->filePath(ui->Source->rootIndex()));    //Куда копируем - исходная папка

    /*toDir.cdUp();
    toDir.cdUp();

    toDir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name|QDir::DirsFirst);
    foreach(QFileInfo toDirFile, toDir.entryList())
    {
        if(toDirFile.fileName()!=".copy")
        {
            if(toDirFile.isDir())
            {
                toDirFile.removeRecoursively();
            }
            else
            {
                toDir.remove(toDirFile.fileName());
            }
        }
    }*/

    //Сперва удалим всё, кроме папки .сору, чтобы оттуда можно было взять определённое сохранение
    if (copyPath.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка!", "Отсутствует папка резервного копирования!");
    }
    else
    {
        QDir dir(copyPath);
        dir.setFilter(QDir::NoDotAndDotDot|QDir::Files);
        foreach(QString dirItem, dir.entryList()) dir.remove(dirItem);

        dir.setFilter(QDir::NoDotAndDotDot|QDir::Dirs);
        foreach (QString dirItem, dir.entryList())
        {
            QDir subDir(dir.absoluteFilePath(dirItem));
            if(subDir.dirName()==".copy") continue;
            else subDir.removeRecursively();
        }

        QFileInfoList diffList = QFileInfoList();
        contentDifference(fromDir,dir,diffList);
        foreach(QFileInfo diffInfo, diffList)
        {
            QString backupPath = diffInfo.filePath().replace(fromDir.absolutePath(), dir.absolutePath()); //путь для копирования каждого файла - у каждого свой :)
            if(diffInfo.isFile())
            {
                QFile::copy(diffInfo.absoluteFilePath(), backupPath); //копируем файл
            }
            if(diffInfo.isDir())
            {
                toDir.mkdir(backupPath); //копируем папку
            }
        }
        QMessageBox::information(this, "Успешно!", "Файлы были были восстановлены из папки:\n"+fromCommitPath+"\n в папку:\n"+copyPath);
    }
}

void MainWindow::on_CloseButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Выход", "Вы уверены, что хотите выйти?", QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}

