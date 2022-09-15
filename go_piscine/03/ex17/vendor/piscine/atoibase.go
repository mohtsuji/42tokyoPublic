package piscine

func countLen(s string) int {
	var l int
	for range s {
		l++
	}
	return l
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

func AtoiBase(s string, base string) int {
	baseLen := countLen(base)
	var re uint
	m := map[rune]int{}

	if errorCheck(base, baseLen) == false {
		return 0
	}

	for i, v := range base {
		m[v] = i
	}

	for _, v := range s {
		if re > ((^uint(0)>>1)-uint(m[v]))/uint(baseLen) {
			return 0
		}
		re = re*uint(baseLen) + uint(m[v])
	}

	return int(re)
}
