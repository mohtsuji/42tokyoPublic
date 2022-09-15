package piscine

func StrRev(s string) string {
	var re string
	for _, v := range s {
		re = string(v) + re
	}
	return re
}
