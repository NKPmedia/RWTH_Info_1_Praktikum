#ifndef ADDSTREETDIALOG_H
#define ADDSTREETDIALOG_H

#include <QDialog>

namespace Ui {
class AddStreetDialog;
}

class AddStreetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStreetDialog(QWidget *parent = 0);
    ~AddStreetDialog();

    void addCityName(QString name);
    QString getCity1Name();
    QString getCity2Name();

private:
    Ui::AddStreetDialog *ui;
};

#endif // ADDSTREETDIALOG_H
