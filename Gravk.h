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
    Gravk(){
        x;
        y;
        vx;
        vy;
        mass = 1.0;
    } /*Konstruktor, für die oben genannten Werte wird im Gravk.cpp definiert*/
    ~Gravk(){
        ;
    }
    void setAll(double a, double b, double c,double d, double h){ //Set Funktion um einem Körper Werte zuzuweisen
        x.push_back(a);
        y.push_back(b);
        vx.push_back(c);
        vy.push_back(d);
        mass=h;
    }
    double getMass(){
        return mass;
    }
    double getPosx(unsigned t){ //Funktion um X-Wert zur Zeit t zu kriegen
        return x.at(t);
    }
    double getPosy(unsigned t){ //Funktion um Y-Wert zur Zeit t zu kriegen
        return y.at(t);
    }
    double getVelx(unsigned t){ //Funktion um X-Geschw. zur Zeit t zu kriegen
        return vx.at(t);
    }
    double getVely(unsigned t){ //Funktion um Y-Geschw. zur Zeit t zu kriegen
        return vy.at(t);
    }
    double distance(Gravk a, unsigned t){ //Berechnet Abstand von zwei Körpern zur Zeit t
        return sqrt(pow((getPosx(t) - a.getPosx(t)),2)+pow((getPosy(t)-a.getPosy(t)),2));
    }
    double forcex(Gravk a, unsigned t){
        return (G*mass*a.getMass()*(getPosx(t)-a.getPosx(t)))/pow(distance(a,t),3);
    }
    double forcey(Gravk a, unsigned t){
        return (G*mass*a.getMass()*(getPosy(t)-a.getPosy(t)))/pow(distance(a,t),3);
    }
    double Forcex(Gravk** body, unsigned t, int bcount){
        double force=0;
        for(int i=0;i<bcount;i++){
            double dis=distance((*body[i]),t-1);
            if (dis>1000.0)
        force = force+(G*mass*(*body[i]).getMass()*(getPosx(t-1)-(*body[i]).getPosx(t-1)))/pow(dis,3);
        }
        return force;
    }
    double Forcey(Gravk** body, unsigned t, int bcount){
        int i;
        double force=0;
        for(i=0;i<bcount;i++){
            double dis=distance((*body[i]),t-1);
            if (dis>1000.0)
            force = force+(G*mass*(*body[i]).getMass()*(getPosy(t-1)-(*body[i]).getPosy(t-1)))/pow(dis,3);
        }
        return force;
    }
    //void newVel(Gravk a, int t) {vx[t]=vx[t-1]+(this->forcex(a,t)*dt)/(mass), vy[t]=vy[t-1]+(this->forcey(a,t)*dt)/(mass);}
    //void velAdd(Gravk a, int t) {vx.at(t)+=vx.at(t)+(forcex(a,t)*dt)/(mass), vy.at(t)+=vy.at(t)+(forcey(a,t)*dt)/(mass);}
    void setVel(Gravk** body, unsigned t, int bcount){
        vx.push_back(vx.at(t-1)+(this->Forcex(body,t,bcount)*dt)/(mass));
        vy.push_back(vy.at(t-1)+(this->Forcey(body,t,bcount)*dt)/(mass));
    } //bcount anzahl der körper -1
    void newPos(unsigned t) {
        x.push_back(x.at(t-1)+vx.at(t)*1); //ACHTUNG hier wird immer von Zeitschritten von einer sek ausgegangen
        y.push_back(y.at(t-1)+vy.at(t)*1);}
    double test(int t) {return mass;}
    void print(int t) { cout << "Koerper mit m = " << this->getMass() << ", v= (" << this->getVelx(t) << " , " << this->getVely(t) <<")"<< "; r= (" << this->getPosx(t) <<" , " << getPosy(t) <<")"<< endl;}
};


#endif //DREIKOERPER_GRAVK_H
