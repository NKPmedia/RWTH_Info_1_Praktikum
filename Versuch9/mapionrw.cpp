#include "mapionrw.h"
#include <QDebug>


MapIoNrw::MapIoNrw()
{

}

MapIoNrw::~MapIoNrw()
{
    qDebug("Destructor MapIoNrw");
}

/**
 * @brief fills a given map with preconfigured cities and streets
 * @param map
 */
void MapIoNrw::fillMap(AbstractMap &map)
{
    City *aachen = new City ("Aachen", -100, 100);
    City *bonn = new City ("Bonn", 0,200);
    City *koeln = new City ("Köln", 0,0);
    City *duesseldorf = new City ("Düsseldorf", 50,-100);

    Street *aachen_koeln = new Street(aachen, koeln);
    Street *bonn_koeln = new Street(bonn, koeln);
    Street *ddorf_koeln = new Street(duesseldorf, koeln);

    map.addCity(aachen);
    map.addCity(bonn);
    map.addCity(koeln);
    map.addCity(duesseldorf);

    map.addStreet(aachen_koeln);
    map.addStreet(bonn_koeln);
    map.addStreet(ddorf_koeln);
}
