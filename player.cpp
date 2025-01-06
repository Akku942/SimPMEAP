#include "player.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QPixmap pixmap) :
    direction(Direction::Forward),
    carDirection(0)
{
    setPixmap(pixmap);
    QTimer * carTimer = new QTimer(this);
    connect(carTimer,&QTimer::timeout,[=](){
        updatePixmap();
    });

    carTimer->start(20);
}

void Player::updatePixmap()
{
    if (direction == Direction::Forward){
        setPixmap(QPixmap(":/images/car.png"));
        direction = Direction::Forward;
        carDirection = 0;
    }
}


void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_D)
    {
        if (pos().x()+100<800)
        {
            setPos (x()+10,y());
        }
    }
    else if (event->key() == Qt::Key_A)
    {
        if (pos().x()>0)
        {
            setPos (x()-10,y());
        }
    }
    else if (event->key() == Qt::Key_W)
    {
        if (pos().y()>0)
        {
            setPos (x(),y()-10);
        }
    }
    else if (event->key() == Qt::Key_S)
    {
        if (pos().y()+100<600)
        {
            setPos (x(),y()+10);
        }
    }

}

