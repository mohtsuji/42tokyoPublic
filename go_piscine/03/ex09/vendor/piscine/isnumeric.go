package piscine

func IsNumeric(s string) bool {
	for _, v := range s {
		if '0' <= v && v <= '9' {
		} else {
			return false
		}
	}
	return true
}
