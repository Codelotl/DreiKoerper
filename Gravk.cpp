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

    //Konstruktor
    Gravk::Gravk(){
        posx;
        posy;
        velx;
        vely;
        mass = 1.0;
    }
    Gravk::~Gravk(){};

    //Set-Funktion, weißt allen Körpern Anfangswerte zu
    void Gravk::setAll(double a, double b, double c, double d, double h){ //Set Funktion um einem Körper Werte zuzuweisen
        posx[0]=a, posx[1]=a;
        posy[0]=b, posy[1]=b;
        velx[0]=c, velx[1]=c;
        vely[0]=d, vely[1]=d;
        mass=h;
    }

    //get-Funktionen für alle Parameter eines Körpers
    double Gravk::getMass(){
        return mass;
    }
    double Gravk::getPosx(unsigned t) { //Funktion um X-Wert zur Zeit t zu kriegen
        return posx[t];
    }
    double Gravk::getPosy(unsigned t){ //Funktion um Y-Wert zur Zeit t zu kriegen
        return posy[t];
    }
    double Gravk::getVelx(unsigned t){ //Funktion um X-Geschw. zur Zeit t zu kriegen
        return velx[t];
    }
    double Gravk::getVely(unsigned t){ //Funktion um Y-Geschw. zur Zeit t zu kriegen
        return vely[t];
    }

    //distance Funktion berechnet Abstand als Skalar
    double Gravk::distance(Gravk a){ //Berechnet Abstand von zwei Körpern
        return sqrt(pow((getPosx(1) - a.getPosx(1)),2)+pow((getPosy(1)-a.getPosy(1)),2)); //Euklidische Norm 2-dim
    }

    //Berechnet Kraft zwischen zwei Körpern mithilfe des Abstands in x und in y Richtung
    double Gravk::Forcex(Gravk **body, int bcount) {
        double force=0;
        for(int i=0;i<bcount;i++){ //Die einzelnen Kräfte zu den anderen Körpern werden per Scheleife addiert
            double dis=distance(*body[i]);
            if (dis>1000.0)
                force = force+(G*mass*(*body[i]).getMass()*(getPosx(1)-(*body[i]).getPosx(1)))/pow(dis,3); //Newtonsches Gravitationsgesetz
        }
        return force;
    }
    double Gravk::Forcey(Gravk **body, int bcount) {
        int i;
        double force=0;
        for(i=0;i<bcount;i++){
            double dis=distance(*body[i]);
            if (dis>1000.0)
                force = force+(G*mass*(*body[i]).getMass()*(getPosy(1)-(*body[i]).getPosy(1)))/pow(dis,3);
        }
        return force;
    }

    //Berechnungsmethoden der Bewegungen nach dem Euler-Verfahren
    void Gravk::setVel(Gravk **body, int bcount, unsigned dt) {
        velx[1]=velx[1]+((-1)*(this->Forcex(body,bcount)*dt)/(mass));
        vely[1]=vely[1]+((-1)*(this->Forcey(body,bcount)*dt)/(mass));
    } //bcount anzahl der körper -1
    void Gravk::newPos(unsigned dt) {
        posx[1]=(posx[1]+velx[1]*dt);
        posy[1]=(posy[1]+vely[1]*dt);}
    //double Gravk::test(int t) {return mass;}

    //Berechnung der neuen Position der Körper mit Verlet-Algorithmus
    void Gravk::verPos(Gravk **body, int bcount, unsigned dt){
        double help1=posx[1]; //speichert denn n-ten iterationsschritt
        double help2=posy[1];
        posx[1]=(2*(help1)-posx[0]+(-1)*Forcex(body,bcount)/(mass)*pow(dt,2)); //schreibt in den n+1-ten Iterationsschritt in den n-ten
        posy[1]=(2*(help2)-posy[0]+(-1)*Forcey(body,bcount)/(mass)*pow(dt,2));
        posx[0]=help1; //setzt den alten Iterationsschritt n-1 auf das neue n-1, also n.
        posy[0]=help2;
    }

    //Berechnung der ersten Position nach Verlet
    void Gravk::firstPos(Gravk **body, int bcount, unsigned dt) {
        posx[1]=(posx[0]+velx[0]*dt+(-0.5)*Forcex(body,bcount)/(mass)*pow(dt,2)); //x1=x0+vt+1/2at^2
        posy[1]=(posy[0]+vely[0]*dt+(-0.5)*Forcex(body,bcount)/(mass)*pow(dt,2));
    }

    //Print Funktion
    void Gravk::print() { cout << "Koerper mit m = " << this->getMass() << ", v= (" << this->getVelx(1) << " , " << this->getVely(1) <<")"<< "; r= (" << this->getPosx(1) <<" , " << getPosy(1) <<")"<< endl;}





