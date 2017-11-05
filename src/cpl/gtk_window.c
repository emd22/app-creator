#include <stdlib.h>
#include <string.h>

#include <gtk_window.h>
#include <utils/vector.h>
#include <utils/error.h>

static vector_t windows;

void hello(GtkWidget *widget, gpointer data) {
    g_print("Hello World\n");
}

gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
    g_print("delete event occurred\n");
    return TRUE;
}

void init(int argc, char **argv) {
    gtk_init(&argc, &argv);
    vector_init(&windows);
    window_new("index");
}

void destroy(void) {
    int i;
    for (i = 0; i < windows.used; i++)  {
        free(vector_get(&windows, i)->title);
        free(vector_get(&windows, i)->window);
    }
    vector_free(&windows, 0);
}

void destroy_all(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

void window_new(const char *title) {
    window_t *window = (window_t *)malloc(sizeof(window_t));
    window->title = (char *)malloc(64);
    strcpy(window->title, title);
    window->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window->window, "delete_event", G_CALLBACK(delete_event), NULL);
    g_signal_connect(window->window, "destroy", G_CALLBACK(destroy_all), NULL);
    vector_add(&windows, window);
}

window_t *window_get(int index) {
    int len = windows.used;
    if (index >= 0 && index < len) {
        return vector_get(&windows, index);
    }
    else {
        printf("window_get(): window index(%d) is either less then 0, or is over maximum(%d)\n", index, len);
        exit(1);
    }
}

int window_get_index(char *title) {
    int len = windows.used;
    int i;
    for (i = 0; i < len; i++) {
        if (!strcmp(window_get(i)->title, title)) {
            return i;
        }
    }
    return VECTOR_FAIL;
}

void windows_draw() {
    GtkWidget *main_window;

    main_window = window_get(window_get_index("index"))->window;

    

}

void window_run(void) {
    GtkWidget *window;
    GtkWidget *button;

    window = window_get(0)->window;

    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    button = gtk_button_new_with_label("Hello, World!");

    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);

    gtk_container_add(GTK_CONTAINER(window), button);

    gtk_widget_show(button);
    gtk_widget_show(window);

    gtk_main();
}