package piscine

func countLen(s []string) int {
	var l int
	for range s {
		l++
	}
	return l
}

func ConcatParams(args []string) string {
	l := countLen(args)

	var re string
	for i, v := range args {
		re += v
		if i != l-1 {
			re += "\n"
		}
	}
	return re
}
