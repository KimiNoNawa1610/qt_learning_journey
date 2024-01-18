#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "shapecanvas.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_shapebox_activated(int index);

    void on_penwidthbox_valueChanged(int arg1);

    void on_stylebox_activated(int index);

    void on_capbox_activated(int index);

    void on_joinbox_activated(int index);

    void on_brushbox_activated(int index);

    void on_a_toggled(bool checked);

    void on_t_toggled(bool checked);

    void penChanged();
    void brushChanged();

private:
    Ui::Widget *ui;
    ShapeCanvas * canvas;
};
#endif // WIDGET_H
