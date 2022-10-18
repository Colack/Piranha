# Piranha
Piranha is a programming language designed to have a simplified syntax with heavy power.

It is currently still in development for the foreseeable future.    
The language is designed to be a functional programming language, and will not support OOP programming.   
Here is a basic example of what the language will be like:

```piranha
exchange "classic"

int visited;
str place;

fun main() {
    place = ask "What place have you visited?";
    visited = ask "How many times have you visited " + place + "?";

    spew "You have visited " + place + " " + visited + " times.";
}
```
