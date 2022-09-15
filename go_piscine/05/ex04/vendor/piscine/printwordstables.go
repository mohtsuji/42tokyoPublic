package piscine

import "ft"

func SplitWhiteSpaces(s string) []string {
	re := make([]string, 0, 0)
	var tmp string

	complete := false
	for _, v := range s {
		if v == ' ' || v == '	' || v == '\n' {
			if complete == true {
				re = append(re, tmp)
				tmp = ""
				complete = false
			}
		} else {
			tmp += string(v)
			complete = true
		}
	}
	if tmp != "" {
		re = append(re, tmp)
	}
	return re
}

func printString(s string) {
	for _, v := range s {
		ft.PrintRune(v)
	}
	ft.PrintRune('\n')
}

func PrintWordsTables(a []string) {
	for _, v := range a {
		printString(v)
	}
}
