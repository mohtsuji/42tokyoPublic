package piscine

func countLen(s []byte) int {
	var l int
	for range s {
		l++
	}
	return l
}

func Index(s string, toFind string) int {
	final := true
	var re int

	sb := []byte(s)
	fb := []byte(toFind)
	sLen := countLen(sb)
	for i := range sb {
		re = i
		for j := range fb {
			if i >= sLen {
				final = false
				break
			} else if sb[i] != fb[j] {
				final = false
				break
			}
			i++
		}
		if final == true {
			return re
		}
		final = true
	}
	return -1
}
