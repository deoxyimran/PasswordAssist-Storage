#include <gtk/gtk.h>
#include "ui.h"
#include <stdio.h>

static gboolean focus_in_stack_switcher(GtkWidget* self, GdkEventFocus event, gpointer user_data) {
    gtk_widget_grab_focus(self);
    return TRUE;
}

void setup_ui(GtkWindow *main_win, App *app) {
    gint width = 0;
    GtkStack *stack = GTK_STACK(gtk_stack_new());
    GtkStackSwitcher *stack_switcher = GTK_STACK_SWITCHER(gtk_stack_switcher_new()); 
    GtkListBox *list_box = GTK_LIST_BOX(gtk_list_box_new());
    GtkFrame *main_frame = GTK_FRAME(gtk_frame_new(""));
    GtkBox *main_box = GTK_BOX(gtk_box_new(GTK_ORIENTATION_VERTICAL, 5));
    GtkBox *search_window_box = GTK_BOX(gtk_box_new(GTK_ORIENTATION_VERTICAL, 2));
    GtkBox *add_record_window_box = GTK_BOX(gtk_box_new(GTK_ORIENTATION_VERTICAL, 2));
    app->record_name_entry = GTK_ENTRY(gtk_entry_new());
    app->record_password_entry = GTK_ENTRY(gtk_entry_new());
    app->record_ok_button = GTK_BUTTON(gtk_button_new_with_label("Ok"));
    app->info_bar = GTK_INFO_BAR(gtk_info_bar_new());
    app->search_entry = GTK_ENTRY(gtk_entry_new());
    //app->records_file = fopen("./records.txt", "a");

    gtk_entry_set_placeholder_text(app->search_entry, "Search by name...");
    gtk_entry_set_placeholder_text(app->record_name_entry, "Name");
    gtk_entry_set_placeholder_text(app->record_password_entry, "Password");

    gtk_stack_add_titled(stack, GTK_WIDGET(search_window_box), "search", "Search");
    gtk_stack_add_titled(stack, GTK_WIDGET(add_record_window_box), "new-record", "Add New Record");
    gtk_stack_switcher_set_stack(stack_switcher, stack);
    gtk_box_set_homogeneous(GTK_BOX(stack_switcher), TRUE);
    gtk_widget_get_size_request(GTK_WIDGET(main_frame), &width, NULL);
    gtk_widget_set_size_request(GTK_WIDGET(app->info_bar), width, 50);

    //Connect signals
    g_signal_connect(stack_switcher, "focus-in-event", G_CALLBACK(focus_in_stack_switcher), NULL);

    // Add to containers
    gtk_box_pack_start(search_window_box, GTK_WIDGET(list_box), TRUE, TRUE, 0);
    gtk_box_pack_start(search_window_box, GTK_WIDGET(app->search_entry), TRUE, TRUE, 0);
    gtk_box_pack_start(add_record_window_box, GTK_WIDGET(app->record_name_entry), TRUE, TRUE, 0);
    gtk_box_pack_start(add_record_window_box, GTK_WIDGET(app->record_password_entry), TRUE, TRUE, 0);
    gtk_box_pack_start(add_record_window_box, GTK_WIDGET(app->record_ok_button), TRUE, TRUE, 0);
    gtk_box_pack_start(main_box, GTK_WIDGET(stack_switcher), TRUE, TRUE, 0);
    gtk_box_pack_start(main_box, GTK_WIDGET(stack), TRUE, TRUE, 0);
    gtk_box_pack_start(main_box, GTK_WIDGET(app->info_bar), FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(main_frame), GTK_WIDGET(main_box));
    gtk_container_add(GTK_CONTAINER(main_win), GTK_WIDGET(main_frame));    
}

App *app_refs_new(void) { 
    return g_malloc(sizeof(App));
}

void app_destroy_refs(App *app) {
    g_free(app);
}