#include "city.h"
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QDebug>

City::City(QString name, int x, int y) : name(name), x(x), y(y)
{

}

/**
 * @brief Draws this city on a given QGraphicsScene
 * @param scene QGraphicsScene
 */
void City::draw(QGraphicsScene& scene)
{
    scene.addEllipse(this->x,this->y,3,3,QPen(Qt::red));
    QGraphicsTextItem *text = new QGraphicsTextItem;
    text->setPos(this->x,this->y-10);
    text->setPlainText(this->name);
    scene.addItem(text);
    qDebug() << QString("City %1 wurde gemahlt").arg(this->name);
}

/**
 * @brief Returns x position of the city
 * @return x position
 */
int City::getX()
{
    return this->x;
}

/**
 * @brief Returns y position of the city
 * @return y position
 */
int City::getY()
{
    return this->y;
}

/**
 * @brief Returns the name of the city
 * @return name as QString
 */
QString City::getName()
{
    return this->name;
}
