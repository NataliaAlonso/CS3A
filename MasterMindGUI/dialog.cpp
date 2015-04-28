#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen blackpen(Qt::black);
    //blackpen.setWidth(2);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_textEdit_textChanged()
{

}

void Dialog::on_pushButton_clicked()
{

}

void Dialog::on_pushButton_2_clicked()
{

}

void Dialog::on_label_linkActivated(const QString &link)
{

}
