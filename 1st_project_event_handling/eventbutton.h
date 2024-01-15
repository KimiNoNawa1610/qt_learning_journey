#ifndef EVENTBUTTON_H
#define EVENTBUTTON_H

#include <QPushButton>

class EventButton : public QPushButton
{
    Q_OBJECT
public:
    explicit EventButton(QWidget *parent = nullptr);

signals:

    // QObject interface
public:
    bool event(QEvent *event) override;
};

#endif // EVENTBUTTON_H
