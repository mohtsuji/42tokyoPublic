package piscine

func IsUpper(s string) bool {
	for _, v := range s {
		if 'A' <= v && v <= 'Z' {
		} else {
			return false
		}
	}
	return true
}
