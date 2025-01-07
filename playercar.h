#ifndef PLAYERCAR_H
#define PLAYERCAR_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

class PlayerCar : public QGraphicsRectItem {
    Q_OBJECT
public:
    explicit PlayerCar(QObject *parent = nullptr);

    void setSpeed(qreal newSpeed);  // Nastavenie rýchlosti
    qreal getSpeed() const;         // Získanie aktuálnej rýchlosti
    void moveLeft();                // Presun do ľavého pruhu
    void moveRight();               // Presun do pravého pruhu
    void updatePosition();          // Aktualizácia pozície auta

private:
    int currentLane;   // Aktuálny jazdný pruh (0 = ľavý, 1 = pravý)
    qreal speed;       // Rýchlosť vozidla
    PlayerCar *playerCar;
};

#endif // PLAYERCAR_H
