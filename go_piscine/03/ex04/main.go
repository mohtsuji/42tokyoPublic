package main

import (
	"fmt"
	"piscine"
)

func main() {
	fmt.Println(piscine.Compare("Hello!", "Hello!"))
	fmt.Println(piscine.Compare("Salut!", "lut!"))
	fmt.Println(piscine.Compare("Ola!", "Ol"))
	fmt.Println(piscine.Compare("O", "Ol"))  //-1
	fmt.Println(piscine.Compare("Oあ", "Oお")) //-1
	fmt.Println(piscine.Compare("", "Oお"))   //-1
	fmt.Println(piscine.Compare("Oあ", ""))   //1
}
