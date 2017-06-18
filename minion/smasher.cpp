#include "smasher.h"


smasher::smasher(QPointF _position, QSize _diameter, int _faction)
    :unit(_position,_diameter,QPointF(0,0),700,80,_faction,90,30,100,0.1),rotate(0){
    image.push_back(P_hexagon(position,diameter*1.3));
    image.push_back(P_hexagon(position,diameter*1.3));
    image.push_back(P_circle(position,diameter,faction));

    behavior.push_back(&unit::selectPath);
    behavior.push_back(&unit::selectNearEnemy);
    behavior.push_back(&unit::attack);
    behavior.push_back(&unit::walk);
}
int smasher::attack(){
    if(cooldown<=40){
        damage=80;
        if(!cooldown){
            damage=150;
            cooldown+=60;
        }
    }
    else rotate+=3;
    return 0;
}
unit* smasher::summon(QPointF _position, QSize _diameter, int _faction){
    return new smasher(_position,_diameter,_faction);
}
void smasher::show(qreal opacity){
    for(int i=0;i<image.size();++i){
        image.at(i)->setPos(position);
        image.at(i)->setOpacity(opacity);
    }
    image.at(0)->setRotation(rotate);
    image.at(1)->setRotation(-rotate);
    return;
}
void smasher::demo(){
    rotate+=3;
    image.at(0)->setRotation(rotate);
    image.at(1)->setRotation(-rotate);
    return;
}
