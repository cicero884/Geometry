#include "select_minion_button.h"

extern QTimer *DemoClock;
extern QMap<QString,QColor> Colors;
extern MainWindow *w;

QVector<QString> selected_count;

select_minion_button::select_minion_button(QPointF _position,QSize _diameter,int _font,scene *_parent,scene *_next,QString _text,unit *_exhibit)
    :scene_button(_position,_diameter,_font,_parent,_next,_text),exhibit(_exhibit){
    image.push_back(P_slot(position,diameter));
    selected_color=new QGraphicsColorizeEffect;
    selected_color->setColor(Colors["l_gray"]);
    (*image.rbegin())->setGraphicsEffect(selected_color);
    parent->addObject(exhibit);
}
void select_minion_button::pressedThere(QMouseEvent *e){
    if(RecPointCompare(position,diameter/2,QPointF(e->x(),e->y()))){
        if(e->button()==Qt::LeftButton){
            if(selected){
                selected_color->setColor(Colors["l_gray"]);
                for(int i=0;i<selected_count.size();++i){
                    if(selected_count.at(i)==button_name){
                        selected_count.remove(i);
                        break;
                    }
                }
                selected=false;
                disconnect(DemoClock,SIGNAL(timeout()),exhibit,SLOT(demo()));
            }
            else if(selected_count.size()<4){
                selected_color->setColor(Colors["red"]);
                selected_count.push_back(button_name);
                selected=true;
                connect(DemoClock,SIGNAL(timeout()),exhibit,SLOT(demo()));
            }
        }
        else{
            parent->disconnectAll();
            w->setScene(next);
            next->connectAll();
        }
    }
    return;
}
