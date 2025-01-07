#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QBrush>
#include <QPen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Naplnenie zoznamu farieb
    ui->comboBox->addItems({"Červená", "Modrá", "Zelená", "Žltá", "Biela"});
    ui->startButton->setStyleSheet("background-color: green; color: white; font-size: 16px;");
    ui->pauseButton->setStyleSheet("background-color: orange; color: white; font-size: 16px;");
    ui->quitButton->setStyleSheet("background-color: red; color: white; font-size: 16px;");


    // Prepojenie tlačidiel s funkciami
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::onStartClicked);
    connect(ui->pauseButton, &QPushButton::clicked, this, &MainWindow::onPauseClicked);
    connect(ui->quitButton, &QPushButton::clicked, this, &MainWindow::onQuitClicked);

    // Vytvorenie grafickej scény a pridanie do QGraphicsView
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    // Nastavenie veľkosti scény (šírka diaľnice)
    const int sceneWidth = 400;
    const int sceneHeight = 600;
    scene->setSceneRect(0, 0, sceneWidth, sceneHeight);

    // Pridanie pozadia cesty
    QGraphicsRectItem *background = new QGraphicsRectItem(0, 0, sceneWidth, sceneHeight);
    background->setBrush(QBrush(Qt::gray));
    scene->addItem(background);

    // Pridanie jazdných pruhov
    QPen whitePen(Qt::white, 2);
    scene->addLine(sceneWidth / 2 - 50, 0, sceneWidth / 2 - 50, sceneHeight, whitePen); // Ľavá deliaca čiara
    scene->addLine(sceneWidth / 2 + 50, 0, sceneWidth / 2 + 50, sceneHeight, whitePen); // Pravá deliaca čiara

    // Pridanie deliacej prerušovanej čiary
    QPen dashedPen(Qt::white, 2, Qt::DashLine);
    for (int i = 0; i < sceneHeight; i += 40) {
        scene->addLine(sceneWidth / 2, i, sceneWidth / 2, i + 20, dashedPen);
    }

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onStartClicked() {
    QString playerName = ui->lineEdit->text();
    QString carColor = ui->comboBox->currentText();

    if (playerName.isEmpty()) {
        QMessageBox::warning(this, "Chyba", "Prosím, zadajte svoje meno!");
        return;
    }

    // Vytvorenie hráčovho auta, ak ešte neexistuje
    if (!playerCar) {
        QColor color;

        if (carColor == "Červená") color = Qt::red;
        else if (carColor == "Modrá") color = Qt::blue;
        else if (carColor == "Zelená") color = Qt::green;
        else if (carColor == "Žltá") color = Qt::yellow;
        else if (carColor == "Biela") color = Qt::white;
        else color = Qt::black; // Záložná farba

        playerCar = new PlayerCar(); // Veľkosť auta
        playerCar->setBrush(QBrush(color));

        // Nastavenie inicializačnej polohy (jazdný pruh a vertikálna pozícia)
        int x = rand()%2;
        int xPos = 250;
        if (x == 0){
            xPos = 250;
        }else{xPos = 150;}
        playerCar->setX(xPos);  // 150 = ľavý pruh, 250 = pravý
        playerCar->setY(500);                // Spodná časť scény
        scene->addItem(playerCar);
    }

    QMessageBox::information(this, "Štart", QString("Hra začína pre hráča: %1 s vozidlom farby %2")
                                                .arg(playerName)
                                                .arg(carColor));


    // Inicializácia časovača pre animáciu
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateHighway);
    timer->start(50); // 20 FPS
}

void MainWindow::onPauseClicked() {
    QMessageBox::information(this, "Pauza", "Hra bola pozastavená.");
    // Tu bude kód na pozastavenie hry
}

void MainWindow::onQuitClicked() {
    close();
}

// Funkcia na posun deliacej čiary (nekonečná cesta)
void MainWindow::updateHighway() {
    lineOffset = (lineOffset + 5) % 40; // Posun o 5 pixelov, cyklicky každých 40
    scene->clear(); // Vymazanie scény a jej opätovné vykreslenie

    // Vykreslenie statickej časti diaľnice (ako v inicializácii)
    const int sceneWidth = 400;
    const int sceneHeight = 600;

    QGraphicsRectItem *background = new QGraphicsRectItem(0, 0, sceneWidth, sceneHeight);
    background->setBrush(QBrush(Qt::gray));
    scene->addItem(background);

    QPen whitePen(Qt::white, 2);
    scene->addLine(sceneWidth / 2 - 50, 0, sceneWidth / 2 - 50, sceneHeight, whitePen);
    scene->addLine(sceneWidth / 2 + 50, 0, sceneWidth / 2 + 50, sceneHeight, whitePen);

    // Posunutá prerušovaná deliaca čiara
    QPen dashedPen(Qt::white, 2, Qt::DashLine);
    for (int i = -lineOffset; i < sceneHeight; i += 40) {
        scene->addLine(sceneWidth / 2, i, sceneWidth / 2, i + 20, dashedPen);
    }

    // Aktualizácia pozície hráčovho auta
    if (playerCar) {
        playerCar->updatePosition();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (!playerCar) return;

    switch (event->key()) {
    case Qt::Key_Up:
        playerCar->setSpeed(playerCar->getSpeed() + 1);  // Zrýchlenie
        break;
    case Qt::Key_Down:
        playerCar->setSpeed(std::max(0.0, playerCar->getSpeed() - 1));  // Spomalenie
        break;
    case Qt::Key_Left:
        playerCar->moveLeft();  // Presun do ľavého pruhu
        break;
    case Qt::Key_Right:
        playerCar->moveRight();  // Presun do pravého pruhu
        break;
    default:
        QMainWindow::keyPressEvent(event);
        break;
    }
}
