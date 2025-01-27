#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <numeric>

using std::string;
const int LIMIT = 10000000;

bool isDigitSum(int n);
int main()
{
    // containt numbers that the sum of its digits power to 5  equals the number
    std::vector<int> num;

    
    for (int i =100 ; i < LIMIT ; i++)
    {
        if (isDigitSum(i))
        {
            num.push_back(i);
        }
    }

    std::cout << std::accumulate(num.begin(), num.end(), 0) << std::endl;

    return 0;
}

bool 
isDigitSum(int n)
{
    if (n==0)
    {
        return false;
    }
    
    string number = std::to_string(n);
    
    int sum = 0;
    for(int i =0 ; i< number.size(); i++)
    {
        sum += static_cast<int>(std::pow(number[i]-'0', 5));
    }
    return sum == n ;
}
