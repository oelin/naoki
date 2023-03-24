# Naoki

A parser generator for C. WIP.


## Installation

```
npm i -g naoki
```


## Usage

```
naoki path/to/grammar.txt
```


## Example

Define a grammar.

```py
# grammar.txt

Proposition      > "[A-Z]"
UnaryOperator    > "¬"
BinaryOperator   > "^"
                 | "v"
                 | ">"
UnaryExpression  > UnaryOperator Expression
BinaryExpression > "(" Expression BinaryOperator Expression ")"
Expression       > Proposition
                 | UnaryExpression
                 | BinaryExpression
```

Compile it.

```sh
$ naoki grammar.txt
```

Congratulations, you now have a parser 🥳.

```c
// grammar.h

...

// Variables.

Variable(Proposition);
Variable(UnaryOperator);
Variable(BinaryOperator);
Variable(UnaryExpression);
Variable(BinaryExpression);
Variable(Expression);

// Production rules.

Production(Proposition, Match("[A-Z"));
Production(UnaryOperator, Match("¬"));

Production(BinaryOperator, Or(
  Match("\\^"),
  Or(
    Match("v"),
    Match(">")
  )
));

Production(UnaryExpression, And(
  UnaryOperator,
  Expression
));

Production(BinaryExpression, And(
  Match("\\("),
  And(
    Expression,
    And(
      BinaryOperator,
      And(
        Expression,
        Match("\\)")
      )
    )
  )
));

Production(Expression, Or(
  Proposition,
  Or(
    UnaryExpression,
    BinaryExpression
  )
));
```

Try it out on some strings.

```c
#include "grammar.h"

parse(Expression, "hello world"); // Returns `NULL` as "hello world" is not an `Expression`.

parse(Expression, "((AvB)^C)");   // Returns a parse tree.
```
