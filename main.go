package main

import (
	"fmt"
	"os"
	"os/exec"
	"random_video_opener/random"
	"random_video_opener/video"
	"runtime"
)

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

func main() {
	cwd, err := os.Getwd()
	if err != nil {
		fmt.Println("Cannot get current working directory:", err)
		return
	} else {
		fmt.Println("Directory:", cwd)
	}

	files := video.GetFilenames(cwd)

	if len(files) == 0 {
		fmt.Println("No video files found.")
		return
	}

	index, filename := random.PickFile(files)
	cmd := exec.Command(getOpenCommand(), filename)

	fmt.Println("Files:", len(files))
	fmt.Printf("File [%d]: %s\n", index, filename)
	fmt.Println("Command:", cmd)

	err = cmd.Start()
	if err != nil {
		fmt.Println("Cannot open video file:", err)
	}
}
