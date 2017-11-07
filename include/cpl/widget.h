#ifndef WIDGET_H
#define WIDGET_H

#include <utils/vector.h>
#include <gtk/gtk.h>
#include <window.h>

enum {
    NONE,
    BUTTON,
    INPUTBOX,
    TEXT,
    RADIOBUTTON,
};

typedef struct {
    int x;
    int y;
    int type;
    GtkWidget *widget;
} widget_t;

void widget_init(window_t *window);
void widget_add(window_t *window, int type);
void widget_free(window_t *window);

//widget modifiers(takes widget_t not vector_t)
void widget_move(window_t *window, int index, int x, int y);

#endif