package piscine

import (
	"ft"
	"os"
)

func countLen(arg []string) int {
	var l int
	for range arg {
		l++
	}
	return l
}

func countLenByte(arg []byte) int {
	var l int
	for range arg {
		l++
	}
	return l
}

func compare(a, b string) int {
	ab := []byte(a)
	bb := []byte(b)
	alen := countLenByte(ab)
	blen := countLenByte(bb)
	var l int

	if alen >= blen {
		l = blen
	} else {
		l = alen
	}

	for i := 0; i < l; i++ {
		if ab[i] > bb[i] {
			return 1
		} else if ab[i] < bb[i] {
			return -1
		}
	}

	if alen == blen {
		return 0
	} else if alen > blen {
		return 1
	} else {
		return -1
	}

}

func SortParams() {
	l := countLen(os.Args)

	args := os.Args
	for i := 1; i < l; i++ {
		for j := i + 1; j < l; j++ {
			if compare(args[i], args[j]) > 0 {
				args[i], args[j] = args[j], args[i]
			}
		}
	}

	for i, v := range args {
		if i == 0 {
			continue
		}
		for _, d := range v {
			ft.PrintRune(d)
		}
		ft.PrintRune('\n')
	}
}
