package piscine

func IterativePower(nb int, power int) int {
	if power < 0 {
		return 0
	} else if power == 0 {
		return 1
	}
	re := nb
	for ; power > 1; power-- {
		re = re * nb
	}
	return int(re)
}
