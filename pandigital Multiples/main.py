def is_pandigital(number: str) -> bool:
    """Check if a number is pandigital (contains all digits 1-9 exactly once)."""
    if len(number) != 9:
        return False
    
    # Using set for O(1) lookup
    digit_set = set(number)
    return len(digit_set) == 9 and '0' not in digit_set

def pandigital_multiples(n: int) -> str:
    """Generate concatenated multiples of n until reaching 9 digits or more."""
    number = ""
    product = 1
    
    while len(number) < 9:
        current = str(n * product)
        # If adding the next multiple would exceed 9 digits, stop
        if len(number) + len(current) > 9:
            return ""
        number += current
        product += 1
    
    # Only return if exactly 9 digits
    return number if len(number) == 9 else ""

def find_largest_pandigital(limit: int) -> tuple[int, str]:
    """Find the largest pandigital number formed by concatenated multiples."""
    max_pandigital = 0
    max_base = 0
    
    for i in range(1, limit):
        pandigital_number = pandigital_multiples(i)
        if pandigital_number and is_pandigital(pandigital_number):
            current_num = int(pandigital_number)
            if current_num > max_pandigital:
                max_pandigital = current_num
                max_base = i
    
    return max_base, str(max_pandigital)

def main():
    LIMIT = 10000  # Increased limit for better coverage
    base, result = find_largest_pandigital(LIMIT)
    if result:
        print(f"Base number: {base}")
        print(f"Largest pandigital number: {result}")
    else:
        print("No pandigital numbers found")

if __name__ == "__main__":
    main()
