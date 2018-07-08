#include <cstdio>
#include <cmath>
#include "Gravk.h"
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
int main() {
    printf("Dies ist eine Bewegungssimulation für mehrere Köerper, die durch ihre Schwerkraft beeinflusst werden. \n Geben Sie bitte die Anzahl der Objekte ein. Vorgefertigte Systeme: \n 0: 3 Jupitermassen \n 1: no function \n 2: no function");
    int bcount=0;
    scanf("%i",bcount); //Anzhal der Körper wird eingelesen
    if (bcount==0) {
        bcount = 3;
        Gravk body[bcount]; //Hier sollen die Köpernamen durch ein Array durchzählbar werden.
        body[0].setAll(); //hier müssen noch Anfangsbedingungen rein. Ort: 0 0, v 0 13000 masse 1.899e27
        body[1].setAll(); //hier müssen noch Anfangsbedingungen rein. Ort: 0 788e6, v 13000 0 masse 1.899e27
        body[2].setAll(); //hier müssen noch Anfangsbedingungen rein. Ort: 788e6 0, v 0 -13000 masse 1.899e27
    }
    if (bcount>2) {
        Gravk body[bcount];
        int i;
        for (i; i<bcount; i++) {
            printf("Anfangsort x, Anfangsort y, Anfangsgeschwindigkeit x, Anfangsgeschwindigkeit y und Masse für Körper %i mit Leerzeichen getrennt eingeben", i);
            scanf(""); //hier müssen noch Anfangsbedingungen eingelesen werden
            body[i].setAll(); //hier dann BEdingungen rein

        }
    }
    std::vector<double> v (100), u={3.844e+1,3.844e+1}, t={10e+10,10e+10}; //v (100) gibt vektor mit 100 null einträgen
    double m1= 5.972e+24;
    double m2= 6.0e+24;
    int time=1;
    int time1=2;
    Gravk a;
    Gravk b;
    Gravk c;
    //v.push_back(2.0);
    //v.push_back(3.0);
    /*int i; //Füllte einst ein Array mit dem Alphabet
    for (i = 97; i < 97 + bcount; i++) {
        body[i - 97] = char(i);
    } */
    // cout << body[0] <<endl; gibt zur Kontrolle "a" aus
    a.setAll(v,v,v,v,m1);
    b.setAll(u,t,v,v,m2);
    c.setAll(t,u,v,v,m1);
    cout << a.getMass() << endl;
    cout << "X:" << a.getPosx(1) << "Y:" << a.getPosy(1) << endl;
    cout << "VX:" << a.getVelx(1) << "VY:" << a.getVely(1) << endl;
    cout << a.distance(b,time) << endl;
    cout << "Kraft in x" << a.forcex(b,time) << "Kraft in y" << a.forcey(b,time) << endl;
    //a.newVel(b,time);
    a.setVel(b,time,time);
    a.setVel(c,time,time);
    a.newPos(time);
    cout << "x=" << a.getPosx(time) << "y=" << a.getPosy(time) << endl;
    return 0;
}