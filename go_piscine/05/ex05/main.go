package main

import (
	"fmt"
	"piscine"
)

func main() {
	result := piscine.ConvertBase("101011", "01", "0123456789")
	fmt.Println(result)
	result16 := piscine.ConvertBase("101011", "01", "0123456789ABCDEF")
	fmt.Println(result16)
}
