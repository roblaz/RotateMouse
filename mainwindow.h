#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_AngleSlider_valueChanged(int value);

    void on_ShearSlider_valueChanged(int value);

private:
    int angle;
    float shear;
    QGraphicsScene *scene;
    void transform(int, float);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
