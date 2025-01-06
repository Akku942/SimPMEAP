#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <Qtimer>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

private:
    void setUpLines();
    void setUpEnemies();

    QTimer * lineTimer;
    QTimer * enemyTimer;
};

#endif // SCENE_H
