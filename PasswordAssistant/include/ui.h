#ifndef UI_H
#define UI_H

#include <gtk/gtk.h>

typedef struct _App {
    FILE *records_file;
    GtkEntry *search_entry;
    GtkEntry *record_name_entry;
    GtkEntry *record_password_entry;
    GtkButton *record_ok_button;
    GtkInfoBar *info_bar;
} App;

void setup_ui(GtkWindow *main_win, App *app);

App *app_refs_new(void);

void app_destroy_refs(App *app); 

#endif