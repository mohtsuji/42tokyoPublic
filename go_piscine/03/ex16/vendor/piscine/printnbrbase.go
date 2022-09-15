package piscine

import "ft"

func countLen(s string) int {
	var l int
	for range s {
		l++
	}
	return l
}

func printString(s string) {
	for _, v := range s {
		ft.PrintRune(v)
	}
}

func errorCheck(base string, l int) bool {
	if l < 2 {
		return false
	}

	for i := 0; i < l; i++ {
		if base[i] == '+' || base[i] == '-' {
			return false
		}
		for j := i + 1; j < l; j++ {
			if base[i] == base[j] {
				return false
			}
		}
	}
	return true
}

func PrintNbrBase(nbr int, base string) {
	var re string
	var n uint64
	neg := false
	l := countLen(base)

	if errorCheck(base, l) == false {
		printString("NV")
		return
	}

	if nbr < 0 {
		neg = true
		if nbr == -9223372036854775808 {
			n = 9223372036854775808
		} else {
			n = uint64(nbr * -1)
		}
	} else {
		n = uint64(nbr)
	}

	if n == 0 {
		re = string(base[0])
	} else {
		for n > 0 {
			re = string(base[n%uint64(l)]) + re
			n /= uint64(l)
		}
	}

	if neg == true {
		re = "-" + re
	}

	printString(re)
}
