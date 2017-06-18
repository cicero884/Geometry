#include "unit.h"

extern QVector<QGraphicsItem*> GameImage;
extern QVector<unit*> NewBorn;
extern QVector<unit*> army;
extern MainWindow *w;

unit::unit(QPointF _position,QSize _diameter,
            QPointF _speed,int _hp,int _damage,int _faction,int _weight,int _propulsion,int _vision,qreal _friction)
    :object(_position,_diameter),
      speed(_speed),hp(_hp),max_hp(_hp),damage(_damage),faction(_faction),weight(_weight),max_weight(_weight),propulsion(_propulsion),vision(_vision),friction(_friction){
    path.push_back(QPointF(-1,-1));
}

void unit::start(){
    target.clear();
    if(cooldown>0) --cooldown;
    if(!path.empty()&&CirPointCompare(position,diameter,path.front())){
        path.pop_front();
        delete imformationImage.at(2);
        delete imformationImage.at(1);
        imformationImage.remove(2);
        imformationImage.remove(1);
    }
    for(int i=0;i<army.size();++i){
        if(CirPointCompare(army.at(i)->position,QSize(army.at(i)->diameter)/2+QSize(vision,vision),position)) target.push_back(army.at(i));
    }
    for(int i=0;i<behavior.size();++i) i+=(this->*behavior.at(i))();
    return;
}
int unit::selectPath(){
    if(!path.empty()) direction=P2A(path.front()-position);
    return 0;
}
/*
int unit::selectFarEnemy(){
    qreal farest=-1,dis;
    for(int i=0;i<target.size();++i){
        dis=P2L(target.at(i)->position-position);
        if(target.at(i)->faction!=faction&&farest<dis){
            farest=dis;
            direction=P2A(target.at(i)->position-position);
        }
    }
    return 0;
}
*/
int unit::selectNearEnemy(){
    qreal nearest=vision+1,dis;
    for(int i=0;i<target.size();++i){
        dis=P2L(target.at(i)->position-position);
        if(target.at(i)->faction!=faction&& dis<nearest&& target.at(i)->vision){
            direction=P2A(target.at(i)->position-position);
            nearest=dis;
        }
    }
    return (nearest==vision+1);
}
int unit::attack(){
    std::cerr<<"attack??\n";
    return 0;
}
int unit::walk(){
    speed+=A2P(direction)*(qreal(propulsion)/weight);
    return 0;
}
unit *unit::summon(QPointF _position,QSize _diameter,int _faction){
    unit *copy=new unit(_position,_diameter,this->speed,this->hp,this->damage,_faction,this->weight,this->propulsion,this->vision,this->friction);
    std::cerr<<"summon what?\n";
    copy->behavior=behavior;
    return copy;
}
void unit::showImformation(QMouseEvent *e){
    if(CirPointCompare(position,diameter/2,e->pos())){
        if(showImformationFlag==false){
            imformationImage.front()->setPos(position);
            if(!path.empty()){
                delete imformationImage.back();
                imformationImage.pop_back();
                imformationImage.push_back(DashDotDotLine(position,path.front()));
                imformationImage.back()->setOpacity(0.3);
                GameImage.push_back(imformationImage.back());
            }
            for(int i=0;i<imformationImage.size();++i) imformationImage.at(i)->show();
            showImformationFlag=true;
        }
    }
    else{
        if(showImformationFlag==true){
            for(int i=0;i<imformationImage.size();++i) imformationImage.at(i)->hide();

            showImformationFlag=false;
        }
    }
    return;
}

void unit::follow(QMouseEvent *e){
    position=e->pos();
    show(0.5);
    return;
}
void unit::disappear(){
    weight-=max_weight/10;
    show(qreal(weight)/max_weight);
    return;
}

