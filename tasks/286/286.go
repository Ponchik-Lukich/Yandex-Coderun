package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	words := strings.Fields(scanner.Text())
	uniqueWords := removeDuplicates(words)

	m := make(map[string]string)
	for _, s := range uniqueWords {
		v := make([]int, len(s)-1)
		for i := 0; i < len(s)-1; i++ {
			result := (int(s[i]) - int(s[i+1]) + 26) % 26
			v[i] = result
		}
		m[convertSliceToString(v)] = s
	}

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < n; i++ {
		scanner.Scan()
		word := scanner.Text()
		v := make([]int, len(word)-1)
		for j := 0; j < len(word)-1; j++ {
			result := (int(word[j]) - int(word[j+1]) + 26) % 26
			v[j] = result
		}
		if val, ok := m[convertSliceToString(v)]; ok {
			fmt.Println(val)
		}
	}
}

func removeDuplicates(words []string) []string {
	uniqueWords := make([]string, 0, len(words))
	seen := make(map[string]bool)
	for _, word := range words {
		if _, ok := seen[word]; !ok {
			uniqueWords = append(uniqueWords, word)
			seen[word] = true
		}
	}
	return uniqueWords
}

func convertSliceToString(slice []int) string {
	var sb strings.Builder
	for _, v := range slice {
		sb.WriteString(strconv.Itoa(v))
		sb.WriteString(",")
	}
	return sb.String()
}
