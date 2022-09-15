package main

import (
	"fmt"
	"ft"
	"piscine"
	"strconv"
)

func main() {
	s := ""
	s = s + "1"
	fmt.Println(piscine.BasicAtoi(s))
	fmt.Println(strconv.Atoi(s))
	fmt.Println(piscine.BasicAtoi("12345"))
	fmt.Println(piscine.BasicAtoi("0000000012345"))
	fmt.Println(piscine.BasicAtoi("000000"))

	var r rune
	r = 0
	ft.PrintRune(0)
	ft.PrintRune('\n')
	fmt.Println("piscine=", piscine.BasicAtoi(string(r)+"1"))
	fmt.Println(strconv.Atoi(string(r)))
	fmt.Println("piscine=", piscine.BasicAtoi(string(r)+"1"))
	fmt.Println(strconv.Atoi(string(r) + "1"))
	/*	ft.PrintRune(0)
		ft.PrintRune('\n')
		ft.PrintRune(1)
		ft.PrintRune('\n')*/
}
