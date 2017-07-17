#ifndef WAR_FOG_H
#define WAR_FOG_H

#include<QPainter>
#include"object.h"

extern QMap<QString,QColor> Colors;

class war_fog:public QGraphicsItem{
public:
    war_fog(QPixmap* background_image=new QPixmap(":/picture/background color"),QColor fog_color=Colors["ll_gray"]);
    ~war_fog();
    QPainter* background=NULL;
    QGraphicsRectItem* fog=NULL;
    virtual void show(qreal opacity=qreal(1));
};

#endif // WAR_FOG_H
