#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "readtxt.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OpenSourceFile_clicked()
{
    filename=QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("源文件"),"",tr("text(*.txt)"));
    source=filename.toStdString();
    ui->dis_mainwindow->append(QString::fromLocal8Bit("打开源文件"));
    ui->dis_mainwindow->append(QString::fromLocal8Bit("源文件路径：")+filename);
}

void MainWindow::on_inputfilepath_clicked()
{
    resultFilename=QFileDialog::getExistingDirectory(this,QString::fromLocal8Bit("保存"),"/home",QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    QString temp=resultFilename+QString("/gps_pos_834.txt");
    gps_pos=temp.toStdString();
    temp=resultFilename+QString("/mode.xlsx");
    gps_xml=temp.toStdString();
	temp = resultFilename + QString("/");
	gps = temp.toStdString();
    ui->dis_mainwindow->append(QString::fromLocal8Bit("路径打开成功"));
}

void MainWindow::on_deal_with_clicked()
{
    //提取文件内容
    ui->dis_mainwindow->append(QString::fromLocal8Bit("开始处理"));
    readtxt s(source,gps_pos);
    s.trans();
    GPStxt_834 s1(gps_pos, gps,gps_xml);
    dir = s1.deal_pos();
    if(dir.size()!=0)
        ui->dis_mainwindow->append(QString::fromLocal8Bit("处理完成"));
    else
        ui->dis_mainwindow->append(QString::fromLocal8Bit("处理失败"));

}
