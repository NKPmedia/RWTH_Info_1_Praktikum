#include "map.h"
#include <vector>
#include "city.h"
#include <QString>
#include <QGraphicsScene>
#include <QDebug>
#include <cmath>

Map::Map()
{

}

/**
 * @brief adds a city to the map (vector)
 * @param city to be added
 */
void Map::addCity(City* city)
{
    this->cities.push_back(city);
}

/**
 * @brief adds a street to the map (vector)
 * @param street to be added
 * @return false if the street cant be added
 */
bool Map::addStreet(Street * street)
{
    //Does the map contain the sities?
    if(this->find_city(street->getCity1()->getName()) != NULL && this->find_city(street->getCity2()->getName()) != NULL)
    {
        //Add street
        this->streets.push_back(street);
        return true;
    }
    return false;
}

/**
 * @brief finds a city by a name
 * @param city_name
 * @return the city
 */
City* Map::find_city(const QString city_name) const
{
    //Draw all cities
    std::vector<City*>::const_iterator it;
    for(it = this->cities.begin();it != this->cities.end();it++)
    {
        City* cityPointer = *it;
        if(cityPointer->getName() == city_name) return cityPointer;
    }
    return NULL;
}

/**
 * @brief draws the whole map at a QGraphicsscene
 * @param scene
 */
void Map::draw(QGraphicsScene &scene)
{
    qDebug() << QString("Male alle Städte");

    //Draw all cities
    std::vector<City*>::iterator it;
    for(it = this->cities.begin();it != this->cities.end();it++)
    {
        City* cityPointer = *it;
        cityPointer->draw(scene);
    }

    qDebug() << QString("Male alle Straßen");

    //Draw all streets
    std::vector<Street*>::iterator streetIt;
    for(streetIt = this->streets.begin();streetIt != this->streets.end();streetIt++)
    {
        Street* streetPointer = *streetIt;
        streetPointer->draw(scene);
    }
}

/**
 * @brief Search for streets in this map.
 * @param city where you want the street_list from
 * @return a list of all streets in this map connected to provided city.
 */
std::vector<Street*> Map::get_street_list(const City* city) const
{
    std::vector<Street*> cityStreets;

    std::vector<Street*>::const_iterator streetIt;
    for(streetIt = this->streets.begin();streetIt != this->streets.end();streetIt++)
    {
        Street* streetPointer = *streetIt;
        if(streetPointer->getCity1() == city || streetPointer->getCity2() == city)
            cityStreets.push_back(streetPointer);
    }
    return cityStreets;
}

/**
 * @brief Look for opposite city.
 * @param street
 * @param city
 * @return opposite city of the street. If city has no connection to street returns NULL.
 */
City * Map::get_opposite_city(const Street* street, const City* city) const
{
    if(street->getCity1() == city)
        return street->getCity2();
    else if(street->getCity2() == city)
        return street->getCity1();
    else return NULL;
}

/**
 * @brief Calculate the street length.
 * @param street
 * @return length of the street
 */
double Map::get_length(const Street* street) const
{
    double xDiff = abs(street->getCity1()->getX() - street->getCity2()->getX());
    double yDiff = abs(street->getCity1()->getY() - street->getCity2()->getY());

    return sqrt(pow(xDiff,2)+pow(yDiff,2));
}

/**
 * @brief returns all cities
 * @return all cities
 */
std::vector<City*> Map::getCities()
{
    return this->cities;
}
