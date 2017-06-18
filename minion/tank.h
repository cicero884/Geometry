#ifndef TANK_H
#define TANK_H

#include"bullet.h"

class tank:public unit{
    Q_OBJECT
public:
    explicit tank(QPointF _position,QSize _diameter,int _faction);
    virtual int attack();
    virtual unit* summon(QPointF _position,QSize _diameter,int _faction);
    virtual void show(qreal opacity=qreal(1));
public slots:
    virtual void demo();
};


#endif // TANK_H
