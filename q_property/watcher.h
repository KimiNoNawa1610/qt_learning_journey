#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>
#include <QDebug>

// to have a slot that we can read from
class watcher : public QObject
{
    Q_OBJECT
public:
    explicit watcher(QObject *parent = nullptr);

signals:

public slots:
    void messageChanged(QString message);
};

#endif // WATCHER_H
