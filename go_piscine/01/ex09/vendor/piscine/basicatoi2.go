package piscine

func BasicAtoi2(s string) int {
	var re int
	for _, v := range s {
		if v < '0' || '9' < v {
			return 0
		} else if re == 0 && v == 0 {
			continue
		} else {
			re = re*10 + (int)(v-'0')
		}
	}
	return re
}
