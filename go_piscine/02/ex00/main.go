package main

import (
	"fmt"
	"piscine"
)

func main() {
	arg := 4
	fmt.Println(piscine.IterativeFactorial(arg))
	arg1 := 0
	fmt.Println(piscine.IterativeFactorial(arg1))
	arg2 := 1
	fmt.Println(piscine.IterativeFactorial(arg2))
	arg3 := 2
	fmt.Println(piscine.IterativeFactorial(arg3))
	arg4 := 9223372036854775807
	fmt.Println(piscine.IterativeFactorial(arg4))
	arg5 := 20 //safe
	fmt.Println(piscine.IterativeFactorial(arg5))
	arg6 := 21 //out
	fmt.Println(piscine.IterativeFactorial(arg6))
}
