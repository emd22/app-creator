#include <widget.h>
#include <window.h>
#include <stdlib.h>

#include <widgets/button.h>

void widgets_init(window_t *window) {
    //this can be subsituted by vector_init(),
    //but this function can be expanded on later.
    vector_init(window->widgets);
}

int widgets_add(window_t *window, int type) {
    //allocate a widget and push it to the vector
    widget_t *widget = malloc(sizeof(widget_t));
    widget->x = 0;
    widget->y = 0;
    widget->type = type;
    widget->widget = malloc(sizeof(GtkWidget));

    vector_add(window->widgets, widget);
    return window->widgets->used;
}

static void hello(GtkWidget *widget, gpointer data) {
    g_print("Hello World\n");
}

void widgets_draw(window_t *window) {
    int i;
    int widget_index = 0;
    for (i = 0; i < window->widgets->used; i++) {
        switch(((widget_t *)vector_get(window->widgets, i))->type) {
            case BUTTON:
                widget_index = widgets_add(window, BUTTON);
                ((widget_t *)vector_get(window->widgets, widget_index))->widget = button(window, "test", G_CALLBACK(hello));
                break;
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