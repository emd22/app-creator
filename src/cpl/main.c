#include <stdio.h>
#include <stdlib.h>

#include <utils/vector.h>
#include <utils/error.h>
#include <widget.h>
#include <gtk/gtk.h>
#include <gtk_window.h>

int main(int argc, char **argv) {
    vector_t *widgets;

    vector_init(&widgets);

    init(argc, argv);
    window_run();
    int index = window_get_index("index");
    if (index == VECTOR_FAIL) {
        error("window_get_index()", "could not find window title", 0, "");
    }
    printf("window title: %s\n", window_get(index)->title);

    vector_free(&widgets, 1);
    destroy();
    return 0;
}