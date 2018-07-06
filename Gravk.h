//
// Created by Max Thinkpad on 02.07.2018.
//

#ifndef DREIKOERPER_GRAVK_H
#define DREIKOERPER_GRAVK_H

#include <cstdio>
#include <vector>
#include <cmath>
const double G= 6.674e-11;
class Gravk { /*Klasse um Gravitationskörper zu initialisieren*/
public:
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
    double distance(Gravk a, int t) {return sqrt(pow((x[t] - a.getPosx(t)),2)+pow((y[t]-a.getPosy(t)),2));} //Berechnet Abstand von zwei Körpern zur Zeit t
    double forcex(Gravk a, int t) {return (mass*a.getMass()*(x[t]-a.getPosx(t)))/(G*(this->distance(a,t)));}
    double forcey(Gravk a, int t) {return (mass*a.getMass()*(y[t]-a.getPosy(t)))/(G*(this->distance(a,t)));}
    void newVel(Gravk a, int t) {vx[t]=vx[t-1]+(this->forcex(a,t)*t)/(mass), vy[t]=vy[t-1]+(this->forcey(a,t)*t)/(mass);}
    void velAdd(Gravk a,int t) {vx[t]+=vx[t]+(this->forcex(a,t)*t)/(mass), vy[t]+=vy[t]+(this->forcey(a,t)*t)/(mass);}
    double test(int t) {return getMass();}
};


#endif //DREIKOERPER_GRAVK_H
