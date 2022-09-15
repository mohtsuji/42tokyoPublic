package piscine

func MakeRange(min, max int) []int {
	if min >= max {
		return nil
	}

	re := make([]int, max-min, max-min)
	for i := 0; min < max; i++ {
		re[i] = min
		min++
	}
	return re
}
