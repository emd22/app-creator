#include <button.h>

void button(window_t *window, char *text, GCallBack cb) {
    GtkWidget *button;
    button = gtk_button_new_with_label(text);
    //attach gtk signals to button
    g_signal_connect(button, "clicked", G_CALLBACK(cb));
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
}
