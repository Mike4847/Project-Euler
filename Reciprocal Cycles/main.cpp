#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <set>
/*
   Problem Statement:
  In the advent of unit fraction (1/d) there is the realisation of recurrence.
  in this Problem Statement we ought find the longest recureing sequence,
  on the bounds of d < 1000.

*/

const int MAXIMUM_DENOMINATOR = 1000;

int main()
{
   //NOTE: loop through from 2...to...999
   for(int d = 2; d< MAXIMUM_DENOMINATOR ; d++)
   {
       // creating a set for remainder conditioning.
       std::set<int> remainders;
       int NUMERATOR= 1, position = 0;
       int remainder_ = NUMERATOR % d;
       
       if (remainders.find(remainder_) != remainders.end())
       {  // Note that there are at most (d-1) unique remainders
          //this means that in advent a remainder is in a set.
          // that means that there is a start of recurring.
        
           
       }else
       {
          
       }
       
   }
    return 0;
}
