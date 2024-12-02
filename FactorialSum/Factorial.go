package main 

// import the io library
import ("fmt")

func main() {
	x:= userInput()

	
	factorial := Factorial(x)

	answer:= 0
	for _,value:= range factorial{
		answer+= value
		
	}
	fmt.Printf("The sum of the above factoral %d\n",x)
	fmt.Println(answer)

}


// func to get the factorial of a number 
// returns the factorial as an array of ints 
func Factorial(x int ) []int{
	//slice to hold the value of the result
	result:= []int{1}

	// variable for holding the value f carry
	var carry int


	for i := 2 ; i <= x; i++ {
		carry = 0
		for j, value:= range(result) {
			multipl := (value * i) + carry
			result[j] = multipl % 10

			carry = multipl / 10 

		}

		// while their is still carry 
		for carry > 0 {
			result = append(result,carry % 10)
			carry /= 10 
		}


		
	}
	return result

}

// getting user input from the keyboard 
func userInput() int{
	var factnum int
	fmt.Println("Enter number(integer) \n To get factorial.")
	fmt.Scanln(&factnum)



	return factnum 
}