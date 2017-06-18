#ifndef GAMEHODER_H
#define GAMEHODER_H

#include<QTimer>
#include"scene.h"
#include"minion/destroyer.h"
#include"objects/card_slot.h"
#include"objects/war_fog.h"

class GameHoder:public object{
    Q_OBJECT
public:
    explicit GameHoder();
    ~GameHoder();
    QTimer *gameClock=NULL;
private:
    int warFog_flag;
    QVector<object*> WarFogs;
    scene *game;
    QVector<unit*> waitingTarget;
    QVector<unit*> morgue;
public slots:
    void startGame(int difficulty,int _warFog);
    void holdGame();
    void endGame(int winner);
};

#endif // GAMEHODER_H
