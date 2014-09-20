#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <vector>
#include <string>

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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QStringList rendered;
    QString parse(QString line);

    std::vector<QString> colors;
    std::vector<QString> htmlcolors;
    std::vector<QString> classes;
    QStringList strings;


    std::string header;
    std::string footer;
    std::string divStartStart;
    std::string divStartEnd;
    std::string divEnd;
    std::string css;
    void writeHtml();

    std::string test;

};

#endif // MAINWINDOW_H
