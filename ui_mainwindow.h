/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *CurrentPath;
    QLabel *PathField;
    QLabel *CurrentPath_2;
    QLabel *PathField_2;
    QListView *Source;
    QSplitter *splitter;
    QPushButton *CommitButton;
    QPushButton *ChooseButton;
    QPushButton *DeleteButton;
    QPushButton *CloseButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(690, 495);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setBaseSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/graphics/icons8-commit-git-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setHorizontalSpacing(2);
        formLayout->setVerticalSpacing(3);
        CurrentPath = new QLabel(centralwidget);
        CurrentPath->setObjectName(QString::fromUtf8("CurrentPath"));
        CurrentPath->setEnabled(true);
        CurrentPath->setAutoFillBackground(false);
        CurrentPath->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        CurrentPath->setFrameShape(QFrame::StyledPanel);
        CurrentPath->setFrameShadow(QFrame::Raised);
        CurrentPath->setLineWidth(1);
        CurrentPath->setMidLineWidth(0);
        CurrentPath->setTextFormat(Qt::AutoText);
        CurrentPath->setAlignment(Qt::AlignCenter);
        CurrentPath->setWordWrap(false);

        formLayout->setWidget(0, QFormLayout::LabelRole, CurrentPath);

        PathField = new QLabel(centralwidget);
        PathField->setObjectName(QString::fromUtf8("PathField"));
        PathField->setCursor(QCursor(Qt::ArrowCursor));
        PathField->setMouseTracking(false);
        PathField->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);"));
        PathField->setFrameShape(QFrame::WinPanel);
        PathField->setFrameShadow(QFrame::Sunken);
        PathField->setLineWidth(1);
        PathField->setMidLineWidth(0);

        formLayout->setWidget(0, QFormLayout::FieldRole, PathField);

        CurrentPath_2 = new QLabel(centralwidget);
        CurrentPath_2->setObjectName(QString::fromUtf8("CurrentPath_2"));
        CurrentPath_2->setEnabled(true);
        CurrentPath_2->setAutoFillBackground(false);
        CurrentPath_2->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        CurrentPath_2->setFrameShape(QFrame::StyledPanel);
        CurrentPath_2->setFrameShadow(QFrame::Raised);
        CurrentPath_2->setLineWidth(1);
        CurrentPath_2->setMidLineWidth(0);
        CurrentPath_2->setTextFormat(Qt::AutoText);
        CurrentPath_2->setAlignment(Qt::AlignCenter);
        CurrentPath_2->setWordWrap(false);

        formLayout->setWidget(1, QFormLayout::LabelRole, CurrentPath_2);

        PathField_2 = new QLabel(centralwidget);
        PathField_2->setObjectName(QString::fromUtf8("PathField_2"));
        PathField_2->setCursor(QCursor(Qt::ArrowCursor));
        PathField_2->setMouseTracking(false);
        PathField_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);"));
        PathField_2->setFrameShape(QFrame::WinPanel);
        PathField_2->setFrameShadow(QFrame::Sunken);
        PathField_2->setLineWidth(1);
        PathField_2->setMidLineWidth(0);

        formLayout->setWidget(1, QFormLayout::FieldRole, PathField_2);


        verticalLayout->addLayout(formLayout);

        Source = new QListView(centralwidget);
        Source->setObjectName(QString::fromUtf8("Source"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Source->sizePolicy().hasHeightForWidth());
        Source->setSizePolicy(sizePolicy1);
        Source->setStyleSheet(QString::fromUtf8(""));
        Source->setFrameShape(QFrame::Box);
        Source->setFrameShadow(QFrame::Plain);
        Source->setLineWidth(1);
        Source->setMidLineWidth(0);
        Source->setDragEnabled(false);
        Source->setDragDropMode(QAbstractItemView::NoDragDrop);
        Source->setDefaultDropAction(Qt::CopyAction);
        Source->setSelectionBehavior(QAbstractItemView::SelectItems);
        Source->setViewMode(QListView::ListMode);
        Source->setUniformItemSizes(false);

        verticalLayout->addWidget(Source);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(5);
        CommitButton = new QPushButton(splitter);
        CommitButton->setObjectName(QString::fromUtf8("CommitButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CommitButton->sizePolicy().hasHeightForWidth());
        CommitButton->setSizePolicy(sizePolicy2);
        CommitButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/graphics/icons8-\320\272\320\275\320\276\320\277\320\272\320\260-new-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        CommitButton->setIcon(icon1);
        CommitButton->setIconSize(QSize(48, 48));
        splitter->addWidget(CommitButton);
        ChooseButton = new QPushButton(splitter);
        ChooseButton->setObjectName(QString::fromUtf8("ChooseButton"));
        sizePolicy2.setHeightForWidth(ChooseButton->sizePolicy().hasHeightForWidth());
        ChooseButton->setSizePolicy(sizePolicy2);
        ChooseButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/graphics/icons8-\320\262\321\213\320\261\320\276\321\200-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        ChooseButton->setIcon(icon2);
        ChooseButton->setIconSize(QSize(48, 48));
        splitter->addWidget(ChooseButton);
        DeleteButton = new QPushButton(splitter);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));
        sizePolicy2.setHeightForWidth(DeleteButton->sizePolicy().hasHeightForWidth());
        DeleteButton->setSizePolicy(sizePolicy2);
        DeleteButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/graphics/Delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        DeleteButton->setIcon(icon3);
        DeleteButton->setIconSize(QSize(40, 40));
        splitter->addWidget(DeleteButton);
        CloseButton = new QPushButton(splitter);
        CloseButton->setObjectName(QString::fromUtf8("CloseButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/graphics/Exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        CloseButton->setIcon(icon4);
        CloseButton->setIconSize(QSize(48, 48));
        splitter->addWidget(CloseButton);

        verticalLayout->addWidget(splitter);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 690, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Commit it!", nullptr));
        CurrentPath->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \320\277\320\260\320\277\320\272\320\260:", nullptr));
#ifndef QT_NO_STATUSTIP
        PathField->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        PathField->setText(QApplication::translate("MainWindow", "My Computer", nullptr));
        CurrentPath_2->setText(QApplication::translate("MainWindow", "\320\237\320\260\320\277\320\272\320\260 \321\200\320\265\320\267. \320\272\320\276\320\277\320\270\320\270:", nullptr));
#ifndef QT_NO_STATUSTIP
        PathField_2->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        PathField_2->setText(QApplication::translate("MainWindow", "My Computer", nullptr));
        CommitButton->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\276\321\202\321\201\320\273\320\265\320\266\320\270\320\262\320\260\320\275\320\270\320\265", nullptr));
        ChooseButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\276\321\202\321\201\320\273\320\265\320\266\320\270\320\262\320\260\320\275\320\270\320\265", nullptr));
        DeleteButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\276\321\202\321\201\320\273\320\265\320\266\320\270\320\262\320\260\320\275\320\270\320\265", nullptr));
        CloseButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
