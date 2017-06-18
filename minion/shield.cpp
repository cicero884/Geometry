#include "shield.h"

shield::shield(QPointF _position, QSize _diameter,int _hp,int _damage,int _faction,int _cooldown,unit *_summon_parent)
    :unit(_position,_diameter,QPointF(0,0),_hp,_damage,_faction,-1,0,0,0),
      max_cooldown(_cooldown),summon_parent(_summon_parent){
    path.pop_front();
    path.push_back(position);

    image.push_back(P_circle(position,diameter,faction));
    cooldown=_cooldown;
}
void shield::show(qreal opacity){
    opacity*=(qreal(cooldown)/max_cooldown+1)/3;

    image.front()->setPos(position);
    image.front()->setOpacity(opacity);
    return;
}
void shield::start(){
    if(cooldown>0) --cooldown;
    else hp=-1;
    pre_collision=summon_parent;
    position=summon_parent->position;
    return;
}
