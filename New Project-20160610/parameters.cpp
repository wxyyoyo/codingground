#include "parameters.h"
#include <cmath>

Parameters::Parameters(const ParametersInner& InnerObjPtr_)
{
    InnerObjPtr = InnerObjPtr_.clone();
}

Parameters::~Parameters()
{
  delete  InnerObjPtr;
}

Parameters::Parameters(const Parameters& original)
{
    InnerObjPtr = original.InnerObjPtr->clone();
}

Parameters& Parameters::operator=(const Parameters& original)
{
    if (this != &original)
    {
        delete InnerObjPtr;
        InnerObjPtr = original.InnerObjPtr->clone();
    }
    return *this;
}

double Parameters::Integral(double time1, double time2)const
{
    return InnerObjPtr->Integral(time1, time2);
}

double Parameters::IntegralSquare(double time1, double time2)const
{
    return InnerObjPtr->IntegralSquare(time1, time2);
}

double Parameters::Mean(double time1, double time2)const
{
    double total = Integral(time1, time2);
    return total /(time2 - time1);
}

double Parameters::RootMeanSquare(double time1, double time2)const
{
    double total = IntegralSquare(time1, time2);
    return total /(time2 - time1);
}

//////////////////////////////////////////////////////////////////
ParametersConstant::ParametersConstant(double constant_)
: constant(constant_)
{
    constantsquare = constant * constant;
}

ParametersInner* ParametersConstant::clone() const
{
    return new ParametersConstant(*this);
}

double ParametersConstant::Integral(double time1, double time2) const
{
    return (time2 - time1) * constant;
}

double ParametersConstant::IntegralSquare(double time1, double time2) const
{
    return (time2 - time1) * constantsquare;
}





