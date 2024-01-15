#include "logger.h"

// initialize the static variables

QString logger::filename = QDir::currentPath()+QDir::separator()+"log.txt";
bool logger::logging = false; // default to false, only start logging when attach
static const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

logger::logger(QObject *parent)
    : QObject{parent}
{}

void logger::attach()
{
    logger::logging = true;
    qInstallMessageHandler(logger::handler);


}

void logger::handler(QtMsgType type, const QMessageLogContext &context, const QString &message)
{
    if(logger::logging){
        QString txt;
        switch(type){
        case QtInfoMsg:
            txt=QString("Info: %1 in %2").arg(message);
            break;
        case QtDebugMsg:
            txt=QString("Debug: %1").arg(message);
            break;
        case QtWarningMsg:
            txt=QString("Warning: %1").arg(message);
            break;
        case QtCriticalMsg:
            txt=QString("Critial: %1").arg(message);
            break;
        case QtFatalMsg:
            txt=QString("Fatal: %1").arg(message);
            break;

        }
        QFile file(logger::filename);
        if(file.open(QIODevice::WriteOnly | QIODevice::Append)){
            QTextStream ts(&file);
            ts<<QDateTime::currentDateTime().toString()<<"-"<<txt<<"file: "<<context.file<<" line:"<<context.line<<endl;
            ts.flush();
            file.close();
        }

    }

    (*QT_DEFAULT_MESSAGE_HANDLER)(type,context,message);
}
