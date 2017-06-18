#ifndef BLOCK_H
#define BLOCK_H

#include"object.h"

class block : public object
{
public:
    block(QPointF _position,QSize _dimension);
};

#endif // BLOCK_H
