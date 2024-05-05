package video

import (
	"fmt"
	"os"
	"path/filepath"
	"strings"
)

func GetFilenames(path string) []string {
	files, err := os.ReadDir(path)
	if err != nil {
		fmt.Println("Cannot read current working directory:", err)
	}

	var videos []string

	for _, file := range files {
		ext := filepath.Ext(file.Name())

		if !file.IsDir() && isVideoExtension(ext) {
			videos = append(videos, file.Name())
		}
	}

	return videos
}

func isVideoExtension(ext string) bool {
	status := false

	switch strings.ToLower(ext) {
	case ".mp4",
		".mkv",
		".webm",
		".mov",
		".avi",
		".m4v",
		".3gp",
		".flv",
		".wmv",
		".mts",
		".m2ts",
		".ts",
		".mpg",
		".mpeg":
		status = true
	}

	return status
}
