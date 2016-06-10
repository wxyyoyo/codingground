#include <iostream>
#include "BiTree.h"
#include "payoffbridge.h"
#include "optionproduct.h"
#include "parameters.h"
using namespace std;

int main()
{
    payoffcall test1(100);
    payoffcall test2(test1);
    payoffbridge test3(test1);
    ParametersConstant r(0.1);
    //payoffbridge(const payoffbridge& original);
    
    TheOption optiontest(test1, 100);
    
    
    BiTree MyTree(100.0,10.0, 105.0, 0.1,0.3,1);
    //MyTree.BuildTree();
   cout << MyTree.ValueTree() << endl; 
   cout << test3(95) << endl; 
   cout << optiontest.GetOptionPayOff(96) << endl;
   cout << r.Integral(1,3) << endl;
   return 0;
}
