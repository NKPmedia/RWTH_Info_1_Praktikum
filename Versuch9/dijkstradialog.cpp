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

void DijkstraDialog::startDijkstra(QGraphicsScene &scene, Map &map)
{
    std::vector<Street*> way = Dijkstra::search(map,this->ui->comboBox_city1->currentText(),this->ui->comboBox_city2->currentText());
    Dijkstra::drawWay(way,scene);
}

void DijkstraDialog::addCityName(QString name)
{
    this->ui->comboBox_city1->addItem(name);
    this->ui->comboBox_city2->addItem(name);
}
