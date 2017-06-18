#include"card_slot.h"

extern MainWindow *w;
extern QVector<QGraphicsItem*> GameImage;
extern QVector<unit*> NewBorn;
extern QVector<unit*> army;
extern QVector<unit*> boss;
extern QTimer *DemoClock;
QVector<card_slot*> cardSlots;


card_slot::card_slot(QPointF _position,QSize _diameter,unit *_exhibit)
    :object(_position,_diameter),exhibit(_exhibit){
    image.push_back(P_slot(position,diameter));
    connect(DemoClock,SIGNAL(timeout()),exhibit,SLOT(demo()));
}
card_slot::~card_slot(){
    delete exhibit;
}
void card_slot::pressedThere(QMouseEvent *e){
    if(RecPointCompare(position,diameter/2,e->pos())){
        newUnit=exhibit->summon(e->pos(),QSize(40,40),1);
        connect(w,SIGNAL(mouseMoved(QMouseEvent*)),newUnit,SLOT(follow(QMouseEvent*)));
        NewBorn.push_back(newUnit);
        for(int i=0;i<cardSlots.size();++i){
            disconnect(w,SIGNAL(mousePressed(QMouseEvent*)),cardSlots.at(i),SLOT(pressedThere(QMouseEvent*)));
            cardSlots.at(i)->show(0.3);
            cardSlots.at(i)->exhibit->show(0.3);
        }
        connect(w,SIGNAL(mousePressed(QMouseEvent*)),this,SLOT(setPath(QMouseEvent*)));
    }
    return;
}
void card_slot::setPath(QMouseEvent *e){
    if(newUnit->path.size()<=1){
        disconnect(w,SIGNAL(mouseMoved(QMouseEvent*)),newUnit,SLOT(follow(QMouseEvent*)));
        newUnit->imformationImage.push_back(P_circle(e->pos(),QSize(newUnit->vision*2,newUnit->vision*2),1));
        newUnit->imformationImage.back()->setOpacity(0.3);
        GameImage.push_back(newUnit->imformationImage.back());
        connect(w,SIGNAL(mouseMoved(QMouseEvent*)),newUnit,SLOT(showImformation(QMouseEvent*)));
    }
    else{
        newUnit->imformationImage.push_back(DashDotDotLine(newUnit->path.back(),e->pos()));
        newUnit->imformationImage.back()->setOpacity(0.3);
        GameImage.push_back(newUnit->imformationImage.back());
        newUnit->imformationImage.push_back(P_cross(e->pos(),newUnit->diameter));
        newUnit->imformationImage.back()->setOpacity(0.3);
        GameImage.push_back(newUnit->imformationImage.back());
    }
    for(int i=0;i<boss.size();++i){
        if(     (CirPointCompare(boss.at(i)->position,boss.at(i)->diameter/2,e->pos())&&boss.at(i)->faction!=newUnit->faction)||
                (e->button()==Qt::RightButton&&boss.at(i)->faction!=newUnit->faction)){
            newUnit->path.push_back(boss.at(i)->position);
            newUnit->path.pop_front();
            newUnit->imformationImage.push_back(DashDotDotLine(newUnit->position,newUnit->path.front()));
            newUnit->imformationImage.back()->setOpacity(0.3);
            disconnect(w,SIGNAL(mousePressed(QMouseEvent*)),this,SLOT(setPath(QMouseEvent*)));
            for(int i=0;i<cardSlots.size();++i){
                connect(w,SIGNAL(mousePressed(QMouseEvent*)),cardSlots.at(i),SLOT(pressedThere(QMouseEvent*)));
                cardSlots.at(i)->show();
                cardSlots.at(i)->exhibit->show();
            }
            return;
        }
    }
    newUnit->path.push_back(e->pos());
    return;
}
void card_slot::follow(QMouseEvent *e){
    newUnit->position=e->pos();
    newUnit->show();
    return;
}
