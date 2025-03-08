#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

const int LIMIT = 100000; // Increased limit to find larger numbers

std::vector<long long> genHexagonal(long long min_value) {
    // H(n) = n(2n-1)
    std::vector<long long> answer;
    long long n = 1;
    long long value;
    
    do {
        value = n * (2 * n - 1);
        if (value >= min_value) {
            answer.push_back(value);
        }
        n++;
    } while (n < LIMIT);
    
    return answer;
}

std::vector<long long> genTriangular(long long min_value) {
    // T(n) = n(n+1)/2
    std::vector<long long> answer;
    long long n = 1;
    long long value;
    
    do {
        value = (n * (n + 1)) / 2;
        if (value >= min_value) {
            answer.push_back(value);
        }
        n++;
    } while (n < LIMIT);
    
    return answer;
}

std::vector<long long> genPentagonal(long long min_value) {
    // P(n) = n(3n-1)/2
    std::vector<long long> answer;
    long long n = 1;
    long long value;
    
    do {
        value = (n * (3 * n - 1)) / 2;
        if (value >= min_value) {
            answer.push_back(value);
        }
        n++;
    } while (n < LIMIT);
    
    return answer;
}

int main() {
    const long long MIN_VALUE = 40756; // Start searching from the number after 40755
    
    std::vector<long long> hexVec = genHexagonal(MIN_VALUE);
    std::vector<long long> triaVec = genTriangular(MIN_VALUE);
    std::vector<long long> penVec = genPentagonal(MIN_VALUE);
    
    // Temporary vector for intersection of first two sets
    std::vector<long long> temp;
    
    // Final result vector
    std::vector<long long> result;
    
    std::set_intersection(
        hexVec.begin(), hexVec.end(),
        triaVec.begin(), triaVec.end(),
        std::back_inserter(temp)
    );
    
    std::set_intersection(
        temp.begin(), temp.end(),
        penVec.begin(), penVec.end(),
        std::back_inserter(result)
    );
    
    if (!result.empty()) {
        std::cout << "The next triangle number that is also pentagonal and hexagonal: " 
                  << result[0] << std::endl;
    } else {
        std::cout << "No result found within the limit." << std::endl;
    }
    
    return 0;
}
