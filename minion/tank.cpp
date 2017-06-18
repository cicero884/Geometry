#include "tank.h"

extern QVector<unit*> NewBorn;

tank::tank(QPointF _position,QSize _diameter,int _faction)
    :unit(_position,_diameter,QPointF(0,0),200,50,_faction,50,20,150,0.1){
    image.push_back(P_circle(position,diameter,faction));
    image.push_back(P_rectangle(position,diameter));
    //
    behavior.push_back(&unit::selectPath);
    behavior.push_back(&unit::selectNearEnemy);
    behavior.push_back(&unit::attack);
    behavior.push_back(&unit::walk);
}
int tank::attack(){
    if(cooldown<=0){
        unit *my_bullet=new bullet(position+A2P(direction)*P2L(diameter)/2,diameter*0.6,A2P(direction)*10,10,100,faction,20,50);
        pre_collision=my_bullet;
        NewBorn.push_back(my_bullet);
        std::cerr<<"tank attack\n";
        cooldown+=60;
    }
    return 0;
}
unit* tank::summon(QPointF _position, QSize _diameter, int _faction){
    unit *copy=new tank(_position,_diameter,_faction);
    copy->behavior=behavior;
    return copy;
}
void tank::show(qreal opacity){
    //std::cerr<<"tank show\n";
    for(int i=0;i<image.size();++i){
        image.at(i)->setPos(position);
        image.at(i)->setOpacity(opacity);
    }
    image.at(1)->setRotation(direction);
    return;
}
void tank::demo(){
    direction++;
    image.at(1)->setRotation(direction);
    return;
}
