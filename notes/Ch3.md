# Ch. 3 - The Lox Language

### 3.1 - Hello, Lox

* Here's our very first taste of Lox!
```c
// Your first Lox program!
print "Hello, World!";
```
* Lox's syntax is a memeber of the C family, chosen for reasons of familiarity

### 3.2 - A High-Level Language

* Lox has to be small by necessity of course, to be able to be taught in one course
* Small but useful languages like Lox include JavaScript, Scheme, and Lua
* Lox looks most like JS, as JS is also a C-style language
* But Lox's approach to scope is closer to Scheme, and shares Lua's clean, efficient implementation
* Lox shares two other aspects with these three languages:
* **Dynamic typing**: Lox is dynamically typed, so variables can store values of any type, and a variable's type can change
* **Automatic memory management**:
  * There are two main ways to automatically manage memory:
    * **Reference counting**: Simple to implement, but is limited, and end up needing to do some amount of garbage collection anyways
    * **Tracing garbage collection**: Often just called garbage collection. Harder to implement, but much more robust
  * We'll be implementing the GC for good practice

### 3.3 - Data Types

* There are only a few data types in Lox
* **Booleans**: The usual boolean type, here represented by `true` and `false`
* **Numbers**: Lox only has one kind of number, double-precision floating point, which can also represent integers
* **Strings**: String literals, enclosed in double quotes
* **Nil**: This is basically `NULL`, the name is changed to distinguish it from the null data types of C and Java

### 3.4 - Expressions

* If data types are atoms, then **expressions** are molecules, being chunks of code that evaluate to a single value
* **Arithmetic**: These are the usual (`+`, `-`, `*`, `/`) such as `a * b;`. Because the operator here is in the middle of the operands, these are **infix binary operators** (as opposed to prefix, where the operator comes first, and postfix, where the operator comes after)
* There is one unary prefix mathematic operator, the negator: `-a;`
* **Comparison and Equality**: We have the usual (`<`, `<=`, `>`, `>=`, `==`, `!=`). Since we have dynamic typing, we can compare literals of two different types, but they will never compare to be equal
* **Logical**: We have the usual (`!`, `and`, `or`). These are set up to short-circuit (i.e., if `a() and b()` and `a()` returns false, `b()` isn't called)
* **Precedence and Grouping**: Precedence and associativity work as expected here

### 3.5 - Statements

* Moving up another level, we get **statements**, which are single-line groups of expressions that have some effect
* Every statement ends with a semicolon (`;`)
* A series of statements can be packed into the space of one statement using a block: `{statement1; statement2;}`

### 3.6 - Variables

* Variables are declared using `var`
* Unitialized variables hold the value `nil`
* Variable scope will be addressed later

### 3.7 - Control Flow

* In addition to the logical oeprators from before, which due to short circuiting can be used for control flow, we have three control flow blocks straight from C:

**if-else:**
```c
if (condition) {
    print "yes";
} else {
    print "no";
}
```

**while:**
```c
var a = 1;
while (a < 10) {
    print a;
    a = a + 1;
}
```

**for:**
```c
for (var a = 1; a < 10; a = a + 1) {
    print a;
}
```

### 3.8 - Functions

* Function calls look the same as they do in C: `myMethod(...);`
* You can define functions in Lox using `fun`: `fun printSum(a, b) { print a + b; }`
* Let's clarify some language:
  * **Argument**: The actual value you pass to the function when you call it. A function *call* has an argument list
  * **Parameter**: A variable that holds the value of the argument inside the body of the function. The function *declaration* has a parameter list
* While you can declare functions in C and define them later, since Lox is dynamically types this isn't important, so function declarations also always define the function
* If nothing is returned, the function returns `nil`
* Functions in Lox are **first class**, meaning they are real values that you can get a reference to, store in variables, pass around, etc.
* Therefore this works:

```c
fun addPair(a, b) {
  return a + b;
}

fun identity(a) {
  return a;
}

print identity(addPair)(1, 2); // Prints "3".
```

### 3.9 - Classes

* We will also make Lox an object-oriented language
* OOP is still used in many different languages and successful softwares around the world, so we want to take a look at how they're implemented
* There are actually two approaches to OOP: classes and **prototypes**
* Classes have two core concepts: instances and classes, where instances hold the state of the object and the reference to the defining class, while classes hold the methods and the inheritance chain
* When you call an object's method, there is a level of indirection in that you have to look up the originating class and find the method there
* Prototype-based languages merge the two concepts. There are only objects, no classes, and each object may contain both state and methods
