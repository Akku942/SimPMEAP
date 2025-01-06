#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class Enemy : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX )
public:
    explicit Enemy();

    qreal x() const;
    void setx(qreal newX);

    int lane;  // 0 = pravý pruh, 1 = ľavý pruh

private:
    QGraphicsPixmapItem * enCar1;
    int yPos;
    int speed; // Rýchlosť pohybu nepriateľa

    QPropertyAnimation *xAnimation;
    qreal m_x;

    void checkForObstacles();
    void switchLane();
};

#endif // ENEMY_H
