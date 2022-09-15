package piscine

func BasicAtoi(s string) int {
	var re int
	for _, v := range s {
		if re == 0 && v == 0 {
			continue
		} else {
			re = re*10 + (int)(v-'0')
		}
	}
	return re
}
