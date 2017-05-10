#include "city.h"
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QDebug>

City::City(QString name, int x, int y) : name(name), x(x), y(y)
{

}
void City::draw(QGraphicsScene& scene)
{
    scene.addEllipse(this->x,this->y,3,3,QPen(Qt::red));
    QGraphicsTextItem *text = new QGraphicsTextItem;
    text->setPos(this->x,this->y-10);
    text->setPlainText(this->name);
    scene.addItem(text);
    qDebug() << QString("City %1 wurde gemahlt").arg(this->name);
}
int City::getX()
{
    return this->x;
}

int City::getY()
{
    return this->y;
}
QString City::getName()
{
    return this->name;
}
