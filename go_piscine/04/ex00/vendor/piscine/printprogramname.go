package piscine

import (
	"ft"
	"os"
)

func countByteLen(s string) int {
	var l int
	res := []byte(s)
	for range res {
		l++
	}
	return l
}

func findSlush(s string) int {
	for i := countByteLen(s) - 1; i >= 0; i-- {
		if s[i] == '/' {
			return i
		}
	}
	return 0
}

func PrintProgramName() {
	s, _ := os.Executable()
	index := findSlush(s)

	for i, v := range s {
		if i <= index {
			continue
		}
		ft.PrintRune(v)
	}
}
