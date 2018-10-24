#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout, std::cin, std::endl;
using std::sin, std::exp;

double f(double x){
    return exp(sin(x)) - (x-1)*(x-6);
}

void wertetabelle(double a, double b, int N){
    cout << "x\t f(x) \n\--------------------------\n";
    double x;
    double h = (b-a)/N;

    for (int i = 0; i <= N; i++){
        x = a + i*h;
        cout << x << "\t " << f(x) << endl;
    }
}

double MPRegel(double a, double b, int N){
    double h = (b-a)/N;
    double res = 0;

    for(int i=1; i <= N; i++){
        res += f(a + (i-0.5)*h);
    }

    return (b-a) * res / N;
}

bool Einschluss(double fa, double fb){
    return (fa * fb < 0);
}

double Bisektion(double a, double b, double eps){

    if (!Einschluss(f(a),f(b))){
        cout << "Fehler: Kein Einschluss";
        return -1;
    }

    double m;
    while (b - a > eps){
        m = (b+a)/2;

        if (Einschluss(f(a),f(m))){
            b = m;
        } else {
            a = m;
        }
    }

    return m;
}

int main()
{
    //cout << "f(0) = " << f(0) << ", f(1) = " << f(1) << endl;

    /*double a,b;
    int N;

    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;

    cout << "N = ";
    cin >> N;
    cout << endl; */

    cout << std::setprecision(10);
    //wertetabelle(a,b,N)

    double nst1 = Bisektion(0,3,1E-15);
    double nst2 = Bisektion(3,7,1E-15);
    //cout << "NST 1: " << Bisektion(0,3,1E-10) << ", NST 2: " << Bisektion(3,7,1E-10);

    cout << "area = " << MPRegel(nst1,nst2,1000);
    double p=1,q=2;

    return 0;
}
