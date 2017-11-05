#ifndef WIDGET_H
#define WIDGET_H

#include <utils/vector.h>
#include <gtk/gtk.h>

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

void widget_add(widgets_t *widgets, int type);

#endif