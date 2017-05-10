#include "newcityui.h"
#include "ui_newcityui.h"
#include <QString>
#include <QDebug>

newCityUI::newCityUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newCityUI)
{
    ui->setupUi(this);
}

newCityUI::~newCityUI()
{
    delete ui;
}

/**
 * @brief Returns a new city with the values of the newCityDialog
 * @return new city
 */
City* newCityUI::createNewCityObject()
{

    qDebug() << QString("City wird erstellt:");

    QString name = this->ui->lineEdit_city_name->text();
    qDebug() << QString("Name %1").arg(name);

    int x = this->ui->lineEdit_city_x->text().toInt();
    qDebug() << QString("X %1").arg(x);

    int y = this->ui->lineEdit_city_y->text().toInt();
    qDebug() << QString("Y %1").arg(y);

    return new City(name,x,y);
}
