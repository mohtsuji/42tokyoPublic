package piscine

func LastRune(s string) rune {
	var l int

	for range s {
		l++
	}
	return []rune(s)[l-1]
}
