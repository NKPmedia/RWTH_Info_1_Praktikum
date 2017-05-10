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

void AddStreetDialog::addCityName(QString name)
{
    this->ui->comboBox_city1->addItem(name);
    this->ui->comboBox_city2->addItem(name);
}

QString AddStreetDialog::getCity1Name()
{
    return this->ui->comboBox_city1->currentText();
}

QString AddStreetDialog::getCity2Name()
{
    return this->ui->comboBox_city2->currentText();
}
