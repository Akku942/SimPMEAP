#include "enemy.h"
#include <QGraphicsScene>
#include <QRandomGenerator>

Enemy::Enemy() : enCar1(new QGraphicsPixmapItem(QPixmap(":/images/carEn.png")))
{
    enCar1->setPos(QPoint(0,0) - QPoint(enCar1->boundingRect().width()/2 - 500,
                                        enCar1->boundingRect().height()/2 + 100));

    addToGroup(enCar1);

    xAnimation = new QPropertyAnimation(this,"x",this);

    for (int i = 0; i< 630; i++)
    {
        setPos(QPoint(0,0) - QPoint(i+10,0));
        xAnimation->setStartValue(0+i);
        xAnimation->setEndValue(-1000);
        xAnimation->setEasingCurve(QEasingCurve::Linear);
        xAnimation->setDuration(3000);
    }

    connect(xAnimation,&QPropertyAnimation::finished,[=](){
        scene()->removeItem(this);
        delete this;
    });

    xAnimation->start();
}

qreal Enemy::x() const
{
    return m_x;
}

void Enemy::setx(qreal newX)
{
    m_x = newX;
}
