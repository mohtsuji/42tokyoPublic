package piscine

import "ft"

func PrintStr(s string) {
	for _, value := range s {
		ft.PrintRune(value)
	}
}
