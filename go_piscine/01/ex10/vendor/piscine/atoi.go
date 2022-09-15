package piscine

func Atoi(s string) int {
	var re int
	neg := 1

	for i, v := range s {
		if i == 0 && (v == '+' || v == '-') {
			if v == '-' {
				neg = -1
			}
			continue
		}
		if v < '0' || '9' < v {
			return 0
		} else if re == 0 && v == 0 {
			continue
		} else {
			re = re*10 + (int)(v-'0')
		}
	}
	return re * neg
}
