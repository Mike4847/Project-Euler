#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int Array[10];
    int size;
} Set;

unsigned long long calculate_factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

void factoridic(Set set, unsigned long long k_th, char *k_th_permutation) {
    if (!k_th_permutation || set.size <= 0 || k_th <= 0) {
        return;
    }
    
    // Calculate total possible permutations
    unsigned long long total = calculate_factorial(set.size);
    
    // Check if k_th is within valid range
    if (k_th > total) {
        printf("Error: k_th value (%llu) exceeds total possible permutations (%llu)\n", k_th, total);
        return;
    }
    
    k_th = k_th - 1;  // Adjust for zero-based indexing
    int n = set.size;
    k_th_permutation[n] = '\0';
    int current_size = n;
    
    printf("Starting permutation generation:\n");
    
    for (int i = 0; i < n; i++) {
        unsigned long long factorial = calculate_factorial(current_size - 1);
        
        int index = (int)(k_th / factorial);
        printf("Step %d: factorial=%llu, k_th=%llu, index=%d\n", 
               i + 1, factorial, k_th, index);
        
        if (index >= current_size) {
            printf("Error: Index %d exceeds current size %d\n", index, current_size);
            return;
        }
        
        k_th_permutation[i] = set.Array[index] + '0';
        
        // Remove used number and shift remaining numbers
        for (int z = index; z < current_size - 1; z++) {
            set.Array[z] = set.Array[z + 1];
        }
        
        current_size--;
        k_th = k_th % factorial;
    }
}

int main() {
    // Initialize set with numbers 0-9 instead of 1-10
    Set set = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 10};
    char *permutation = (char *)malloc(sizeof(char) * 11);
    
    if (!permutation) {
        printf("Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    
    printf("Generating 1,000,000th permutation of numbers 0-9\n");
    factoridic(set, 1000000, permutation);
    printf("Final result: %s\n", permutation);
    
    free(permutation);
    return EXIT_SUCCESS;
}