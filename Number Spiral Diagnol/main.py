def calculate_diagonal_sum(n):
    if n < 1 or n % 2 == 0:
        return 0
        
    diagonal_sum = 1  # Center value
    
    # For each layer/ring moving outward
    for layer in range(1, n//2 + 1):
        # Current square side length
        side_length = 2 * layer + 1
        # Square value at bottom right corner
        square_value = side_length * side_length
        
        # Add the four corners for this layer
        diagonal_sum += square_value  # Bottom right
        diagonal_sum += square_value - (side_length - 1)  # Bottom left
        diagonal_sum += square_value - 2*(side_length - 1)  # Top left
        diagonal_sum += square_value - 3*(side_length - 1)  # Top right
    
    return diagonal_sum

n = 1001
result = calculate_diagonal_sum(n)
print(f"The diagonal sum for {n}x{n} spiral is: {result}")