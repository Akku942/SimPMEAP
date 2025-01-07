#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>

#include "playercar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onStartClicked();
    void onPauseClicked();
    void onQuitClicked();

    void updateHighway();  // Aktualizácia scény pre nekonečnú cestu

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene; // Scéna pre vykreslenie diaľnice
    QTimer *timer;         // Časovač pre posun deliacej čiary
    int lineOffset;        // Posun deliacej čiary pre animáciu
    PlayerCar *playerCar;  // Hráčovo vozidlo
};

#endif // MAINWINDOW_H
