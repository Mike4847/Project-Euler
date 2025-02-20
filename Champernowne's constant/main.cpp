#include <iostream>
#include <string>
#include <cstdint>

const int32_t LIMIT = 1000001;

std::string champernownes_constant();

int main()
{
  const std::string champernownesConstant = champernownes_constant();
  int32_t d_value = 1;

  // Print first few characters to debug
  std::cout << "First few digits: ";
  for (int i = 0; i < 20; i++)
  {
    std::cout << champernownesConstant[i];
  }
  std::cout << std::endl;

  // We need to skip "0." at the start, so our actual digits start at index 2
  // For position 1, we want index 2
  // For position 10, we want index 11
  // For position 100, we want index 101
  // and so on...
  for (int i = 1; i <= 10000; i *= 10)
  {
    int index = i + 1; // +1 because we're skipping the "0."
    if (index < champernownesConstant.length())
    {
      int digit = champernownesConstant[index] - '0';
      std::cout << "Digit at position " << i << " is: " << digit << std::endl;
      d_value *= digit;
    }
  }

  std::cout << "The Champernownes Constant with a limit of " << LIMIT << " is:\n"
            << d_value << std::endl;

  return EXIT_SUCCESS;
}

std::string champernownes_constant()
{
  std::string chamConstant = "0.";
  chamConstant.reserve(LIMIT * 4); // Reserve space to avoid reallocations

  for (int i = 1; i < LIMIT; i++)
  {
    chamConstant += std::to_string(i);
  }
  return chamConstant;
}