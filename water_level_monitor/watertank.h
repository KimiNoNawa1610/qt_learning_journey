#ifndef WATERTANK_H
#define WATERTANK_H

#include <QWidget>
#include <QTimer>

class WaterTank : public QWidget
{
    Q_OBJECT
public:
    explicit WaterTank(QWidget *parent = nullptr);

signals:
    void normal();
    void warning();
    void danger();

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;

    // QWidget interface
public:
    QSize sizeHint() const override;

private:
    int waterHeight; // the high that can come from the sensor but for this project, we can simulate it
    QTimer * timer;

};

#endif // WATERTANK_H
