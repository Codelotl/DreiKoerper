//
// Created by Max Thinkpad on 02.07.2018.
//
#include <cstdio>
#include <cmath>
#include "Gravk.h"
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;

    Gravk::Gravk(){
        x;
        y;
        vx;
        vy;
        mass = 1.0;
    } /*Konstruktor, für die oben genannten Werte wird im Gravk.cpp definiert*/
    Gravk::~Gravk(){

    };
    void Gravk::setAll(double a, double b, double c, double d, double h){ //Set Funktion um einem Körper Werte zuzuweisen
        x.push_back(a);
        y.push_back(b);
        vx.push_back(c);
        vy.push_back(d);
        mass=h;
    }
    double Gravk::getMass(){
        return mass;
    }
    double Gravk::getPosx(unsigned t) { //Funktion um X-Wert zur Zeit t zu kriegen
        return x.at(t);
    }
    double Gravk::getPosy(unsigned t){ //Funktion um Y-Wert zur Zeit t zu kriegen
        return y.at(t);
    }
    double Gravk::getVelx(unsigned t){ //Funktion um X-Geschw. zur Zeit t zu kriegen
        return vx.at(t);
    }
    double Gravk::getVely(unsigned t){ //Funktion um Y-Geschw. zur Zeit t zu kriegen
        return vy.at(t);
    }
    double Gravk::distance(Gravk a, unsigned t){ //Berechnet Abstand von zwei Körpern zur Zeit t
        return sqrt(pow((getPosx(t) - a.getPosx(t)),2)+pow((getPosy(t)-a.getPosy(t)),2));
    }
    double Gravk::Forcex(Gravk **body, unsigned t, int bcount) {
        double force=0;
        for(int i=0;i<bcount;i++){
            double dis=distance((*body[i]),t-1);
            if (dis>1000.0)
                force = force+(G*mass*(*body[i]).getMass()*(getPosx(t-1)-(*body[i]).getPosx(t-1)))/pow(dis,3);
        }
        return force;
    }
    double Gravk::Forcey(Gravk **body, unsigned t, int bcount) {
        int i;
        double force=0;
        for(i=0;i<bcount;i++){
            double dis=distance((*body[i]),t-1);
            if (dis>1000.0)
                force = force+(G*mass*(*body[i]).getMass()*(getPosy(t-1)-(*body[i]).getPosy(t-1)))/pow(dis,3);
        }
        return force;
    }
    void Gravk::setVel(Gravk **body, unsigned t, int bcount) {
        vx.push_back(vx.at(t-1)+((-1)*this->Forcex(body,t,bcount)*dt)/(mass));
        vy.push_back(vy.at(t-1)+((-1)*this->Forcey(body,t,bcount)*dt)/(mass));
    } //bcount anzahl der körper -1
    void Gravk::newPos(unsigned t) {
        x.push_back(x.at(t-1)+vx.at(t)*dt); //ACHTUNG hier wird immer von Zeitschritten von einer sek ausgegangen
        y.push_back(y.at(t-1)+vy.at(t)*dt);}
    //double Gravk::test(int t) {return mass;}
void Gravk::verPos(Gravk **body, unsigned t, int bcount){
        x.push_back(2*(x.at(t))-x.at(t-1)+Forcex(body,t,bcount)/(mass)*pow(dt,2));
        y.push_back(2*(y.at(t))-y.at(t-1)+Forcey(body,t,bcount)/(mass)*pow(dt,2));
    }
    void Gravk::print(int t) { cout << "Koerper mit m = " << this->getMass() << ", v= (" << this->getVelx(t) << " , " << this->getVely(t) <<")"<< "; r= (" << this->getPosx(t) <<" , " << getPosy(t) <<")"<< endl;}

void Gravk::firstPos(Gravk **body, int bcount) {
    x.push_back(x.at(0)+vx.at(0)*dt+0.5*Forcex(body,1,bcount)/(mass)*pow(dt,2));
    y.push_back(y.at(0)+vy.at(0)*dt+0.5*Forcex(body,1,bcount)/(mass)*pow(dt,2));
}


