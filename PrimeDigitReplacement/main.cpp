#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <ranges>


/*  
    Func to check if a number is prime.
    
*/
using std::string;
using std::vector;


bool isPrime(const size_t number) noexcept{
    if (number <= 1) return false;
    if (number <= 3) return true;

    if (((number % 2) == 0) | number % 3 == 0) return false;

    int i = 5;

    while (i * i <= number ){
        if ((number % i == 0) | (number % (i + 2))){
            return false;
        }

        i+=6;
    }
    
    return true;
}

int main(void){

    vector<int> Primes;
    auto LIMIT = std::views::iota(0,1000000);

    for (const auto& n : LIMIT){
        string number = std::to_string(n);
        for (const auto& i : {0,1,2,3,4,5,6,7,8,9}){
            
        }

    }



    return(0);
}
