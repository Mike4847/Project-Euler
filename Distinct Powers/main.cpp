#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using std::string;

//func that returns the power of a number in string format
string
multiply(string a, string b)
{

    if (a=="0" || b=="0")
    {
      std::cout<<0<<std::endl;
      return "0";
   }
    int m = a.size() - 1, n = b.size() - 1, carry = 0;
    string product;
    for (int i=0; i<=m+n || carry; ++i) {
        for (int j=std::max(0, i-n); j<=std::min(i, m); ++j)
            carry += (a[m-j] - '0') * (b[n-i+j] - '0');
        product += carry % 10 + '0';
        carry /= 10;
    }
    std::reverse(begin(product), end(product));
    return product;
}


string power(string A, int b)
{
    string power= "1";
    while(b>0)
    {
        power = multiply(A,power);
        b--;
    }
    return power;
}

int main()
{
    std::set <string> uniqueProducts; 
    for (int a = 2 ; a<=100; a++)
    {
        for( int b= 2 ; b <=100; b++)
        {
            string pow = power(std::to_string(a),b);
            uniqueProducts.insert(pow);
            
        }
    }
    std::cout << uniqueProducts.size() ;

    return 0;
}
