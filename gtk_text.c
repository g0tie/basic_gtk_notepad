#include <gtk/gtk.h>

void on_destroy(GtkWidget *widget, gpointer data) {
	gtk_main_quit();

}

void createWindow(GtkWidget **window, GtkWidget **box) {
	*window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(*window), "Pkiloki");
	gtk_window_set_default_size(GTK_WINDOW(*window), 400, 300);
	g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);
	
	//box to hold widgets
	*box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	gtk_container_add(GTK_CONTAINER(*window), *box);
	
	
}

void createTextView(GtkWidget **scroll_window, GtkWidget **textview) {
	//create text view
	*textview = gtk_text_view_new();


	*scroll_window = gtk_scrolled_window_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER(*scroll_window), *textview);

	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(*scroll_window),
		GTK_POLICY_AUTOMATIC,
		GTK_POLICY_AUTOMATIC
		);

}

int main(int argc, char *argv[]) {

	GtkWidget *window;
	GtkWidget *box;
	GtkWidget *textview;
	GtkWidget *scroll_window;

	gtk_init(&argc, &argv);
	
	createWindow(&window, &box);
	createTextView(&scroll_window, &textview);

	gtk_box_pack_start(GTK_BOX(box), scroll_window, TRUE, TRUE, 0);
	gtk_widget_show_all(window);

	gtk_main();
	return 0;

}
