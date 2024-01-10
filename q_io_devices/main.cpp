#include <QCoreApplication>
#include <QIODevice>
#include <QBuffer>
#include <QDebug>
#include <QDir>
#include <QString>
#include <QDateTime>
#include <QFileInfo>
#include <QStorageInfo>
#include <QByteArray>
#include <QFile>

// function to create a directory
bool create_dir(QString path){
    QDir dir(path); // create a dir

    if(dir.exists()){
        qInfo()<<"Already Existed";
        return true;
    }

    if(dir.mkpath(path)){
        qInfo()<<"Created: ";
        return true;
    }
    else{
        qInfo()<<"Cannot Created";
        return false;
    }
}

// function to rename a dir
bool rename(QString path, QString name){
    QDir dir(path);
    if(!dir.exists()){
        qInfo()<<"Path does not exist";
        return false;
    }
    int pos = path.lastIndexOf(QDir::separator()); // different os has different operator so we should use the QDir::separator()
    QString parent = path.mid(0,pos);// the parent is from the starting to the last separator
    QString new_path = parent + QDir::separator() + name;
    qInfo()<<"New path: "<<new_path;
    return dir.rename(path,new_path); // change the path of the dir
}

// function to remove dir
bool remove(QString path){
    qInfo()<<"Removing: "<<path;
    QDir dir(path);
    if(!dir.exists()){
        qInfo()<<"Not Existed";
        return false;
    }
    return dir.removeRecursively();// remove everything inside the folder, do not put anything in the trash bin
    //return dir.remove() // remove empty folder

}

// put data to a file
bool put(QString path, QByteArray data, QIODevice::OpenMode mode){
    QFile file(path);
    if(!file.open(mode)){
        qWarning() << file.errorString();
        return false;
    }

    qint64 bytes = file.write(data);
    if(!bytes){
        qWarning()<<file.errorString();
    }
    else{
        qInfo()<<"Wrote "<<bytes<<" to the file!";
    }
    file.flush(); // not needed but good to have
    file.close();
    return true;
}

// function to write data to the file
bool write(QString path, QByteArray data){
    qInfo()<<"Write to file";
    if(put(path,data,QIODevice::WriteOnly)){
        qInfo()<<"Data written to file";
        return true;
    }else{
        qWarning()<<"Failed to write to file!";
        return false;
    }
}

// function to append data to the file
void append(QString path, QByteArray data){
    qInfo()<<"Write to file";
    if(put(path,data,QIODevice::Append)){
        qInfo()<<"Data appended to file";
    }else{
        qWarning()<<"Failed to append to file!";
    }
}

bool create_file(QString path){
    QByteArray data;
    for(int i = 0;i<5;i++){
        data.append(QString::number(i)+"\n");
    }
    return write(path,data);
}

void read_file(QString path){
    QFile file(path);
    if(!file.exists()){
        qWarning()<<"File not found";
        return;
    }

    if(!file.open(QIODevice::ReadOnly)){
        qWarning()<<file.errorString();
        return;
    }
    qInfo()<<file.readAll(); // if there is a big file, there maybe a crash if the memory is not enough
    qInfo()<<"Done";
}

void read_lines(QString path){
    QFile file(path);
    if(!file.exists()){
        qWarning()<<"File not found";
        return;
    }

    if(!file.open(QIODevice::ReadOnly)){
        qWarning()<<file.errorString();
        return;
    }
    while(!file.atEnd()){
        qInfo()<<"Read: "<<file.readLine(); // best with text file!
    }

    qInfo()<<"Done";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //* QBuffer *

    QBuffer buffer;

    if(buffer.open(QIODevice::ReadWrite)){
        qInfo()<<"Buffer Open";
        QByteArray data("Hellow Wolrd"); // read and write in and out from the buffer
        for(int i = 0;i<5;i++){
            buffer.write(data);
            buffer.write("\r\n");

        }

        // file and device access you may need to flush the data to the device
        //buffer.flush(); // writing directly to the memory but we will need this in the future
        buffer.seek(0);

        qInfo()<<buffer.readAll(); // return the entire buffer as QByteArray
        buffer.close(); // make sure we always close the buffer after open


    }else{
        qInfo()<<"Cannot open buffer!"; // if cannot open, something wrong with the operation system
    }

    //* QDir *

    QString path = QDir::currentPath();// get the current path of the folder
    QString test = path+QDir::separator()+"test";
    QString temp = path+QDir::separator()+"temp";

    QDir current(QDir::currentPath());
    if(current.exists()){
        //QFileInfoList dirs = current.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot); // get files info with filters
        foreach(QFileInfo fi, current.entryInfoList()){
            qInfo()<<fi.fileName()<<" Size: "<<fi.size()<<" Created: "<<fi.birthTime(); // output all file names in the current dir
        }
    }

    if(create_dir(test)){
        qInfo()<<"Created Test Dir";
        if(rename(test,"temp")){
            qInfo()<<"Renamed!";
            if(remove(temp)){
                qInfo()<<"Removed Temp Dir";
            }
            else{
                qInfo()<<"Cannot Remove Temp Dir";
            }
        }
    }

    //* QStorageInfo *

    foreach(QStorageInfo storage, QStorageInfo::mountedVolumes()){ // get the volume of the disks
        qInfo()<<"Name: "<<storage.displayName()<<" | Type: "<<storage.fileSystemType()<< " | Total Volume: "<<storage.bytesTotal()
                <<" Bytes"<<" | Available: "<<storage.bytesAvailable()<< " Bytes";
    }


    //* QFile *
    QString text_file_path = path + QDir::separator()+"test.txt";
    qInfo()<<text_file_path;
    QByteArray data("This is the line.");
    for(int i =0;i<5;i++){
        QString numbers = QString::number(i);
        numbers.append(", ");
        QByteArray line(numbers.toLatin1()+data);
        write(path,line);
    }

    //* How to read from a file correctly *
    QString read_file_path = QDir::currentPath() + QDir::separator() + "test.txt";

    if(create_file(read_file_path)){
        read_file(read_file_path);
        read_lines(read_file_path);
    }

    return a.exec();
}
