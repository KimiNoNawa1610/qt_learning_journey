#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

void save_age(QSettings *setting,QString group,QString name, int age){
    setting->beginGroup(group);
    setting->setValue(name,age);
    setting->endGroup();
}

int get_age(QSettings *setting,QString group,QString name){
    setting->beginGroup(group);
    if(!setting->contains(name)){
        setting->endGroup();
        qWarning()<<"Does not contain"<<name;
        return 0;
    }
    int value = setting->value(name).toInt();
    setting->endGroup();
    return value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setOrganizationName("test");
    QCoreApplication::setOrganizationDomain("qttest.com");
    QCoreApplication::setApplicationName("qtsettings");

    QSettings settings(QCoreApplication::organizationName(),QCoreApplication::applicationName());

    // save the settings
    //settings.setValue("test",123); // depend on operating system but only need to run one

    // read the settings
    qInfo()<<settings.value("test").toString();

    save_age(&settings,"people","Me",23);
    save_age(&settings,"babies","infant",1);

    qInfo()<<get_age(&settings,"people","Me");
    qInfo()<<get_age(&settings,"babies","infant");

    return a.exec();
}
