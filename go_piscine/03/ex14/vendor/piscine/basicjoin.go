package piscine

func BasicJoin(elems []string) string {
	var re string
	for _, v := range elems {
		re += v
	}
	return re
}
