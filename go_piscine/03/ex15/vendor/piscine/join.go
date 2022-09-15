package piscine

func Join(strs []string, sep string) string {
	var re string
	var l int

	for range strs {
		l++
	}
	for i, v := range strs {
		re += v
		if i < l-1 {
			re += sep
		}
	}
	return re
}
