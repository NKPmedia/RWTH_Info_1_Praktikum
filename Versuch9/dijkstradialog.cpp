#include "dijkstradialog.h"
#include "ui_dijkstradialog.h"
#include "dijkstra.h"
#include <vector>
#include <QString>

DijkstraDialog::DijkstraDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DijkstraDialog)
{
    ui->setupUi(this);
}

DijkstraDialog::~DijkstraDialog()
{
    delete ui;
}

/**
 * @brief Starts the dijkstra algo and draws the way
 * @param scene this scnene will be used to draw the way on QGraphicsscene
 * @param map the map with the streets for the dijkstra algo
 */
void DijkstraDialog::startDijkstra(QGraphicsScene &scene, Map &map)
{
    std::vector<Street*> way = Dijkstra::search(map,this->ui->comboBox_city1->currentText(),this->ui->comboBox_city2->currentText());
    Dijkstra::drawWay(way,scene);
}

/**
 * @brief Adds a name to city comboboxes
 * @param name
 */
void DijkstraDialog::addCityName(QString name)
{
    this->ui->comboBox_city1->addItem(name);
    this->ui->comboBox_city2->addItem(name);
}
