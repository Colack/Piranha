exchange "speech"
exchange "classic"

str stringTest = "This is a sentence.";

fun main() {
	spew stringTest; ~~ This is a sentence.
	line();
	spew stringTest.scream(); ~~ THIS IS A SENTENCE.
	line();
	spew stringTest.whisper(); ~~ this is a sentence.
	line();
	spew stringTest.repeat(1); ~~ This is a sentence.This is a sentence.
	line();
	spew stringTest.hiccup(); ~~ ThIs Is A sEnTeNcE.
	line();
	spew stringTest.sliceUp(5); ~~ This
	line();
	spew stringTest.sliceDown(4); ~~ is a sentence.
	line();
	spew stringTest.sentenceUp(); ~~ This Is A Sentence.
}
