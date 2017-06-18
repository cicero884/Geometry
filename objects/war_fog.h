#ifndef WAR_FOG_H
#define WAR_FOG_H

#include"object.h"

class war_fog:public object{
public:
    war_fog(QPointF _position);
    virtual void show(qreal opacity=qreal(1));
};

#endif // WAR_FOG_H
