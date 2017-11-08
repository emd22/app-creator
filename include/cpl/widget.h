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

void widgets_init(window_t *window);
int widgets_add(window_t *window, int type);
void widgets_free(window_t *window);
void widgets_draw(window_t *window);

//widget modifiers
void widget_move(widget_t *widget, int x, int y);

#endif