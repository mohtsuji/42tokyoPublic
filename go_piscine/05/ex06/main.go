package main

import (
	"fmt"
	"piscine"
)

func main() {

	s := "HelloHAhowHAareHAyou?"
	fmt.Printf("%#v\n", piscine.Split(s, "HA"))
	s = "HelloHAhowHAareHAyou?HAdoingHA"
	fmt.Printf("%#v\n", piscine.Split(s, "HA"))

	s = "aAaaA"
	fmt.Printf("%#v\n", piscine.Split(s, "A"))
	s = "HelloHAhowHAareHAyou?"
	fmt.Printf("%#v\n", piscine.Split(s, "ZZ"))
	s = "AaAAaaA"
	fmt.Printf("%#v\n", piscine.Split(s, "A"))
	s = "aAAaaAAAAA"
	fmt.Printf("%#v\n", piscine.Split(s, "A"))
	s = "aAAaAaAAAAA"
	fmt.Printf("%#v\n", piscine.Split(s, "AA"))
	s = ""
	fmt.Printf("%#v\n", piscine.Split(s, "AA"))
	s = "aAAaAaAAAAA"
	fmt.Printf("%#v\n", piscine.Split(s, ""))
	s = "AAAaAAAaAaAAAAA"
	fmt.Printf("%#v\n", piscine.Split(s, "AA"))

}
