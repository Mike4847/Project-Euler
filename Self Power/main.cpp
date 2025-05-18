#include <iostream>
#include <string>
#include <cmath>

// std::string self_powers(int base, int exponent);
std::string _sum(std::string s1, std::string s2);
std::string multiply(const std::string& num1, const std::string& num2);
std::string self_powers(int base, int exponent);

int main()
{
   std::string sum = "0";
   for (int i = 1; i <= 1000; i++) {
      sum = _sum(sum,self_powers(i, i));
   }

  std::cout << "The sum of the series 1^1 .. up to 10^10 is: " << std::endl;
  std::cout << sum<< std::endl;
  std::cout << "The last 10-digit of the above series is:\n"<< sum.substr(sum.size() - 10, sum.size());

  return 0;
}

std::string multiply(const std::string& num1, const std::string& num2) {
    // Initialize result with zeros (num1.length + num2.length is the maximum possible length)
    std::string result(num1.length() + num2.length(), '0');
    
    // Multiply from right to left as in long multiplication
    for (int i = num1.length() - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = num2.length() - 1; j >= 0; j--) {
            // Calculate position in result
            int position = i + j + 1;
            
            // Calculate product + existing digit value + carry
            int product = (num1[i] - '0') * (num2[j] - '0') + (result[position] - '0') + carry;
            
            // Update result at this position with ones digit
            result[position] = (product % 10) + '0';
            
            // Update carry for next position
            carry = product / 10;
        }
        
        // Handle remaining carry
        if (carry > 0) {
            result[i] = ((result[i] - '0') + carry) + '0';
        }
    }
    
    // Remove leading zeros
    size_t start_pos = result.find_first_not_of('0');
    if (start_pos != std::string::npos) {
        result = result.substr(start_pos);
    } else {
        result = "0"; // If result is all zeros
    }
    
    return result;
}

std::string self_powers(int base, int exponent) {
    if (exponent == 0) return "1";
    
    std::string result = "1";
    std::string base_str = std::to_string(base);
    
    // Simple repeated multiplication approach
    for (int i = 0; i < exponent; i++) {
        result = multiply(result, base_str);
    }
    
    return result;
}

std::string _sum(std::string s1, std::string s2)
{
  std::string result;
  std::string number1(s1);
  std::string number2(s2);

  // check for string length
  if (s2.length()> s1.length()){
    std::string temp = number1;
    number1 = number2;
    number2 = temp;
  }


  std::string temp_number2 = std::string(number1.size() - number2.size(), '0') + number2;
  number2 = temp_number2;

  int carry = 0 ;
  for (int i = number1.size() - 1; i >= 0 ; i--){
    int digit_sum = (number1[i]- '0') + (number2[i]- '0') + carry;
    carry = digit_sum / 10;
    result = char(digit_sum % 10 + '0') + result;
  }

  if (carry){
    result = char(carry) + result;
  }
  
  return result;

}