#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include <bitset>
#include <string>
#include <QDebug>


using namespace std;
string Hex2Bin(const string& s);
string Bin2Hex(const string& bin);
string Hex_Xor(const string& s1,const string& s2);

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

string Hex2Bin(const string& hex)
{
    string bin="";
    for(unsigned long long i=0;i<hex.length();i++){
        switch(toupper(hex[i]))
            {
                case '0': bin+= "0000";
                    break;
                case '1': bin+= "0001";
                break;
                case '2': bin+= "0010";
                break;
                case '3': bin+= "0011";
                break;
                case '4': bin+= "0100";
                break;
                case '5': bin+= "0101";
                break;
                case '6': bin+= "0110";
                break;
                case '7': bin+= "0111";
                break;
                case '8': bin+= "1000";
                break;
                case '9': bin+= "1001";
                break;
                case 'A': bin+= "1010";
                break;
                case 'B': bin+= "1011";
                break;
                case 'C': bin+= "1100";
                break;
                case 'D': bin+= "1101";
                break;
                case 'E': bin+= "1110";
                break;
                case 'F': bin+= "1111";
                break;
            }
    }
    return bin;
}

string Bin2Hex(const string& bin)
{
    string hex="",tmp="";
    for (int i=0;i<bin.length();i+=4)
        {
            tmp = bin.substr(i,4);
            if (!tmp.compare("0000"))
            {
                hex = hex + "0";
            }
            else if (!tmp.compare("0001"))
            {
                hex = hex + "1";
            }
            else if (!tmp.compare("0010"))
            {
                hex = hex + "2";
            }
            else if (!tmp.compare("0011"))
            {
                hex = hex + "3";
            }
            else if (!tmp.compare("0100"))
            {
                hex = hex + "4";
            }
            else if (!tmp.compare("0101"))
            {
                hex = hex + "5";
            }
            else if (!tmp.compare("0110"))
            {
                hex = hex + "6";
            }
            else if (!tmp.compare("0111"))
            {
                hex = hex + "7";
            }
            else if (!tmp.compare("1000"))
            {
                hex = hex + "8";
            }
            else if (!tmp.compare("1001"))
            {
                hex = hex + "9";
            }
            else if (!tmp.compare("1010"))
            {
                hex = hex + "A";
            }
            else if (!tmp.compare("1011"))
            {
                hex = hex + "B";
            }
            else if (!tmp.compare("1100"))
            {
                hex = hex + "C";
            }
            else if (!tmp.compare("1101"))
            {
                hex = hex + "D";
            }
            else if (!tmp.compare("1110"))
            {
                hex = hex + "E";
            }
            else if (!tmp.compare("1111"))
            {
                hex = hex + "F";
            }
            else
            {
                continue;
            }
        }
    return hex;
}

string Hex_Xor(const string& s1,const string& s2){
    stringstream ss;
    string result="";
    unsigned tmp1,tmp2;
    if(s1.length()!=s2.length()){
        result ="Error, not simular lengths of string";
        return result;
    }
    for(unsigned long long i=0;i<s1.length();i++ ){
        stringstream converter1;
        converter1<<s1[i];
        converter1 >> hex >> tmp1;
        converter1.str().clear();
        stringstream converter2;
        converter2<<s2[i];
        converter2 >> hex >> tmp2;
        converter2.str().clear();
        tmp1=tmp1^tmp2;
        ostringstream converter3;
        converter3<<hex<<tmp1;

        result+=converter3.str();
    }
    result.rend();
    return result;
}

void MainWindow::on_pushButton_3_clicked()
{
    string txt = ui->textEdit_2->toPlainText().toStdString();
    ui->textEdit->setText(QString::fromStdString(Bin2Hex(txt)));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit_6->setText(QString::fromStdString(Hex_Xor(ui->textEdit_4->toPlainText().toStdString(),ui->textEdit_5->toPlainText().toStdString())));
}
