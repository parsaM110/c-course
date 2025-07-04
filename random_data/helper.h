// Header Guard MACRO for avoiding redeclaration
#ifndef HELPER_H
#define HELPER_H

#include <stdlib.h> // becuase I use size_t

void generate_random_numbers(int *buf, size_t count, int min, int max);
void print_array(const int *buf, size_t count);

#endif