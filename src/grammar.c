#include "tree.h"
#include <stdlib.h>


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
