#ifndef WINDOW_H
#define WINDOW_H

#include <utils/vector.h>
#include <gtk/gtk.h>

typedef struct {
    vector_t *widgets;
    char *title;
    GtkWidget *window;
} window_t;

#endif