#include "paintcanvas.h"
#include <QPainter>
#include <QMouseEvent>

PaintCanvas::PaintCanvas(QWidget *parent)
    : QWidget{parent},
      m_tool(Pen),
      m_fill(false),
      m_drawing(false),
      m_penWidth(3),
      m_fillColor(Qt::red),
      m_penColor(Qt::green),
      m_lastRect(QRectF(0, 0, 0, 0))
{

}

PaintCanvas::ToolType PaintCanvas::tool() const
{
    return m_tool;
}

void PaintCanvas::setTool(ToolType newTool)
{
    m_tool = newTool;
}

bool PaintCanvas::fill() const
{
    return m_fill;
}

void PaintCanvas::setFill(bool newFill)
{
    m_fill = newFill;
}

int PaintCanvas::penWidth() const
{
    return m_penWidth;
}

void PaintCanvas::setPenWidth(int newPenWidth)
{
    m_penWidth = newPenWidth;
}

QColor PaintCanvas::fillColor() const
{
    return m_fillColor;
}

void PaintCanvas::setFillColor(const QColor &newFillColor)
{
    m_fillColor = newFillColor;
}

QColor PaintCanvas::penColor() const
{
    return m_penColor;
}

void PaintCanvas::setPenColor(const QColor &newPenColor)
{
    m_penColor = newPenColor;
}

void PaintCanvas::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void PaintCanvas::drawLineTo(const QPoint &endPoint)
{

}

void PaintCanvas::drawRectTo(const QPoint &endPoint, bool ellipse)
{

}

void PaintCanvas::eraseUnder(const QPoint &topLeft)
{

}

void PaintCanvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_lastPoint = event->pos();
        m_drawing = true;
    }
}

void PaintCanvas::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && m_drawing)
    {
        m_drawing = false;

        if (m_tool == Pen)
        {
            drawLineTo(event->pos());
        }
        if (m_tool == Rect)
        {
            drawRectTo(event->pos());
        }
        if (m_tool == Ellipse)
        {
            drawRectTo(event->pos(), true);
        }
        if (m_tool == Eraser)
        {
            eraseUnder(event->pos());
        }

        // Reset the last rect
        m_lastRect = QRect(0, 0, 0, 0);
    }
}

void PaintCanvas::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->button() & Qt::LeftButton) && m_drawing)
    {
        if (m_tool == Pen)
        {
            drawLineTo(event->pos());
        }
        if (m_tool == Rect)
        {
            drawRectTo(event->pos());
        }
        if (m_tool == Ellipse)
        {
            drawRectTo(event->pos(), true);
        }
        if (m_tool == Eraser)
        {
            eraseUnder(event->pos());
        }
    }
}

void PaintCanvas::paintEvent(QPaintEvent *event)
{

}

void PaintCanvas::resizeEvent(QResizeEvent *event)
{
    if (width() > m_image.width() || height() > m_image.height())
    {
        int newWidth = qMax(width() + 128, m_image.width());
        int newHeight = qMax(height() + 128, m_image.height());
        resizeImage(&m_image, QSize(newWidth, newHeight));
        update();
    }

    QWidget::resizeEvent(event);
}
