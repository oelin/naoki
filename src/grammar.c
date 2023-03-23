#include "grammar.h"
#include <stdlib.h>


Grammar *grammarConstruct(
        GrammarType type,
        Grammar *left,
        Grammar *right
) {
        Grammar *grammar = (Grammar *) calloc(1, sizeof(Grammar));

        grammar->type = type;
        grammar->left = left;
        grammar->right = right;

        return grammar;
}


void grammarDeconstruct(Grammar *grammar) {

        if (grammar->left) grammarDeconstruct(grammar->left);
        if (grammar->right) grammarDeconstruct(grammar->right);

        free(grammar);
}
