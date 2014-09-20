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
        //qDebug() << i;
        //rendered += parse(strings[i]);
        test += strings[i].toLocal8Bit().constData();
        test += "\n";

    }

    //TODO
    size_t pos= 0;
    css = "<style> @import url(http://fonts.googleapis.com/css?family=Ubuntu+Mono);body{ letter-spacing: 1.5px; background-color:#444444; font-family: 'Ubuntu Mono' ;} .black{ color:#000000; } .darkblue{ color:#000080; } .darkgreen{ color:#008000; } .darkcyan{ color:#008080; } .darkred{ color:#800000; } .darkmagenta{ color:#800080; } .darkyellow{ color:#808000; } .darkwhite{ color:#C0C0C0; } .darkgrey{ color:#808080; } .blue{ color:#0000FF; } .green{ color:#00FF00; } .cyan{ color:#00FFFF; } .red{ color:#FF0000; } .magenta{ color:#FF00FF; } .yellow{ color:#FFFF00; } .white{ color:#FFFFFF; } </style> ";
    ui->setupUi(this);
    divStartStart = "<span class=\"";
    divStartEnd   = "\">";

    divEnd = "</span>";
    footer = "</body></html>";
    header = "<!DOCTYPE html>\
<html lang=\"en\">\
<head>\
<meta charset=\"UTF-8\">\
<title>Document</title>\
</head>\
<body> ";

    //std::string test = "&00&10&20&30&40\n&50&60&70&80&90";
    //qDebug() <<pos;
    std::string prepared;

    prepared = header + divStartStart + "white" + divStartEnd;
    test.insert(pos, prepared);
    pos += prepared.size();

    bool isPrevC = false;

    while(pos < test.size())
    {
        if(test[pos] == '\n')
        {
            prepared = "<br>";
            test.insert(pos, prepared);
            pos += prepared.size();
        }
        if(isPrevC)
        {
            switch(test[pos])
            {
            case '&':
                test.erase(pos,1);
                break;
            case '0':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "black" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            case '1':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "darkblue" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            case '2':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "darkgreen" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            case '3':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "darkcyan" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            case '4':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "darkred" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            case '5':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "darkmagenta" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            case '6':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "darkyellow" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            case '7':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "darkwhite" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            case '8':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "darkgrey" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            case '9':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "blue" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            case 'a':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "green" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            case 'b':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "cyan" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            case 'c':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "red" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            case 'd':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "magenta" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            case 'e':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "yellow" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            case 'f':
                pos--;
                test.erase(pos,2);
                prepared = divEnd + divStartStart + "white" + divStartEnd;
                test.insert(pos, prepared);
                pos += prepared.size();
                break;
            default:

            ;}
        }

        isPrevC = (test[pos] == '&');
        pos++;
    }
    prepared = divEnd + css + footer;
    test.insert(pos, prepared);
    pos += prepared.size();


    qDebug() << test.c_str();

    writeHtml();


}

QString MainWindow::parse(QString line){
    QString helper;

    //qDebug() << "Übergabe: ";
    //qDebug() << "Color capacity" << colors.s
    for(int i = 0; i < colors.size(); i++){
        std::string temp = line.toLocal8Bit().constData();
        qDebug() << temp.c_str();

        //qDebug() << "Conversion: " << i;
        if(temp.find(colors[i].toLocal8Bit().constData()) != std::string::npos){
            qDebug() << "foundcolor";

                line = line.replace(colors[i],"");

                helper= "<div class=\"" + classes[i] + " log\">" + line + "</div>";
        }else {
            helper=  line + "<br>";
        }


    }






    return helper;
}

void MainWindow::writeHtml(){
    QString filename = QFileDialog::getSaveFileName(this,
        tr("Save as html"), "", tr("html Files (*.html)"));

    QFile file(filename);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);


    out << test.c_str();
    file.close();

}
