package piscine

func countLen(s string) int {
	var l int
	for range s {
		l++
	}
	return l
}

func toDecimal(nbr, baseFrom string) int {
	nbrLen := countLen(nbr)
	baseLen := countLen(baseFrom)
	decimal := 0
	weight := 1
	for i := nbrLen - 1; i >= 0; i-- {
		decimal += int(nbr[i]-'0') * weight
		weight *= baseLen
	}
	return decimal
}

func toBaseTo(decimal int, baseTo string) string {
	baseToLen := countLen(baseTo)
	var re string

	for decimal > 0 {
		re = string(baseTo[decimal%baseToLen]) + re
		decimal /= baseToLen
	}
	return re
}

func ConvertBase(nbr, baseFrom, baseTo string) string {
	decimal := toDecimal(nbr, baseFrom)
	return toBaseTo(decimal, baseTo)
}
