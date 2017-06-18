#include "gamehoder.h"
#include"minion/tank.h"

extern QTimer *DemoClock;
extern MainWindow *w;
extern QMap<QString,unit*> Minions;
extern QVector<QString> selected_count;
extern QVector<card_slot*> cardSlots;

QVector<QGraphicsItem*> GameImage;
QVector<unit*> NewBorn;
QVector<unit*> army;
QVector<unit*> boss;

static void collision(unit *a,unit *b){
    if(a->weight==-1){
        if(b->weight!=-1){
            QPointF d=a->position-b->position;
            b->speed=b->speed-2*(d*dot(b->speed,d)/PSquare(d));
        }
    }
    else{
        if(b->weight==-1){
            QPointF d=b->position-a->position;
            a->speed=a->speed-2*(d*dot(a->speed,d)/PSquare(d));
        }
        else{
            QPointF ah,al,bh,bl,d=b->position-a->position;
            ah=d*dot(a->speed,d)/PSquare(d);
            al=a->speed-ah;
            d=a->position-b->position;
            bh=d*dot(b->speed,d)/PSquare(d);
            bl=b->speed-bh;
            d=(ah*a->weight+bh*b->weight)/(a->weight+b->weight);
            ah=d*2-ah;
            bh=d*2-bh;
            a->speed=ah+al;
            b->speed=bh+bl;
        }
    }
    return;
}

GameHoder::GameHoder()
    :object(QPointF(800,450),QSize(250,150)){
    game=new scene();
    gameClock=new QTimer;
    gameClock->start(30);
}
GameHoder::~GameHoder(){
    delete gameClock;
    while(!morgue.empty()){
        delete morgue.begin();
        morgue.erase(morgue.begin());
    }
}
void GameHoder::startGame(int difficulty,int _warFog){
    warFog_flag=_warFog;
    std::cerr<<"set fog: "<<warFog_flag<<"\n";
    if(warFog_flag==1){
        for(int i=0;i<104;++i){
            for(int j=5*(i%2);j<1600;j+=10){
                object *newFog=new war_fog(QPointF(j,i*8.7));
                game->addObject(newFog);
                WarFogs.push_back(newFog);
            }
        }
    }
    while(!army.empty()){
        delete army.front();
        army.pop_front();
    }
    while(!morgue.empty()){
        delete morgue.front();
        morgue.pop_front();
    }
    while(!waitingTarget.empty()){
        delete waitingTarget.front();
        waitingTarget.pop_front();
    }
    while(!GameImage.empty()){
        delete GameImage.front();
        GameImage.pop_front();
    }
    NewBorn.push_back(new destroyer(QPointF(200,450),QSize(100,100),1));
    NewBorn.push_back(new destroyer(QPointF(1400,450),QSize(100,100),2));
    boss=NewBorn;
    connect(gameClock,SIGNAL(timeout()),this,SLOT(holdGame()));
    for(int i=0,x=100,y=800;i<selected_count.size();++i){
        unit *exhibit=Minions[selected_count.at(i)]->summon(QPointF(x,y),QSize(40,40),1);
        game->addObject(exhibit);
        cardSlots.push_back(new card_slot(QPointF(x,y),QSize(100,100),exhibit));
        game->addButton(cardSlots.back());
        x+=100;
    }
    game->connectAll();
    w->setScene(game);
}
void GameHoder::holdGame(){
    while(!NewBorn.empty()){
        game->addObject(NewBorn.front());
        waitingTarget.push_back(NewBorn.front());
        NewBorn.pop_front();
    }
    while(!GameImage.empty()){
        game->addItem(GameImage.front());
        GameImage.pop_front();
    }
    for(int i=0;i<waitingTarget.size();){
        if(waitingTarget.at(i)->path.front()!=QPointF(-1,-1)){
            army.push_back(waitingTarget.at(i));
            connect(gameClock,SIGNAL(timeout()),waitingTarget.at(i),SLOT(start()));
            waitingTarget.remove(i);
        }
        else ++i;
    }
    for(int i=0;i<army.size();){
        unit *collision_unit=NULL;
        //touch
        for(int j=i+1;j<army.size();++j){
            if(CirPointCompare(army.at(i)->position,(army.at(i)->diameter+army.at(j)->diameter)/2,army.at(j)->position)){
                collision_unit=army.at(j);
                if(     army.at(i)->pre_collision!=army.at(j) &&
                        army.at(j)->pre_collision!=army.at(i)){
                    collision(army.at(i),army.at(j));
                }
                if(army.at(i)->faction!=army.at(j)->faction){
                    army.at(i)->hp-=army.at(j)->damage;
                    army.at(j)->hp-=army.at(i)->damage;
                }
            }
        }
        if(army.at(i)->pre_collision!=collision_unit) army.at(i)->pre_collision=collision_unit;
        if(collision_unit) collision_unit->pre_collision=army.at(i);
        //touch wall
        if(army.at(i)->position.x()-army.at(i)->diameter.width()/2<=0||army.at(i)->position.x()+army.at(i)->diameter.width()/2>=1600){
            army.at(i)->speed.setX(-army.at(i)->speed.x());
        }
        if(army.at(i)->position.y()-army.at(i)->diameter.height()/2<=0||army.at(i)->position.y()+army.at(i)->diameter.height()/2>=900){
            army.at(i)->speed.setY(-army.at(i)->speed.y());
        }
        //walk and show
        //std::cerr<<army.at(i)->position.x()<<","<<army.at(i)->position.y()<<"\n";
        if(RecPointCompare(army.at(i)->position,QSize(800+50,450+50),army.at(i)->position)){
            army.at(i)->position+=army.at(i)->speed;
            army.at(i)->speed*=(1-army.at(i)->friction);
            army.at(i)->show();
        }
        else army.at(i)->hp=-1;

        //look hp
        if(army.at(i)->hp<=0){
            morgue.push_back(army.at(i));
            disconnect(gameClock,SIGNAL(timeout()),army.at(i),SLOT(start()));
            connect(DemoClock,SIGNAL(timeout()),army.at(i),SLOT(disappear()));
            disconnect(w,SIGNAL(mouseMoved(QMouseEvent*)),army.at(i),SLOT(showImformation(QMouseEvent*)));
            army.remove(i);
        }
        else ++i;
    }
    //war fog
    for(int i=0;i<WarFogs.size();++i) WarFogs.at(i)->show();
    for(int i=0;i<army.size();++i){
        if(warFog_flag&&army.at(i)->faction==1){
            for(int j=0;j<WarFogs.size();++j){
                if(CirPointCompare(army.at(i)->position,army.at(i)->vision,WarFogs.at(j)->position)){
                    WarFogs.at(j)->show(0);
                }
            }
        }
    }
    //dead body effect
    for(int i=0;i<morgue.size();++i){
        morgue.at(i)->position+=morgue.at(i)->speed;
        if(morgue.at(i)->weight<=0){
            delete morgue.at(i);
            morgue.remove(i);
        }
    }
}
void GameHoder::endGame(int winner){
    disconnect(gameClock,SIGNAL(timeout()),this,SLOT(holdGame()));
    switch (winner) {
    case 1:
        image.push_back(Text(position,diameter,0,"Player 1 win!"));
        break;
    default:
        image.push_back(Text(position,diameter,0,"Player 2 win!"));
        break;
    }
    while(!NewBorn.empty()){
        delete NewBorn.begin();
        NewBorn.pop_front();
    }
    while(!WarFogs.empty()){
        delete WarFogs.front();
        WarFogs.pop_front();
    }
}
