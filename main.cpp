#include <cstdio>
#include <cmath>
#include "Gravk.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
double mjup=1.899e27,merde=5.972e24,msun=1.989e30,mmond=7.349e22;
double rjup=778.36e6, rerde=149598022.96e3,rmond=383397.7916e3;
double vjup=13070, verde=29.78e3,vmond=	1.023e3;
int main() {
    Gravk a, b, c;
    printf("Dies ist eine Bewegungssimulation für mehrere Köerper, die durch ihre Schwerkraft beeinflusst werden. \n Geben Sie bitte die Anzahl der Objekte ein. Vorgefertigte Systeme: \n 0: 3 Sonnenmassen \n 1: Sonne-Erde-Mond \n 2: no function \n");
    int bcount = 0;
    scanf("%i", &bcount); //Anzahl der Körper wird eingelesen
    if (bcount == 0) {
        bcount = 3;
        Gravk *body[bcount] = {&a, &b, &c}; //Hier sind die Körpernamen durch ein Array durchzählbar
        (*body[0]).setAll(-rjup, rjup, 0, -vjup, msun); //hier befinden sich die startparameter wie in aufgabe c)
        b.setAll(0, rjup, 0, vjup, msun);
        c.setAll(rjup, 0, vjup, 0, msun);
        a.print(0), b.print(0), c.print(0); //unsere printfunktion um die startwerte in die Konsole auszugeben
        std::ofstream dat;
        dat.open("shootout.txt");
        for (unsigned i = 1; i < 10000000; i++) {
            for (unsigned k = 0; k < bcount; k++) {
                (*body[k]).setVel(body, bcount);
                (*body[k]).newPos(1);
            }
            if (i % 100 == 0) {
                dat << a.getPosx(1) << " " << a.getPosy(1) << " " << b.getPosx(1) << " " << b.getPosy(1) << " "
                    << c.getPosx(1) << " " << c.getPosy(1) << endl;
                //  dat << a.getPosx(i) << a.getPosy(i) << b.getPosx(i) << b.getPosy(i) << c.getPosx(i) << c.getPosy(i)  << endl;
            }


        }
        dat.close();
        }
    if (bcount == 1) {
        bcount = 3;
        Gravk *body[bcount] = {&a, &b, &c}; //Hier wieder das array aus Körpern
        (*body[0]).setAll(0,0, 0,0, msun); //Startbedingungen hoffentlich wie im sonne erde mond system
        b.setAll(rerde,0, 0,-verde,merde);
        c.setAll(rerde-rmond,0,0,vmond, mmond); //mond startet zwischen erde und sonne
        a.print(0),b.print(0),c.print(0);
        a.firstPos(body,bcount); //hier werden die ersten positionen nach dem Verlet-Algorithmus berechnet
        b.firstPos(body,bcount);
        c.firstPos(body,bcount);
        std::ofstream data;
        data.open("sem.txt");

        for (unsigned i = 1; i < 10000000; i++) { //in der Schleife wird dann mit der Pos.bestimmung nach Verlet gearbeitet
            for (unsigned k = 0; k < bcount; k++) {
                (*body[k]).verPos(body, bcount);
            }
            if (i % 100 == 0) {
                data << a.getPosx(2) << " " << a.getPosy(2) << " " << b.getPosx(2) << " " << b.getPosy(2) << " " << c.getPosx(2) << " " << c.getPosy(2) << endl;
                //  dat << a.getPosx(i) << a.getPosy(i) << b.getPosx(i) << b.getPosy(i) << c.getPosx(i) << c.getPosy(i)  << endl;
            }


        }data.close();
    }

/*if (bcount==2) {
        Gravk body[bcount];
        int i;
        for (i; i<bcount; i++) {
            printf("Anfangsort x, Anfangsort y, Anfangsgeschwindigkeit x, Anfangsgeschwindigkeit y und Masse für Körper %i mit Leerzeichen getrennt eingeben", i);
            scanf(""); //hier müssen noch Anfangsbedingungen eingelesen werden
            body[i].setAll(0,0,0,0,0); //hier dann BEdingungen rein

        }
    }*/
    //std::vector<double> v (100), u={3.844e+1,3.844e+1}, t={10e+10,10e+10}; //v (100) gibt vektor mit 100 null einträgen
    //v.push_back(2.0);
    //v.push_back(3.0);
    /*int i; //Füllte einst ein Array mit dem Alphabet
    for (i = 97; i < 97 + bcount; i++) {
        body[i - 97] = char(i);
    } */
    // cout << body[0] <<endl; gibt zur Kontrolle "a" aus
    /*cout << a.distance(b,time) << endl;
    cout << "Kraft in x" << a.forcex(b,time) << "Kraft in y" << a.forcey(b,time) << endl;
    //a.newVel(b,time);
    a.setVel(b,time,time);
    a.setVel(c,time,time);
    a.newPos(time);
    cout << "x=" << a.getPosx(time) << "y=" << a.getPosy(time) << endl;*/
    return 0;
}