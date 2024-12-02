
#function for calculating amicable numbers 
def Amicable(n:int)->int:
  """ function takes the parameter(input) and
    calculate the perfect divisor of the number.
    The divisors should be less than n.
    
    
    Return values is the number(n) and the sum of the elements(perfect divisors)"""
  result = []
  for i in range(1,n):
    if n % i == 0:
      result.append(i)
  
  return sum(result)

def main():


  #initialize a dictionary 
  AmicableNumbers ={}
  # loop from 1 to 1000 to populate the keyvalue pair.
  for i in range(1,10000):
    AmicableNumbers[i] = Amicable(i)
    # print(f"{i} : {Amicable(i)}")


  # list containing amicable numbers
  result = set()
  # check for amicable numbers in the dic
  
  

    
  
  # #check if numbers are amicable
  # for j in range(1, 10000):
  #   b = Amicable(j)
  #   if b in AmicableNumbers and AmicableNumbers[b] == j and j != b:
  #       result.update([j, b])
  for j in range(1, 10000):
    b = Amicable(j)
    # print(f"j: {j}, b: {b}, AmicableNumbers[b]: {AmicableNumbers.get(b)}")
    if b in AmicableNumbers and AmicableNumbers[b] == j and j != b:
        result.update([j, b])
  
  print(result)
  print("The sum of amicable numbers in range 1...1000 is: %d\n " % sum(result))


# drivercode 
if __name__ == "__main__":
  main()