#ifndef INDICATOR_H
#define INDICATOR_H

#include <QWidget>
#include <QTimer>

class Indicator : public QWidget
{
    Q_OBJECT
public:
    explicit Indicator(QWidget *parent = nullptr);

public slots:
    void normal(); // green
    void warning(); // yellow
    void danger(); // red

signals:
private:
    void toggleLight();
    bool greenActive;
    bool redActive;
    bool yellowActive;
    bool lightOn;
    QTimer * timer;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;

    // QWidget interface
public:
    QSize sizeHint() const override;
};

#endif // INDICATOR_H
