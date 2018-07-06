#include <cstdio>
#include <cmath>
#include "Gravk.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
int main() {
    std::vector<double> v={0,0}, u={3.844e+2,3.844e+2}, t;
    double m1= 5.972e+24;
    double m2= 6.0e+10;
    int time=1;
    int time1=2;
    Gravk a;
    Gravk b;
    Gravk c;
    //v.push_back(2.0);
    //v.push_back(3.0);
    a.setAll(v,v,v,v,m1);
    b.setAll(u,u,v,v,m2);
    cout << a.getMass() << endl;
    cout << "X:" << a.getPosx(1) << "Y:" << a.getPosy(1) << endl;
    cout << "VX:" << a.getVelx(1) << "VY:" << a.getVely(1) << endl;
    cout << a.distance(b,time) << endl;
    cout << "Kraft in x" << a.forcex(b,time) << "Kraft in y" << a.forcey(b,time) << endl;
    a.newVel(b,time);
    cout << a.getVelx(time) << endl << a.getVely(time) << endl;
    cout << a.test(time);
    return 0;
}