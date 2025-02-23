import math

LIMIT = 1000000
"""
largest n-digit pandigital prime number that exists 
and the idea is that the should use all the digits 1 - n exactly ONCE.

"""
def is_prime(number: int) -> bool:
    if number <= 1:
        return False
    if number <= 3:
        return True
    if number % 2 == 0 or number % 3 == 0:
        return False
    i = 5
    while i * i <= number:
        if number % i == 0 or number % (i + 2) == 0:
            return False
        i += 6
    return True

def is_pandigital_prime(num: int) -> bool:
    num_str = str(num)
    n = len(num_str)
    
    # Early exit if sum of digits is divisible by 3 (not prime)
    if sum(int(d) for d in num_str) % 3 == 0:
        return False
    
    # Check if the number is prime first
    if not is_prime(num):
        return False
    
    # Create set of digits
    digits = set(num_str)
    
    # Must have exactly n unique digits
    if len(digits) != n:
        return False
    
    # Must not contain 0
    if '0' in digits:
        return False
    
    # Must contain all digits from 1 to n
    expected_digits = set(str(i) for i in range(1, n + 1))
    return digits == expected_digits

def main():
    # Since we need all digits from 1 to n, maximum n is 9
    # We can start from largest possible n-digit number to optimize
    largest_pandigital_prime = 0
    
    # Try 7-digit numbers (7-digit pandigital numbers can be prime)
    for n in range(7, 0, -1):  # Start with 7 digits
        digits = list(range(1, n + 1))
        from itertools import permutations
        
        # Generate permutations in descending order
        for p in sorted(permutations(digits), reverse=True):
            num = int(''.join(map(str, p)))
            if is_pandigital_prime(num):
                largest_pandigital_prime = max(largest_pandigital_prime, num)
                break  # Found the largest for this digit count
        
        if largest_pandigital_prime > 0:
            break  # We found our answer
    
    print(f"The largest n-digit pandigital prime number is {largest_pandigital_prime}")

if __name__ == "__main__":
    main()

