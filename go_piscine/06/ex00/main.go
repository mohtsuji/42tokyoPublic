package main

import (
	"ft"
	"os"
)

type boolean bool

func printStr(s string) {
	for _, r := range s {
		ft.PrintRune(r)
	}
	ft.PrintRune('\n')
}

func even(nbr int) int {
	if nbr%2 == 0 {
		return 1
	} else {
		return 0
	}
}

func isEven(nbr int) boolean {
	if even(nbr) == 1 {
		return yes
	} else {
		return no
	}
}

func countLen(s []string) int {
	var l int
	for range s {
		l++
	}
	return l
}

func main() {
	lengthOfArg := countLen(os.Args)
	if isEven(lengthOfArg) == 1 {
		printStr(EvenMsg)
	} else {
		printStr(OddMsg)
	}
}
