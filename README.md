# Limbo

A parser generator for C.


## Example

Context-free grammar for propositional logic formulas.

```py
Proposition      = "[A-Z]"
UnaryOperator    = "¬"
BinaryOperator   = "^"
                 | "v"
                 | ">"
UnaryExpression  = UnaryOperator Expression
BinaryExpression = "(" Expression BinaryOperator Expression ")"
Expression       = Proposition
                 | UnaryExpression
                 | BinaryExpression
```

Generated parser code.

```c
#include "limbo.h"

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
