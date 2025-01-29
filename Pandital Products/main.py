"""
    The pandital problem statement:
    For a number to be pandital in some sense, its all about all its multicands and the products must contain
    the digits 1 through n.
    n = 9  , in this case.
"""


def is_pandital(A: int, B:int)->bool:
    mult_str =str( A * B) 
    answer = set()
    # the idea is checking that the product and the multicands digits are 1 through 9
    str_a = str(A)
    str_b = str(B)

    if (len(mult_str) + len(str_a) + len(str_b) != 9):
        return False
    for digit in str_a:
        answer.add(digit)

    for digit in str_b:
        answer.add(digit)   
    for digit in mult_str:
        answer.add(digit)


    #test cases
    # print(f"{A} X {B} = {A * B}")
    for i in range(1,10):
        if (str(i) not in answer ):          
            return False

    #print the sets of digits.

    # print(f"The set of digits are {answer}")
    return True


def main():

    LIMIT = 10000

    # set to avoid duplicates
    answer = set()
    for i in range(1,LIMIT):
        for j in range(i,LIMIT):
            if (is_pandital(i,j)):
                answer.add((i * j))
            





    print(f"The answer is {sum(answer)}")

                



#driver code
if __name__ == "__main__":
    main()
    #print(is_pandital(39, 186))


