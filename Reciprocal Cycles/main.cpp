#include <iostream>
#include <map> // Use map to track remainder positions
#include <set>
#include <string>

const int MAXIMUM_DENOMINATOR = 1000;

int main() {
    int max_cycle_length = 0; // To track the maximum cycle length
    int best_d = 0;           // To track the denominator with the longest cycle

    for (int d = 2; d < MAXIMUM_DENOMINATOR; d++) {
        std::map<int, int> remainder_positions; // Map to store remainder and its position
        int numerator = 1;                      // Start with numerator = 1
        int position = 0;                       // Track the position in the decimal expansion

        while (numerator != 0) {
            int remainder = numerator % d;

            // If remainder is already in the map, we've found a repeating cycle
            if (remainder_positions.find(remainder) != remainder_positions.end()) {
                int cycle_length = position - remainder_positions[remainder];
                if (cycle_length > max_cycle_length) {
                    max_cycle_length = cycle_length;
                    best_d = d;
                }
                break; // Stop processing for this denominator
            }

            // Otherwise, store the remainder and its position
            remainder_positions[remainder] = position;

            // Update numerator and position
            numerator = remainder * 10;
            position++;
        }
    }

    // Output the result
    std::cout << "The value of d < " << MAXIMUM_DENOMINATOR
              << " with the longest recurring cycle is: " << best_d
              << " with a cycle length of: " << max_cycle_length << std::endl;

    return 0;
}
