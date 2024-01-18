#ifndef SHAPECANVAS_H
#define SHAPECANVAS_H

#include <QWidget>
#include <QPen>
#include <QBrush>

class ShapeCanvas : public QWidget
{
    Q_OBJECT
public:
    enum Shape{Polygon,Rectangle,RoundedRectangle,Ellipse,Pie,Chord,Text,Pixmap};
    explicit ShapeCanvas(QWidget *parent = nullptr);

    Shape getShape() const;
    void setShape(Shape newShape);
    QPen getPen() const;
    void setPen(const QPen &newPen);

    QBrush getBrush() const;
    void setBrush(const QBrush &newBrush);

signals:

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Shape shape;
    QPen pen;
    QBrush brush;
    bool antialized;
    bool transformed;
    QPixmap pixmap;

    // QWidget interface
public:
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    bool getAntialized() const;
    void setAntialized(bool newAntialized);
    bool getTransformed() const;
    void setTransformed(bool newTransformed);
};

#endif // SHAPECANVAS_H
