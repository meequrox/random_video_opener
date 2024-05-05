package video

import (
	"os"
	"path/filepath"
	"testing"
)

func TestGetFilenames(t *testing.T) {
	dir := t.TempDir()

	input := []string{"1.mp4", "2.MP4", "3.wav",
		"4.MP3", "f.i.f.t.h.avi", "six.th",
		"binary.exe", "script.sh", "______",
		"extensionless", "record.ts", "name with spaces & symbols.mp4"}

	expected := map[string]bool{
		"1.mp4":                          true,
		"2.MP4":                          true,
		"f.i.f.t.h.avi":                  true,
		"record.ts":                      true,
		"name with spaces & symbols.mp4": true,
	}

	for _, filename := range input {
		_, err := os.Create(filepath.Join(dir, filename))
		if err != nil {
			t.Error("Cannot create test file in temporary test directory:", err)
		}
	}

	result := GetFilenames(dir)

	if len(result) != len(expected) {
		t.Errorf("GetFilenames(%q) = %v; len(result) = %d, len(expected) = %d.", input, result, len(result), len(expected))
	}

	for _, filename := range result {
		if !expected[filename] {
			t.Errorf("GetFilenames(%q) = %v; filename %v is not expected.", input, result, filename)
		}
	}
}

func TestIsVideoExtensionKnown(t *testing.T) {
	tests := []struct {
		input    string
		expected bool
	}{
		{".mp4", true},
		{".mkv", true},
		{".webm", true},
		{".mov", true},
		{".avi", true},
		{".m4v", true},
		{".3gp", true},
		{".flv", true},
		{".wmv", true},
		{".mts", true},
		{".m2ts", true},
		{".ts", true},
		{".mpg", true},
		{".mpeg", true},
	}

	for _, test := range tests {
		result := isVideoExtension(test.input)

		if result != test.expected {
			t.Errorf("isVideoExtension(%q) = %v; expected %v.", test.input, result, test.expected)
		}
	}
}

func TestIsVideoExtensionUnknown(t *testing.T) {
	tests := []struct {
		input    string
		expected bool
	}{
		{".rar", false},
		{".mp3", false},
		{".wav", false},
		{".flac", false},
		{".ogg", false},
	}

	for _, test := range tests {
		result := isVideoExtension(test.input)

		if result != test.expected {
			t.Errorf("isVideoExtension(%q) = %v; expected %v.", test.input, result, test.expected)
		}
	}
}

func TestIsVideoExtensionEmptyString(t *testing.T) {
	input := ""
	expected := false

	result := isVideoExtension(input)
	if result != expected {
		t.Errorf("isVideoExtension(%q) = %v; expected %v.", input, result, expected)
	}
}

func TestIsVideoExtensionMixedCase(t *testing.T) {
	tests := []struct {
		input    string
		expected bool
	}{
		{".mP4", true},
		{".MP4", true},
		{".Mp4", true},
		{".MOV", true},
		{".mov", true},
		{".AVI", true},
		{".3GP", true},
		{".MTS", true},
		{".MtS", true},
		{".TS", true},
		{".MPEG", true},
	}

	for _, test := range tests {
		result := isVideoExtension(test.input)

		if result != test.expected {
			t.Errorf("isVideoExtension(%q) = %v; expected %v.", test.input, result, test.expected)
		}
	}
}
