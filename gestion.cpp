#include "gestion.h"
#include <qsqlquery.h>
#include <qsqlrecord.h>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QtWidgets>
#include <QLayout>
#include <QMessageBox>
//#include "database.h"
#include <QString>


gestion::gestion()
{


}

void gestion::competence()
{
        QGroupBox *groupboxPrincipal = new QGroupBox("Gestion des compétences");
        QVBoxLayout *mainLayout = new QVBoxLayout;

        // Créer une nouvelle compétence
        QGroupBox *groupbox1 = new QGroupBox("Créer une nouvelle compétence");
        QLineEdit *nom= new QLineEdit();
        QPushButton *ValiderNewSkill = new QPushButton("Valider");
        QVBoxLayout *layoutGroupbox1 = new QVBoxLayout;
        layoutGroupbox1->addWidget(nom);
        layoutGroupbox1->addWidget(ValiderNewSkill);
        groupbox1->setLayout(layoutGroupbox1);
        QObject::connect(ValiderNewSkill, &QPushButton::clicked, [=]() {
                QString Nom = nom->text();
                addskills(Nom);

            });

        // Supprimer une compétence
        QGroupBox *groupbox3 = new QGroupBox("Supprimer une compétence");
        QSqlQuery querysuprr;
        querysuprr.exec("SELECT skill FROM skills");
        QComboBox *comboSupprimerCompetence = new QComboBox();
        while (querysuprr.next()) {
          comboSupprimerCompetence->addItem(querysuprr.value(0).toString());
        }
        QPushButton *Supprimer = new QPushButton("Supprimer");
        QFormLayout *layoutGroupbox3 = new QFormLayout;
        layoutGroupbox3->addRow("Compétence à supprimer:", comboSupprimerCompetence);
        layoutGroupbox3->addRow(Supprimer);
        groupbox3->setLayout(layoutGroupbox3);
        QObject::connect(Supprimer, &QPushButton::clicked, [=]() {
                QString Nom =comboSupprimerCompetence->currentText();
                deleteskills(Nom);

            });


        //ajouter ou retirer une competence a un professionnel

        QGroupBox *groupbox4 = new QGroupBox("Ajouter/Retirer une competence à un professionnel");
        QSqlQuery querry;
        querry.exec("SELECT First_name FROM professionals");
        QComboBox *combonomProfessionnel = new QComboBox();
        while (querry.next()) {
            combonomProfessionnel->addItem(querry.value(0).toString());
        }

        combonomProfessionnel->setCurrentText("Faites votre choix");

        QComboBox *combonom = new QComboBox();
          QSqlQuery querycpt;
          querycpt.exec("SELECT Last_name FROM professionals");
          while (querycpt.next()) {
            combonom->addItem(querycpt.value(0).toString());
          }

          combonom->setCurrentText("Faites votre choix");



          QLineEdit *competence = new QLineEdit;


        QPushButton *Ajouter1 = new QPushButton("Ajouter");
        QPushButton *boutonSupprimer2 = new QPushButton("Supprimer");
        QFormLayout *layoutGroupbox4 = new QFormLayout;
        layoutGroupbox4->addRow("Nom Professionnel:", combonomProfessionnel );
        layoutGroupbox4->addRow("Prénoms Professionnel:", combonom );
        layoutGroupbox4->addRow("competence:", competence);


        layoutGroupbox4->addRow(Ajouter1);
        layoutGroupbox4->addRow(boutonSupprimer2);
        groupbox4->setLayout(layoutGroupbox4);


        QObject::connect(Ajouter1, &QPushButton::clicked, [=]() {
            QString firstname = combonomProfessionnel->currentText();
            QString lastname = combonom->currentText();
            QString skill = competence->text();
            addprofessionalskills(firstname,lastname,skill); });


        //ajouter ou retirer une competence a un profil

        QGroupBox *groupbox5 = new QGroupBox("Ajouter/Retirer une competence à un profil");
        QComboBox *combonomProfil = new QComboBox();
        QSqlQuery querypfl;
        querypfl.exec("SELECT name_profile FROM profiles");
        while (querypfl.next()) {
          combonomProfil->addItem(querypfl.value(0).toString());
        }

        combonomProfil->setCurrentText("Faites votre choix");

        QLineEdit *competenceProfil = new QLineEdit;



        QPushButton *Ajouter2 = new QPushButton("Ajouter");
        QPushButton *boutonSupprimer3 = new QPushButton("Supprimer");
        QFormLayout *layoutGroupbox5 = new QFormLayout;
        layoutGroupbox5->addRow("Nom Profil:", combonomProfil );
        layoutGroupbox5->addRow("Nom Compétence:", competenceProfil);
        layoutGroupbox5->addRow(Ajouter2);
        layoutGroupbox5->addRow(boutonSupprimer3);
        groupbox5->setLayout(layoutGroupbox5);

        QVBoxLayout *groupBoxLayout = new QVBoxLayout;
        groupBoxLayout->addWidget(groupbox1);
        groupBoxLayout->addWidget(groupbox3);
        mainLayout->addLayout(groupBoxLayout);
        groupBoxLayout->addWidget(groupbox4);
        groupBoxLayout->addWidget(groupbox5);

        groupboxPrincipal->setLayout(mainLayout);
        groupboxPrincipal->show();


        QObject::connect(Ajouter2, &QPushButton::clicked, [=]() {
            QString profilename = combonomProfil->currentText();
            QString skill =competenceProfil->text();
            addprofileskills(profilename,skill); });


       //connect(boutonSupprimer,&QPushButton::clicked, this, &Database::ouvrir_supprcompetence);

}

void gestion::professionnel()
{
    QGroupBox *groupboxPrincipal = new QGroupBox("Gestion des Professionel");
    QVBoxLayout *mainLayout = new QVBoxLayout;


    // Créer une nouveau professionel
    QGroupBox *groupbox1 = new QGroupBox("Créer un nouveau professionnel");
    QPushButton *Valider = new QPushButton("Valider");
    QLineEdit *nom = new QLineEdit;
    QLineEdit *prenom = new QLineEdit;

    QFormLayout *layout = new QFormLayout;
    layout->addRow("nom", nom);
    layout->addRow("prénom", prenom);
    layout->addRow(Valider);
    groupbox1->setLayout(layout);

   //int Nombre =nombre->text().toInt();



   QObject::connect(Valider, &QPushButton::clicked, [=]() {
       QString Nom = nom->text();
       QString Prenom = prenom->text();
       addprofessional(Nom,Prenom); });


       QGroupBox *groupbox = new QGroupBox("Supprimer un professionnel");
       QPushButton *Valider1 = new QPushButton("Supprimer");
       QLineEdit *nomProfessionel = new QLineEdit;
       QLineEdit *prenomProfessionel = new QLineEdit;
       QFormLayout *layout1 = new QFormLayout;
       layout1->addRow("nom", nomProfessionel);
       layout1->addRow("prénom", prenomProfessionel);
       layout1->addRow(Valider1);
       groupbox->setLayout(layout1);

       QObject::connect(Valider1, &QPushButton::clicked, [=]() {
           QString Nom = nomProfessionel->text();
           QString Prenom = prenomProfessionel->text();
           deleteProfessional(Nom,Prenom); });


       QVBoxLayout *groupBoxLayout = new QVBoxLayout;
       groupBoxLayout->addWidget(groupbox1);
       groupBoxLayout->addWidget(groupbox);

       mainLayout->addLayout(groupBoxLayout);
       groupboxPrincipal->setLayout(mainLayout);
       groupboxPrincipal->show();





    groupboxPrincipal->show();

}

void gestion::profil()
{

    QGroupBox *groupboxPrincipal = new QGroupBox("Gestion des Profils");
    QVBoxLayout *mainLayout = new QVBoxLayout;


    QGroupBox *groupbox1 = new QGroupBox("Créer un nouveau profil");
    QPushButton *Valider = new QPushButton("Valider");
    QLineEdit *nom = new QLineEdit;
    QFormLayout *layout = new QFormLayout;
    layout->addRow("nom :", nom);
    layout->addRow(Valider);
    groupbox1->setLayout(layout);
    groupbox1->show();
    QObject::connect(Valider, &QPushButton::clicked, [=]() {
            QString Nom = nom->text();
            addprofile(Nom);

        });

    QGroupBox *groupbox = new QGroupBox("Supprimer un profil");
    QPushButton *Valider1 = new QPushButton("Supprimer");
    QLineEdit *nomProfil = new QLineEdit;
    QFormLayout *layout1 = new QFormLayout;
    layout1->addRow("nom :", nomProfil);
    layout1->addRow(Valider1);
    groupbox->setLayout(layout1);

    QObject::connect(Valider1, &QPushButton::clicked, [=]() {
        QString Nom = nomProfil->text();
        deleteProfil(Nom); });


    QVBoxLayout *groupBoxLayout = new QVBoxLayout;
    groupBoxLayout->addWidget(groupbox1);
    groupBoxLayout->addWidget(groupbox);

    mainLayout->addLayout(groupBoxLayout);
    groupboxPrincipal->setLayout(mainLayout);
    groupboxPrincipal->show();

       //connect(boutonSupprimer,&QPushButton::clicked, this, &Database::ouvrir_supprcompetence);

}

//////////////////
/*void gestion::Database()
{
    bdd=QSqlDatabase::addDatabase("QSQLITE");
    bdd.setDatabaseName("C:/Users/Utilisateur/Desktop/SQL-1/SQL/ProjetQt.db");
    if(bdd.open())qDebug()<<"Ouvert";
    else qDebug()<<"erreur";
    //getIdByName("tin","tin");
    //getIdprofil("alide");
    //displayProfessionalSkills("zounmevo","constantin");
    //displayProfilSkills("operateur");
     //numberskillprofile("operateur");
     //numberskillprofessinel("zounmevo","constantin");
    //actualiserCompetenceProfessionel("ZOUNMEVO","constantin")
    //getIdskill("RAGE");
}*/

/* méthode pour charger la base de données*/
void gestion::Database()
{
    bdd=QSqlDatabase::addDatabase("QSQLITE");
    bdd.setDatabaseName("C:/Users/Utilisateur/Desktop/SQL-1/SQL/ProjetQt.db");
    if(bdd.open()) {
        QMessageBox::information(nullptr, "Connexion réussie", "La base de données a été ouverte avec succès.");
    } else {
        QMessageBox::critical(nullptr, "Erreur de connexion", "Impossible de se connecter à la base de données.");
    }
}



void gestion::addprofessional(QString const First_name, QString const Last_name)
{
    QSqlQuery request;
    request.prepare("INSERT INTO professionals(First_name,Last_name) VALUES(:First_name,:Last_name)");
    request.bindValue(":First_name", First_name);
    request.bindValue(":Last_name", Last_name);
    bool success = request.exec();

    if(success) {
        QMessageBox::information(nullptr, "Professionnel ajouté", "Le professionnel a été ajouté avec succès.");
    } else {
        QMessageBox::critical(nullptr, "Erreur d'ajout", "Impossible d'ajouter le professionnel.");
    }
}



void gestion::addprofile(QString const& name_profile)
{
    QSqlQuery request;
    request.prepare("INSERT INTO profiles(name_profile) VALUES(:name_profile)");
    request.bindValue(":name_profile",name_profile);
    bool success = request.exec();
    if(success) {
        QMessageBox::information(nullptr, "Profil ajouté", "Le profil a été ajouté avec succès.");
    } else {
        QMessageBox::critical(nullptr, "Erreur d'ajout", "Impossible d'ajouter le profil.");
    }
}

void gestion::addskills(QString const& name)
{
    QSqlQuery request;
    request.prepare("INSERT INTO skills(skill) VALUES(:skill)");
    request.bindValue(":skill",name);
    bool success = request.exec();
    if(success) {
        QMessageBox::information(nullptr, "Competence ajoutée", "La competence a été ajouté avec succès.");
    } else {
        QMessageBox::critical(nullptr, "Erreur d'ajout", "Impossible d'ajouter la competence.");
    }
}

void gestion::deleteskills(QString name)
{
    QSqlQuery request;
    request.prepare("DELETE FROM skills WHERE ID_skill=:id");
    request.bindValue(":id",(getIdskill(name)));
    bool success = request.exec();
    if(success) {
        QMessageBox::information(nullptr, "Competence supprimée", "La competence a été supprimée avec succès.");
    } else {
        QMessageBox::critical(nullptr, "Erreur de suppression", "Impossible de supprimer la competence.");
    }
}
//slot
void gestion::deleteProfessional(QString First_name, QString Last_name)
{

    QSqlQuery query;
    query.prepare("DELETE FROM professionals WHERE ID_professional= :id");
    query.bindValue(":id", getIdprofessionel(First_name,Last_name));
    bool success = query.exec();
    if(success) {
        QMessageBox::information(nullptr, "Professionnel supprimé", "Le professionnel a été supprimé avec succès.");
    } else {
        QMessageBox::critical(nullptr, "Erreur de suppression", "Impossible de supprimer le professionnel.");
    }

}

//slot

void gestion::deleteProfil(QString name_profile)
{
    int id=0;
    id=getIdprofil(name_profile);
    QSqlQuery query;
    query.prepare("DELETE FROM profiles WHERE ID_profile= :id");
    query.bindValue(":id",id);
    bool success = query.exec();
    if(success) {
           QMessageBox::information(nullptr, "Profil ajouté", "Le profilaété supprimé avec succès.");
       } else {
           QMessageBox::critical(nullptr, "Erreur de suppression", "Impossible de supprimer le profil.");
       }
}



int  gestion::getIdprofessionel(QString firstName, QString lastName)
{
    QSqlQuery query;
    query.prepare("SELECT ID_professional FROM professionals WHERE First_name = :firstName AND Last_name = :lastName");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
        if (!query.exec()) {
            qCritical() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
            return 0;
        }

        // Récupération des résultats de la requête
        while (query.next()) {
            int id = query.value(0).toInt();
            qDebug() << "ID du professionnel: " << id;
               return id;
        }

}

int  gestion::getIdprofil(QString name_profile)
{
    int id=0;
    QSqlQuery query;
    query.prepare("SELECT ID_profile FROM profiles WHERE  name_profile= :name_profile");
    query.bindValue(":name_profile",name_profile);
       /* if (!query.exec()) {
            qCritical() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
            return 0;
        }*/

        // Récupération des résultats de la requête
        if (query.next()) {

             id = query.value(0).toInt();
            qDebug() << "ID du profil: " << id;
           // return id;
    }
        return id;
       /* else
           {
            return
        }*/



}

int  gestion::getIdskill(QString name_skill)
{
    QSqlQuery query;
    query.prepare("SELECT ID_skill FROM skills WHERE skill= :name_skill");
    query.bindValue(":name_skill",name_skill);
        if (!query.exec()) {
            qCritical() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
            return 0;
        }

        // Récupération des résultats de la requête
        while (query.next()) {

            int id = query.value(0).toInt();
            qDebug() << "ID de la competence: " << id;
            return id;
    }


}


int gestion::ajouterCompetence(QString competence)
{


    // Création de la requête d'insertion
    QSqlQuery query;
    query.prepare("INSERT INTO skills (skill) VALUES (:skill)");
    query.bindValue(":skill", competence);

    // Exécution de la requête
    if (!query.exec()) {
        qWarning() << "Erreur lors de l'ajout de la compétence : " << query.lastError().text();
        return -1;
    }

    // Récupération de l'ID_skill généré automatiquement
    int id_skill = query.lastInsertId().toInt();
    qDebug() << "L'ID_skill de la compétence ajoutée est : " << id_skill;

    return id_skill;
}

//slot
bool gestion::addprofessionalskills(QString first_name, QString last_name,QString skill_name)
{

    int idprofessinnel=0;
    idprofessinnel=getIdprofessionel(first_name,last_name);
    int idcompetence=0;
    idcompetence=ajouterCompetence(skill_name);
    QSqlQuery request;
    request.prepare("INSERT INTO professionals_skills(professionalsID_professinal,skillsID_skill) VALUES(:professionalsID_professinal,:skillsID_skill)");
    request.bindValue(":professionalsID_professinal",idprofessinnel);
    request.bindValue(":skillsID_skill",idcompetence);
    bool success = request.exec();
    if(success) {qDebug() << "Competence du professionnel Ajoutée";
        actualiserCompetenceProfessionel(first_name,last_name);}
    else qDebug() << "Erreur lors de l'ajout du professionnel";
    return success;
}


//slot
bool gestion::addprofileskills(QString profile_name,QString skill_name)
{
    int idprofil=0;
    idprofil=getIdprofil(profile_name);
    int idcompetence=0;
    idcompetence=ajouterCompetence(skill_name);
    QSqlQuery request;
    request.prepare("INSERT INTO profiles_skills(profilesID_profile,skillsID_skill) VALUES(:profilesID_profile,:skillsID_skill)");
    request.bindValue(":profilesID_profile",idprofil);
    request.bindValue(":skillsID_skill",idcompetence);
    bool success = request.exec();
    if(success)
    {qDebug() << "Competence du professionnel Ajoutée";
    actualiserCompetenceProfile(profile_name);}
    else qDebug() << "Erreur lors de l'ajout du professionnel";
    return success;
}


void gestion::reinitiliserdatabase()
{
    QStringList tables = bdd.tables();
    bool resetDone = false; // Added boolean variable to keep track of reset status

    foreach (QString table, tables) {
        QSqlQuery query;
        query.exec("DELETE FROM " + table);
        if (query.lastError().isValid()) {
            // Traitement de l'erreur
        } else {
            resetDone = true; // If no error occurred, set resetDone to true
        }
    }

    // Display message alerting user if reset was done or not
    if (resetDone) {
        QMessageBox::information(nullptr, "Réinitialisation réussie", "La base de données a été réinitialisée.");
    } else {
        QMessageBox::warning(nullptr, "Réinitialisation échouée", "La base de données n'a pas été réinitialisée.");
    }
}


void gestion::displayProfessionalSkills(QString firstName,QString lastName)
{

        // Requête pour récupérer l'ID du professionnel
        int professionalId = getIdprofessionel(firstName,lastName);
        QSqlQuery query;

        // Requête pour récupérer les compétences du professionnel
        query.prepare("SELECT skills.skill FROM professionals_skills "
                      "JOIN skills ON professionals_skills.skillsID_skill = skills.ID_skill "
                      "WHERE professionals_skills.professionalsID_professinal = :professional_id");
        query.bindValue(":professional_id", professionalId);
        if (!query.exec()) {
            qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
            return;
        }

       /* // Affichage des compétences
        qDebug() << "Compétences de" << firstName << lastName << ":";
        while (query.next()) {
            QString skill = query.value(0).toString();
            qDebug() << skill;
        }*/

        //
        QDialog* dialog = new QDialog();
        QVBoxLayout* layout = new QVBoxLayout(dialog);

        // Ajout d'un label pour afficher le nom du professionnel
        QString title = QString("Compétences de %1 %2").arg(firstName, lastName);
        QLabel* titleLabel = new QLabel(title, dialog);
        titleLabel->setStyleSheet("font-weight: bold; font-size: 16px;");
        layout->addWidget(titleLabel);

        // Ajout d'un widget QTextEdit pour afficher les compétences
        QTextEdit* textEdit = new QTextEdit(dialog);
        textEdit->setReadOnly(true);
        layout->addWidget(textEdit);

        QStringList skillsList;
        while (query.next()) {
            QString skill = query.value(0).toString();
            qDebug() << skill;
            skillsList << skill;
        }
        textEdit->setPlainText(skillsList.join("\n"));

        // Affichage de la fenêtre de dialogue
        dialog->exec();

        // Libération de la mémoire utilisée par la fenêtre de dialogue
        delete dialog;




}



void gestion::displayProfilSkills(QString name_profile)
{
    // Récupérer l'identifiant du profil professionnel
    int profileId =getIdprofil( name_profile);

    // Récupérer les compétences associées à ce profil professionnel dans la base de données
    QSqlQuery query;
    query.prepare("SELECT skills.skill FROM skills INNER JOIN profiles_skills ON skills.ID_skill = profiles_skills.skillsID_skill WHERE profiles_skills.profilesID_profile = :profileId");
    query.bindValue(":profileId", profileId);
    query.exec();

    // Afficher les compétences dans la console
    while (query.next()) {
        QString skillName = query.value(0).toString();
        qDebug() << skillName;
    }
}
//Permet de récupérer le nombre de compétences associées à un profil
int gestion::numberskillprofile(QString name_profile)
{
    int profileId = getIdprofil(name_profile);
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) AS num_skills FROM profiles_skills WHERE profilesID_profile = :profileId") ;
    query.bindValue(":profileId", profileId);
    query.exec();
    query.next();
    int n = query.value(0).toInt();
    qDebug() << n;
    return n;
}

//Permet de récupérer le nombre de compétences associées à un profil

int gestion::numberskillprofessinel(QString firstName,QString lastName)
{
    int professionelId = getIdprofessionel(firstName,lastName);
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) AS num_skills FROM professionals_skills WHERE professionalsID_professinal = :professionelId") ;
    query.bindValue(":professionelId",professionelId);
    query.exec();
    query.next();
    int n = query.value(0).toInt();
    qDebug() << n;
    return n;
}

void gestion::actualiserCompetenceProfile(QString profile_name)
{

    int number_skills_profile = numberskillprofile(profile_name);
       int id = getIdprofil(profile_name);
       QSqlQuery request;
       request.prepare("UPDATE profiles SET number_skills_profile = :number_skills_profile WHERE ID_profile = :id");
       request.bindValue(":number_skills_profile", number_skills_profile);
       request.bindValue(":id", id);
       request.exec();


}

void gestion::actualiserCompetenceProfessionel(QString firstName,QString lastName)
{

    int number_skills_professionel = numberskillprofessinel(firstName, lastName);
        int id = getIdprofessionel(firstName, lastName);
        QSqlQuery request;
        request.prepare("UPDATE professionals SET number_of_skills = :number_of_skills WHERE ID_professional = :id");
        request.bindValue(":number_of_skills", number_skills_professionel); // Correction: bindValue() prend le nom du paramètre, pas le nom de la variable
        request.bindValue(":id", id);
        request.exec();


}


/*void deleteskillprofile(QString profile_name,QString skill_name)
{


}*/


