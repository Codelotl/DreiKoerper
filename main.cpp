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
    Gravk a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z; //einmal alle 26 möglichen Graviationskörper festlegen, per Schleife nur schwerer umsetzbar
    //Startmenü
    cout<<"//=====================================================================\\\\"<<endl
        <<"||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||"<<endl
        <<"||~~~~~~~~~~~~~~~ Simulation f\201r Gravitations Systeme ~~~~~~~~~~~~~~~~~||"<<endl
        <<"||~~~~~~~~~ (C) Timo G\224hring & Maximilian Jaffke. Version 1.0 ~~~~~~~~~||"<<endl
        <<"||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||"<<endl
        <<"\\\\=====================================================================//"<<endl;
    printf("Dies ist eine Bewegungssimulation f\201r mehrere K\224rper, die durch ihre Schwerkraft beeinflusst werden. \nGeben Sie bitte die Anzahl der K\224rper ein (max. 26). 0 f\201r vorgefertigte Systeme: \n");
    int bcount = 0;
    scanf("%i", &bcount); //Anzahl der Körper wird eingelesen

    //Vorgefertigte Systeme
    if (bcount == 0) {
        printf("Vorgefertigte Systeme: \n 0: 3 Sonnenmassen \n 1: Sonne-Erde-Mond \n 2: Erde und Mond \n 3: 2 schwere 1 leichter K\224rper \n 4: Vierk\224rpersystem\n 5: Sonne-Merkur-Uranus\n 6: 3 chaotische K\224rper\n");
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
            unsigned m, d; //maximale Iteration, Schrittweite, Druckhäufigkeit
            double s;
            printf("Anzahl Iterationen, Schrittweite in Sekunden und jeder wie vielte Wert in die Ausgabedatei geschrieben werden soll mit Leerzeichen getrennt angeben:\n");
            scanf("%i %lf %i", &m, &s, &d);
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
            unsigned m, d; //maximale Iteration, Schrittweite, Druckhäufigkeit
            double s;
            printf("Anzahl Iterationen, Schrittweite in Sekunden und jeder wie vielte Wert in die Ausgabedatei geschrieben werden soll mit Leerzeichen getrennt angeben:\n");
            scanf("%i %lf %i", &m, &s, &d);
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
            unsigned m, d; //maximale Iteration, Schrittweite, Druckhäufigkeit
            double s;
            printf("Anzahl Iterationen, Schrittweite in Sekunden und jeder wie vielte Wert in die Ausgabedatei geschrieben werden soll mit Leerzeichen getrennt angeben:\n");
            scanf("%i %lf %i", &m, &s, &d);
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
                    dat << a.getPosx(1) << " " << a.getPosy(1) << " " << b.getPosx(1) << " " << b.getPosy(1) << endl;
                }
            }
            dat.close();
        }

        //3 chaotische Körper
        if (fall == 3) {
            bcount = 3;
            Gravk *body[bcount] = {&a, &b, &c}; //Hier sind die Körpernamen durch ein Array durchzählbar
            (*body[0]).setAll( -1e11, 0, 0, -9132.36, 6e30); //3 Sonnenmassen
            b.setAll(3e11, 0,0, 27397.080, 2e30 ); // 1 Sonnenmasse
            c.setAll(5e11, 0, 0, 47106.481, 1e27); // halbe Jupitermasse
            a.print(), b.print(), c.print(); //unsere printfunktion um die startwerte in die Konsole auszugeben
            printf("Bitte ein Verfahren ausw\204hlen, 0 f\201r Euler-Verfahren, 1 f\201r Verlet-Algorithmus:\n");
            int typ;
            scanf("%i", &typ);
            unsigned m, d; //maximale Iteration, Schrittweite, Druckhäufigkeit
            double s;
            printf("Anzahl Iterationen, Schrittweite in Sekunden und jeder wie vielte Wert in die Ausgabedatei geschrieben werden soll mit Leerzeichen getrennt angeben:\n");
            scanf("%i %lf %i", &m, &s, &d);
            a.firstPos(body, bcount, s); //hier werden die ersten positionen nach dem Verlet-Algorithmus berechnet
            b.firstPos(body, bcount, s); //Dies kann unnötig geschehen
            c.firstPos(body, bcount, s);
            std::ofstream dat;
            dat.open("2Schwer1Leicht.txt");
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

        //Vierkörpersystem
        if (fall == 4) {
            bcount = 4;
            Gravk *body[bcount] = {&a, &b, &c, &d}; //Hier sind die Körpernamen durch ein Array durchzählbar
            (*body[0]).setAll(4e9,0, 0,200,merde);
            b.setAll(0,4e9, -200,0,merde);
            c.setAll(-4e9,0,0,-200,merde);
            d.setAll(0,-4e9,200,0,merde);
            a.print(), b.print(), c.print(), d.print(); //unsere printfunktion um die startwerte in die Konsole auszugeben
            printf("Bitte ein Verfahren ausw\204hlen, 0 f\201r Euler-Verfahren, 1 f\201r Verlet-Algorithmus:\n");
            int typ;
            scanf("%i", &typ);
            unsigned m, d; //maximale Iteration, Schrittweite, Druckhäufigkeit
            double s;
            printf("Anzahl Iterationen, Schrittweite in Sekunden und jeder wie vielte Wert in die Ausgabedatei geschrieben werden soll mit Leerzeichen getrennt angeben:\n");
            scanf("%i %lf %i", &m, &s, &d);
            a.firstPos(body, bcount, s); //hier werden die ersten positionen nach dem Verlet-Algorithmus berechnet
            b.firstPos(body, bcount, s); //Dies kann unnötig geschehen
            c.firstPos(body, bcount, s);
            (*body[3]).firstPos(body, bcount, s);
            std::ofstream dat;
            dat.open("4Koerper.txt");
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
                    for (unsigned j = 0; j<bcount; j++) {
                        dat << (*body[j]).getPosx(1) << " " << (*body[j]).getPosy(1) << " " ;
                    }
                    dat << endl;
                }


            }
            dat.close();
        }

        // Sonne-Merkur-Uranus
        if (fall == 5) {
            bcount = 3;
            Gravk *body[bcount] = {&a, &b, &c}; //Hier sind die Körpernamen durch ein Array durchzählbar
            (*body[0]).setAll( 0, 0, 0, 0, msun);
            b.setAll(57909175e3, 0,0, 47872, 0.33e24 ); //Merkur
            c.setAll(2870972200e3, 0, 0, 6835, 1e27); //Uranus
            a.print(), b.print(), c.print(); //unsere printfunktion um die startwerte in die Konsole auszugeben
            printf("Bitte ein Verfahren ausw\204hlen, 0 f\201r Euler-Verfahren, 1 f\201r Verlet-Algorithmus:\n");
            int typ;
            scanf("%i", &typ);
            unsigned m, d; //maximale Iteration, Schrittweite, Druckhäufigkeit
            double s;
            printf("Anzahl Iterationen, Schrittweite in Sekunden und jeder wie vielte Wert in die Ausgabedatei geschrieben werden soll mit Leerzeichen getrennt angeben:\n");
            scanf("%i %lf %i", &m, &s, &d);
            a.firstPos(body, bcount, s); //hier werden die ersten positionen nach dem Verlet-Algorithmus berechnet
            b.firstPos(body, bcount, s); //Dies kann unnötig geschehen
            c.firstPos(body, bcount, s);
            std::ofstream dat;
            dat.open("SonneMerkurUranus.txt");
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

        //3 chaotische Körper
        if (fall == 6) {
            bcount = 3;
            Gravk *body[bcount] = {&a, &b, &c}; //Hier sind die Körpernamen durch ein Array durchzählbar
            (*body[0]).setAll( rerde, 0, 0, verde, msun);
            b.setAll(rerde, rerde, 0, -verde, msun);
            c.setAll(0, rerde, verde, 0, msun);
            a.print(), b.print(), c.print(); //unsere printfunktion um die startwerte in die Konsole auszugeben
            printf("Bitte ein Verfahren ausw\204hlen, 0 f\201r Euler-Verfahren, 1 f\201r Verlet-Algorithmus:\n");
            int typ;
            scanf("%i", &typ);
            unsigned m, d; //maximale Iteration, Schrittweite, Druckhäufigkeit
            double s;
            printf("Anzahl Iterationen, Schrittweite in Sekunden und jeder wie vielte Wert in die Ausgabedatei geschrieben werden soll mit Leerzeichen getrennt angeben:\n");
            scanf("%i %lf %i", &m, &s, &d);
            a.firstPos(body, bcount, s); //hier werden die ersten positionen nach dem Verlet-Algorithmus berechnet
            b.firstPos(body, bcount, s); //Dies kann unnötig geschehen
            c.firstPos(body, bcount, s);
            std::ofstream dat;
            dat.open("3Chaos.txt");
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
        Gravk *body[bcount] = {&a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &o, &p, &q, &r, &s, &t, &u, &v, &w, &x, &y, &z};
        printf("Bitte eine Daten.txt Datei mit erster Spalte x-Positionen, zweiter Spalte y-Positionen, dritter Spalte x-Geschwindigkeiten und vierter Spalte y-Geschwindigkeiten und f\201nfter Spalte Masse (in SI-Einheiten, ohne e oder E) in den Ordner der   Dreikoerper.exe anlegen. Beliebige Zahl eingeben zum Fortfahren.\n");
        int dummy;
        scanf("%i", &dummy); //Fügt Programmpause durch Warten auf Eingabe ein
        FILE *einlesen;
        einlesen=fopen("Daten.txt","r");
        int bi=0;
        double xa,ya,vxa,vya,mobj; //Hilfsvariablen
        while (fscanf(einlesen," %lf %lf %lf %lf %lf", &xa, &ya, &vxa, &vya, &mobj) != EOF) { //solange er nicht am Ende des Dokumentes liest er die Zeilen aus
            (*body[bi]).setAll(xa, ya, vxa, vya, mobj);
            bi=bi+1;
        }
        fclose(einlesen);
        printf("Bitte ein Verfahren ausw\204hlen, 0 f\201r Euler-Verfahren, 1 f\201r Verlet-Algorithmus: \n");
        int typ=0;
        scanf("%i", &typ);
        unsigned max, dru;
        double sch;
        printf("Anzahl Iterationen, Schrittweite in Sekunden und jeder wie vielte Wert in die Ausgabedatei geschrieben werden soll mit Leerzeichen getrennt angeben:\n");
        scanf("%i %lf %i", &max, &sch, &dru);
        for (bi=0; bi<bcount; bi++) {
            (*body[bi]).firstPos(body, bcount, sch); //hier werden die ersten positionen nach dem Verlet-Algorithmus berechne. Dies kann unnötig geschehen
        }
        std::ofstream dat;
        dat.open("Ausgabe.txt");
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
                for (unsigned j = 0; j<bcount; j++) {
                    dat << (*body[j]).getPosx(1) << " " << (*body[j]).getPosy(1) << " " ;
                }
                dat << endl;
            }
        }
        dat.close();
        // Falls mehr als 26 Körper
    }
    else if (bcount ==42){
        printf("Herzlichen Gl\201ckwunsch, du hast gerade ein Easter-Egg gefunden. Aber war es das Einzige?\n");
    }
    else if (bcount ==1337){
        printf("Nicht sicher ob Leet oder Molekularsimulation!?\n");
    }
    else {
        printf("Hilfe, bin ich eine Molekularsimulation? Programm beendet");
        return 0;
    }
    printf("Berechnung und Programm beendet");
    return 1;
}
