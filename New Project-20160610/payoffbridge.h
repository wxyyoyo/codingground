#ifndef PAYOFFBRIDGE_H
#define PAYOFFBRIDGE_H

#include "payoff.h"

class payoffbridge
{
public:
    
    payoffbridge(const payoff& innerpayoff);
    payoffbridge(const payoffbridge& original);
    ~payoffbridge();
    payoffbridge& operator=(const payoffbridge& original);
    double operator()(double spot)const;
    
private:
payoff* payoffptr;
};


#endif

