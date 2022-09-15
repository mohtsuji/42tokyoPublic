package piscine

func NRune(s string, n int) rune {
	if n < 0 {
		return 0
	}

	var l int
	for range s {
		l++
	}
	if l < n {
		return 0
	}
	return []rune(s)[n-1]
}
