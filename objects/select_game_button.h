#ifndef SELECT_GAME_BUTTON_H
#define SELECT_GAME_BUTTON_H

#include"gamehoder.h"

class select_game_button:public scene_button{
    Q_OBJECT
public:
    explicit select_game_button(QPointF _position,QSize _diameter,int _font,scene *_parent,QString _text,int _level,int _warFog);
private:
    int level,warFog;
signals:
    void GameStart(int _level,int _warFog);
public slots:
    virtual void pressedThere(QMouseEvent *e);
};

#endif // SELECT_GAME_BUTTON_H
