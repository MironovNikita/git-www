#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>      //формирование окна
#include <QFileSystemModel> //отображение данных
#include <QDir>             //навигация и получения данных элементов файловой структуры(название, размер, время последнего изменения и т.п.)
#include <QDateTime>        //отображение текущего времени
#include <QPixmap>          //подключение графических ресурсов
#include <QMessageBox>      //вывод окон с сообщениями

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Source_doubleClicked(const QModelIndex &index);
    void on_CommitButton_clicked();
    void on_DeleteButton_clicked();
    void on_ChooseButton_clicked();
    void on_CloseButton_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *model;

    QString fromCommitPath; //Откуда коммитить
    QString toCommitPath;   //Куда коммитить файлы
    QString copyPath;       //Исходная папка всех коммитов
};

//Ищет отсутствующие или файлы старой версии в папке коммита
void contentDifference(QDir &sDir, QDir &dDir, QFileInfoList &diffList, QString timeCurrent);
void contentDifference(QDir &fromDir, QDir &toDir, QFileInfoList &diffList);

//Составляет список всех вложенных папок и файлов
void contentList(QDir &dir, QFileInfoList &conList, QString timeCurrent);
void contentList(QDir &dir, QFileInfoList &conList);

//Создаёт папку в том каталоге, в котором находится пользователь
void createCopyFolder(QString fromCommitPath);

#endif // MAINWINDOW_H
