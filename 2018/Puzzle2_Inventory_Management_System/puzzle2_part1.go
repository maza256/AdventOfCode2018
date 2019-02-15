package main

import (
	"bufio"
	"fmt"
	"os"
	s "strings"
	"time"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func puzzle1() {
	f, err := os.Open("inventory_list.txt")
	check(err)

	readbuff := bufio.NewScanner(f)
	dubsCount := 0
	dubs := 0
	trips := 0
	tripsCount := 0
	//line, err := readbuff.ReadSlice('\n')
	//	freq := 0
	for readbuff.Scan() {
		str := string(readbuff.Text())
		for i := 0; i < len(str); i++ {
			if str[i] != '+' {
				count := s.Count(str, string(str[i]))
				if count == 2 {
					dubsCount = 1
				}
				if count == 3 {
					tripsCount = 1
				}
				str = s.Replace(str, string(str[i]), "+", -1)
				//	fmt.Printf("%s\n ", str)
			}
		}
		dubs += dubsCount
		trips += tripsCount
		dubsCount = 0
		tripsCount = 0

	}
	fmt.Printf("Number: %v %v %v\n", dubs, trips, trips*dubs)
}

func puzzle2() {
	f, err := os.Open("inventory_list.txt")
	check(err)

	readbuff := bufio.NewScanner(f)

	match := 0
	a := make([]string, 0)

	for readbuff.Scan() {
		stemp := string(readbuff.Text())
		a = append(a, stemp)
	}
	//	fmt.Println(a)
	position := 0
	testing := 0

	for match == 0 {
		for i := 1; i < len(a)-1; i++ {
			//	b := string(a[i])

			mistakes := 2

			for k := 0; k < 26; k++ {
				if !(a[position][k] == a[i][k]) {
					mistakes--
				}
				if mistakes == 0 {
					continue
				}
			}
			if mistakes == 1 {
				fmt.Printf("%s\n%s\n", a[i], a[position])
				match++
				break

			}
			if testing == 0 {
				//sslice := append(sslice, a[position])
				position++
				testing = 1
			}
		}
		testing = 0
	}
	f.Close()
}

func main() {
	//Reads Entire file!
	//	dat, err := ioutil.ReadFile("frequencies.txt")
	//	check(err)
	//Prints Entire File
	//	fmt.Print(string(dat))

	puzzle1()
	timer1 := time.Now()
	puzzle2()
	timer2 := time.Now()
	elapsed := timer2.Sub(timer1)
	fmt.Printf("Time elapsed: %v\n", elapsed)
}
