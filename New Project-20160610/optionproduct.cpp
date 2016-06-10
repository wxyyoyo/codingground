#include "optionproduct.h"
#include <cmath>

double TheOption::GetStrike() const
{
    return strike;
}

double TheOption::GetOptionPayOff(double spot)const
{
    return optionpayoff(spot);
}