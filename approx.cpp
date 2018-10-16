#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;

int main()
{
    double X, Tol;
    cout << "Enter real number X to approximate > ";
    cin >> X;

    cout << "Enter error tolerance > ";
    cin >> Tol;

    cout << endl;

    int Z,Znew,Zold,N,Nnew,Nold,a;
    double rnew,rold,r;

    r = X;

    Zold = 1; Z = floor(r);
    Nold = 0; N = 1;

    a = floor(r);
    int counter = 0;

    //the setting so far: Z-1,Z0,N-1,N0, r0 and a0 have been initialised.
    //ready to start the first iteration of the algorithm.

    while (abs(Z*1.0/N - X) > Tol){
        r = 1 / (r - a);

        if (abs(r-ceil(r)) < abs(r-floor(r))){                // improved version, rounding r correctly
            a = ceil(r);
        } else {
            a = floor(r);
        }

        Znew = a * Z + Zold;                         //calculate Z_k
        Zold = Z;                                    //save the old ones
        Z = Znew;

        Nnew = a * N + Nold;                         //same here
        Nold = N;
        N = Nnew;

        counter++;                                     //successfully terminated a step of the algorithm

        //write results on console for control
        cout << "a" << counter << " = " << a << "............... Z/N = " << Z << "/" << N << ".............. |Z/N - X| = " << abs(Z*1.0/N - X) << endl;
    }

    int d = gcd(Z,N);
    Z /= d;
    N /= d;               //simplifying the fraction

    cout << endl << X << " is approximated by the rational number " << Z << " / " << N << " .\n";
    cout << "|Z/N - X| = " << abs(Z*1.0/N - X) << endl;;

    return 0;
}
