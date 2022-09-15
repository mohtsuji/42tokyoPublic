package piscine

func Capitalize(s string) string {
	var re string
	goCapital := false

	for i, v := range s {
		if i == 0 && ('a' <= v && v <= 'z') {
			re += string(v - 32)
		} else if ('a' <= v && v <= 'z') || ('A' <= v && v <= 'Z') ||
			('0' <= v && v <= '9') {
			if goCapital == true && ('a' <= v && v <= 'z') {
				re += string(v - 32)
			} else {
				re += string(v)
			}
			goCapital = false
		} else {
			re += string(v)
			goCapital = true
		}
	}
	return re
}
