#ifndef PARAMETERS_H
#define PARAMETERS_H

// This file includes a bridge pattern. 
// class Parameter is the bridge
// These classes can encapsulate variable and constant paramers 
// and functionality to calculate integrals and so on.


class ParametersInner
{
public:
ParametersInner(){};
virtual ParametersInner* clone() const=0;
virtual double Integral(double time1, double time2) const=0;
virtual double IntegralSquare(double time1, double time2) const=0;
virtual ~ParametersInner(){}

protected:

private:

};

class ParametersConstant:public ParametersInner
{
public:
ParametersConstant(double constant_);
virtual ParametersInner* clone() const;
virtual double Integral(double time1, double time2) const;
virtual double IntegralSquare(double time1, double time2) const;


private:
double constant;
double constantsquare;
};

class Parameters
{
// This is the bridge class
public:
Parameters(const ParametersInner& InnerObjPtr_);
virtual ~Parameters(); // not using VIRTUAL in payoff bridge. WHY?
Parameters(const Parameters& original);
Parameters& operator=(const Parameters& original);

double Integral(double time1, double time2)const;
double IntegralSquare(double time1, double time2)const;

// These functions are not in derived classes
double Mean(double time1, double time2)const;
double RootMeanSquare(double time1, double time2)const;

private:
ParametersInner* InnerObjPtr;
};


#endif