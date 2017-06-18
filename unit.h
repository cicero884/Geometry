#ifndef UNIT_H
#define UNIT_H

#include"object.h"
#include"mainwindow.h"


class unit:public object{
    Q_OBJECT
public:
    explicit unit(QPointF _position,QSize _diameter,
         QPointF _speed,int _hp,int _damage,int _faction,int _weight,int _propulsion,int _vision,qreal _friction);
    QPointF speed;
    int hp,max_hp,damage,faction,weight,max_weight,propulsion,vision,cooldown=0;
    qreal friction;
    unit *pre_collision;

    QVector<unit*> target;
    QVector<QPointF> path;
    QVector<QGraphicsItem*> imformationImage;
    QVector<int (unit::*)()> behavior;

    int selectPath();
    //int selectFarEnemy();
    int selectNearEnemy();
    virtual int attack();
    int walk();

    virtual unit* summon(QPointF _position,QSize _diameter,int _faction);
private:
    bool showImformationFlag=true;
public slots:
    virtual void follow(QMouseEvent *e);
    void showImformation(QMouseEvent *e);
    void disappear();
    virtual void start();
};
typedef QVector<unit*> troop;
#endif // UNIT_H
