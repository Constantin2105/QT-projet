#include "acceuil.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //Database bdd("C:/Users/Utilisateur/Documents/helpme/newDB.db");
    acceuil acceuil;
    acceuil.setFixedSize(800,500);
    acceuil.setStyleSheet("background-color: sky blue");
    acceuil.show();
    return a.exec();
}
