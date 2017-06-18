#ifndef OBJECT_H
#define OBJECT_H

#include"basic_set.h"
#include<QObject>

class object : public QObject{
    Q_OBJECT
public:
    explicit object(QPointF _position,QSize _dimension);
    ~object();
    QPointF position;
    QSize diameter;
    qreal direction;
    QVector<QGraphicsItem*> image;
    virtual void show(qreal opacity=qreal(1));
public slots:
    virtual void pressedThere(QMouseEvent *e);
    virtual void passThere(QMouseEvent *e);
    virtual void releasedThere(QMouseEvent *e);
    virtual void demo();
};

#endif // OBJECT_H
