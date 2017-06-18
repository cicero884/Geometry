#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"basic_set.h"
#include<QMainWindow>
#include<QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool eventFilter(QObject *watched, QEvent *event);
    void setScene(QGraphicsScene*);
    /*
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    */
private:
    Ui::MainWindow *ui;
signals:
    void mousePressed(QMouseEvent*);
    void mouseMoved(QMouseEvent*);
    void mouseReleased(QMouseEvent*);
public slots:
};

#endif // MAINWINDOW_H
