#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QWidget>
#include <QColor>
#include <QGridLayout>
#include <QLabel>

class ColorPicker : public QWidget
{
    Q_OBJECT
public:
    explicit ColorPicker(QWidget *parent = nullptr);
    QColor getColor() const;
    void setColor(const QColor &newColor);

private:
    void populateColors();
    void setupUi();
    QColor color;
    QVector<QColor> colorList;
    QGridLayout* gridLayout;
    QLabel *label;

signals:
    void colorChanged(QColor newColor);

public slots:
    void colorButtonClicked(int num);
};

#endif // COLORPICKER_H
