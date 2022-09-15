package piscine

func IsPrintable(s string) bool {
	for _, v := range s {
		if 32 <= v && v <= 126 {
		} else {
			return false
		}
	}
	return true
}
