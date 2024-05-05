package random

import (
	"os"
	"path/filepath"
	"random_video_opener/video"
	"strconv"
	"testing"
)

func TestPickFile(t *testing.T) {
	dir := t.TempDir()
	tries := 200

	// Create test files
	for i := 0; i < tries; i++ {
		filename := strconv.Itoa(i) + ".mp4"

		_, err := os.Create(filepath.Join(dir, filename))
		if err != nil {
			t.Error("Cannot create test file in temporary test directory:", err)
		}
	}

	files := video.GetFilenames(dir)
	counters := make(map[string]int)

	// Pick random files multiple times
	for i := 0; i < tries*8; i++ {
		_, file := PickFile(files)
		counters[file] += 1
	}

	// Check whether each file has been picked at least 1 time
	if len(counters) < tries {
		t.Errorf("PickFile algorithm is not working optimally. Expected %d keys in map, got %d.", tries, len(counters))
	}
}
