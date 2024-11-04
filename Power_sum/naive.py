"""
  performing computation (a^b) naively by multiplying a by itself b timess

"""


def power_a_b(a:int,b:int)->int:
  result = 1
  if (b>0):
    for _ in range(b-1,-1,-1):
      result *=a
  
  return result



#driver code
if __name__ == "__main__":
  a = 2
  b = 3
  print(power_a_b(2,3))
  print(pow(2,3)==power_a_b(2,3))