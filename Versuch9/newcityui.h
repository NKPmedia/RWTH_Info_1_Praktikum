#ifndef NEWCITYUI_H
#define NEWCITYUI_H

#include <QDialog>
#include "city.h"

namespace Ui {
class newCityUI;
}

class newCityUI : public QDialog
{
    Q_OBJECT

public:
    explicit newCityUI(QWidget *parent = 0);
    City* createNewCityObject();
    ~newCityUI();

private:
    Ui::newCityUI *ui;
};

#endif // NEWCITYUI_H
