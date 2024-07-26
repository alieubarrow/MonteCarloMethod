//Herader files
#include <iostream>
#include <cmath>
#include <iomanip>
#include <random>
using namespace std;

//Const variables
const double R = 100; // Radius of the circle (=square side) is determined here
const double M_PI = 4 * atan(1.0); //Pi

struct Coord { // Data representation of a point where the arrow hits

        double x, y;
};

//Function prototypes 
Coord throwArrow();
void throwSeries(int n);
bool below(Coord cordinate);

int main() {

        cout << setw(7) << "n" << setw(10) << "pi" << setw(22) << "Rel. fault" << endl;
        cout << "-------|----------------|-----------------|" << endl;

        //Loop through to get samples 
        for (int i = 100; i <= 10000; i += 100) {
                throwSeries(i);
        }
        return 0;
}

//throwArrow fucntion which returns a coordinate of the type Coord. The function
//throws arrows by generating random numbers for x and y within the square area.
Coord throwArrow() {

        struct Coord cnd;
        random_device rd;  // Will be used to obtain a seed for the random number engine
        mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        uniform_real_distribution<> dis(1.0, R);

        cnd.x = dis(gen);
        cnd.y = dis(gen);

        return cnd;
}

//Function returns true if the coordinate falls below the circle arc.
bool below(Coord cordinate) {

        return (pow(cordinate.x, 2) + pow(cordinate.y, 2)) < pow(R, 2);
}

//Function calls below() and throwArrow() functions to geenrate random numbers,
//check if numbers are below arc and then calculates pi along with relFel
void throwSeries(int n) {

        //Variables 
        struct Coord cordinate;
        double counter = 0;
        bool belowCircleArc;
        double pi;
        double relFel;

        //Loop and generate random numbers then check if they are below arc
        for (int i = 1; i <= n; i++) {
                cordinate = throwArrow();
                belowCircleArc = below(cordinate);
                if (belowCircleArc) {
                        counter++;
                }
        }

        pi = 4.0 * (counter / n); //Calculate pi

        relFel = ((pi - M_PI) / pi) * 100; //Calculate relFel

        //Output
        cout << setw(7) << n << setw(12) << fixed << showpoint << setprecision(5) << pi;
        cout << setw(17) << fixed << showpoint << setprecision(1) << relFel << endl;
}

