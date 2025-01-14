#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>


/*
  ! Problem definition:
  1. Calculate the n-th fibonacci number(F_n) using Binets closed-form formula.
    F_n = ((1 + 5**0.5)^n - (1 - 5**0.5)^n )/2^n * 5**0.5
  2. find the # of digits d(x) of the number (F_n) by usng the formula = |__log_10 F_n __|(floor) + 1
  3. if (d(x) != 1000) return to 1.

*/

// * function to calculate the n-th Fibonnacci

// int main()
// {
//   // function to find the number of digits of a number

//   double nThFibonacci(int n);
//   size_t numOfDigits(double fibonacci);

//   std::cout << "The Fibonacci of 20 is: " << nThFibonacci(20) << std::endl;
//   std::cout << "The above has " << numOfDigits(nThFibonacci(20)) << std::endl;

//   return 0;
// }

// double
// nThFibonacci(int n)
// {

//   /*
//   ((1 + sqrt(5))**n - (1 - 5**0.5)**n )/(2**n * 5**0.5)
//   */
//   // double fibonacci = (pow((1 + sqrt(5)), n) - pow((1 + sqrt(5)), n)) / (pow(2, n) * sqrt(5));

//   return (std::pow((1 + std::sqrt(5)), n) - std::pow((1 - std::sqrt(5)), n)) / (std::pow(2, n) * std::sqrt(5));
// }

// size_t
// numOfDigits(double fibonacci)
// { // the idea of getting the individual digit length of a number n found by
//   // floor(log10(n)) + 1

//   return static_cast<size_t>(floor(log10(fibonacci)) + 1);
// }


class BigInteger {
private:
    std::string digits;
    
    static std::string add(const std::string& a, const std::string& b) {
        std::string result;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            result.push_back(sum % 10 + '0');
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
    
    static std::string multiply(const std::string& a, const std::string& b) {
        std::vector<int> result(a.length() + b.length(), 0);
        
        // Multiply each digit
        for (int i = a.length() - 1; i >= 0; i--) {
            for (int j = b.length() - 1; j >= 0; j--) {
                int product = (a[i] - '0') * (b[j] - '0');
                int sum = result[i + j + 1] + product;
                
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        // Convert to string
        std::string s;
        bool leadingZero = true;
        for (int digit : result) {
            if (digit != 0) leadingZero = false;
            if (!leadingZero) s += std::to_string(digit);
        }
        
        return s.empty() ? "0" : s;
    }

public:
    BigInteger(const std::string& num = "0") : digits(num) {
        digits.erase(0, digits.find_first_not_of('0'));
        if (digits.empty()) digits = "0";
    }
    
    BigInteger(unsigned long long num) {
        digits = std::to_string(num);
    }
    
    size_t numberOfDigits() const {
        return digits == "0" ? 1 : digits.length();
    }
    
    BigInteger operator+(const BigInteger& other) const {
        return BigInteger(add(digits, other.digits));
    }
    
    BigInteger operator*(const BigInteger& other) const {
        return BigInteger(multiply(digits, other.digits));
    }
    
    std::string toString() const {
        return digits;
    }
};

// 2x2 matrix structure for Fibonacci calculation
struct Matrix {
    BigInteger a, b, c, d;
    
    Matrix(const BigInteger& a, const BigInteger& b, 
           const BigInteger& c, const BigInteger& d) 
        : a(a), b(b), c(c), d(d) {}
    
    Matrix operator*(const Matrix& other) const {
        return Matrix(
            a * other.a + b * other.c,
            a * other.b + b * other.d,
            c * other.a + d * other.c,
            c * other.b + d * other.d
        );
    }
};

// Fast matrix exponentiation
Matrix matrixPower(Matrix base, int exponent) {
    Matrix result(BigInteger(1), BigInteger(0),
                 BigInteger(0), BigInteger(1));
    
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = result * base;
        }
        base = base * base;
        exponent /= 2;
    }
    
    return result;
}

// Calculate nth Fibonacci using matrix exponentiation
BigInteger getFibonacci(int n) {
    if (n <= 1) return BigInteger(n);
    
    // Fibonacci matrix base [[1,1],[1,0]]
    Matrix base(BigInteger(1), BigInteger(1),
                BigInteger(1), BigInteger(0));
    
    Matrix result = matrixPower(base, n - 1);
    return result.a;
}

int main() {
    int n = 0;
    while (true) {
        BigInteger fib = getFibonacci(n);
        size_t digits = fib.numberOfDigits();
        
        if (n % 100 == 0) {
            std::cout << "Checking F(" << n << ") with " << digits << " digits\n";
        }
        
        if (digits >= 1000) {
            std::cout << "The first Fibonacci number with 1000 or more digits is F(" << n << ")\n";
            std::cout << "It has exactly " << digits << " digits\n";
            break;
        }
        n++;
    }
    return 0;
}