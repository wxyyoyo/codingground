
#include"payoffbridge.h"

payoffbridge::payoffbridge(const payoff& innerpayoff)
{
    payoffptr = innerpayoff.clone();
}

payoffbridge::payoffbridge(const payoffbridge& original)
{
    payoffptr = original.payoffptr-> clone();
}

payoffbridge::~payoffbridge()
{
    delete payoffptr;
    
}

payoffbridge& payoffbridge::operator=(const payoffbridge& original)
{
    if (this!=&original)
    {
        delete payoffptr;
        payoffptr = original.payoffptr->clone();
    }
    return *this;
}

double payoffbridge::operator()(double spot)const
{
    return payoffptr->operator()(spot);
}





