package piscine

func IsLower(s string) bool {
	for _, v := range s {
		if 'a' <= v && v <= 'z' {
		} else {
			return false
		}
	}
	return true
}
