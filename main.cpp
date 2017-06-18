#include"main.h"

QTimer *DemoClock;
GameHoder *GM;
MainWindow *w;

QVector<QFont> Fonts;
QMap<QString,QColor> Colors;
QMap<QString,unit*> Minions;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    initialize();
    initialScene();
    w->show();
    return a.exec();
}

void initialize(){
    Fonts.push_back(QFont("Courier",70,QFont::Black,true));
    Fonts.push_back(QFont("Courier",40,QFont::Bold,true));
    Fonts.push_back(QFont("Helvetica",20,QFont::Normal,true));
    Colors["white"]=QColor(255,255,255);
    Colors["black"]=QColor(0,0,0);
    Colors["d_gray"]=QColor(128,128,128);
    Colors["l_gray"]=QColor(179,179,179);
    Colors["ll_gray"]=QColor(200,200,200);
    Colors["blue"]=QColor(128,212,255);
    Colors["red"]=QColor(255,128,128);
    Colors["yellow"]=QColor(255,255,128);
    Colors["green"]=QColor(159,255,128);

    DemoClock=new QTimer;
    DemoClock->start(50);
    GM=new GameHoder();
    return;
}

void initialScene(){
    w=new MainWindow;

    Minions["Tank"]=new tank(QPointF(),QSize(),0);
    Minions["Smasher"]=new smasher(QPointF(),QSize(),0);
    Minions["Protector"]=new protector(QPointF(),QSize(),0);

    scene *MainMenu=new scene();
    scene *selectGame=new scene();
    scene *selectMinion=new scene();

    MainMenu->addObject(new scene_button(QPointF(800,300),QSize(475,150),0,MainMenu,MainMenu,"Geometry"));
    MainMenu->addButton(new scene_button(QPointF(800,450),QSize(200,100),1,MainMenu,selectGame,"START!"));
    MainMenu->addButton(new scene_button(QPointF(800,550),QSize(200,100),1,MainMenu,selectMinion,"Cards"));
    MainMenu->addObject(new tank(QPointF(200,400),QSize(100,100),1));
    MainMenu->addObject(new tank(QPointF(1200,600),QSize(100,100),1));
    w->setScene(MainMenu);
    MainMenu->connectAll();
    //selectGame->addObject(exit);

    selectGame->addButton(new select_game_button(QPointF(300,300),QSize(300,50),1,selectGame,"Test",0,0));
    selectGame->addButton(new select_game_button(QPointF(300,350),QSize(300,50),1,selectGame,"Test(Fog)",1,1));

    selectGame->addButton(new scene_button(QPointF(1300,50),QSize(90,50),2,selectGame,MainMenu,"BACK"));
    //normal?

    {
        int x=100,y=300;
        scene *customizedMinion;
        for(QMap<QString,unit*>::iterator iter=Minions.begin();iter!=Minions.end();++iter){
            customizedMinion=new scene;
            x+=200;
            selectMinion->addButton(new select_minion_button(QPointF(x,y),QSize(180,180),2,selectMinion,customizedMinion,iter.key(),iter.value()->summon(QPointF(x,y),QSize(80,80),1)));

            customizedMinion->addObject(iter.value()->summon(QPointF(300,300),QSize(150,150),1));
            customizedMinion->addObject(new begin());
            customizedMinion->addButton(new scene_button(QPointF(1300,50),QSize(90,30),2,customizedMinion,selectMinion,"BACK"));
            if(x>=1300){
                x=100;
                y+=200;
            }
        }
    }
    selectMinion->addButton(new scene_button(QPointF(1300,50),QSize(90,30),2,selectMinion,MainMenu,"BACK"));
    return;
}
