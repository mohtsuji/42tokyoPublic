package main

import (
	"fmt"
	"piscine"
)

func main() {
	fmt.Println(piscine.IterativePower(4, 3))
	fmt.Println(piscine.IterativePower(0, 3))
	fmt.Println(piscine.IterativePower(-4, 3))
	fmt.Println(piscine.IterativePower(0, 0))
	fmt.Println(piscine.IterativePower(9, 0))
	fmt.Println(piscine.IterativePower(9, -9))
}
