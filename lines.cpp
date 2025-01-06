#include "lines.h"
#include <QGraphicsScene>
#include <QDebug>

Lines::Lines(): line1(new QGraphicsPixmapItem(QPixmap(":/images/pruh.png"))),
                line2(new QGraphicsPixmapItem(QPixmap(":/images/pruh.png"))),
                line3(new QGraphicsPixmapItem(QPixmap(":/images/pruh.png"))),
                line4(new QGraphicsPixmapItem(QPixmap(":/images/pruh.png"))),
                line5(new QGraphicsPixmapItem(QPixmap(":/images/pruh.png"))),
                line6(new QGraphicsPixmapItem(QPixmap(":/images/pruh.png"))),
                line7(new QGraphicsPixmapItem(QPixmap(":/images/pruh.png"))),
                line8(new QGraphicsPixmapItem(QPixmap(":/images/pruh.png")))
{
    line1->setPos(QPoint(0,0) - QPoint(line1->boundingRect().width()/2 + 270,
                                line1->boundingRect().height()/2));
    line2->setPos(QPoint(0,0) - QPoint(line2->boundingRect().width()/2 + 90,
                                        line2->boundingRect().height()/2));
    line3->setPos(QPoint(0,0) - QPoint(line3->boundingRect().width()/2 - 90,
                                        line3->boundingRect().height()/2));
    line4->setPos(QPoint(0,0) - QPoint(line4->boundingRect().width()/2 - 270,
                                        line4->boundingRect().height()/2));
    line5->setPos(QPoint(0,0) - QPoint(line5->boundingRect().width()/2 + 450,
                                        line5->boundingRect().height()/2));
    line6->setPos(QPoint(0,0) - QPoint(line6->boundingRect().width()/2 + 630,
                                        line6->boundingRect().height()/2));
    line7->setPos(QPoint(0,0) - QPoint(line7->boundingRect().width()/2 - 450,
                                        line7->boundingRect().height()/2));
    line8->setPos(QPoint(0,0) - QPoint(line8->boundingRect().width()/2 - 630,
                                        line8->boundingRect().height()/2));

    addToGroup(line1);
    addToGroup(line2);
    addToGroup(line3);
    addToGroup(line4);
    addToGroup(line5);
    addToGroup(line6);
    addToGroup(line7);
    addToGroup(line8);

    xAnimation = new QPropertyAnimation(this,"x",this);

    for (int i = 0; i< 630; i++)
    {
        setPos(QPoint(0,0) - QPoint(i+10,0));
        xAnimation->setStartValue(0+i);
        xAnimation->setEndValue(-630);
        xAnimation->setEasingCurve(QEasingCurve::Linear);
        xAnimation->setDuration(3500);
    }

    connect(xAnimation,&QPropertyAnimation::finished,[=](){
        scene()->removeItem(this);
        delete this;
    });

    xAnimation->start();
}

Lines::~Lines()
{
    //qDebug() << "Deleted lines";
}

qreal Lines::x() const
{
    return m_x;
}

void Lines::setx(qreal newX)
{
    m_x = newX;
}
