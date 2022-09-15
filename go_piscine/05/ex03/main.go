package main

import (
	"fmt"
	"piscine"
)

func main() {
	fmt.Printf("%#v\n", piscine.SplitWhiteSpaces("Hello how are you?"))
	fmt.Printf("%#v\n", piscine.SplitWhiteSpaces("Hello		how are you?"))
	fmt.Printf("%#v\n", piscine.SplitWhiteSpaces("Hello\nhow are you?    "))
	fmt.Printf("%#v\n", piscine.SplitWhiteSpaces("    Hello how are you?"))
	fmt.Printf("%#v\n", piscine.SplitWhiteSpaces(""))
	fmt.Printf("%#v\n", piscine.SplitWhiteSpaces("     \n"))
}
