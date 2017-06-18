#include "war_fog.h"

war_fog::war_fog(QPointF _position)
    :object(_position,QSize((1+qreal(qrand())/RAND_MAX)*10,(1+qreal(qrand())/RAND_MAX)*10)){

    switch(qrand()%3){
    case 0:image.push_back(P_circle(position,diameter,-2));break;
    case 1:image.push_back(P_circle(position,diameter,-3));break;
    case 2:image.push_back(P_circle(position,diameter,0));break;
    }

    image.back()->setZValue(30);
}

void war_fog::show(qreal opacity){
    image.front()->setOpacity(opacity);
}
