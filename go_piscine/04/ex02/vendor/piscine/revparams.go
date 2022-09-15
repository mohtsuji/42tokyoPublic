package piscine

import (
	"ft"
	"os"
)

func countLen(arg []string) int {
	var l int
	for range arg {
		l++
	}
	return l
}

func RevParams() {
	l := countLen(os.Args) - 1

	for ; l > 0; l-- {
		for _, s := range os.Args[l] {
			ft.PrintRune(s)
		}
		ft.PrintRune('\n')
	}
}
