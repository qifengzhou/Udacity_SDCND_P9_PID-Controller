#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;

    cte_sum = 0;
}

void PID::UpdateError(double cte){
    cte_sum += cte;
    double cte_diff = cte - cte_prev;
    cte_prev = cte;
    p_error = -Kp * cte;
    d_error = -Kd * cte_diff;
    i_error = -Ki * cte_sum;
}

double PID::TotalError() {
    return p_error + d_error + i_error;
}

