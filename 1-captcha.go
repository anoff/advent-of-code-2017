package main

import (
	"os"
	"fmt"
)

func main() {
	var inputString string
	if (len(os.Args) > 1) {
		inputString = string(os.Args[1])
	} else {
		fmt.Println("Please provide captcha string as argument")
		os.Exit(0)
	}
	
	var sum int
	lookupStr := inputString + inputString
	for pos, char := range inputString {
		var n1, n2 int
		// convert string value to integer
		n1 = int(char - 48)
		if (len(os.Args) > 2 && os.Args[2] == "half") {
			n2 = int(lookupStr[pos + len(inputString) / 2])
		} else {
			n2 = int(lookupStr[pos + 1])
		}
		n2 -= 48

		if (n1 == n2) {
			sum += n1
		}
	}
	fmt.Println("Total sum:", sum)
}
