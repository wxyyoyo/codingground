#ifndef OPTION_PRODUCT_H
#define OPTION_PRODUCT_H

#include "payoffbridge.h"

class TheOption
{
public:
TheOption(const payoffbridge& payoff_, double strike_)
        :optionpayoff(payoff_), strike(strike_)
        {}
        
double GetStrike()const;
double GetOptionPayOff(double spot)const;

private:
payoffbridge optionpayoff;
double strike;

};


#endif
