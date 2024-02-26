package main

import (
	"fmt"
	"log"
	"os"
	"strconv"
)

const FILE_START = 1
const FILE_END = 25
const PUZZLES = "/source/problems/"
const SOLUTIONS = "/source/solutions/"
const INPUTS = "/source/inputs/"
const SAMPLES = "/source/samples/"
const MARKDOWN = ".md"
const INPUT = ".input"
const GO = ".go"

func CodeGenerator() {
	GenerateMarkdownFiles()
	GenerateSolutions()
	GenerateInputFiles()
	GenerateSampleInputFiles()
}

func GenerateMarkdownFiles() {
	for FILE_START := 1; FILE_START <= FILE_END; FILE_START++ {
		for index := 0; index <= 1; index++ {

			stringBuilder, err := os.Getwd()
			if err != nil {
				log.Fatal(err)
			}
			stringBuilder += PUZZLES
			if _, err := os.Stat(stringBuilder); os.IsNotExist(err) {
				err = os.Mkdir(stringBuilder, os.ModeDir)
				if err != nil {
					log.Fatal(err)
				}
			}
			stringBuilder += "Problem"
			if FILE_START < 10 {
				stringBuilder += "0"
			}
			stringBuilder += strconv.Itoa(FILE_START)
			if index == 0 {
				stringBuilder += "A"
			}
			if index == 1 {
				stringBuilder += "B"
			}
			stringBuilder += MARKDOWN
			_, err = os.Create(stringBuilder)
			if err != nil {
				log.Fatal(err)
			}
		}
	}
}

func GenerateSolutions() {
	for FILE_START := 1; FILE_START <= FILE_END; FILE_START++ {
		for index := 0; index <= 1; index++ {
			directoryBuilder, err := os.Getwd()
			if err != nil {
				log.Fatal(err)
			}
			directoryBuilder += SOLUTIONS
			if _, err := os.Stat(directoryBuilder); os.IsNotExist(err) {
				if err = os.Mkdir(directoryBuilder, os.ModeDir); err != nil {
					log.Fatal(err)
				}
			}

			fileBuilder := "Solution"
			if FILE_START < 10 {
				fileBuilder += "0"
			}
			fileBuilder += strconv.Itoa(FILE_START)
			template := ""
			if index == 0 {
				fileBuilder += "A"
				template = fmt.Sprintf(SOLUTION_TEMPLATE, fileBuilder)
			}
			if index == 1 {
				fileBuilder += "B"
				template = fmt.Sprintf(SOLUTION_TEMPLATE, fileBuilder)
			}
			fileBuilder += GO
			file, err := os.Create(directoryBuilder + fileBuilder)
			if err != nil {
				log.Fatal(err)
			}
			if _, err := file.Write([]byte(template)); err != nil {
				log.Fatal(err)
			}
			if err := file.Close(); err != nil {
				log.Fatal(err)
			}
		}
	}
}

func GenerateInputFiles() {
	for FILE_START := 1; FILE_START <= FILE_END; FILE_START++ {
		stringBuilder, err := os.Getwd()
		if err != nil {
			log.Fatal(err)
		}
		stringBuilder += INPUTS
		if _, err := os.Stat(stringBuilder); os.IsNotExist(err) {
			err = os.Mkdir(stringBuilder, os.ModeDir)
			if err != nil {
				log.Fatal(err)
			}
		}
		stringBuilder += "Input"
		if FILE_START < 10 {
			stringBuilder += "0"
		}
		stringBuilder += strconv.Itoa(FILE_START)
		stringBuilder += INPUT
		_, err = os.Create(stringBuilder)
		if err != nil {
			log.Fatal(err)
		}
	}
}

func GenerateSampleInputFiles() {
	for FILE_START := 1; FILE_START <= FILE_END; FILE_START++ {
		stringBuilder, err := os.Getwd()
		if err != nil {
			log.Fatal(err)
		}
		stringBuilder += SAMPLES
		if _, err := os.Stat(stringBuilder); os.IsNotExist(err) {
			err = os.Mkdir(stringBuilder, os.ModeDir)
			if err != nil {
				log.Fatal(err)
			}
		}
		stringBuilder += "Sample"
		if FILE_START < 10 {
			stringBuilder += "0"
		}
		stringBuilder += strconv.Itoa(FILE_START)
		stringBuilder += INPUT
		_, err = os.Create(stringBuilder)
		if err != nil {
			log.Fatal(err)
		}
	}
}

// if _, err := os.Stat("/path/to/whatever"); os.IsNotExist(err) {
//     // path/to/whatever does not exist
// }

// if _, err := os.Stat("/path/to/whatever"); err == nil {
//     // path/to/whatever exists
// }
