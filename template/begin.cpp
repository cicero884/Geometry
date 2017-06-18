#include "begin.h"

begin::begin(QPointF _position,QSize _diameter)
    :object(_position,_diameter){
    image.push_back(Text(position,diameter,2,"begin"));
    image.push_back(P_slot(position,diameter));
}
