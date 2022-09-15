package piscine

func RecursiveFactorial(nb int) int {
	var re uint64
	if nb == 0 {
		return 1
	} else if nb < 0 {
		return 0
	}

	re = uint64(RecursiveFactorial(nb - 1))

	if uint64(nb) > 9223372036854775807/re {
		return 0
	}
	return int(re) * nb
}
