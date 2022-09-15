package piscine

func AppendRange(min, max int) []int {
	if min >= max {
		return nil
	}

	var re []int
	for ; min < max; min++ {
		re = append(re, min)
	}
	return re
}
