from math import isqrt

LIMIT = 1000000


def odd_composite_list( limit : int)->list[int]:
    odd_composite = []
    for num in range(3, limit , 2): # only check odd numbers
        
        is_composite = False
        for divisor in range(3, int(num ** 0.5) + 1 , 2):
            if (num % divisor == 0):
                is_composite = True
                break
        if (is_composite):
            odd_composite.append(num)
    return odd_composite


def prime_list(limit: int)->list[int]:
    """
    To calculate prime upto a limit we are gonna use 'Sieve of Erostothene':
    This methods elagantly calculates primes by making looping upto the Squaroot of the limit

    """
    
    is_prime = [True for i in range(limit + 1)]
    
    is_prime[0] = is_prime[1] = False # 0 and 1 arent prime numbers

    p = 2

    while p * p < limit:

        if is_prime[p]:
            
            for i in range(p * p, limit + 1, p):
                
                is_prime[i] = False

        p += 1
    primes = [ i for i in range(limit + 1) if is_prime[i]]

    return primes

    
def is_goldbach_other_conjecture(composite :int)->bool:

    if is_prime(composite):
        return False

    primes = prime_list(composite)

    for prime in primes:    

        remaining = (composite - prime)

        if remaining % 2 != 0:
            continue
        square_candidate = remaining // 2
        square = isqrt(square_candidate)

        if (square * square == square_candidate):
            return True

    return False

def is_prime(n: int) -> bool:
    """Check if a number is prime."""
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    
    return True
     




def main():
    composites = odd_composite_list(LIMIT)
    
    answer = 0
    for composite in composites:
        if (not is_goldbach_other_conjecture(composite)):
            answer = composite
            break
    print(f"The smallets number that Goldbacks conjecture fails is {answer}\n")




#Driver code 
if __name__ == "__main__":
    main()


