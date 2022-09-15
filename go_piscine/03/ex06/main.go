package main

import (
	"fmt"
	"piscine"
)

func main() {
	fmt.Println(piscine.ToLower("Hello! How are you?"))
	fmt.Println(piscine.ToLower("Hello! How are あyou?"))
	fmt.Println(piscine.ToLower(""))
}
