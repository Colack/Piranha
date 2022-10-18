package main

import (
	interpreter "piranha/Interpreter"
	info "piranha/Information"
	"fmt"
	"os"
	"strings"
)

func main() {
	args := os.Args[1:]

	if len(args) != 0 {
		if args[0] == "run" {
			if len(args[1]) != 0 && strings.HasSuffix(args[1], ".pir") {
				interpreter.Run(args[1])
			} else {
				fmt.Println("Please specify a '.pir' file.")
			}
		} else {
			fmt.Println("The command '%s' does not exist.", args[0])
		}
	} else {
		fmt.Printf("Chomp %s", Information.versionString)
	}
}
