#ifndef CARD_SLOT_H
#define CARD_SLOT_H

#include"scene.h"

class card_slot:public object{
    Q_OBJECT
public:
    explicit card_slot(QPointF _position,QSize _diameter,unit *_exhibit);
    ~card_slot();
private:
    unit *exhibit;
    scene *game;
    unit *newUnit;
public slots:
    virtual void pressedThere(QMouseEvent *e);
    void setPath(QMouseEvent *e);
    void follow(QMouseEvent *e);
};

#endif // CARD_SLOT_H
