#ifndef GESTION_H
#define GESTION_H

#include <QWidget>
#include <QtSql>
#include <QString>



class gestion:public QWidget//,public Database
{
public:
    gestion();
    int getIdprofessionel(QString firstName, QString lastName);
    int  getIdprofil(QString name_profile);
    int  getIdskill(QString name_skill);
    int ajouterCompetence(QString competence) ;
    void displayProfessionalSkills(QString firstName,QString lastName);
    void displayProfilSkills(QString profile_name);
    int numberskillprofile(QString name_profile);
    int numberskillprofessinel(QString firstName,QString lastName);
    void actualiserCompetenceProfile(QString profile_name);
    void actualiserCompetenceProfessionel(QString firstName,QString lastName);


public slots:
    void professionnel();
    void competence();
    void profil();
    void Database();
    void addprofessional(QString const First_name,QString const Last_name);
    void addprofile(QString const& name_profile);
    void addskills(QString const& name);
    void deleteskills(QString name);
    void deleteProfessional(QString first_name,QString last_name);
    void deleteProfil(QString name_profile);
    bool addprofessionalskills(QString  first_name, QString  last_name,QString skill_name);
    bool addprofileskills(QString profile_name,QString skill_name);
    void reinitiliserdatabase();


public:
     QSqlDatabase bdd;

};

#endif // GESTION_H

