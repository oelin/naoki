#pragma once


typedef enum {
        GrammarTypeProposition,
        GrammarTypeConjunction,
        GrammarTypeDisjunction,
        GrammarTypeImplication
} GrammarType;


typedef struct Grammar Grammar;

struct Grammar {
        Grammar *left;
        Grammar *right;
        GrammarType type;
};


Grammar *grammarConstruct(GrammarType, Grammar *, Grammar *);
void grammarDeconstruct(Grammar *);


#define Proposition(l) grammarConstruct(GrammarTypeProposition, (Grammar *) l, NULL)
#define Conjunction(l, r) grammarConstruct(GrammarTypeConjunction, l, r)
#define Disjunction(l, r) grammarConstruct(GrammarTypeDisjunction, l, r)
#define Implication(l, r) grammarConstruct(GrammarTypeImplication, l, r)
