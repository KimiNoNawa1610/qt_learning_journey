#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // setup the canvas
    canvas = new ShapeCanvas(this);
    ui->canvaslayout->addWidget(canvas);

    // populate the value for shape box
    ui->shapebox->addItem(tr("Polygon"),ShapeCanvas::Polygon);
    ui->shapebox->addItem(tr("Rectangle"),ShapeCanvas::Rectangle);
    ui->shapebox->addItem(tr("Rounded Rectangle"),ShapeCanvas::RoundedRectangle);
    ui->shapebox->addItem(tr("Ellipse"),ShapeCanvas::Ellipse);
    ui->shapebox->addItem(tr("Pie"),ShapeCanvas::Pie);
    ui->shapebox->addItem(tr("Chord"),ShapeCanvas::Chord);
    ui->shapebox->addItem(tr("Text"),ShapeCanvas::Text);
    ui->shapebox->addItem(tr("Pixmap"),ShapeCanvas::Pixmap);

    // populate the value for pen style
    ui->stylebox->addItem(tr("Solid"),static_cast<int>(Qt::SolidLine));
    ui->stylebox->addItem(tr("Dash"),static_cast<int>(Qt::DashLine));
    ui->stylebox->addItem(tr("Dot"),static_cast<int>(Qt::DotLine));
    ui->stylebox->addItem(tr("Dash Dot"),static_cast<int>(Qt::DashDotDotLine));
    ui->stylebox->addItem(tr("Dash Dot Dot"),static_cast<int>(Qt::DashDotDotLine));
    ui->stylebox->addItem(tr("None"),static_cast<int>(Qt::NoPen));

    // pencap box
    ui->capbox->addItem(tr("Flat"), Qt::FlatCap);
    ui->capbox->addItem(tr("Square"), Qt::SquareCap);
    ui->capbox->addItem(tr("Round"), Qt::RoundCap);

    // join box
    ui->joinbox->addItem(tr("Miter"),Qt::MiterJoin);
    ui->joinbox->addItem(tr("Bevel"),Qt::BevelJoin);
    ui->joinbox->addItem(tr("Round"),Qt::RoundJoin);

    // brush box
    ui->brushbox->addItem(tr("Linear Gradient"),
                                    static_cast<int>(Qt::LinearGradientPattern));
    ui->brushbox->addItem(tr("Radial Gradient"),
                                    static_cast<int>(Qt::RadialGradientPattern));
    ui->brushbox->addItem(tr("Conical Gradient"),
                                    static_cast<int>(Qt::ConicalGradientPattern));
    ui->brushbox->addItem(tr("Texture"), static_cast<int>(Qt::TexturePattern));
    ui->brushbox->addItem(tr("Solid"), static_cast<int>(Qt::SolidPattern));
    ui->brushbox->addItem(tr("Horizontal"), static_cast<int>(Qt::HorPattern));
    ui->brushbox->addItem(tr("Vertical"), static_cast<int>(Qt::VerPattern));
    ui->brushbox->addItem(tr("Cross"), static_cast<int>(Qt::CrossPattern));
    ui->brushbox->addItem(tr("Backward Diagonal"), static_cast<int>(Qt::BDiagPattern));
    ui->brushbox->addItem(tr("Forward Diagonal"), static_cast<int>(Qt::FDiagPattern));
    ui->brushbox->addItem(tr("Diagonal Cross"), static_cast<int>(Qt::DiagCrossPattern));
    ui->brushbox->addItem(tr("Dense 1"), static_cast<int>(Qt::Dense1Pattern));
    ui->brushbox->addItem(tr("Dense 2"), static_cast<int>(Qt::Dense2Pattern));
    ui->brushbox->addItem(tr("Dense 3"), static_cast<int>(Qt::Dense3Pattern));
    ui->brushbox->addItem(tr("Dense 4"), static_cast<int>(Qt::Dense4Pattern));
    ui->brushbox->addItem(tr("Dense 5"), static_cast<int>(Qt::Dense5Pattern));
    ui->brushbox->addItem(tr("Dense 6"), static_cast<int>(Qt::Dense6Pattern));
    ui->brushbox->addItem(tr("Dense 7"), static_cast<int>(Qt::Dense7Pattern));
    ui->brushbox->addItem(tr("None"), static_cast<int>(Qt::NoBrush));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_shapebox_activated(int index)
{
    ShapeCanvas::Shape shape = ShapeCanvas::Shape(index);
    canvas->setShape(shape);
}


void Widget::on_penwidthbox_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    penChanged();
}


void Widget::on_stylebox_activated(int index)
{
    Q_UNUSED(index);
    penChanged();
}


void Widget::on_capbox_activated(int index)
{
    Q_UNUSED(index);
    penChanged();
}


void Widget::on_joinbox_activated(int index)
{
    Q_UNUSED(index);
    penChanged();
}


void Widget::on_brushbox_activated(int index)
{
    Q_UNUSED(index);
    brushChanged();
}


void Widget::on_a_toggled(bool checked)
{
    canvas->setAntialized(checked);
}


void Widget::on_t_toggled(bool checked)
{
    canvas->setTransformed(checked);
}

void Widget::penChanged()
{
    int width = ui->penwidthbox->value();
    Qt::PenStyle style = Qt::PenStyle(ui->stylebox->itemData(ui->stylebox->currentIndex()).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(ui->capbox->itemData(ui->capbox->currentIndex()).toInt());
    Qt::PenJoinStyle joint = Qt::PenJoinStyle(ui->joinbox->itemData(ui->joinbox->currentIndex()).toInt());

    QPen pen;
    pen.setWidth(width);
    pen.setCapStyle(cap);
    pen.setStyle(style);
    pen.setJoinStyle(joint);
    canvas->setPen(pen);


}

void Widget::brushChanged()
{
    Qt::BrushStyle style = Qt::BrushStyle(ui->brushbox->itemData(ui->brushbox->currentIndex()).toInt());
    if (style == Qt::LinearGradientPattern) {
        QLinearGradient linearGradient(0, 0, 100, 100);
        linearGradient.setColorAt(0.0, Qt::red);
        linearGradient.setColorAt(0.2, Qt::green);
        linearGradient.setColorAt(1.0, Qt::blue);
        canvas->setBrush(linearGradient);
    } else if (style == Qt::RadialGradientPattern) {
        QRadialGradient radialGradient(50, 50, 50, 70, 70);
        radialGradient.setColorAt(0.0, Qt::red);
        radialGradient.setColorAt(0.2, Qt::green);
        radialGradient.setColorAt(1.0, Qt::blue);
        canvas->setBrush(radialGradient);
    } else if (style == Qt::ConicalGradientPattern) {
        QConicalGradient conicalGradient(50, 50, 150);
        conicalGradient.setColorAt(0.0, Qt::red);
        conicalGradient.setColorAt(0.2, Qt::green);
        conicalGradient.setColorAt(1.0, Qt::blue);
        canvas->setBrush(conicalGradient);
    } else if (style == Qt::TexturePattern) {
        canvas->setBrush(QBrush(QPixmap(":/images/image.png")));
    } else {
        canvas->setBrush(QBrush(Qt::blue, style));
    }
}

