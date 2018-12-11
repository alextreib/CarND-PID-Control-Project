#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd)
{
    // Init factors
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;

    // Init errors
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
}

void PID::UpdateError(double cte)
{
    // Prior Newcte - OldCte
    d_error = (cte - p_error);
    // Assign the new cte -> p_error
    p_error = cte;
    // Sum of all old cte = i_error
    i_error += cte;
}

double PID::TotalError()
{
    return -Kp * p_error - Kd * d_error - Ki * i_error;
}
