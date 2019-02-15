package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"time"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func puzzle1() {
	f, err := os.Open("frequencies.txt")
	check(err)

	readbuff := bufio.NewScanner(f)
	//line, err := readbuff.ReadSlice('\n')
	freq := 0
	for readbuff.Scan() {
		temp, _ := strconv.Atoi(readbuff.Text())
		check(err)
		freq += temp
	}
	fmt.Printf("Number: %v\n", freq)
}

func puzzle2() {
	//	f, err := os.OpenFile("frequencies.txt", os.O_RDONLY, 0777)
	//	check(err)

	//	readbuff := bufio.NewScanner(f)
	//line, err := readbuff.ReadSlice('\n')
	freq := 0
	match := 0

	m := make(map[int]int)

	for match == 0 {
		f, err := os.OpenFile("frequencies.txt", os.O_RDONLY, 0777)
		readbuff := bufio.NewScanner(f)
		for readbuff.Scan() {
			temp, _ := strconv.Atoi(readbuff.Text())
			//	fmt.Printf("%v\n", temp)
			check(err)
			freq += temp
			if 0 == m[freq] {
				m[freq] = freq
				//				fmt.Print("%v", freq)
			} else {
				fmt.Printf("found: %v\n", freq)
				match++
				break
			}
		}
		f.Close()
		//	fmt.Printf("rewind\n")
	}
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
