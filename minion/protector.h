#ifndef PROTECTOR_H
#define PROTECTOR_H

#include"shield.h"

class protector:public unit{
    Q_OBJECT
public:
    explicit protector(QPointF _position,QSize _diameter,int _faction);
    virtual int attack();
    virtual unit* summon(QPointF _position,QSize _diameter,int _faction);
    virtual void show(qreal opacity=qreal(1));
private:
    int rotation;
public slots:
    virtual void demo();
};

#endif // PROTECTOR_H
