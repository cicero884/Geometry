#ifndef BULLET_H
#define BULLET_H

#include"unit.h"

class bullet:public unit{
    Q_OBJECT
public:
    explicit bullet(QPointF _position,QSize _diameter,QPointF _speed,int _hp,int _damage,int _faction,int _weight,int _cooldown);
public slots:
    virtual void show(qreal opacity=qreal(1));
    virtual void start();
};

#endif // BULLET_H
