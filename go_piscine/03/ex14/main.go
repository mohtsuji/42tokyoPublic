package main

import (
	"fmt"
	"piscine"
)

func main() {
	elems := []string{"Hello!", " How", " are", " you?"}
	fmt.Println(piscine.BasicJoin(elems))
	elems2 := []string{"Hello!", "", " are", " you?"}
	fmt.Println(piscine.BasicJoin(elems2))
}
