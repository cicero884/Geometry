#ifndef BASIC_SET_H
#define BASIC_SET_H

#include<QTimer>
#include<QTime>
#include<QtGlobal>
#include<QMouseEvent>
#include<QVector>
#include<QMap>
#include<QtMath>
#include<iostream>
#include<QGraphicsColorizeEffect>
#include<QGraphicsPixmapItem>
#include<QGraphicsLineItem>
#include<QPen>
#include<QFont>

QGraphicsEffect *FactionColor(int faction);

QGraphicsTextItem *Text(QPointF position,QSize size,int font,QString word,QColor color=QColor(0,0,0));
QGraphicsLineItem *DashDotDotLine(QPointF a,QPointF b,QString color="blue",qreal width=10);
QGraphicsPixmapItem *P_background(QPointF position=QPointF(0,0),QSize size=QSize(1600,900),QPointF offset=QPointF(0,0),QString background_color="white",QString line_color="");
QGraphicsPixmapItem *P_block(QPointF position,QSize size,QPointF offset);
QGraphicsPixmapItem *P_circle(QPointF position,QSize size,int faction,QPointF offset);
QGraphicsPixmapItem *P_cross(QPointF position,QSize size,int faction,QPointF offset);
QGraphicsPixmapItem *P_hexagon(QPointF position,QSize size,int faction,QPointF offset);
QGraphicsPixmapItem *P_rectangle(QPointF position,QSize size,int faction,QPointF offset);
QGraphicsPixmapItem *P_slot(QPointF position,QSize size,int faction,QPointF offset);
QGraphicsPixmapItem *P_trapezoid(QPointF position,QSize size,int faction,QPointF offset);
QGraphicsPixmapItem *P_triangle(QPointF position,QSize size,int faction,QPointF offset);
inline QGraphicsPixmapItem *P_block(QPointF position,QSize size){
    return P_block(position,size,-QPointF(size.width()/2,size.height()/2));
}
inline QGraphicsPixmapItem *P_circle(QPointF position,QSize size,int faction){
    return P_circle(position,size,faction,-QPointF(size.width()/2,size.height()/2));
}
inline QGraphicsPixmapItem *P_cross(QPointF position,QSize size){
    return P_cross(position,size,2,-QPointF(size.width()/2,size.height()/2));
}
inline QGraphicsPixmapItem *P_hexagon(QPointF position,QSize size){
    return P_hexagon(position,size,-4,-QPointF(size.width()/2,size.height()/2));
}
inline QGraphicsPixmapItem *P_rectangle(QPointF position,QSize size){
    return P_rectangle(position,size,-1,-QPointF(0,size.height()/2));
}
inline QGraphicsPixmapItem *P_slot(QPointF position,QSize size){
    return P_slot(position,size,0,-QPointF(size.width()/2,size.height()/2));
}
inline QGraphicsPixmapItem *P_trapezoid(QPointF position,QSize size){
    return P_trapezoid(position,size,-1,-QPointF(size.width()/2,size.height()/2));
}
inline QGraphicsPixmapItem *P_triangle(QPointF position,QSize size,int faction){
    return P_triangle(position,size,faction,-QPointF(size.width()/2,size.height()/2));
}
inline QGraphicsPixmapItem *P_triangle(QPointF position,QSize size){
    return P_triangle(position,size,0);
}

inline qreal PSquare(QPointF p){
    return pow(p.x(),2)+pow(p.y(),2);
}
inline qreal PSquare(QSize p){
    return pow(p.width(),2)+pow(p.height(),2);
}

inline QPointF A2P(qreal direction){
    return QPointF(cos(direction*M_PI/180),sin(direction*M_PI/180));
}
inline qreal P2A(QPointF direction){
    return atan2(direction.y(),direction.x())*180/M_PI;
}
inline qreal P2L(QPointF a){
    return sqrt(PSquare(a));
}
inline qreal P2L(QSize a){
    return sqrt(PSquare(a));
}
inline QPointF P2P(QPointF direction){
    return direction/P2L(direction);
}
inline qreal cross(QPointF a,QPointF b){
    return a.x()*b.y()-a.y()*b.x();
}
inline qreal dot(QPointF a,QPointF b){
    return a.x()*b.x()+a.y()*b.y();
}

int RecPointCompare(QPointF a,QSize half_range,QPointF b);
inline bool CirPointCompare(QPointF a,QSize half_range,QPointF b){
    return PSquare(a-b)<PSquare(half_range)/sqrt(2);
}
inline bool CirPointCompare(QPointF a,qreal half_range,QPointF b){
    return PSquare(a-b)<half_range*half_range;
}
#endif // BASIC_SET_H
