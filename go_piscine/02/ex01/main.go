package main

import (
	"fmt"
	"piscine"
)

func main() {
	arg := 4
	fmt.Println(piscine.RecursiveFactorial(arg))
	arg1 := 0
	fmt.Println(piscine.RecursiveFactorial(arg1))
	arg2 := 1
	fmt.Println(piscine.RecursiveFactorial(arg2))
	arg3 := 2
	fmt.Println(piscine.RecursiveFactorial(arg3))
	arg5 := 20 //safe
	fmt.Println(piscine.RecursiveFactorial(arg5))
	arg6 := 21 //out
	fmt.Println(piscine.RecursiveFactorial(arg6))
}
