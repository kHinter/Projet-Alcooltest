#include "alcooltest.h"
#include "ui_alcooltest.h"
#include <QDebug>

Alcooltest::Alcooltest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Alcooltest)
{
    ui->setupUi(this);

    //Je paramètre l'affichage
    ui->hommeRadioBtn->setChecked(true);
    setWidgetColors();
    ui->Valider->setEnabled(false);

    //On écoute les évènements
    connect(ui->Valider, SIGNAL(clicked()), SLOT(valider()));
    connect(ui->Effacer, SIGNAL(clicked()), SLOT(effacer()));
    connect(ui->lineEdit_poids, SIGNAL(textChanged(const QString&)), SLOT(activerBoutonValider(const QString&)));
}

void Alcooltest::activerBoutonValider(const QString& newValue) noexcept
{
    ui->Valider->setEnabled(newValue.toDouble() != 0.0);
}

void Alcooltest::valider() noexcept
{
    double tauxAlcoolBiere = ui->lineEdit_biere->text().toDouble() * 10 * 0.05;
    double tauxAlcoolVin = ui->lineEdit_vin->text().toDouble() * 10 * 0.12;
    double tauxAlcoolAperitif = ui->lineEdit_apero->text().toDouble() * 10 * 0.35;
    double tauxAlcoolAutres = ui->lineEdit_autres2->text().toDouble() * 10 * ui->lineEdit_autres1->text().toDouble() * 0.01;

    double coefSexe = 0.7;

    if(ui->femmeRadioBtn->isChecked())
    {
        coefSexe = 0.6;
    }

    double tauxAlcoolTotal = ((tauxAlcoolBiere + tauxAlcoolVin + tauxAlcoolAperitif + tauxAlcoolAutres) * 0.8)
            / (coefSexe * ui->lineEdit_poids->text().toDouble());

    QPalette palette;
    if(tauxAlcoolTotal >= 0.5)
    {
        palette.setColor(QPalette::Window, Qt::red);
    }
    else
    {
        palette.setColor(QPalette::Window, Qt::green);
    }

    ui->tauxAlcool->setAutoFillBackground(true);
    ui->tauxAlcool->setPalette(palette);

    ui->tauxAlcool->setText(QString::number(tauxAlcoolTotal, 'd', 2) + " g/L");
}

void Alcooltest::effacer() noexcept
{
    ui->lineEdit_poids->clear();
    ui->lineEdit_biere->clear();
    ui->lineEdit_vin->clear();
    ui->lineEdit_apero->clear();

    ui->lineEdit_autres1->clear();
    ui->lineEdit_autres2->clear();
}

void Alcooltest::setWidgetColors() noexcept
{
    QPalette palette;
    QColor blue (39, 128, 245);
    palette.setColor(QPalette::Window, blue);

    ui->label_2->setAutoFillBackground(true);
    ui->label_2->setPalette(palette);

    ui->Boissons->setAutoFillBackground(true);
    ui->Boissons->setPalette(palette);

    ui->Pourcent->setAutoFillBackground(true);
    ui->Pourcent->setPalette(palette);

    ui->Quantite->setAutoFillBackground(true);
    ui->Quantite->setPalette(palette);

    ui->Biere->setAutoFillBackground(true);
    ui->Biere->setPalette(palette);

    ui->Vin->setAutoFillBackground(true);
    ui->Vin->setPalette(palette);

    ui->Aperitif->setAutoFillBackground(true);
    ui->Aperitif->setPalette(palette);

    ui->Autres->setAutoFillBackground(true);
    ui->Autres->setPalette(palette);
}

Alcooltest::~Alcooltest()
{
    delete ui;
}
