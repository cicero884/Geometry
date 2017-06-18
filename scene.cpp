#include "scene.h"

extern MainWindow *w;
extern QVector<QFont> Fonts;

scene::scene()
    :QGraphicsScene(){
    object *background=new object(QPoint(0,0),QSize(2000,900));
    background->image.push_back(P_background());
    addObject(background);
}
scene::~scene(){
    while(!buttons.empty()){
        delete buttons.front();
        buttons.erase(buttons.begin());
    }
}
void scene::addObject(object *newObject){
    for(int i=0;i<newObject->image.size();++i){
        this->addItem(newObject->image.at(i));
    }
    return;
}
void scene::removeObject(object *oldObject){
    for(int i=0;i<oldObject->image.size();++i){
        this->removeItem(oldObject->image.at(i));
    }
    return;
}
void scene::addButton(object *newButton){
    buttons.push_back(newButton);
    addObject(newButton);
    return;
}
void scene::connectAll(){
    for(int i=0;i<buttons.size();++i){
        connect(w,SIGNAL(mousePressed(QMouseEvent*)),buttons[i],SLOT(pressedThere(QMouseEvent*)));
    }
    return;
}
void scene::disconnectAll(){
    for(int i=0;i<buttons.size();++i){
        disconnect(w,SIGNAL(mousePressed(QMouseEvent*)),buttons[i],SLOT(pressedThere(QMouseEvent*)));
    }
    return;
}
void scene::dynamic(){

}

scene_button::scene_button(QPointF _position,QSize _diameter,int _font,scene *_parent,scene *_next,QString _text)
    :object(_position,_diameter),parent(_parent),next(_next),button_name(_text){
    image.push_back(Text(position,diameter,_font,button_name));
}
void scene_button::pressedThere(QMouseEvent *e){
    if(RecPointCompare(position,diameter/2,QPointF(e->x(),e->y()))==1){
        parent->disconnectAll();
        next->connectAll();
        w->setScene(next);
    }
    return;
}

