package piscine

func IsAlpha(s string) bool {
	for _, v := range s {
		if ('a' <= v && v <= 'z') || ('A' <= v && v <= 'Z') ||
			('0' <= v && v <= '9') {
		} else {
			return false
		}
	}
	return true
}
