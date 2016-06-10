#include "payoff.h"
#include "maxmin.h"

double payoffcall:: operator()(double spot)const
{
    return max(strike -spot, 0.0);
}

payoff* payoffcall::clone() const
{
    return new payoffcall(*this);
}

double payoffput:: operator()(double spot)const
{
    return max(-strike + spot, 0.0);
}

payoff* payoffput::clone() const
{
    return new payoffput(*this);
}