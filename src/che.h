enum {
	SEQ_COLUMN,
	ZUIN_COLUMN,
	USERFREQ_COLUMN,
	TIME_COLUMN,
	MAXFREQ_COLUMN,
	ORIGFREQ_COLUMN,
	N_COLUMNS
};

GtkTreeStore *store;
GtkTreeIter iter;
GtkTreeSelection *selection;
gchar *filename;

GtkWidget *che_create_tree( GtkWindow* );
GtkWidget *che_create_menu( GtkWindow* );
void che_read_hash(gchar *filename);
void convert(char*, char*, int);

/* callback */
void file_open( GtkWindow* );
void file_save_as( GtkWindow* );
void file_save( gchar* );
void cell_edited(GtkCellRendererText *cellrenderertext, gchar *arg1, gchar *arg2, gpointer column);
void che_new_phrase_dlg( GtkWidget* );
void save_new_phrase(GtkWidget *obj, gpointer vbox);
void che_remove_phrase(GtkWidget *menu);
