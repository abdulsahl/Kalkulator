#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setAlignment(Qt::AlignRight);
    QFont font = ui->lineEdit->font();
    font.setPointSize(30);
    ui->lineEdit->setFont(font);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    inputString += "1";
    ui->lineEdit->setText(inputString);
}


void MainWindow::on_pushButton_2_clicked()
{
    inputString += "2";
    ui->lineEdit->setText(inputString);
}


void MainWindow::on_pushButton_3_clicked()
{
    inputString += "3";
    ui->lineEdit->setText(inputString);
}


void MainWindow::on_pushButton_4_clicked()
{
    inputString += "4";
    ui->lineEdit->setText(inputString);
}


void MainWindow::on_pushButton_5_clicked()
{
    inputString += "5";
    ui->lineEdit->setText(inputString);
}


void MainWindow::on_pushButton_7_clicked()
{
    inputString += "6";
    ui->lineEdit->setText(inputString);
}


void MainWindow::on_pushButton_6_clicked()
{
    inputString += "7";
    ui->lineEdit->setText(inputString);
}


void MainWindow::on_pushButton_8_clicked()
{
    inputString += "8";
    ui->lineEdit->setText(inputString);
}


void MainWindow::on_pushButton_9_clicked()
{
    inputString += "9";
    ui->lineEdit->setText(inputString);
}


void MainWindow::on_pushButton_10_clicked()
{
    inputString += "0";
    ui->lineEdit->setText(inputString);
}


void MainWindow::on_pushButton_11_clicked()
{
    inputString.chop(1);
    ui->lineEdit->setText(inputString);
}


void MainWindow::on_pushButton_12_clicked()
{
    inputString.clear();
    ui->lineEdit->setText("");
}


void MainWindow::on_pushButton_13_clicked()
{
    if (!inputString.isEmpty() && inputString.at(inputString.length() - 1).isDigit())
    inputString += "+";
    ui->lineEdit->setText(inputString);
}


void MainWindow::on_pushButton_14_clicked()
{
    if (!inputString.isEmpty() && inputString.at(inputString.length() - 1).isDigit())
    inputString += "-";
    ui->lineEdit->setText(inputString);
}


void MainWindow::on_pushButton_15_clicked()
{
    if (!inputString.isEmpty() && inputString.at(inputString.length() - 1).isDigit())
    inputString += "*";
    ui->lineEdit->setText(inputString);
}


void MainWindow::on_pushButton_16_clicked()
{
    if (!inputString.isEmpty() && inputString.at(inputString.length() - 1).isDigit())
    inputString += "/";
    ui->lineEdit->setText(inputString);
}


void MainWindow::on_pushButton_17_clicked()
{
    // Dapatkan input string dari lineEdit
    QString inputString = ui->lineEdit->text();
    QVector<double> numbers; // Menyimpan angka
    QVector<QChar> ops; // Menyimpan operator

    QString tempNum = ""; // Untuk menyimpan sementara angka yang sedang dibaca
    for(int i = 0; i < inputString.length(); ++i) {
        QChar c = inputString[i];
        if(c.isDigit() || c == '.') {
            tempNum += c;
        } else if(c == '+' || c == '-' || c == '*' || c == '/') {
            numbers.push_back(tempNum.toDouble());
            ops.push_back(c);
            tempNum = "";
        }
    }
    if(!tempNum.isEmpty()) numbers.push_back(tempNum.toDouble());

    // Evaluasi * dan / terlebih dahulu
    for(int i = 0; i < ops.size(); ) {
        if(ops[i] == '*' || ops[i] == '/') {
            double result = ops[i] == '*' ? numbers[i] * numbers[i+1] : numbers[i] / numbers[i+1];
            numbers[i] = result;
            numbers.removeAt(i + 1);
            ops.removeAt(i);
        } else {
            ++i;
        }
    }

    // Evaluasi + dan -
    double result = numbers[0];
    for(int i = 0; i < ops.size(); ++i) {
        if(ops[i] == '+') {
            result += numbers[i + 1];
        } else if(ops[i] == '-') {
            result -= numbers[i + 1];
        }
    }

    // Tampilkan hasil
    ui->lineEdit->setText(QString::number(result));
    this->inputString = QString::number(result);

}


