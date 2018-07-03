//
// Created by Max Thinkpad on 02.07.2018.
//

#ifndef DREIKOERPER_GRAVK_H
#define DREIKOERPER_GRAVK_H

#include <cstdio>
#include <vector>

class Gravk {
public:       /*Klasse um Gravitationskörper zu initialisieren*/
    std::vector<double> x, y, vx, vy;    /*x,y,z-Vektoren um die Position in 3D anzugeben, vx,vy,vz bietet Platz für
                                                * die Geschwindigkeiten*/
    double mass;                                /*mass gibt die Masse des jeweiligen Körpers an*/
    Gravk() {std::vector<double> a = {0}; std::vector<double> b = {0}; std::vector<double> c = {0}; std::vector<double> d = {0};
            double h= 1.0;} /*Konstruktor, für die oben genannten Werte wird im Gravk.cpp definiert*/
    void setAll (std::vector<double> a, std::vector<double> b, std::vector<double> c, std::vector<double> d, double h)
                 {x=a; y=b; vx=c; vy=d; mass=h;} //Set Funktion um einem Körper Werte zuzuweisen
double getMass() {return mass;}
double getPosx(int t) {return x[t];} //Funktion um X-Wert zur Zeit t zu kriegen
double getPosy(int t) {return y[t];} //Funktion um Y-Wert zur Zeit t zu kriegen
double getVelx(int t) {return vx[t];} //Funktion um X-Geschw. zur Zeit t zu kriegen
double getVely(int t) {return vy[t];} //Funktion um Y-Geschw. zur Zeit t zu kriegen
};


#endif //DREIKOERPER_GRAVK_H
