#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QMenu* menu[10];
    QAction* act[10];
    QMenuBar* menuBar ;
    QStatusBar* status ;

private slots:
    void on_pushButton_clicked();
    void trigerMenu(QAction* act);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
