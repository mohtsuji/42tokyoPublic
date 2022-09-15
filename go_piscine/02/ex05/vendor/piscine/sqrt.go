package piscine

func Sqrt(nb int) int {
	re := 1

	for ; re <= nb/re; re++ {
		if re*re == nb {
			return re
		}
	}
	return 0
}
