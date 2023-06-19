#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile file(filePath);
    if(!file.open(QIODevice::ReadWrite)) QMessageBox::information(0, "Error.", file.errorString());
    QTextStream in(&file);
    while(!in.atEnd()){
        QListWidgetItem* task = new QListWidgetItem(in.readLine(), ui->taskList);
        ui->taskList->addItem(task);
        task->setFlags(task->flags() | Qt::ItemIsEditable);
    }
    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
    QFile file(filePath);
    if(!file.open(QIODevice::ReadWrite)) QMessageBox::information(0, "Error.", file.errorString());
    QTextStream out(&file);
    for(int i = 0; i < ui->taskList->count(); ++i) out<<ui->taskList->item(i)->text()<<"\n";
    file.close();
}


void MainWindow::on_addButton_clicked()
{
    QListWidgetItem* task = new QListWidgetItem(ui->taskToAdd->text(), ui->taskList); //Format is QListWidgetItem(text, parentOfText).
    ui->taskList->addItem(task);
    task->setFlags(task->flags() | Qt::ItemIsEditable);
    ui->taskToAdd->clear();
    ui->taskToAdd->setFocus();
}


void MainWindow::on_clearButton_clicked()
{
    QListWidgetItem* task = ui->taskList->takeItem(ui->taskList->currentRow());
    delete task;
}


void MainWindow::on_clearAllButton_clicked()
{
    ui->taskList->clear();
}

