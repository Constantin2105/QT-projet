#include "acceuil.h"
#include "gestion.h"
#include "gestion_professionnel.h"

#include <QDebug>
#include <QSqlQuery>
#include <QPushButton>


acceuil::acceuil()
{

  //interface graphique qui s'affiche au lancement du programme
  QVBoxLayout *layoutprincipal = new QVBoxLayout;


  QGroupBox *groupbox1 = new QGroupBox("BIENVENUE DANS LE PROJET QT DU GROUPE 1", this);
  groupbox1 -> setFont(QFont("Eras Bold ITC"));
  QFormLayout *layoutt = new QFormLayout;

  QLabel *label = new QLabel();
  label->setPixmap(QPixmap("C:/Users/Utilisateur/Desktop/helpme/2.jpg"));
  label->setScaledContents(true);

  QLabel *textLabel = new QLabel();
  textLabel->setText("GESTION DES COMPETENCES");
  textLabel->setAlignment(Qt::AlignCenter);
  textLabel->setStyleSheet("QLabel { background-color : transparent; color : black; font-size: 50px; font-family: Times New Roman }");
  //qDebug() << "Error loading image";

  layoutt->addWidget(label);
  layoutt->addWidget(textLabel);
  groupbox1->setLayout(layoutt);
  groupbox1->move(1,1);

  //creation du bouton START pour commencer l'utilisation de notre app
    QPushButton *start= new QPushButton("START",this);
    start -> setFont(QFont("Eras Bold ITC"));
    start-> setCursor(Qt::PointingHandCursor);
    start->move(120,300);

    //creation du bouton pour avoir les informations sur l'app
    QPushButton *apropos = new QPushButton("A Propos",this);
    apropos -> setFont(QFont("Eras Bold ITC"));
    apropos-> setCursor(Qt::PointingHandCursor);

  setLayout(layoutprincipal);
  layoutprincipal->addWidget(groupbox1);
  layoutprincipal->addWidget(start);
  layoutprincipal->addWidget(apropos);

  connect(start, &QPushButton::clicked, this, &acceuil::ouvrirgenerer);
   connect(start, &QPushButton::clicked, this, &acceuil::close);
  connect(apropos, &QPushButton::clicked, this, &acceuil::ouvrirapropos);


}




void acceuil::ouvrirgenerer()
{
    //cette methode permet à l'utilsateur de choisir entre l'utilisation de la base de donnee intégrée et l'importation du fichier.cpp
    QDialog *dialog = new QDialog;

            QLabel *label = new QLabel("Ceci est une image");
            label->setPixmap(QPixmap("C:/Users/Utilisateur/Desktop/helpme/3png.png"));

            QPushButton *bouton1 = new QPushButton("Utiliser la base de donnée intégrée");
            QPushButton *bouton2 = new QPushButton("Charger un fichier.cpt");
            QVBoxLayout *layout = new QVBoxLayout;
            bouton1->move(50,50);
            bouton2->move(60,60);
            layout->addWidget(bouton1);
            layout->addWidget(bouton2);

            QVBoxLayout *mainLayout = new QVBoxLayout;
            mainLayout->addWidget(label);
            mainLayout->addLayout(layout);

            dialog->setLayout(mainLayout);
            dialog->show();
            //gestion_competence *obj=new gestion_competence;

            QObject::connect(bouton1,&QPushButton::clicked,this, &acceuil::principal);
            QObject::connect(bouton1,&QPushButton::clicked,this, &gestion::Database);
            //connect(bouton1, &QPushButton::clicked, this, &acceuil::close);



}



void acceuil::ouvrirapropos()
{

    //methode concernant les infos sur l'application
    QMessageBox::information(this, "A Propos", "Bienvenu dans CPT Manager!\n Ce logiciel est mis en place pour permettre de gérer les compétences et profils des professionnels de la base de donnée intégrée. Vous pourrez également utlisée les données d'un fichier.cpt que vous importerai.\n Découvrez notre logiciel plus amplement en cliquant sur START ! .\n\n \t\tRéalisé par Déodat ADANDEDJAN\t\t \n \t\tCopyright , Tous droits réservés\t\t");
}

void acceuil::principal()
{
    //interface de gestion de la base de donnée

        QGroupBox *mainGroupBox = new QGroupBox;
        QVBoxLayout *mainLayout = new QVBoxLayout;

        //competence
        QGroupBox *groupBox1 = new QGroupBox;
        QVBoxLayout *groupBox1Layout = new QVBoxLayout;
        QLabel *image1 = new QLabel;
      //  image1->setPixmap(QPixmap("C:/Users/Utilisateur/Desktop/helpme/4.jpg"));
        QPushButton *buttoncompetence = new QPushButton("Gérer");
        groupBox1Layout->addWidget(image1);
        groupBox1Layout->addWidget(buttoncompetence);
        groupBox1->setLayout(groupBox1Layout);
        groupBox1->setTitle("Compétence");

        //profil
        QGroupBox *groupBox2 = new QGroupBox;
        QVBoxLayout *groupBox2Layout = new QVBoxLayout;
        QLabel *image2 = new QLabel;
       // image2->setPixmap(QPixmap("C:/Users/Utilisateur/Desktop/helpme/committee.jpg"));
        QPushButton *buttonprofil = new QPushButton("Gérer");
        groupBox2Layout->addWidget(image2);
        groupBox2Layout->addWidget(buttonprofil);
        groupBox2->setLayout(groupBox2Layout);
        groupBox2->setTitle("Profil");

        //professionnel
        QGroupBox *groupBox3 = new QGroupBox;
        QVBoxLayout *groupBox3Layout = new QVBoxLayout;
        QLabel *image3 = new QLabel;
       // image3->setPixmap(QPixmap("C:/Users/Utilisateur/Desktop/helpme/5.jpg"));
        QPushButton *buttonprofessionnel = new QPushButton("Gérer");
        groupBox3Layout->addWidget(image3);
        groupBox3Layout->addWidget(buttonprofessionnel);
        groupBox3->setLayout(groupBox3Layout);
        groupBox3->setTitle("Professionnel");

        //reinitialisation
        QGroupBox *groupBox4 = new QGroupBox;
        QVBoxLayout *groupBox4Layout = new QVBoxLayout;
        QLabel *image4 = new QLabel;
       // image4->setPixmap(QPixmap("C:/Users/Utilisateur/Desktop/helpme/.jpg"));
        QPushButton *reset = new QPushButton("Réinitialiser");
        groupBox4Layout->addWidget(image4);
        groupBox4Layout->addWidget(reset);
        groupBox4->setLayout(groupBox4Layout);
        groupBox4->setTitle("Réinitialiser la base de donnée");

        //outils de gestions des compétences et des profils
        QGroupBox *groupBox5 = new QGroupBox;
        QVBoxLayout *groupBox5Layout = new QVBoxLayout;
        QLabel *image5 = new QLabel;
       // image4->setPixmap(QPixmap("C:/Users/Utilisateur/Desktop/helpme/.jpg"));
        QPushButton *outils= new QPushButton("outils de gestions");
        groupBox5Layout->addWidget(image5);
        groupBox5Layout->addWidget(outils);
        groupBox5->setLayout(groupBox5Layout);
        groupBox5->setTitle("Outils");

        QHBoxLayout *groupBoxLayout1 = new QHBoxLayout;
        groupBoxLayout1->addWidget(groupBox1);
        groupBoxLayout1->addWidget(groupBox2);
        QHBoxLayout *groupBoxLayout2 = new QHBoxLayout;
        groupBoxLayout2->addWidget(groupBox3);
        groupBoxLayout2->addWidget(groupBox4);
         groupBoxLayout2->addWidget(groupBox5);

        mainLayout->addLayout(groupBoxLayout1);
        mainLayout->addLayout(groupBoxLayout2);
        mainLayout->addWidget(groupBox3);
        mainGroupBox->setLayout(mainLayout);
        //outils de gestion

        //bouton pour quitter l'app
      //  QPushButton *buttonquitter = new QPushButton("Quitter");
      //  QObject::connect(buttonquitter, SIGNAL(clicked()), qApp, SLOT(quit()));
       // mainLayout->addWidget(buttonquitter);

        //creation des signaux
        //pour le 1er connect, quand on clique sur le bouton mis au niveau de competence, cela ouvre, le slot ouvrir_gestioncompetence()
     QObject::connect(buttoncompetence, &QPushButton::clicked,this, &gestion::competence);
     QObject::connect(buttonprofessionnel,&QPushButton::clicked,this,&gestion::professionnel);
     QObject::connect(buttonprofil, &QPushButton::clicked, this, &gestion::profil);
     QObject::connect(reset, &QPushButton::clicked, this, &gestion::reinitiliserdatabase);

        mainGroupBox->show();
}


