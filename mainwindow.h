#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>

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
    void on_addButton_clicked();

    void on_clearButton_clicked();

    void on_clearAllButton_clicked();

private:
    Ui::MainWindow *ui;
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "//ToDoList.txt";
};
#endif // MAINWINDOW_H
