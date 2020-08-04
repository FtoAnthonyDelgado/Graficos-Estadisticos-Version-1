#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <openchart.h>
#include <QMap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mLayout = new QVBoxLayout;
    mChart = new OpenChart(this);

    mLayout->addWidget(mChart);
    mLayout->setMargin(0);
    setLayout(mLayout);

    QMap<QString, double> estudiantes;
    estudiantes["Nota 1: "] = 60;
    estudiantes["Nota 2: "] = 70;
    estudiantes["Nota 3: "] = 80;
    estudiantes["Promedio: "] = 70;

    //Poner nombre a nuestro diagrama de barras
    mChart->setTitle("Promedio Estudiantes");

    const auto estudiantesEnd = estudiantes.end();
    for (auto i = estudiantes.begin(); i!= estudiantesEnd; ++i){
        mChart->addItem(i.key(), i.value());

    }

}

Widget::~Widget()
{
    delete ui;
}

