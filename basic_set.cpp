#include"basic_set.h"

extern QVector<QFont> Fonts;
extern QMap<QString,QColor> Colors;

QGraphicsEffect *FactionColor(int faction){
    QGraphicsColorizeEffect *skin=new QGraphicsColorizeEffect();
    switch (faction){
    case -3:skin->setColor(Colors["ll_gray"]);break;
    case -2:skin->setColor(Colors["white"]);break;
    case -1:skin->setColor(Colors["d_gray"]);break;
    case 0: skin->setColor(Colors["l_gray"]);break;
    case 1: skin->setColor(Colors["blue"]);break;
    case 2: skin->setColor(Colors["red"]);break;
    case 3: skin->setColor(Colors["yellow"]);break;
    case 4: skin->setColor(Colors["green"]);break;
    default:skin->setColor(Colors["black"]);break;
    }
    return skin;
}

QGraphicsTextItem *Text(QPointF position,QSize size,int font,QString word,QColor color){
    QGraphicsTextItem *text=new QGraphicsTextItem(word);
    text->setPos(position-QPointF(size.width()/2,size.height()/2));
    text->setFont(Fonts.at(font));
    text->setDefaultTextColor(color);
    text->setTextWidth(size.width());
    return text;
}
QGraphicsLineItem *DashDotDotLine(QPointF a,QPointF b,QString color,qreal width){
    QGraphicsLineItem *line=new QGraphicsLineItem(a.x(),a.y(),b.x(),b.y());
    QPen pen(Colors[color]);
    pen.setStyle(Qt::DashDotDotLine);
    pen.setWidthF(width);
    line->setPen(pen);
    return line;
}
QGraphicsPixmapItem* P_background(QPointF position,QSize size,QPointF offset){
    QGraphicsPixmapItem *picture=new QGraphicsPixmapItem;
    picture->setPixmap(QPixmap(":/picture/background color").scaled(size));
    picture->setOffset(offset);
    picture->setPos(position);
    return picture;
}
QGraphicsPixmapItem *P_block(QPointF position,QSize size,QPointF offset){
    QGraphicsPixmapItem *picture=new QGraphicsPixmapItem;
    QPixmap image(size);
    image.fill(Colors["t_gray"]);
    picture->setPixmap(image);
    picture->setOffset(offset);
    picture->setPos(position);
    return picture;
}
QGraphicsPixmapItem *P_circle(QPointF position,QSize size,int faction,QPointF offset){
    QGraphicsPixmapItem *picture=new QGraphicsPixmapItem;
    picture->setPixmap(QPixmap(":/picture/circle").scaled(size));
    picture->setOffset(offset);
    picture->setPos(position);
    picture->setGraphicsEffect(FactionColor(faction));
    picture->setZValue(13);
    return picture;
}
QGraphicsPixmapItem *P_cross(QPointF position,QSize size,int faction,QPointF offset){
    QGraphicsPixmapItem *picture=new QGraphicsPixmapItem;
    picture->setPixmap(QPixmap(":/picture/cross").scaled(size));
    picture->setOffset(offset);
    picture->setPos(position);
    picture->setGraphicsEffect(FactionColor(faction));
    return picture;
}
QGraphicsPixmapItem *P_hexagon(QPointF position,QSize size,int faction,QPointF offset){
    QGraphicsPixmapItem *picture=new QGraphicsPixmapItem;
    picture->setPixmap(QPixmap(":/picture/hexagon").scaled(size));
    picture->setOffset(offset);
    picture->setPos(position);
    picture->setGraphicsEffect(FactionColor(faction));
    picture->setZValue(10);
    return picture;
}
QGraphicsPixmapItem *P_rectangle(QPointF position,QSize size,int faction,QPointF offset){
    QGraphicsPixmapItem *picture=new QGraphicsPixmapItem;
    picture->setPixmap(QPixmap(":/picture/rectangle").scaled(size));
    picture->setOffset(offset);
    picture->setPos(position);
    picture->setGraphicsEffect(FactionColor(faction));
    picture->setZValue(11);
    return picture;
}
QGraphicsPixmapItem *P_slot(QPointF position,QSize size,int faction,QPointF offset){
    QGraphicsPixmapItem *picture=new QGraphicsPixmapItem;
    picture->setPixmap(QPixmap(":/picture/slot").scaled(size));
    picture->setOffset(offset);
    picture->setPos(position);
    picture->setGraphicsEffect(FactionColor(faction));
    return picture;
}
QGraphicsPixmapItem *P_trapezoid(QPointF position,QSize size,int faction,QPointF offset){
    QGraphicsPixmapItem *picture=new QGraphicsPixmapItem;
    picture->setPixmap(QPixmap(":/picture/trapezoid").scaled(size));
    picture->setOffset(offset);
    picture->setPos(position);
    picture->setGraphicsEffect(FactionColor(faction));
    picture->setZValue(12);
    return picture;
}
QGraphicsPixmapItem *P_triangle(QPointF position,QSize size,int faction,QPointF offset){
    QGraphicsPixmapItem *picture=new QGraphicsPixmapItem;
    picture->setPixmap(QPixmap(":/picture/triangle").scaled(size));
    picture->setOffset(offset);
    picture->setPos(position);
    picture->setGraphicsEffect(FactionColor(faction));
    picture->setZValue(14);
    return picture;
}
int RecPointCompare(QPointF a,QSize half_range,QPointF b){
    if(     b.x()<a.x()+half_range.width()&&b.x()>a.x()-half_range.width() &&
            b.y()<a.y()+half_range.height()&&b.y()>a.y()-half_range.height()){
        return 1;
    }
    return 0;
}
