#include "BiTree.h"
#include "maxmin.h"
#include <cmath>
#include <cstdlib>

BiTree::BiTree(double S_, double T_, double K_, double r_, 
               double vol_, double dt_)
              :S(S_),T(T_), K(K_), r(r_), vol(vol_),dt(dt_)
{
   TreeBuilt = false;
   u = exp(vol * sqrt(dt)); 
   d = exp(-vol* sqrt(dt));
   pu = (exp(r *dt) - d) / (u - d);
   pd =1 - pu;
   nsteps = static_cast<unsigned long>(T / dt) + 1;
}

void BiTree::BuildTree()
{
    TreeBuilt = true;
    TheTree.resize(nsteps);
    TheTree[0].resize(1);
    TheTree[0][0].first = S;
    
    for (int i = 1; i<=(nsteps-1); ++i)
    {
        TheTree[i].resize(i+1);
        for (int j = 0; j<i; ++j)
        {
            TheTree[i][j].first = u * TheTree[i-1][j].first; 
        }
        
        TheTree[i][i].first = d * TheTree[i-1][i-1].first;
    }
}

double BiTree::ValueTree()
{
    if (! TreeBuilt )
        BuildTree();
    
    // Here we need compute payoff
    // And we assume to compute call payoff
    for (int i = 0; i<= nsteps-1; ++i)
    {
        TheTree[nsteps-1][i].second = max(TheTree[nsteps-1][i].first - K, 0);
    }
    
    // Then calculate the previous time nods
    // Need to use discount numbers
    // can augment to a different class
     for (int i = nsteps -2; i >= 0; --i)
     {
         for (int j = 0; j<= i; ++j)
         {
           TheTree[i][j].second = exp(-r*dt)*(pu * TheTree[i+1][j].second 
                                  + pd * TheTree[i+1][j+1].second);  
         }
     }
    
    
    // Also needs to add early excercise functionality.
    return TheTree[0][0].second;
    
}

