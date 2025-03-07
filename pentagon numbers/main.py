# Pentagon numbers are of the form 
# P_n = n(3n-1)/2
LIMIT = 10000

def genPentNumbers() -> list:
    """Generate pentagonal numbers up to a specified count."""
    penNumbers = []
    n = 1
    while len(penNumbers) < LIMIT:
        penNumber = n * (3 * n - 1) // 2
        penNumbers.append(penNumber)
        n += 1
    return penNumbers

def main():
    pentagonNumbers = genPentNumbers()
    pentSet = set(pentagonNumbers)  # For efficient lookups
    
    min_difference = float('inf')
    min_pair = (0, 0)
    
    for i in range(len(pentagonNumbers)):
        for j in range(i + 1, len(pentagonNumbers)):
            p_i = pentagonNumbers[i]
            p_j = pentagonNumbers[j]
            
            # Check if both sum and difference are pentagonal
            if (p_i + p_j) in pentSet and (p_j - p_i) in pentSet:
                if (p_j - p_i) < min_difference:
                    min_difference = p_j - p_i
                    min_pair = (p_i, p_j)
    
    print(f"The minimized difference of pentagon numbers is {min_difference}")
    print(f"The pentagon numbers are {min_pair[0]} and {min_pair[1]}")

if __name__ == "__main__":
    main()
#driver code
if __name__ == "__main__":
    main()

