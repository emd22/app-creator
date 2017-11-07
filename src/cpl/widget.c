#include <widget.h>
#include <window.h>
#include <stdlib.h>

void widgets_init(window_t *window) {
    //this can be subsituted by vector_init(),
    //but this function can be expanded on later.
    vector_init(window->widgets);
}

void widgets_add(window_t *window, int type) {
    //allocate a widget and push it to the vector
    widget_t *widget = malloc(sizeof(widget_t));
    widget->x = 0;
    widget->y = 0;
    widget->type = type;
    widget->widget = malloc(sizeof(GtkWidget));

    vector_add(window->widgets, widget);
}

void widgets_draw(window_t *window) {
    widget_t *widgets = window->widgets;
    int i;
    for (i = 0; i < widgets->used; i++) {
        switch(widgets[i]->type) {
            case BUTTON:
                
        }
    }
}

void widgets_free(window_t *window) {
    int i;
    widget_t *ptr;
    
    for (i = 0; i < window->widgets->used; i++) {
        ptr = (widget_t *)vector_get(window->widgets, i);
        free(ptr->widget);
        free(ptr);
    }
    vector_free(window->widgets, 0);
}

void widget_move(widget_t *widget, int x, int y) {
    widget->x = x;
    widget->y = y;
}