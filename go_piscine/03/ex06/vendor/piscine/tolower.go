package piscine

func ToLower(s string) string {
	var re string
	for _, v := range s {
		if 'A' <= v && v <= 'Z' {
			re += string(v + 32)
		} else {
			re += string(v)
		}
	}
	return re
}
