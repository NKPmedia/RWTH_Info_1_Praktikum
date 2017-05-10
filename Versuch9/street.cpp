#include "street.h"
#include <QString>
#include <QGraphicsScene>
#include <QDebug>

Street::Street(City* city1, City* city2) : city1(city1), city2(city2)
{

}

/**
 * @brief draws the street between two cities
 * @param scene the QGraphicsscenen that should be used to draw on
 */
void Street::draw(QGraphicsScene& scene)
{
    scene.addLine(this->city1->getX(),this->city1->getY(),this->city2->getX(),this->city2->getY());
    qDebug() << QString("Straße zwischen %1 und %2 wurde gemahlt").arg(this->city1->getName()).arg(this->city2->getName());
}

/**
 * @brief draws the street in red between two cities
 * @param scene the QGraphicsscenen that should be used to draw on
 */
void Street::drawRed(QGraphicsScene& scene)
{
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::red);
    scene.addLine(this->city1->getX(),this->city1->getY(),this->city2->getX(),this->city2->getY(),pen);
    qDebug() << QString("Straße zwischen %1 und %2 wurde gemahlt").arg(this->city1->getName()).arg(this->city2->getName());
}

/**
 * @brief returns city 1
 * @return city 1
 */
City* Street::getCity1() const
{
    return this->city1;
}

/**
 * @brief returns city 2
 * @return city 2
 */
City* Street::getCity2() const
{
    return this->city2;
}
