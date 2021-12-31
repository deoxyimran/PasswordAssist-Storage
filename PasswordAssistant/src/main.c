#include <stdio.h>
#include <gtk/gtk.h>
#include "ui.h"

static void destroy(GtkWidget *widget, gpointer data) {
    gtk_widget_destroy(widget);
    //fclose(((App *)data)->records_file);
    app_destroy_refs((App *)data);
    gtk_main_quit();
}

int main(int argc, char **argv) {  
    gtk_init(&argc, &argv); 
    GtkWindow *main_win = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    App *app = app_refs_new();

    g_signal_connect(main_win, "destroy", G_CALLBACK(destroy), app);
    gtk_window_set_default_size(main_win, 500, 500);
    gtk_window_set_resizable(main_win, FALSE);
    setup_ui(main_win, app);
    gtk_widget_show_all(GTK_WIDGET(main_win));
    gtk_main();

    return 0;   
}