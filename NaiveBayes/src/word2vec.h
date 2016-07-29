#ifndef _WORD2VEC_
#define _WORD2VEC_

#include "bayes.h"

Data word2vec(char* filename, Data (*generator)(char*));

Data word2vecSet(FILE* file);

Data word2vecBag(FILE* file);

#endif