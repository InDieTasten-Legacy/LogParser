#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    colors.push_back("&0");
    colors.push_back("&1");
    colors.push_back("&2");
    colors.push_back("&3");
    colors.push_back("&4");
    colors.push_back("&5");
    colors.push_back("&6");
    colors.push_back("&7");
    colors.push_back("&8");
    colors.push_back("&9");
    colors.push_back("&a");
    colors.push_back("&b");
    colors.push_back("&c");
    colors.push_back("&d");
    colors.push_back("&e");
    colors.push_back("&f");


    htmlcolors.push_back("000000");
    htmlcolors.push_back("000080");
    htmlcolors.push_back("008000");
    htmlcolors.push_back("008080");
    htmlcolors.push_back("800000");
    htmlcolors.push_back("800080");
    htmlcolors.push_back("808000");
    htmlcolors.push_back("C0C0C0");
    htmlcolors.push_back("808080");
    htmlcolors.push_back("0000FF");
    htmlcolors.push_back("00FF00");
    htmlcolors.push_back("00FFFF");
    htmlcolors.push_back("FF0000");
    htmlcolors.push_back("FF00FF");
    htmlcolors.push_back("FFFF00");
    htmlcolors.push_back("FFFFFF");


    classes.push_back("black");
    classes.push_back("darkblue");
    classes.push_back("darkgreen");
    classes.push_back("darkcyan");
    classes.push_back("darkred");
    classes.push_back("darkmagenta");
    classes.push_back("darkyellow");
    classes.push_back("darkwhite");
    classes.push_back("darkgrey");
    classes.push_back("blue");
    classes.push_back("green");
    classes.push_back("cyan");
    classes.push_back("red");
    classes.push_back("magenta");
    classes.push_back("yellow");
    classes.push_back("white");




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open ulog"), "H\\Data\\Github\\--UntitledGame--\\UG\\logs", tr("ulog Files (*.ulog)"));

    QFile log(fileName);
    QStringList strings;


    if(log.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&log);
        while (!in.atEnd()) {
            QString temp =in.readLine();
            strings.append(temp);

        }
    }

    for (int i = 0; i < strings.size(); i++){
        qDebug() << i;
        rendered += parse(strings[i]);

    }

    writeHtml();


}

QString MainWindow::parse(QString line){
    qDebug() << "Übergabe: ";
    //qDebug() << "Color capacity" << colors.s
    for(int i = 0; i < colors.size(); i++){
        std::string temp = line.toLocal8Bit().constData();
        //qDebug() << "Conversion: " << i;
        if(temp.find(colors[i].toLocal8Bit().constData()) != std::string::npos){
            qDebug() << "foundcolor";
                line = line.replace(colors[i],"");

                line= "<div class=\"" + classes[i] + " log\">" + line + "</div>";
        }


    }


    return line;
}

void MainWindow::writeHtml(){
    QString filename = QFileDialog::getSaveFileName(this,
        tr("Save as html"), "", tr("html Files (*.html)"));

    QFile file(filename);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    for (int i = 0; i < rendered.size(); i++){
        out << rendered[i];
    }

}
