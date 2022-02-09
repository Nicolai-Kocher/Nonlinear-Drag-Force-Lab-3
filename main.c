/*
Comp 166
Lab 3
Nicolai Kocher
Feb 09, 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double density(double height) {
        const double p0 = 101.325e3;    // sea-level standard atmospheric pressure
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
    double mass, height, dragCoeificient, crossSection, timeStep;
    const double g = 9.80665;

    //prompt for height in meters
    printf("Enter Height of the object in meters:");
    scanf("%lf", &height);

    //prompt for mass
    printf("Enter Mass of the object:");
    scanf("%lf", &mass);

    //prompt for drag coeificient
    printf("Enter Drag coeificient:");
    scanf("%lf", &dragCoeificient);

    //prompt for cross-sectional area of object
    printf("Enter Cross-Sectional area of object:");
    scanf("%lf", &crossSection);

    //prompt for time-step size
    printf("Enter Time Step:");
    scanf("%lf", &timeStep);

    double time = 0;
    double acceleration = 0;
    double velocity = 0;
    printf("Time    Height    Velocity\n");
    for (int base = 0; base<100000 && height>0.0; base++){
        double time = base*timeStep;
        printf("%4.2lf  %8.2lf   %8.2lf\n", time, height, velocity);
        double Fg = mass*g;
        double Fa = -0.5*dragCoeificient*density(height)*crossSection*pow(velocity,2);
        double Fnet = Fa + Fg;
        acceleration = Fnet/mass;
        velocity = velocity + (acceleration * timeStep);
        height = height - velocity*timeStep;
    }
    double terminalVelocity;
    terminalVelocity = sqrt((2*mass*g)/(0.5*density(0.0)*crossSection)); 
    printf("Terminal Velocity: %0.2lf", terminalVelocity);

    return(EXIT_SUCCESS);
}
