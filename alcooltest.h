#ifndef ALCOOLTEST_H
#define ALCOOLTEST_H

#include <QMainWindow>

namespace Ui {
class Alcooltest;
}

class Alcooltest : public QMainWindow
{
    Q_OBJECT

public:
    explicit Alcooltest(QWidget *parent = 0);
    void closeApp();
    ~Alcooltest();

    void setWidgetColors() noexcept;

public slots:
    void activerBoutonValider(const QString& newValue) noexcept;
    void valider() noexcept;
    void effacer() noexcept;

private:
    Ui::Alcooltest *ui;
};

#endif // ALCOOLTEST_H
