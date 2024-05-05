package random

import (
	"math/rand"
	"time"
)

func PickFile(filenames []string) (int, string) {
	generator := getGenerator()
	index := generator.Intn(len(filenames))

	return index, filenames[index]
}

func getGenerator() *rand.Rand {
	seed := time.Now().UnixNano()
	generator := rand.New(rand.NewSource(seed))

	return generator
}
