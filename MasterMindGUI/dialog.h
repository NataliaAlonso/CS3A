#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QGraphicsScene *scene;
    QGraphicsScene *secondscene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;
    
private slots:
    void on_textEdit_textChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_label_linkActivated(const QString &link);

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
