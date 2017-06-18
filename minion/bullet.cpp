#include "bullet.h"

bullet::bullet(QPointF _position,QSize _diameter,QPointF _speed,int _hp,int _damage,int _faction,int _weight,int _cooldown)
    :unit(_position+_speed+QPointF(_diameter.width()/2,_diameter.height()/2),_diameter,_speed,_hp,_damage,_faction,_weight,0,0,0){
    image.push_back(P_circle(position,diameter,faction));
    path.pop_front();
    path.push_back(position);
    cooldown=_cooldown;
}
void bullet::show(qreal opacity){
    //std::cerr<<"bullet show\n";
    image.front()->setPos(position);
    image.front()->setOpacity(opacity);
    return;
}
void bullet::start(){
    if(cooldown&&P2L(speed)>0.5) --cooldown;
    else hp=-1;
    return;
}
