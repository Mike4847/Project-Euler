#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 100
#define MAX_FRACTIONS 20

bool isCancellingFraction(int num, int denom) {
    // Check range: must be 2-digit numbers and proper fraction
    if (num >= denom || num < 10 || denom < 10 || num >= 100 || denom >= 100)
        return false;
        
    // Convert to digits
    int num_tens = num / 10;
    int num_ones = num % 10;
    int den_tens = denom / 10;
    int den_ones = denom % 10;
    
    // Check for trivial cases (ending in zero)
    if (num_ones == 0 || den_ones == 0)
        return false;
        
    double originalFraction = (double)num / denom;
    
    // Check each possible digit cancellation
    if (num_tens == den_tens && den_ones != 0) {
        if ((double)num_ones / den_ones == originalFraction)
            return true;
    }
    if (num_tens == den_ones && den_tens != 0) {
        if ((double)num_ones / den_tens == originalFraction)
            return true;
    }
    if (num_ones == den_tens && den_ones != 0) {
        if ((double)num_tens / den_ones == originalFraction)
            return true;
    }
    if (num_ones == den_ones && den_tens != 0) {
        if ((double)num_tens / den_tens == originalFraction)
            return true;
    }
    
    return false;
}

// Modified to use long long
long long multiply(const int* arr, int size) {
    long long result = 1;
    for (int i = 0; i < size; i++) {
        result *= arr[i];
        printf("Multiplying by %d, current product = %lld\n", arr[i], result);
    }
    return result;
}

// Modified to use long long
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int *numerator = (int *)malloc(MAX_FRACTIONS * sizeof(int));
    int *denominator = (int *)malloc(MAX_FRACTIONS * sizeof(int));
    
    if (!numerator || !denominator) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    
    int currentCount = 0;
    
    // Find cancelling fractions
    for (int i = 10; i < LIMIT; i++) {
        for (int j = i + 1; j < LIMIT; j++) {
            if (currentCount >= MAX_FRACTIONS) {
                fprintf(stderr, "Warning: Maximum fraction count reached\n");
                break;
            }
            
            if (isCancellingFraction(i, j)) {
                numerator[currentCount] = i;
                denominator[currentCount] = j;
                printf("Found fraction: %d/%d\n", i, j);
                currentCount++;
            }
        }
    }
    
    printf("\nFound %d cancelling fractions\n", currentCount);
    if (currentCount == 0) {
        printf("No cancelling fractions found!\n");
        free(numerator);
        free(denominator);
        return EXIT_FAILURE;
    }
    
    // Calculate product using long long
    printf("\nCalculating numerator product:\n");
    long long productOfNumerators = multiply(numerator, currentCount);
    printf("\nCalculating denominator product:\n");
    long long productOfDenominators = multiply(denominator, currentCount);
    
    printf("\nBefore reduction: %lld/%lld\n", productOfNumerators, productOfDenominators);
    
    // Reduce final fraction using GCD
    long long common_factor = gcd(productOfNumerators, productOfDenominators);
    printf("Common factor (GCD): %lld\n", common_factor);
    
    productOfNumerators /= common_factor;
    productOfDenominators /= common_factor;
    
    printf("Final reduced fraction: %lld/%lld\n", productOfNumerators, productOfDenominators);
    printf("The value of the denominator is %lld\n", productOfDenominators);
    
    free(numerator);
    free(denominator);
    return EXIT_SUCCESS;
}
