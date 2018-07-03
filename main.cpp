#include <stdio.h>
#include <math.h>
#include "Gravk.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
int main() {
    std::vector<double> v, u = {1,2}, t;
    double m= 1.0;
    double m1, x1;
    Gravk a;
    a.setAll(v,v,v,v,m);
    v.push_back(2.0);
    v.push_back(3.0);
    a.setAll(v,v,v,v,m);
    m1 = a.getMass();
    cout << m1 << endl;
    cout << "X:" << a.getPosx(1) << "Y:" << a.getPosy(1) << endl;
    cout << "VX:" << a.getVelx(1) << "VY:" << a.getVely(1) << endl;
    return 0;
}