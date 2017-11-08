#ifndef BUTTON_H
#define BUTTON_H

#include <gtk/gtk.h>
#include <window.h>

GtkWidget *button(window_t *window, char *text, GCallback cb);

#endif