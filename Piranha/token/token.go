package token

type TokenType string

const (
	ILLEGAL = "ILLEGAL"
	EOF     = "EOF"
	BUILTIN = "BUILTIN"

	IDENT   = "IDENT"
	INT     = "int"
	FLOAT   = "float64"
	STRING  = "str"
	TRUE    = "true"
	FALSE   = "false"
	COMMENT = "COMMENT"

	BEGIN = "BEGIN"
	END   = "END"

	ASSIGN     = "="
	CMD_ASSIGN = "=cmd="
	VAR_ASSIGN = "=var="
	DEF_ASSIGN = "=def="
	GVN_ASSIGN = "=gvn="
	PVR_ASSIGN = "=pvr="
	TYP_ASSIGN = "=typ="

	COLON     = ":"
	DOT       = "."
	NEWLINE   = "\n"
	SEMICOLON = ";"

	AND = "and"
	OR  = "or"
	NOT = "not"

	EQ     = "=="
	NOT_EQ = "!="

	DOUBLESLASH = "//"

	DOTDOT = ".."

	RIGHTARROW = "->"

	NO_INDENT = "|||"

	COMMA      = ","
	WEAK_COMMA = ",,"

	LPAREN = "("
	RPAREN = ")"
	LBRACE = "{"
	RBRACE = "}"
	LBRACK = "["
	RBRACK = "]"

	IMPORT  = "import"
	VAR     = "var"
	CMD     = "cmd"
	DEF     = "def"
	PRIVATE = "private"

	RETURN = "return"
	ELSE   = "else"
	GIVEN  = "given"
	EVAL   = "eval"
	EXEC   = "exec"

	MAGIC_COLON = "MAGIC_COLON"

	GOLANG = "golang"
)

type Token struct {
	Type    TokenType
	Literal string
	Line    int
	ChStart int
	ChEnd   int
	Source  string
}

var keywords = map[string]TokenType{
	"true":   TRUE,
	"false":  FALSE,
	"else":   ELSE,
	"return": RETURN,

	"eval":   EVAL,
	"given":  GIVEN,
	"exec":   EXEC,
	"golang": GOLANG,

	"import":  IMPORT,
	"var":     VAR,
	"cmd":     CMD,
	"def":     DEF,
	"private": PRIVATE,

	"and": AND,
	"or":  OR,
	"not": NOT,

	"=cmd=": CMD_ASSIGN,
}

func LookupIdent(ident string) TokenType {
	if tok, ok := keywords[ident]; ok {
		return tok
	}
	return IDENT
}

func TokenTypeIsHeadword(t TokenType) bool {
	return t == IMPORT || t == VAR || t == CMD || t == DEF
}
