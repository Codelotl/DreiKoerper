//
// Created by Max Thinkpad on 02.07.2018.
//

#ifndef DREIKOERPER_GRAVK_H
#define DREIKOERPER_GRAVK_H

#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;
const double G= 6.674e-11;
const double dt=5;

class Gravk { /*Klasse um Gravitationskörper zu initialisieren*/
public:
    double posx[3] , posy[3] , velx[3], vely[3];    /*x,y -Vektoren um die Position in 2D anzugeben, vx,vy bietet Platz für
                                                * die Geschwindigkeiten*/
    double mass;                                /*mass gibt die Masse des jeweiligen Körpers an*/
    Gravk(); /*Konstruktor, für die oben genannten Werte wird im Gravk.cpp definiert*/
    ~Gravk();
    void setAll(double a, double b, double c,double d, double h); //Set Funktion um einem Körper Werte zuzuweisen
    double getMass();
    double getPosx(unsigned t); //Funktion um X-Wert zur Zeit t zu kriegen
    double getPosy(unsigned t); //Funktion um Y-Wert zur Zeit t zu kriegen
    double getVelx(unsigned t); //Funktion um X-Geschw. zur Zeit t zu kriegen
    double getVely(unsigned t); //Funktion um Y-Geschw. zur Zeit t zu kriegen
    double distance(Gravk a); //Berechnet Abstand von zwei Körpern zur Zeit t
    double Forcex(Gravk** body, int bcount);
    double Forcey(Gravk** body, int bcount);
    void setVel(Gravk** body, int bcount);
    void newPos(unsigned t);
    void firstPos(Gravk** body, int bcount);
    void verPos(Gravk** body, int bcount);
    void print(int t);
};


#endif //DREIKOERPER_GRAVK_H
