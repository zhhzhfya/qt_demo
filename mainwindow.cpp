#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QDate>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    menu[0] = new QMenu("文件");
    menu[0]->addAction("编辑");
    menu[0]->addAction("查看");
    menu[0]->addAction("工具");

    act[0] = new QAction("新建",this);
    act[0]->setShortcut(Qt::CTRL | Qt::Key_A );
    act[0]->setStatusTip("这是一个新建菜单");

    act[1] = new QAction("打开",this);
    act[1]->setCheckable(true);

    menu[1] = new QMenu("保存");
    menu[1]->addAction(act[0]);
    menu[1]->addAction(act[1]);

    menu[2] = new QMenu("打印");
    menu[2]->addAction("打印设置");
    menu[2]->addMenu(menu[1]);

    menuBar = new QMenuBar(this);
    menuBar->addMenu(menu[0]);
    menuBar->addMenu(menu[2]);
    menuBar->setGeometry(0,0,this->width(),30);
 //asdfasdfsad
    connect(menuBar,SIGNAL(triggered(QAction*)),this,SLOT(trigerMenu(QAction*)));
}

void MainWindow::trigerMenu(QAction* act)
{
    if(act->text() == "新建")
    {
        qDebug()<<"新建菜单被按下";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QPushButton *button = new QPushButton("&Download", this);
    ui->mainToolBar->addWidget(button);
    qDebug() << "Date:" << QDate::currentDate();
    QMessageBox::information(this, "ok", "hi");
}
