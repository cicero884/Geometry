#ifndef DESTROYER_H
#define DESTROYER_H

#include"bullet.h"

class destroyer:public unit{
    Q_OBJECT
public:
    explicit destroyer(QPointF _position,QSize _diameter,int _faction);
    virtual int attack();
    virtual unit* summon(QPointF _position,QSize _diameter,int _faction);
    virtual void show(qreal opacity=qreal(1));
public slots:
    virtual void start();
    virtual void demo();
};

#endif // DESTROYER_H
