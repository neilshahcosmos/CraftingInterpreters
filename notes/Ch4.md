# Ch. 4 - Scanning

* We'll start by implementing the Scanner, which takes in raw source code and groups it into a series of chunks called **tokens**
* These tokens are meaningful "words" and "punctuation" that make up the language's grammar
* This is a good starting point as it's not too hard to code

### 4.1 - The Interpreter Framework

* We start with writing the framework of our interpreter
* We write a `run()` function that will be the core of our scanner, including not yet existent classes such as `Scanner` and `Token`

##### Error Handling

* Any usable language has to have error handling as a vital component
* In order to do this, we need to give the user all the information the need to understand what went wrong, and to guide them gently back to where they are trying to go, whenever an error arises
* The error handler we'll implement is pretty barebones. There are a lot more features we could add later:
  * Interactice debuggers
  * Static analyzers
* We want to keep our normal code separate from our code for error reporting

### 4.2 - Lexemes and Tokens

* A **lexeme** is a sequence of characters that is a smallest unit of meaning
* To see this, look at the following code:
`var language = "lox";`
Here, `var` is a lexeme, as it represents that the following is a declarative statement, but `guag` is not, since it doesn't mean anything.
* `= "lox"` isn't a lexeme, since it's composed of two units of meaning, and can be broken down into the actual lexemes `=` and `"lox"`
* A lexeme bundled with other useful data is a **Token**. This useful data can include:
* **Token Type**: We store these as enums in the TokenType.java file
* **Literal Value**: If the lexeme is a literal, the value of that literal can be stored as well
* **Location Information**: We can store the line number of the lexeme, which can be used in the error reporting class we wrote
* We can pack this up into a struct, located in Token.java

### 4.3 - Regular Languages and Expressions

* The way the scanner works is:
  * It starts at the first character of the source code
  * It figures out what lexeme that character belongs to, and consumes any and all following characters that belong to that lexeme
  * At the end of the lexeme, it emits a token
  * It then iterates to the next character and loops, excreting tokens until it hits the end of the file
* We can implement the scanner using Regex, since Lox is a **regular language**, but we'll do it all by hand for good practice

### 4.4 - The Scanner Class

* 
