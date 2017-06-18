#include "destroyer.h"

extern QVector<unit*> NewBorn;
extern QVector<unit*> army;

destroyer::destroyer(QPointF _position,QSize _diameter,int _faction)
    :unit(_position,_diameter,QPointF(0,0),2000,50,_faction,-1,0,400,qreal(1)){
    image.push_back(P_hexagon(position,diameter*1.3));
    image.push_back(P_rectangle(position,QSize(diameter.width()*0.8,diameter.height()*0.8)));
    image.push_back(P_trapezoid(position,QSize(diameter.width()*1.3,diameter.height()*0.9)));
    image.push_back(P_circle(position,diameter,faction));
    for(int i=0;i<image.size();++i){
        image.at(i)->setZValue(40+i);
    }
    //for(int i=0;i<image.size();++i) image.at(i)->setPos(position);
    path.clear();
    path.push_back(QPointF(800,450));
    selectPath();

    behavior.push_back(&unit::selectNearEnemy);
    behavior.push_back(&unit::attack);

}
int destroyer::attack(){
    //std::cerr<<"cooldown";
    if(!cooldown){
        std::cerr<<"destroyer attack\n";
        unit *my_bullet=new bullet(position+A2P(direction)*P2L(diameter)/2,diameter*0.4,A2P(direction)*4,200,300,faction,150,50);
        pre_collision=my_bullet;
        NewBorn.push_back(my_bullet);
        cooldown+=170;
    }
    return 0;
}
unit *destroyer::summon(QPointF _position, QSize _diameter, int _faction){
    return new destroyer(_position,_diameter,_faction);
}
void destroyer::show(qreal opacity){
    image.at(1)->setRotation(direction);
    image.at(2)->setRotation(direction);
    return;
}
void destroyer::start(){
    target.clear();
    if(cooldown>0) --cooldown;
    for(int i=0;i<army.size();++i){
        if(CirPointCompare(army.at(i)->position,QSize(army.at(i)->diameter)/2+QSize(vision,vision),position)) target.push_back(army.at(i));
    }
    for(int i=0;i<behavior.size();++i) i+=(this->*behavior.at(i))();
    return;
}
void destroyer::demo(){
    image.at(1)->setRotation(direction);
    image.at(2)->setRotation(direction);
    ++direction;
}
