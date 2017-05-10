#include "street.h"
#include <QString>
#include <QGraphicsScene>
#include <QDebug>

Street::Street(City* city1, City* city2) : city1(city1), city2(city2)
{

}

void Street::draw(QGraphicsScene& scene)
{
    scene.addLine(this->city1->getX(),this->city1->getY(),this->city2->getX(),this->city2->getY());
    qDebug() << QString("Straße zwischen %1 und %2 wurde gemahlt").arg(this->city1->getName()).arg(this->city2->getName());
}

void Street::drawRed(QGraphicsScene& scene)
{
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::red);
    scene.addLine(this->city1->getX(),this->city1->getY(),this->city2->getX(),this->city2->getY(),pen);
    qDebug() << QString("Straße zwischen %1 und %2 wurde gemahlt").arg(this->city1->getName()).arg(this->city2->getName());
}

City* Street::getCity1() const
{
    return this->city1;
}
City* Street::getCity2() const
{
    return this->city2;
}
