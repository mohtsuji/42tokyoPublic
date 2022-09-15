package main

import (
	"fmt"
	"piscine"
)

func main() {
	fmt.Println(piscine.RecursivePower(4, 3))
	fmt.Println(piscine.RecursivePower(0, 3))
	fmt.Println(piscine.RecursivePower(-4, 3))
	fmt.Println(piscine.RecursivePower(0, 0))
	fmt.Println(piscine.RecursivePower(9, 0))
	fmt.Println(piscine.RecursivePower(9, -9))
	fmt.Println(piscine.RecursivePower(9, 1))
}
