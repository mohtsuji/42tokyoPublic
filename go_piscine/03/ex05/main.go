package main

import (
	"fmt"
	"piscine"
)

func main() {
	fmt.Println(piscine.ToUpper("Hello! How are you?"))
	fmt.Println(piscine.ToUpper("Hello! How are あyou?"))
	fmt.Println(piscine.ToUpper(""))
}
