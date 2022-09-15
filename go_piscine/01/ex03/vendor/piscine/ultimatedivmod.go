package piscine

func UltimateDivMod(a *int, b *int) {
	tmp1 := *a
	tmp2 := *b
	*a = tmp1 / tmp2
	*b = tmp1 % tmp2
}
