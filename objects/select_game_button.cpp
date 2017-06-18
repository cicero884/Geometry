#include "select_game_button.h"

extern MainWindow *w;
extern GameHoder *GM;

select_game_button::select_game_button(QPointF _position, QSize _diameter, int _font, scene *_parent, QString _text, int _level,int _warFog)
    :scene_button(_position,_diameter,_font,_parent,NULL,_text),level(_level),warFog(_warFog){
    connect(this,SIGNAL(GameStart(int,int)),GM,SLOT(startGame(int,int)));
}

void select_game_button::pressedThere(QMouseEvent *e){
    if(RecPointCompare(position,diameter/2,QPointF(e->x(),e->y()))){
        parent->disconnectAll();
        w->setScene(next);
        emit GameStart(level,warFog);
    }
    return;
}
