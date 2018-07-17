#include <cstdio>
#include <cmath>
#include "Gravk.h"
#include <iostream> // \201 ü, \204 ä, \224 ö
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
    //Startmenü
    printf("Dies ist eine Bewegungssimulation f\201r mehrere K\224rper, die durch ihre Schwerkraft beeinflusst werden. \nGeben Sie bitte die Anzahl der K\224rper ein (max. 26). 0 f\201r vorgefertigte Systeme: \n");
    int bcount = 0;
    scanf("%i", &bcount); //Anzahl der Körper wird eingelesen

    //Vorgefertigte Systeme
    if (bcount == 0) {
        printf("Vorgefertigte Systeme: \n 0: 3 Sonnenmassen \n 1: Sonne-Erde-Mond \n 2: Erde und Mond \n");
        int fall = 0;
        scanf("%i", &fall); //Einlesen von Fall

        //3 Sonnenmassen
        if (fall == 0) {
            bcount = 3;
            Gravk *body[bcount] = {&a, &b, &c}; //Hier sind die Körpernamen durch ein Array durchzählbar
            (*body[0]).setAll(-rjup, rjup, 0, -vjup, msun); //hier befinden sich die startparameter wie in aufgabe c)
            b.setAll(0, rjup, 0, vjup, msun);
            c.setAll(rjup, 0, vjup, 0, msun);
            a.print(), b.print(), c.print(); //unsere printfunktion um die startwerte in die Konsole auszugeben
            printf("Bitte ein Verfahren ausw\204hlen, 0 f\201r Euler-Verfahren, 1 f\201r Verlet-Algorithmus:\n");
            int typ;
            scanf("%i", &typ);
            unsigned m, s, d; //maximale Iteration, Schrittweite, Druckhäufigkeit
            printf("Anzahl Iterationen, Schrittweite in Sekunden und jeder wie vielte Wert in die Ausgabedatei geschrieben werden soll mit Leerzeichen getrennt angeben:\n");
            scanf("%i %i %i", &m, &s, &d);
            a.firstPos(body, bcount, s); //hier werden die ersten positionen nach dem Verlet-Algorithmus berechnet
            b.firstPos(body, bcount, s); //Dies kann unnötig geschehen
            c.firstPos(body, bcount, s);
            std::ofstream dat;
            dat.open("3Sonnen.txt");
            for (unsigned i = 1; i < m; i++) {
                for (unsigned k = 0; k < bcount; k++) {
                    if (typ == 0) {
                        (*body[k]).setVel(body, bcount, s);
                        (*body[k]).newPos(s);
                    } else if (typ == 1) {
                        (*body[k]).verPos(body, bcount, s);
                    } else {
                        printf("Aua, falsche Parameter? Programm beendet");
                        return 0;
                    }
                }
                if (i % d == 0) {
                    dat << a.getPosx(1) << " " << a.getPosy(1) << " " << b.getPosx(1) << " " << b.getPosy(1) << " "
                        << c.getPosx(1) << " " << c.getPosy(1) << endl;
                }


            }
            dat.close();
        }

        //Sonne-Erde-Mond
        if (fall == 1) {
            bcount = 3;
            Gravk *body[bcount] = {&a, &b, &c}; //Hier wieder das array aus Körpern
            (*body[0]).setAll(0, 0, 0, 0, msun); //Startbedingungen hoffentlich wie im sonne erde mond system
            b.setAll(rerde, 0, 0, -verde, merde);
            c.setAll(rerde - rmond, 0, 0, -verde + vmond, mmond); //mond startet zwischen erde und sonne
            a.print(), b.print(), c.print();
            printf("Bitte ein Verfahren ausw\204hlen, 0 f\201r Euler-Verfahren, 1 f\201r Verlet-Algorithmus: \n");
            int typ;
            scanf("%i", &typ);
            unsigned m, s, d;
            printf("Anzahl Iterationen, Schrittweite in Sekunden und jeder wie vielte Wert in die Ausgabedatei geschrieben werden soll mit Leerzeichen getrennt angeben:\n");
            scanf("%i %i %i", &m, &s, &d);
            a.firstPos(body, bcount, s); //hier werden die ersten positionen nach dem Verlet-Algorithmus berechnet
            b.firstPos(body, bcount, s); //Dies kann unnötig geschehen
            c.firstPos(body, bcount, s);
            std::ofstream data;
            data.open("SonneErdeMond.txt");
            for (unsigned i = 1; i < m; i++) {
                for (unsigned k = 0; k < bcount; k++) {
                    if (typ == 0) {
                        (*body[k]).setVel(body, bcount, s);
                        (*body[k]).newPos(s);
                    } else if (typ == 1) {
                        (*body[k]).verPos(body, bcount, s);
                    } else {
                        printf("Aua, falsche Parameter? Programm beendet");
                        return 0;
                    }
                }
                if (i % d == 0) {
                    data << a.getPosx(1) << " " << a.getPosy(1) << " " << b.getPosx(1) << " " << b.getPosy(1) << " "
                         << c.getPosx(1) << " " << c.getPosy(1) << endl;
                }
            }
            data.close();
        }

        //Erde und Mond
        if (fall == 2) {
            bcount = 2;
            Gravk *body[bcount] = {&a, &b}; //Hier sind die Körpernamen durch ein Array durchzählbar
            a.setAll(0, 0, 0, 0, merde); //hier befinden sich die startparameter wie in aufgabe c)
            b.setAll(rmond, 0, 0, vmond, mmond);
            a.print(), b.print(); //unsere printfunktion um die startwerte in die Konsole auszugeben
            printf("Bitte ein Verfahren ausw\204hlen, 0 f\201r Euler-Verfahren, 1 f\201r Verlet-Algorithmus: \n");
            int typ;
            scanf("%i", &typ);
            unsigned m, s, d;
            printf("Anzahl Iterationen, Schrittweite in Sekunden und jeder wie vielte Wert in die Ausgabedatei geschrieben werden soll mit Leerzeichen getrennt angeben:\n");
            scanf("%i %i %i", &m, &s, &d);
            a.firstPos(body, bcount, s); //hier werden die ersten positionen nach dem Verlet-Algorithmus berechnet
            b.firstPos(body, bcount, s); //Dies kann unnötig geschehen
            std::ofstream dat;
            dat.open("ErdeMond.txt");
            for (unsigned i = 1; i < m; i++) {
                for (unsigned k = 0; k < bcount; k++) {
                    if (typ == 0) {
                        (*body[k]).setVel(body, bcount, s);
                        (*body[k]).newPos(s);
                    } else if (typ == 1) {
                        (*body[k]).verPos(body, bcount, s);
                    } else {
                        printf("Aua, falsche Parameter? Programm beendet");
                        return 0;
                    }
                }
                if (i % d == 0) {
                    dat << a.getPosx(1) << " " << a.getPosy(1) << " " << b.getPosx(1) << " " << b.getPosy(1) << " "
                        << c.getPosx(1) << " " << c.getPosy(1) << endl;
                }
            }
            dat.close();
        }

    } else if (bcount < 27) {
        //Hier n-Körpereingabe
        Gravk a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
        Gravk *body[bcount] = {&a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &o, &p, &q, &r, &s, &t, &u, &v, &w, &x, &y, &z};
        printf("Bitte eine Daten.txt Datei mit erster Spalte x-Positionen, zweiter Spalte y-Positionen, dritter Spalte x-Geschwindigkeiten und vierter Spalte y-Geschwindigkeiten und f\201nfter Spalte Masse (in SI-Einheiten) in den Ordner der Dreikoerper.exe anlegen. Beliebige Eingabe zum Fortfahren t\204tigen.\n");
        std::string puffer;
        scanf("%i",&puffer);
        std::ifstream einlesen;
        einlesen.open("Daten.txt");
        std::string line;
        int bi;
        double xa,ya,vxa,vya,mobj;
        for (bi=0; bi<bcount; bi++) {
            std::getline(einlesen,line);
         //   sscanf(line,"&i, &i, &i, &i, &i", &xa, &ya, &vxa, &vya, &mobj);
            (*body[bi]).setAll(xa, ya, vxa, vya, mobj);
        }
        printf("Bitte ein Verfahren ausw\204hlen, 0 f\201r Euler-Verfahren, 1 f\201r Verlet-Algorithmus: \n");
        int typ;
        scanf("%i", &typ);
        unsigned max, sch, dru;
        printf("Anzahl Iterationen, Schrittweite in Sekunden und jeder wie vielte Wert in die Ausgabedatei geschrieben werden soll mit Leerzeichen getrennt angeben:\n");
        scanf("%i %i %i", &max, &sch, &dru);
        for (bi=0; bi<bcount; bi++) {
            (*body[bi]).firstPos(body, bcount, sch); //hier werden die ersten positionen nach dem Verlet-Algorithmus berechne. Dies kann unnötig geschehen
        }
        std::ofstream dat;
        dat.open("ErdeMond.txt");
        for (unsigned i = 1; i < max; i++) {
            for (unsigned k = 0; k < bcount; k++) {
                if (typ == 0) {
                    (*body[k]).setVel(body, bcount, sch);
                    (*body[k]).newPos(sch);
                } else if (typ == 1) {
                    (*body[k]).verPos(body, bcount, sch);
                } else {
                    printf("Aua, falsche Parameter? Programm beendet");
                    return 0;
                }
            }
            if (i % dru == 0) {
                dat << a.getPosx(1) << " " << a.getPosy(1) << " " << b.getPosx(1) << " " << b.getPosy(1) << " "
                    << c.getPosx(1) << " " << c.getPosy(1) << endl;
            }
        }
        dat.close();
        // Falls mehr als 26 Körper
    } else {
        printf("Aua, falsche Parameter? Programm beendet");
        return 0;
    }
    printf("Programm beendet");
    return 1;
}
