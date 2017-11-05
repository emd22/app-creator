#ifndef GTK_WINDOW_H
#define GTK_WINDOW_H

#include <gtk/gtk.h>

typedef struct {
    char *title;
    GtkWidget *window;
} window_t;

void init(int argc, char **argv);
void destroy(void);
void window_new(const char *title);
window_t *window_get(int index);
int window_get_index(char *title);
void window_run(void);

#endif