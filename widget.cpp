#include "widget.h"
#include "./ui_widget.h"
#include <QGraphicsPixmapItem>
#include "player.h"
#include "enemy.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new Scene(this);
    scene->setSceneRect(-250,-300,500,600);

    QGraphicsPixmapItem * road = new QGraphicsPixmapItem(QPixmap(":/images/road.png"));
    scene->addItem(road);
    road->setPos(QPointF(0,0) - QPointF(road->boundingRect().width()/2,
                                        road->boundingRect().height()/2));
    scene->addLine(-400,0,400,0,QPen(Qt::blue));
    scene->addLine(0,-400,0,400,QPen(Qt::blue));

    Player * player = new Player(QPixmap(":/images/car.png"));
    player->setPos(-600, 50);
    scene->addItem(player);

    Enemy * enemy = new Enemy();
    scene->addItem(enemy);

    ui->graphicsView->setScene(scene);
}

Widget::~Widget()
{
    delete ui;
}
