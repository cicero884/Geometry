#ifndef SHIELD_H
#define SHIELD_H

#include"unit.h"

class shield:public unit{
    Q_OBJECT
public:
    shield(QPointF _position,QSize _diameter,int _hp,int _damage,int _faction,int _cooldown,unit *_sumon_parent);
    virtual void show(qreal opacity=qreal(1));
private:
    int max_cooldown=0;
    unit *summon_parent;
public slots:
    virtual void start();
};

#endif // SHIELD_H
