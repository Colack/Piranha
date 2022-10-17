# Piranha
Piranha is a programming language designed to have a simplified syntax with heavy power.

It is currently still in development for the foreseeable future.    
The language will support OOP and Functional programming, here are some examples:

```piranha
~~ Functional Example
exchange "classic"

int visited;
str place;

fun main() {
    place = ask "What place have you visited?";
    visited = ask "How many times have you visited " + place + "?";

    spew "You have visited " + place + " " + visited + " times.";
}
```

```piranha
~~ OOP Example
exchange "classic"

class myString {
    str phrase;

    myString(str newPhrase) {
        phrase = newPhrase;
    }

    fun toString() {
        send phrase;
    }
}

fun main() {
    myString stringy = new myString("Hello World!");
    spew myString();
}
```

Pirahna also comes will a shell called Chomper, and will have basic utilities and the ability to read and create progams.   
Here is what a template Piranha program would look like:
```piranha
~~ Piranha Template
exchange "classic"

fun main() {
    spew "Hello World!";
}
```

Once again, this language is still being created, but you can help with setting up the project and fixing/contributing to code.
