package piscine

func Fibonacci(index int) int {
	if index == 0 || index == 1 {
		return index
	} else if index < 0 {
		return -1
	}
	var re uint64

	re = uint64(Fibonacci(index-2) + Fibonacci(index-1))
	if re > 9223372036854775807 {
		return 0
	}
	return int(re)
}
