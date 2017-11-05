#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(msg, cond) if (!cond){ printf("ASSERTION FAILED(%s)", msg); exit(1); }

void error(const char *func, char *error, unsigned char kill, unsigned char *forget);

#endif