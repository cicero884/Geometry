#ifndef BEGIN_H
#define BEGIN_H

#include"object.h"

class begin:public object{
public:
    begin(QPointF _position=QPointF(800,400),QSize _diameter=QSize(150,50));
};

#endif // BEGIN_H
