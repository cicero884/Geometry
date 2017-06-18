#include "object.h"

object::object(QPointF _position,QSize _diameter)
    :position(_position),diameter(_diameter),direction(0){}
object::~object(){
    while(!image.empty()){
        delete image.front();
        image.erase(image.begin());
    }
}

void object::pressedThere(QMouseEvent *e){
    std::cerr<<"mouse Pressed "<<e->x()<<","<<e->y()<<" connect but no virtual\n";
    return;
}
void object::passThere(QMouseEvent *e){
    std::cerr<<"mouse Released "<<e->x()<<","<<e->y()<<" connect but no virtual\n";
    return;
}
void object::releasedThere(QMouseEvent *e){
    std::cerr<<"mouse Released "<<e->x()<<","<<e->y()<<" connect but no virtual\n";
    return;
}
void object::demo(){
    direction++;
    show();
    return;
}
void object::show(qreal opacity){
    std::cerr<<"object show\n";
    for(int i=0;i<image.size();++i){
        image.at(i)->setPos(position);
        image.at(i)->setRotation(direction);
        image.at(i)->setOpacity(opacity);
    }
    return;
}
