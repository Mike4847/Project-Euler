# binary exponentiaion is a somewhat algorithmic modular in some sense
# Works by reducing the operation performed through squaring  

def binary_exp(a:int,b:int)->str:
  """
  Also called exponentiation by squaring
  Above method works for large numbers that are somewhat infeasible with the inbult power func

  Args:
      a (int): base
      b (int): exponent

  Returns:
      int: results after multiplying a b time
  """
  result = 1
  while (b>0):
    if (b%2):
      result *= a
    a*=a
    b//=2

  return str(result)

def Sum(result:str)->int:
  _sum= 0
  for i in range(len(result)):
    _sum +=int(result[i])

  return _sum




#driver code 
if __name__ == "__main__":
  a =2
  b = 1000
  results = binary_exp(a,b)
  print(Sum(results))