#ifndef BUTTON_H
#define BUTTON_H

#include <gtk/gtk.h>
#include <window.h>

void button(window_t *window, char *text, GCallBack cb);

#endif