#ifndef SELECT_MINION_BUTTON_H
#define SELECT_MINION_BUTTON_H

#include"scene.h"

class select_minion_button:public scene_button{
    Q_OBJECT
public:
    select_minion_button(QPointF _position,QSize _diameter,int _font,scene *_parent,scene *_next,QString _text,unit *_exhibit);
    unit *exhibit=NULL;
    bool selected=NULL;
private:
    QGraphicsColorizeEffect *selected_color=NULL;
public slots:
    virtual void pressedThere(QMouseEvent *e);
};

#endif // SELECT_MINION_BUTTON_H
