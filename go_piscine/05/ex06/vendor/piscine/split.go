package piscine

func countLen(s []byte) int {
	var l int
	for range s {
		l++
	}
	return l
}

func countStringLen(s string) int {
	var l int
	for range s {
		l++
	}
	return l
}

func index(s string, toFind string) int {
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

func substr(s string, start int, end int) string {
	var re string
	for i, v := range s {
		if start <= i && i < end {
			re += string(v)
		}
	}
	return re
}

func Split(s, sep string) []string {
	re := make([]string, 0, 0)
	sLen := countStringLen(s)
	sepLen := countStringLen(sep)
	var end int
	var start int
	var reIndex int

	if sep == "" {
		re = append(re, s)
		return re
	}
	for start < sLen {
		reIndex = index(substr(s, start, sLen), sep)
		if reIndex == -1 {
			re = append(re, substr(s, start, sLen))
			return re
		}
		if start == 0 {
			end += reIndex
		} else {
			end += reIndex + sepLen
		}
		tmp := substr(s, start, end)
		if tmp != "" {
			re = append(re, tmp)
		}
		start = end + sepLen
	}
	return re
}
