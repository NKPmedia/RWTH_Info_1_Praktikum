#include "addstreetdialog.h"
#include "ui_addstreetdialog.h"

AddStreetDialog::AddStreetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStreetDialog)
{
    ui->setupUi(this);
}

AddStreetDialog::~AddStreetDialog()
{
    delete ui;
}

/**
 * @brief Adds a name to the two city comboboxes
 * @param name the name to be added
 */
void AddStreetDialog::addCityName(QString name)
{
    this->ui->comboBox_city1->addItem(name);
    this->ui->comboBox_city2->addItem(name);
}

/**
 * @brief Returns the name of city 1
 * @return name of city 1
 */
QString AddStreetDialog::getCity1Name()
{
    return this->ui->comboBox_city1->currentText();
}

/**
 * @brief Returns the name of city 2
 * @return name of city 2
 */
QString AddStreetDialog::getCity2Name()
{
    return this->ui->comboBox_city2->currentText();
}
