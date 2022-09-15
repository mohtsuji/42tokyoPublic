package piscine

func FindNextPrime(nb int) int {
	re := 2

	if nb <= 2 {
		return 2
	}
	for ; re < nb; re++ {
		if nb%re == 0 {
			nb++
			re = 2
		}
	}
	return nb
}
