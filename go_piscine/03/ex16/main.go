package main

import (
	"ft"
	"piscine"
)

func main() {
	piscine.PrintNbrBase(125, "0123456789")
	ft.PrintRune('\n')
	piscine.PrintNbrBase(-125, "01")
	ft.PrintRune('\n')
	piscine.PrintNbrBase(125, "0123456789ABCDEF")
	ft.PrintRune('\n')
	piscine.PrintNbrBase(-125, "choumi")
	ft.PrintRune('\n')
	piscine.PrintNbrBase(125, "aa") //NV
	ft.PrintRune('\n')
	piscine.PrintNbrBase(125, "a") //NV
	ft.PrintRune('\n')
	piscine.PrintNbrBase(125, "987+") //NV
	ft.PrintRune('\n')
	piscine.PrintNbrBase(125, "98-7") //NV
	ft.PrintRune('\n')
	piscine.PrintNbrBase(125, "9877") //NV
	ft.PrintRune('\n')
	piscine.PrintNbrBase(125, "9879") //NV
	ft.PrintRune('\n')
	piscine.PrintNbrBase(-9223372036854775808, "0123456789ABCDEF")
	ft.PrintRune('\n')
	piscine.PrintNbrBase(0, "0123456789ABCDEF")
	ft.PrintRune('\n')
	piscine.PrintNbrBase(1, "0123456789ABCDEF")
	ft.PrintRune('\n')
	piscine.PrintNbrBase(16, "0123456789ABCDEF")
	ft.PrintRune('\n')
}
