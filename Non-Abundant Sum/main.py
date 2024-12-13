ABUNDANT_NO_LIMIT = 28123




def is_abundant(n:int)->bool:
  """
  Args:
      n (int): 

  Returns:
      bool: return true if the sum of proper divisor is
        greater than the number n.
  """
  divisors = [i for i in range(1,n) if n % i == 0]
  return sum(divisors) > n


def is_deficient(n:int):
    
    """
  Args:
      n (int): 

  Returns:
      bool: return true if the sum of proper divisor is
       less than n.
  """
    divisors = [i for i in range(1,n) if n % i == 0]
    return sum(divisors) < n




def abundant():
  """
  By mathematical analysis, it can be shown that all integers greater than 28123
  can be written as sum of 2 abundant numbers.
  Calculatin the abundant numbers that are less than 28123
  """
  return [i for i in range(1,ABUNDANT_NO_LIMIT) if is_abundant(i)]

def main():
  positive_integers = []
  abundant_numbers = abundant()       # populates with abundant numbers
  sum_of_abundant = []
  for i in range(1,ABUNDANT_NO_LIMIT):
    for number_2 in range(i):
      if is_abundant():
        pass




      # if i + number_2 not in abundant_numbers:
      #   positive_integers.append(i)
      #   break
  
  print(f"\nSum of all positive integers Which cannot be \
     written as sum of two abundant numbers.\n is {sum(positive_integers)}")

#Driver Code
if __name__ == "__main__":
  #  print(abundant())
  main()