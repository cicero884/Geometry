#include "war_fog.h"

extern QMap<QString,unit*> Minions;

war_fog::war_fog(QPixmap *background_image, QColor fog_color){
    background=new QPainter();
    fog=new QGraphicsRectItem(0,0,1600,900);
    background->drawPixmap(0,0,2000,900,background_image);
    background->setClipRegion();
    fog
}
war_fog::~war_fog(){
    delete background;
    delete fog;
}


/*
    :object(QPointF(0,0),QSize(1600,900)){
    image.back()->setZValue(30);
}

void war_fog::show(qreal opacity){
    image.front()->setOpacity(opacity);
}
