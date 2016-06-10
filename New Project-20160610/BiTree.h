
#ifndef BITREE_H
#define BITREE_H

#include<vector>

class BiTree
{
public:
BiTree(double S_, double T_, double K_, double r_, 
       double vol_, double dt_);
       

double ValueTree();

protected:
void BuildTree();

private:
double S;
double T; 
double K; 
double r; 
double vol; 
double dt;

double u;
double d;
double pu;
double pd;

unsigned long nsteps;
std::vector<std::vector<std::pair<double, double>>> TheTree;

bool TreeBuilt;
};


#endif