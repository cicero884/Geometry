#ifndef SCENE_H
#define SCENE_H

#include<QGraphicsTextItem>
#include"mainwindow.h"
#include"unit.h"

class scene:public QGraphicsScene{
    Q_OBJECT
public:
    scene();
    ~scene();
    QVector<object*> buttons;
    void addObject(object*);
    void removeObject(object*);
    void addButton(object*);
    void connectAll();
    void disconnectAll();
public slots:
    virtual void dynamic();
};

class scene_button:public object{
    Q_OBJECT
public:
    explicit scene_button(QPointF _position,QSize _diameter,int _font,scene *_parent,scene *_next,QString _text);
    scene *next=NULL,*parent=NULL;
    QString button_name;
public slots:
    virtual void pressedThere(QMouseEvent *e);
};

#endif // SCENE_H
