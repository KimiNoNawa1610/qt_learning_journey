#ifndef DATETIMEWIDGET_H
#define DATETIMEWIDGET_H

#include <QWidget>
#include <QDate>
#include <QLabel>
#include <QTimer>

class DateTimeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DateTimeWidget(QWidget *parent = nullptr);

private:
    QTimer * timer;
    QLabel * labelTop; // display date
    QLabel * labelBottom; // display time
    QString  dateString;
    QString  timeString;

signals:

public slots:
    void updateTime();

};

#endif // DATETIMEWIDGET_H
