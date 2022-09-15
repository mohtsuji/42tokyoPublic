package piscine

func IsPrime(nb int) bool {
	re := 2

	if nb <= 1 {
		return false
	}
	for ; re < nb; re++ {
		if nb%re == 0 {
			return false
		}
	}
	return true
}
