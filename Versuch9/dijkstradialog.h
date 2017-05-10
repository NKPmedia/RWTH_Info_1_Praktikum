#ifndef DIJKSTRADIALOG_H
#define DIJKSTRADIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <map.h>
#include <QString>

namespace Ui {
class DijkstraDialog;
}

class DijkstraDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DijkstraDialog(QWidget *parent = 0);
    ~DijkstraDialog();

    void startDijkstra(QGraphicsScene &scene, Map &map);
    void addCityName(QString name);

private:
    Ui::DijkstraDialog *ui;
};

#endif // DIJKSTRADIALOG_H
