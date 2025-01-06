#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Player(QPixmap pixmap);

    void keyPressEvent(QKeyEvent * event);

signals:

private:
    enum Direction{
        Forward
    };
    void updatePixmap();

    Direction direction;
    bool carDirection;
};

#endif // PLAYER_H
