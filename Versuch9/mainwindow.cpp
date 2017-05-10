#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QString"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include "city.h"
#include "map.h"
#include "street.h"
#include "mapionrw.h"
#include "newcityui.h"
#include "dijkstra.h"
#include <QString>
#include "dijkstradialog.h"
#include "addstreetdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),map()
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&this->scene);

    this->mapIo = new MapIoNrw();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Eingabe_clicked()
{
    QString text = this->ui->lineEdit_Eingabe->text();
    double zahl = text.toDouble();

    double zufall = qrand()*100.0/RAND_MAX;


    this->scene.addRect(zufall,zufall,20,20);

    qDebug() << QString("EingabeButton gedrück! Mit dem Text: %1").arg(zahl + 4);
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionClear_Scene_triggered()
{
    this->scene.clear();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;

    msgBox.setText("Das ist ein Straßenplaner der im Rahmen des Ino1 Praktikums entstanen ist.");
    msgBox.setDefaultButton(QMessageBox::Cancel);
    msgBox.exec();
}

void MainWindow::on_pushButton_test_draw_City_clicked()
{
    this->scene.clear();
    qDebug() << QString("Test Draw City");
    City c1("Baum",10,10);
    City c2("Holz",20,20);
    Map map;
    map.addCity(&c1);
    map.addCity(&c2);
    map.draw(this->scene);
}


void MainWindow::on_pushButton_test_draw_street_clicked()
{
    this->scene.clear();
    qDebug() << QString("Test Draw Street");
    City c1("Affe",100,100);
    City c2("Franz",200,200);
    Street street(&c1,&c2);
    street.draw(this->scene);
}

void MainWindow::on_pushButton_test_add_street_clicked()
{
    this->scene.clear();
    qDebug() << QString("Test Add Street");

    City c1("Affe",100,100);
    City c2("Franz",200,200);

    City c3("Baum",10,10);
    City c4("Holz",20,20);

    Map map;
    map.addCity(&c1);
    map.addCity(&c2);
    map.addCity(&c3);

    Street street1(&c1,&c2);
    Street street2(&c3,&c4);

    bool result1 = map.addStreet(&street1);
    bool result2 = map.addStreet(&street2);

    qDebug() << QString("Add Street 1 should be true: %1").arg(result1);
    qDebug() << QString("Add Street 2 should be false: %1").arg(result2);

    map.draw(this->scene);
}

void MainWindow::on_checkBox_clicked()
{
    if(this->ui->checkBox->isChecked())
    {
        this->ui->pushButton_test_add_street->hide();
        this->ui->pushButton_test_draw_City->hide();
        this->ui->pushButton_test_draw_street->hide();
    }
    else
    {
        this->ui->pushButton_test_add_street->show();
        this->ui->pushButton_test_draw_City->show();
        this->ui->pushButton_test_draw_street->show();
    }
}

void MainWindow::on_pushButton_add_city_clicked()
{
    newCityUI newCityUi;
    int result = newCityUi.exec();

    if(result == 1)
    {
        City* city = newCityUi.createNewCityObject();
        this->map.addCity(city);
        this->map.draw(this->scene);

    }

}

void MainWindow::on_pushButton_fill_map_clicked()
{
    this->mapIo->fillMap(this->map);
    this->map.draw(this->scene);
}

void MainWindow::on_pushButton_test_abstractMap_clicked()
{
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);

    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = map.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        map.addCity(a);
        map.addCity(b);
        bool t1 = map.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: find city";
        City* city = map.find_city("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = map.find_city("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = map.find_city("c");
        if (city != NULL)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    map.addCity(c);
    map.addStreet(s2);

    {
        qDebug() << "MapTest: get_opposite_city";
        const City *city = map.get_opposite_city(s, a);
        if (city != b)
                qDebug() << "-Error: Opposite city should be b.";

        city = map.get_opposite_city(s, c);
        if (city != 0)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: street_length";
        double l = map.get_length(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: get_street_list";
        std::vector<Street*> streetList1 = map.get_street_list(a);
        std::vector<Street*> streetList2 = map.get_street_list(b);

        if (streetList1.size() != 1)
            qDebug() << "-Error: One street should be found for city a.";
        else if (*streetList1.begin() != s)
            qDebug() << "-Error: The wrong street has been found for city a.";

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }
    qDebug() << "MapTest: End Test of the Map.";
}

void MainWindow::on_pushButton_test_dijkstra_clicked()
{
    qDebug("Test Dijkstra");
    std::vector<Street*> way = Dijkstra::search(this->map,"Bonn","Aachen");

    std::vector<Street *>::iterator it;
    for(it = way.begin(); it != way.end();++it)
    {
        Street* street = *it;
        qDebug() << QString("Ein Teil des Wegen: %1 %2").arg(street->getCity1()->getName()).arg(street->getCity2()->getName());
        street->drawRed(this->scene);
    }
}

void MainWindow::on_pushButton_show_dijkstra_dialog_clicked()
{
    DijkstraDialog dijkstraDialog;
    std::vector<City *>::iterator it;
    std::vector<City *> test = this->map.getCities();
    for(it = test.begin(); it != test.end();++it)
    {
        City* cityPointer = *it;
        dijkstraDialog.addCityName(cityPointer->getName());

    }
    int result = dijkstraDialog.exec();

    if(result == 1)
    {
        dijkstraDialog.startDijkstra(this->scene,this->map);
    }
}

void MainWindow::on_pushButton_add_street_clicked()
{
    AddStreetDialog addStreetDialog;
    std::vector<City *>::iterator it;
    std::vector<City *> test = this->map.getCities();
    for(it = test.begin(); it != test.end();++it)
    {
        City* cityPointer = *it;
        addStreetDialog.addCityName(cityPointer->getName());

    }
    int result = addStreetDialog.exec();

    if(result == 1)
    {
        Street *street = new Street(this->map.find_city(addStreetDialog.getCity1Name()), this->map.find_city(addStreetDialog.getCity2Name()));
        this->map.addStreet(street);
        this->map.draw(this->scene);
    }
}
