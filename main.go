package main

import (
	"fmt"
	"math/rand"
	"os"
	"os/exec"
	"path/filepath"
	"runtime"
	"time"
)

var videoExtensions = []string{".mp4", ".mkv", ".webm", ".flv", ".avi", ".mts", ".mpg", ".m2ts", ".ts", ".mov", ".wmv", ".m4v", ".3gp", ".mpeg"}

func getRandomGenerator() *rand.Rand {
	seed := time.Now().UnixNano()
	generator := rand.New(rand.NewSource(seed))

	return generator
}

// TODO: Test this function
func chooseRandomFile(filenames []string) (int, string) {
	generator := getRandomGenerator()

	filenames = shuffleFilenames(filenames, generator)
	index := generator.Intn(len(filenames))

	return index, filenames[index]
}

func shuffleFilenames(slice []string, generator *rand.Rand) []string {
	fun := func(i int, j int) {
		// 20% swap chance
		if generator.Intn(10) < 2 {
			slice[i], slice[j] = slice[j], slice[i]

			// TODO: remove
			fmt.Printf("Shuffled: %d <-> %d\n", i, j)
		}
	}

	rand.Shuffle(len(slice), fun)
	return slice
}

func getOpenCommand() string {
	cmd := ""
	os := runtime.GOOS

	switch os {
	case "linux":
		cmd = "xdg-open"
	case "darwin":
		cmd = "open"
	case "windows":
		cmd = "start .\\"
	default:
		fmt.Printf("Probably unsupported OS: %s. Trying fallback command.", os)
		cmd = "open"
	}

	return cmd
}

func isVideo(filename string) bool {
	ext := filepath.Ext(filename)

	for _, knownExt := range videoExtensions {
		if knownExt == ext {
			return true
		}
	}

	return false
}

func getVideoFilenames(path string) []string {
	files, err := os.ReadDir(path)
	if err != nil {
		fmt.Println("Cannot read current working directory:", err)
	}

	var videos []string

	for _, file := range files {
		if !file.IsDir() && isVideo(file.Name()) {
			videos = append(videos, file.Name())
		}
	}

	return videos
}

func main() {
	cwd, err := os.Getwd()
	if err != nil {
		fmt.Println("Cannot get current working directory:", err)
		return
	} else {
		fmt.Println("Directory:", cwd)
	}

	files := getVideoFilenames(cwd)

	if len(files) == 0 {
		fmt.Println("No video files found.")
		return
	}

	index, filename := chooseRandomFile(files)
	cmd := exec.Command(getOpenCommand(), filename)

	fmt.Println("Files:", len(files))
	fmt.Printf("File [%d]: %s\n", index, filename)
	fmt.Println("Command:", cmd)

	err = cmd.Start()
	if err != nil {
		fmt.Println("Cannot open video file:", err)
	}
}
