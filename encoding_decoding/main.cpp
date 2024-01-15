#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QRandomGenerator>


QByteArray make_ascii_data(){
    QByteArray data;
    for(int i = 0;i<10;i++){
        data.append(1);
        data.append(4);
        data.append(124);
        data.append(21);
        data.append(10); // \n
    }
    return data;
}

QString make_utf_data(){
    QString data;
    data.append("Unicode test\r\n");
    for(int i = 0;i<10;i++){
        int number = QRandomGenerator::global()->bounded(121231);
        data.append(number);
    }
    data.append("\n");
    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /*
     ASCII is a 7-bit character set containing 128 characters.
     It contains the numbers from 0-9, the upper and lower case English letters from A to Z, and some special characters.
     The character sets used in modern computers, in HTML, and on the Internet, are all based on ASCII.

     http://www.asciitable.com/
     */

    QByteArray data = make_ascii_data();
    QString path = QDir::currentPath() + QDir::separator()+"ASCII_data.txt";
    QFile file(path);
    if(file.open(QIODevice::WriteOnly)){
        file.write(data);
        file.close();
    }
    qInfo()<<"Done!";

    /*
      UTF-8 is a variable width character encoding capable of encoding all 1,112,064 valid code points in
      Unicode using one to four 8-bit bytes.
      The encoding is defined by the Unicode standard, and was originally designed by Ken Thompson and Rob Pike.
      Called "Unicode"
    */

    QString data1 = make_utf_data();
    QString path1 = QDir::currentPath() + QDir::separator()+"utf_data.txt";
    QFile file1(path1);
    if(file1.open(QIODevice::WriteOnly)){
        QTextStream stream(&file1);
        stream.setCodec("UTF-8");
        stream<<data1;
        stream.flush();

        file1.close();
    }
    qInfo()<<"Done!";


    return a.exec();
}
