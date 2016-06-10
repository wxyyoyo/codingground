#ifndef PAYOFF_H
#define PAYOFF_H

class payoff
{
public:
payoff(){};
virtual ~payoff(){}
virtual double operator()(double spot)const = 0;
virtual payoff* clone()const=0;

protected:

private:
};

class payoffcall:public payoff
{
public:
payoffcall(double strike_):strike(strike_){}

virtual double operator()(double spot)const;
virtual ~payoffcall(){}
virtual payoff* clone() const;

private:
double strike;
};


class payoffput:public payoff
{
public:
payoffput(double strike_):strike(strike_){}

virtual double operator()(double spot)const;
virtual ~payoffput(){}
virtual payoff* clone() const;

private:
double strike;
};


#endif