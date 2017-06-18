#ifndef SMASHER_H
#define SMASHER_H

#include"unit.h"

class smasher:public unit{
    Q_OBJECT
public:
    qreal rotate;
    explicit smasher(QPointF _position,QSize _diameter,int _faction);
    virtual int attack();
    virtual unit* summon(QPointF _position,QSize _diameter,int _faction);
    virtual void show(qreal opacity=qreal(1));
public slots:
    virtual void demo();
};
#endif // SMASHER_H
