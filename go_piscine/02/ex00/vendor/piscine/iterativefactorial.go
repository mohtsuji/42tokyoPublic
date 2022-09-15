package piscine

func IterativeFactorial(nb int) int {
	if nb == 0 {
		return 1
	} else if nb < 0 {
		return 0
	}

	var re uint64
	re = uint64(nb)

	nb--
	for ; nb > 1; nb-- {
		if uint64(nb) > 9223372036854775807/re {
			return 0
		}
		re *= uint64(nb)
	}
	return int(re)
}
