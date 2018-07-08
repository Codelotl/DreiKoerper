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
const double dt=1.0;

class Gravk { /*Klasse um Gravitationskörper zu initialisieren*/
public:
    std::vector<double> x , y , vx, vy;    /*x,y -Vektoren um die Position in 2D anzugeben, vx,vy bietet Platz für
                                                * die Geschwindigkeiten*/
    double mass;                                /*mass gibt die Masse des jeweiligen Körpers an*/
    Gravk() {x; y ; vx; vy; mass = 1.0;} /*Konstruktor, für die oben genannten Werte wird im Gravk.cpp definiert*/
    ~Gravk() {;}
    void setAll(double a, double b, double c,double d, double h) {x.push_back(a) ; y.push_back(b); vx.push_back(c); vy.push_back(d); mass=h;} //Set Funktion um einem Körper Werte zuzuweisen
    double getMass() {return mass;}
    double getPosx(unsigned t) {return x.at(t);} //Funktion um X-Wert zur Zeit t zu kriegen
    double getPosy(unsigned t) {return y.at(t);} //Funktion um Y-Wert zur Zeit t zu kriegen
    double getVelx(unsigned t) {return vx.at(t);} //Funktion um X-Geschw. zur Zeit t zu kriegen
    double getVely(unsigned t) {return vy.at(t);} //Funktion um Y-Geschw. zur Zeit t zu kriegen
    double distance(Gravk a, int t) {return sqrt(pow((getPosx(t) - a.getPosx(t)),2)+pow((getPosy(t)-a.getPosy(t)),2));} //Berechnet Abstand von zwei Körpern zur Zeit t
    double forcex(Gravk a, int t) {return (G*mass*a.getMass()*(getPosx(t)-a.getPosx(t)))/pow(distance(a,t),3);}
    double forcey(Gravk a, int t) {return (G*mass*a.getMass()*(getPosy(t)-a.getPosy(t)))/pow(distance(a,t),3);}
    void newVel(Gravk a, int t) {vx[t]=vx[t-1]+(this->forcex(a,t)*dt)/(mass), vy[t]=vy[t-1]+(this->forcey(a,t)*dt)/(mass);}
    void velAdd(Gravk a, int t) {vx.at(t)+=vx.at(t)+(forcex(a,t)*dt)/(mass), vy.at(t)+=vy.at(t)+(forcey(a,t)*dt)/(mass);}
    void setVel(Gravk a, int t, int bcount) {vx[t]+=vx[t]+(vx[t-1]/bcount)+(this->forcex(a,t)*dt)/(mass),vy[t]+=vy[t]+(vy[t-1]/bcount)+(this->forcey(a,t)*dt)/(mass);} //bcount anzahl der körper -1
    void newPos(int t) {x.at(t)+=x.at(t-1)+vx.at(t),y.at(t)+=y.at(t-1)+vy.at(t)*t;}
    double test(int t) {return mass;}
    void print(int t) { cout << "Körper mit m = " << this->getMass() << ", v= (" << this->getVelx(t) << " , " << this->getVely(t) <<")"<< "; r= (" << this->getPosx(t) <<" , " << getPosy(t) <<")"<< endl;}
};


#endif //DREIKOERPER_GRAVK_H
