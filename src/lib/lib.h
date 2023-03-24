#pragma once
#include <stdlib.h>


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


#define Parse(l, r) treeConstruct( \
        TreeTypeProposition, (Tree *) l, r)

#define Proposition(l) Parse(l, NULL)

#define Conjunction(l, r) treeConstruct( \
        TreeTypeConjunction, l, r)

#define Disjunction(l, r) treeConstruct( \
        TreeTypeDisjunction, l, r)

#define Implication(l, r) treeConstruct( \
        TreeTypeImplication, l, r)


Tree *treeConstruct(
        TreeType type,
        Tree *left,
        Tree *right
) {
        Tree *tree = (Tree *) calloc(1, sizeof(Tree));

        tree->type = type;
        tree->left = left;
        tree->right = right;

        return tree;
}


void treeDeconstruct(Tree *tree) {
        if (tree->left) treeDeconstruct(tree->left);
        if (tree->right) treeDeconstruct(tree->right);
}
