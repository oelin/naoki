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
#include <stdlib.h>

Tree *Expression = Promise();

Tree *Proposition = Match("[A-Z");

Tree *UnaryOperator = Match("¬");

Tree *BinaryOperator = Or(
  Match("^"),
  Or(
    Match("v"),
    Match(">")
  )
);

Tree *UnaryExpression = And(
  UnaryOperator,
  Expression,
);

Tree *BinaryExpression = And(
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
);

resolvePromise(Expression, Or(
  Proposition,
  Or(
    UnaryExpression,
    BinaryExpression
  )
));


Tree *parse(char *string) {
  return parseTree(Expression, Parse(string, NULL));
}
```
