#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>
#include "qdesktopservices.h"
#include "GPStxt_834.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_OpenSourceFile_clicked();

    void on_inputfilepath_clicked();

    void on_deal_with_clicked();

    void on_DisplayPath_clicked();

    void on_Quit_clicked();

    bool warrn ();

private:
    Ui::MainWindow *ui;
    QString filename;//文件名
    vector<string> dir;//处理数组输出
    QString resultFilename;//输出文件路径
//    QString Name;
//    QString Value;


    string source;
    string gps_pos;
    string gps_xml;
    string gps;
};

#endif // MAINWINDOW_H
