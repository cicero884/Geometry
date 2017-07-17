#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    qApp->installEventFilter(this);
}
MainWindow::~MainWindow(){
    delete ui;
}
bool MainWindow::eventFilter(QObject *watched, QEvent *event){
    static bool pressed=false;
    if(event->type()==QEvent::MouseMove) emit mouseMoved(static_cast<QMouseEvent*>(event));
    if(event->type()==QEvent::MouseButtonPress&&(!pressed)){
        pressed=true;
        emit mousePressed(static_cast<QMouseEvent*>(event));
    }
    if(pressed&&event->type()==QEvent::MouseButtonRelease){
        pressed=false;
        emit mouseReleased(static_cast<QMouseEvent*>(event));
    }
    return false;
}

void MainWindow::setScene(QGraphicsScene *next){
    ui->graphicsView->setScene(next);
}
