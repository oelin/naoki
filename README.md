# Naoki

An elegant parser generator for C. WIP.


## Installation

```
npm i -g naoki
```


## Usage

```
naoki path/to/grammar.txt
```


## Example

A grammar for propositional logic.

```py
# logic.txt

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

Compile the grammar with Naoki.

```sh
$ naoki logic.txt
```

Generated parser.

```sh
generated/
generated/lib.h
generated/grammar.h
```

```c
// generated/grammar.h

#include "lib.h"

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
  Match("^"),
  Or(
    Match("v"),
    Match(">")
  )
));

Production(UnaryExpression, And(
  UnaryOperator,
  Expression,
));

Production(BinaryExpression, And(
  Match("\\("),
  And(
    Expression,
    And(
      BinaryOperator,
      And(
        Expression,
        Match(")")
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

The parser can then be used via the `parse` macro.

```c
#include "generated/grammar.h"

parse(Expression, "hello world"); // Returns `NULL` as "hello world" is not an `Expression`.

parse(Expression, "(AvB)>C");     // Returns the output of `Expression`.
```
