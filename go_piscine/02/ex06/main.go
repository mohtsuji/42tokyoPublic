package main

import (
	"fmt"
	"piscine"
)

func main() {
	fmt.Println(piscine.IsPrime(-1))
	fmt.Println(piscine.IsPrime(0))
	fmt.Println(piscine.IsPrime(1))
	fmt.Println(piscine.IsPrime(2))
	fmt.Println(piscine.IsPrime(5))
	fmt.Println(piscine.IsPrime(4))
}
