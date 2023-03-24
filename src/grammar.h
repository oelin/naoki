#pragma once


typedef enum {
        TreeTypeProposition,
        TreeTypeConjunction,
        TreeTypeDisjunction,
        TreeTypeImplication
} TreeType;


typedef struct Tree Tree;

struct Tree {
        Tree *left;
        Tree *right;
        TreeType type;
};


Tree *treeConstruct(TreeType, Tree *, Tree *);
void treeDeconstruct(Tree *);


#define Proposition(l) treeConstruct( \
        TreeTypeProposition, (Tree *) l, NULL)

#define Conjunction(l, r) treeConstruct( \
        TreeTypeConjunction, l, r)

#define Disjunction(l, r) treeConstruct( \
        TreeTypeDisjunction, l, r)

#define Implication(l, r) treeConstruct( \
        TreeTypeImplication, l, r)

#define Parse(l, r) treeConstruct( \
        TreeTypeProposition, l, r)
