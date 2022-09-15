package main

import (
	"fmt"
	"piscine"
)

func main() {
	toConcat := []string{"Hello!", " How", " are", " you?"}
	fmt.Println(piscine.Join(toConcat, ":"))
	toConcat2 := []string{"", " How", " are", " you?"}
	fmt.Println(piscine.Join(toConcat2, "qqqqq"))
}
