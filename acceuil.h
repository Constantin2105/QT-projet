#ifndef ACCEUIL_H
#define ACCEUIL_H


#include <QMainWindow>
#include <QSqlDatabase>
#include <QtWidgets>
#include <QLayout>
#include <QtWidgets>
#include "gestion.h"


class acceuil: public gestion
{
    Q_OBJECT
public:
    acceuil();


private slots:
    void ouvrirgenerer();
    void ouvrirapropos();
    void principal();
    //void gocompetence();

private:
    QPushButton *start;
    QPushButton *apropos;


};

#endif // ACCEUIL_H
