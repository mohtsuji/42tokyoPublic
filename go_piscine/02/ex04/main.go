package main

import (
	"fmt"
	"piscine"
)

func main() {
	fmt.Println(piscine.Fibonacci(4))
	fmt.Println(piscine.Fibonacci(0))
	fmt.Println(piscine.Fibonacci(1))
	fmt.Println(piscine.Fibonacci(-4))
	fmt.Println(piscine.Fibonacci(42))
}
