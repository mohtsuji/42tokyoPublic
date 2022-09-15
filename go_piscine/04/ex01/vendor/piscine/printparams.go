package piscine

import (
	"ft"
	"os"
)

func PrintParams() {
	for i, v := range os.Args {
		if i == 0 {
			continue
		}
		for _, s := range v {
			ft.PrintRune(s)
		}
		ft.PrintRune('\n')
	}
}
