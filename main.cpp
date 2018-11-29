#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
double phifunc(int,int);
int main() {

    double delta = 20.0/101.0;

    // This creates intial array and sets a value for each point
    double phival [102][102];
    for (int i=0; i<102; i++) {
        for (int j=0; j<102; j++) {
            phival[i][j]=phifunc(i,j); // stores the number computed into the point
            // cout << fixed;
            // std::cout << std::setprecision(6) << phival[i][j] << "  ";
        } //closes for j loop
        //cout << endl;
    } // closes for i loop

    // This creates array for second derivative WRT x
    double phixx [102][102];
    double phiyy [102][102];
    double phixy [102][102];
    for (int m=1; m<101; m++) {
        for (int n=1; n<101; n++) {
            phixx[m][n]=(phival[m+1][n]+phival[m-1][n]+2*phival[m][n])/pow(delta,2);
            phiyy[m][n]=(phival[m][n+1]+phival[m][n-1]+2*phival[m][n])/pow(delta,2);
            phixy[m][n]=(phival[m+1][n+1]-phival[m+1][n-1]
                         +phival[m-1][n-1]-phival[m-1][n+1])/(pow(delta,2)*4);
            //cout << fixed;
            //std::cout << std::setprecision(6) << phival[m][n] << "  ";
        } //closes m
        //cout << endl;
    } // closes n

    return 0;
} // closes main file

double phifunc(int i, int j) {
    double sigma = .05;
    double rc = 4.0;
    double x = -10.0 +i*(20.0/101.0);
    double y = -10.0 +j*(20.0/101.0);
    double r = sqrt(pow(x,2)+pow(y,2));
    double sigsqr = pow(sigma,2);

    if(r/rc < 1) {
        return 2*sigsqr*log(r/rc)-2*sigsqr;
    } //closes if
    else {
        return -2*sigsqr*rc/r;
    } // closes else
} // closes function