#include "protector.h"

extern QVector<unit*> NewBorn;

protector::protector(QPointF _position, QSize _diameter, int _faction)
    :unit(_position,_diameter,QPointF(0,0),50,10,_faction,10,10,70,0.4),rotation(0){
    image.push_back(P_hexagon(position,diameter*1.3));
    image.push_back(P_circle(position,diameter,faction));
    image.push_back(P_triangle(position,diameter*0.8));

    behavior.push_back(&unit::selectPath);
    behavior.push_back(&unit::attack);
    behavior.push_back(&unit::walk);
}
int protector::attack(){
    if(cooldown<=50){
        if(cooldown<=0){
            std::cerr<<"protector attack\n";
            unit *my_shield=new shield(position,diameter*5,100,30,faction,200,this);
            pre_collision=my_shield;
            NewBorn.push_back(my_shield);
            cooldown+=250;
        }
    }
    else ++rotation;
    return 0;
}
unit* protector::summon(QPointF _position, QSize _diameter, int _faction){
    unit *copy=new protector(_position,_diameter,_faction);
    copy->behavior=behavior;
    return copy;
}
void protector::show(qreal opacity){
    for(int i=0;i<image.size();++i){
        image.at(i)->setPos(position);
        image.at(i)->setOpacity(opacity);
    }
    image.at(0)->setRotation(rotation);
    image.at(2)->setRotation(-rotation);
    //std::cerr<<"protector at "<<position.x()<<","<<position.y()<<"\n";
    return;
}
void protector::demo(){
    image.at(0)->setRotation(rotation);
    image.at(2)->setRotation(-rotation);
    ++rotation;
    return;
}
