package text

import (
	"path/filepath"
	"strings"
)

const (
	VERSION       = "1.0.0"
	VERSION_MAJOR = 1
	VERSION_MINOR = 0
	VERSION_PATCH = 0
	BULLET        = "  ▪ "
	PROMPT        = "→ "
)

func ToEscapedText(s string) string {
	result := "\""
	for _, ch := range s {
		switch ch {
		case '\n':
			result = result + "\n"
		case '\r':
			result = result + "\r"
		case '\t':
			result = result + "\t"
		default:
			result = result + string(ch)
		}
	}
	return result + "\""
}

func FlattenedFilename(s string) string {
	s = filepath.Base(s)
	s = strings.Replace(s, ".", "_", -1)
	return s
}

func Cyan(s string) string {
	return CYAN + s + RESET
}
