#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include <bitset>
#include <string>

const int bits=83;

using namespace std;
string Hex2Bin(const string& s);

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

void MainWindow::on_pushButton_clicked()
{
    string txt = ui->textEdit->toPlainText().toStdString();
    ui->textEdit_2->setText(QString::fromStdString(Hex2Bin(txt)));
}

string Hex2Bin(const string& s)
{
    stringstream ss;
    ss << hex << s;
    unsigned int n;
    ss >> n;
    bitset<bits> b(n);
    return b.to_string();
}

string Bin2Hex(const string& s)
{
    bitset<bits> bs(s);
    unsigned n = bs.to_ulong();
    stringstream ss;
    ss << hex << n;
    return ss.str();
}



void MainWindow::on_pushButton_3_clicked()
{
    string txt = ui->textEdit_2->toPlainText().toStdString();
    ui->textEdit->setText(QString::fromStdString(Bin2Hex(txt)));
}
