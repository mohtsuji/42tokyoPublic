package piscine

func ToUpper(s string) string {
	var re string
	for _, v := range s {
		if 'a' <= v && v <= 'z' {
			re += string(v - 32)
		} else {
			re += string(v)
		}
	}
	return re
}
