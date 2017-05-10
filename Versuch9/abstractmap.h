#ifndef ABSTRACTMAP
#define ABSTRACTMAP

//  Ändern Sie an dieser Datei nichts!
//  Die Schnittstellen (Signaturen) der Funktionen
//  werden genau so gebraucht.

#include "city.h"
#include "street.h"

class AbstractMap {
public:

    /// Virtual Destructor
    virtual ~AbstractMap();

    /**
     * @brief Adds the provided city to this map.
     * @param Pointer to city to be added
     * @return true if the has been added
     */
    virtual void addCity(City *) = 0;

    /**
     * @brief Adds the provided street to this map. If the cities linked by the street
     *  have not been added to this map before, the street is not added.
     * @param Pointer to the street to be added
     * @return true if the street has beed added.
     */
    virtual bool addStreet(Street *) = 0;

    /**
     * @brief Search for a city in this map by given name.
     * @param name
     * @return the city pointer, if city not found NULL
     */
    virtual City* find_city(const QString city_name) const = 0;

    /**
     * @brief Search for streets in this map.
     * @param city where you want the street_list from
     * @return a list of all streets in this map connected to provided city.
     */
    virtual std::vector<Street*> get_street_list(const City* city) const = 0;

    /**
     * @brief Look for opposite city.
     * @param street
     * @param city
     * @return opposite city of the street. If city has no connection to street returns NULL.
     */
    virtual City * get_opposite_city(const Street* street, const City* city) const = 0;

    /**
     * @brief Calculate the street length.
     * @param street
     * @return length of the street
     */
    virtual double get_length(const Street* street) const = 0;
};

#endif // ABSTRACTMAP

