#include "scene.h"
#include "lines.h"
#include "enemy.h"
#include <QRandomGenerator>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    setUpLines();
    setUpEnemies();
}

void Scene::setUpLines()
{
    lineTimer = new QTimer(this);
    connect(lineTimer,&QTimer::timeout,[=](){
        Lines * lines = new Lines();

        addItem(lines);
    });

    lineTimer->start(2000);

}

void Scene::setUpEnemies()
{
    enemyTimer = new QTimer(this);
    connect(enemyTimer, &QTimer::timeout, [=]() {
        Enemy *enemy = new Enemy();

        // Pridanie nepriateľa na scénu
        addItem(enemy);
    });

    enemyTimer->start(2000); // Spawn nepriateľa každé 2 sekundy
}


