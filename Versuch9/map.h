#ifndef MAP_H
#define MAP_H

#include <vector>
#include <QGraphicsScene>
#include "city.h"
#include "abstractmap.h"
#include "street.h"

class Map :public AbstractMap
{
public:
    Map();
    void addCity(City* city);
    std::vector<City*> getCities();
    bool addStreet(Street* street);
    void draw(QGraphicsScene &scene);
    virtual City* find_city(const QString city_name) const;
    virtual std::vector<Street*> get_street_list(const City* city) const;
    virtual City * get_opposite_city(const Street* street, const City* city) const;
    virtual double get_length(const Street* street) const;
private:
    std::vector<City*> cities;
    std::vector<Street*> streets;
};

#endif // MAP_H
