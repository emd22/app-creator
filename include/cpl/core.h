#ifndef CORE_H
#define CORE_H

#include <window.h>

void init(int argc, char **argv);
void destroy(void);
void window_new(const char *title);
window_t *window_get(int index);
int window_get_index(char *title);
void window_run(void);

#endif