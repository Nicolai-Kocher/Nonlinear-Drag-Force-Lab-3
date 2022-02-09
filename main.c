/*
Comp 166
Lab 3
Nicolai Kocher
Jan 29, 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double density(double height) {
        const double p0 = 101.325e3;    // sea-level standard atmospheric presure
        const double T0 = 288.15;       // sea-level standard temperature
        const double g = 9.80665;       // (m/s^2) earth-surface gravitational acceleration
        const double L = 0.0065;        // temperature lapse rate
        const double R = 8.31447;       // ideal (universal) gas constant
        const double M = 0.0289644;     // molar mass of dry air
        double p, T;
        T = T0 - L;
        p = p0 * pow((1-(L*height)/T0), (g*M)/(R*L));
        return((p*M)/(R*T));
    }

int main() {

    //Variables
    double mass, height, crossSection, timeStep;
    const double g = 9.80665;
    double velocity, acceleration;
    long dragCoeificient;

    //prompt for height
    printf("Enter Height of the object in meters:");
    scanf("%ld", height);

    //prompt for mass
    printf("Enter Mass of the object:");
    scanf("%lf", mass);

    //prompt for drag coeificient
    printf("Enter Drag coeificient:");
    scanf("%ld", dragCoeificient);

    //prompt for cross-sectional area of object
    printf("Enter Cross-Sectional area of object:");
    scanf("%lf", crossSection);

    //prompt for time-step size
    printf("Enter Time Step:");
    scanf("%lf", timeStep);

    long time = 0;
    acceleration = 0;
    velocity = 0;
    printf("Time   Height   Velocity\n");
    for (int base = 0; base>100000; base++)
    {
        long time = base*timeStep;
        printf("%4.2ld  %8.2lf   %8.2lf\n", time, height, velocity);
        double Fg = mass*g;
        double Fa = -0.5*(dragCoeificient*density(height)*acceleration*pow(velocity));
        double Fnet = Fa + Fg;
        velocity = velocity + (acceleration * timeStep);
        height = height - ((1/2)*velocity*pow(timeStep));
    }


    return("EXIT_SUCCESS");
}
