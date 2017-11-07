//version: 07092017

#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include <utils/vector.h>
#include <utils/error.h>
#include <widget.h>
#include <core.h>

int main(int argc, char **argv) {
    init(argc, argv);
    core_main();
    //get index window title
    int index = window_get_index("index");
    if (index == VECTOR_FAIL) {
        error("window_get_index()", "could not find window title", 0, "index window could not be created.");
    }
    printf("window title: %s\n", window_get(index)->title);
    
    destroy();
    return 0;
}