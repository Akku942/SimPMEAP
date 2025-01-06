#ifndef LINES_H
#define LINES_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class Lines : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX )
public:
    explicit Lines();
    ~Lines();

    qreal x() const;

signals:

public slots:
    void setx(qreal newX);

private:
    QGraphicsPixmapItem * line1;
    QGraphicsPixmapItem * line2;
    QGraphicsPixmapItem * line3;
    QGraphicsPixmapItem * line4;
    QGraphicsPixmapItem * line5;
    QGraphicsPixmapItem * line6;
    QGraphicsPixmapItem * line7;
    QGraphicsPixmapItem * line8;

    QPropertyAnimation *xAnimation;

    qreal m_x;
};

#endif // LINES_H
