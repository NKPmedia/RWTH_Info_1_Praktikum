#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "abstractmap.h"
#include <QGraphicsScene>
#include <vector>

class Dijkstra
{
public:

    /**
     * @brief Dijkstra Algorithm to find the shortest path between two towns.
     * @param start Name of the start town.
     * @param target Name of the target town.
     * @return Pointer to a list of streets between the towns. Empty list if no connection found.
     */
    static std::vector<Street*> search(const AbstractMap &map, QString start, QString target);

    static void drawWay(std::vector<Street*>& way, QGraphicsScene &scene);

private:
    Dijkstra();
};

#endif // DIJKSTRA_H
