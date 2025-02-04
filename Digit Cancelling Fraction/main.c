#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 100

/*
 *
 *NOTE: Problem statement:
 * Finding numerical values that have cancelling digits (i.e., have a common digit in the numerator and the denominator) which in return, in its simplest form is true.
 *
 */

void printCharArray(char *str);
bool isCancellingFraction(int num, int denom);
void remove_char(char *str, char ch);

int main() {
    int n = isCancellingFraction(49, 98);

    if (n) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return EXIT_SUCCESS;
}

void remove_char(char *str, char ch) {
    int i, j;
    int len = strlen(str);

    if (len <= 0) return;

    for (i = 0; i < len; i++) {
        if (str[i] == ch) {
            for (j = i; j < len - 1; j++) {
                str[j] = str[j + 1];
            }
            str[len - 1] = '\0';
            break;
        }
    }
}

bool isCancellingFraction(int num, int denom) {
    // We are only considering (numerator and denominator) = 2 digits.
    if (num >= denom)
        return false;

    char numerator[3], denominator[3];
    sprintf(numerator, "%d", num);
    sprintf(denominator, "%d", denom);
    double originalFraction = (double) num / denom;

    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            if (numerator[i] == denominator[j]) {
                char commonDigit = numerator[i];
                remove_char(numerator, commonDigit);
                remove_char(denominator, commonDigit);
                break;
            }
        }
    }

    // Check if the strings are empty after removing the common digit
    if (strlen(numerator) == 0 || strlen(denominator) == 0) {
        return false;
    }
    
    printCharArray(numerator);
    printCharArray(denominator);

    double newFraction = (double) atoi(numerator) / atoi(denominator);
    return newFraction == originalFraction;
}

void printCharArray(char *str) {
    int length = strlen(str);
    int i;

    for (i = 0; i < length; i++) {
        printf("%c\n", str[i]);
    }
}
