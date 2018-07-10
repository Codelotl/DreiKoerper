#include <cstdio>
#include <cmath>
#include "Gravk.h"
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
double mjup=1.899e27;
int main() {
    Gravk a,b,c;
    printf("Dies ist eine Bewegungssimulation für mehrere Köerper, die durch ihre Schwerkraft beeinflusst werden. \n Geben Sie bitte die Anzahl der Objekte ein. Vorgefertigte Systeme: \n 0: 3 Jupitermassen \n 1: no function \n 2: no function \n");
    int bcount=0;
    scanf("%i",&bcount); //Anzahl der Körper wird eingelesen
    if (bcount==0) {
        bcount = 3;
       Gravk* body[bcount]={&a,&b,&c}; //Hier sollen die Körpernamen durch ein Array durchzählbar werden.
        (*body[0]).setAll(0,0,0,13000,mjup); //hier müssen noch Anfangsbedingungen rein. Ort: 0 0, v 0 13000 masse 1.899e27
        b.setAll(0,788e6,13000,0,mjup); //hier müssen noch Anfangsbedingungen rein. Ort: 0 788e6, v 13000 0 masse 1.899e27
        c.setAll(788e6,0,0,-13000,mjup); //hier müssen noch Anfangsbedingungen rein. Ort: 788e6 0, v 0 -13000 masse 1.899e27
        a.print(0),b.print(0),c.print(0);
    for(int i=1;i<10001;i++) {
        for(int k=0;k<bcount;k++) {
            (*body[k]).setVel(body, i, bcount);
            (*body[k]).newPos(i);
        }
    }
    }
a.print(10000);
    b.print(10000);
    c.print(10000);
   /* if (bcount>3) {
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