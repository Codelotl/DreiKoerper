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
//const double dt=1;

class Gravk { /*Klasse um Gravitationskörper zu initialisieren*/
public:
    double posx[2] , posy[2] , velx[2], vely[2];    /*x,y -Vektoren um die Position in 2D anzugeben, velx,vely bietet Platz für
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
    double Forcex(Gravk** body, int bcount); //Berechnet Kraft in x-Richtung
    double Forcey(Gravk** body, int bcount);  //Berechnet Kraft in y-Richtung
    void setVel(Gravk** body, int bcount, double dt); //Berechnet Geschwindigkeit nach Euler
    void newPos(double dt); //Berechnet Ort nach Euler
    void firstPos(Gravk** body, int bcount, double dt); //Erste Iteration, um Verlet anwenden zu können
    void verPos(Gravk** body, int bcount,double dt); //Berechnet Ort nach Verlet
    void print(); //Gibt Startparamter/n-1 Ort aus
};


#endif //DREIKOERPER_GRAVK_H
