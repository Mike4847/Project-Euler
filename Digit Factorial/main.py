def factorial(number: int) -> str:
    MAX = 1000
    result = [0] * MAX
    result[0] = 1
    result_length = 1

    for i in range(2, number + 1):
        carry = 0
        for j in range(result_length):
            mult = result[j] * i + carry
            result[j] = mult % 10
            carry = mult // 10

        while carry > 0:
            result[result_length] = carry % 10
            carry //= 10
            result_length += 1
    
    result = result[:result_length][::-1]
    # Reverse the result to get the correct order
    return ''.join(str(x) for x in result)



def is_digit_factorial( number :int):
    
    sum = 0
    num = str(number)
    for i in range(len(num)):
        sum += int(factorial(int(num[i])))
    return number == sum 
        



def main():
    MAX = 1000000
    fact = input("Calculate the factorial of :\n")
    #print(f"And the factorial is : {factorial(int(fact))}.\n")
    

    arr_factorials = []

    for i in range(10,MAX):
        if(is_digit_factorial(i)):
            arr_factorials.append(i)

    print(sum(arr_factorials))

 

if __name__ == "__main__":
    main()
