LIMIT = 1000000


def to_binary(n : int)->str:
  number = n
  answer : str = ""

  while (number > 0):
    if (number % 2 == 0):
      answer += "0"
    else:
      answer += "1"
    number//=2
  
  return answer[::-1]


def is_palindrome_base_10(num :int)->bool:
  number = str(num)
  number_string = ""          # number without leading zeros.
  for i in range(len(number)):
    if (number != "0"):
      number_string = number[i:]
      break
    else:
      continue
  return number_string== number_string[::-1]



def is_palindrome_base_2(binary_string :str)->bool:
  #check for leading zeros
  binary = ""
  for i in range(len(binary_string)):
    if (binary_string[i]=="1"):
      binary = binary_string[i:]
      break
    else:
      continue
  
  return binary == binary[::-1]






def main():
  # number = int(input("Enter number to convert to binary.\n"))

  # binary = to_binary(number)
  # print(f"The binary representation of {number} is:\n{binary}")
  double_base_paliondrome = []
  for i in range(LIMIT):
    if (is_palindrome_base_10(i) and is_palindrome_base_2(to_binary(i)) ):
      double_base_paliondrome.append(i)
  

  print(f"The sum of all double base paliondrome is :\n{sum(double_base_paliondrome)}")

  

# drivercode 
if __name__ == "__main__":
  main()