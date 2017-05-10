#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "map.h"
#include "mapio.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Eingabe_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_test_draw_City_clicked();

    void on_pushButton_test_draw_street_clicked();

    void on_pushButton_test_add_street_clicked();

    void on_checkBox_clicked();

    void on_pushButton_add_city_clicked();

    void on_pushButton_fill_map_clicked();

    void on_pushButton_test_abstractMap_clicked();

    void on_pushButton_test_dijkstra_clicked();

    void on_pushButton_show_dijkstra_dialog_clicked();

    void on_pushButton_add_street_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    MapIo* mapIo;
};

#endif // MAINWINDOW_H
