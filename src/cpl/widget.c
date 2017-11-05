#include <widget.h>
#include <stdlib.h>

void widget_init(vector_t *vec) {
    //this can be subsituted by vector_init(),
    //but this function can be expanded on later.
    vector_init(&vec);
}

void widget_add(vector_t *widgets, int type) {
    widget_t *widget = (widget_t *)malloc(sizeof(widget_t *));
    widget.x = 0;
    widget.y = 0;
    widget.type = type;
    widget.widget = (GtkWidget *)malloc(sizeof(GtkWidget));

    vector_add(&widgets->widgets, widget_ptr);
    widgets->len++;
}

void widget_free(vector_t *widgets) {
    int i;
    void *ptr;
    
    for (i = 0; i < widgets->used; i++) {
        ptr = vector_get(&widgets, i);
        free(ptr->widget);
        free(ptr);
    }
    vector_free(&widgets);
}