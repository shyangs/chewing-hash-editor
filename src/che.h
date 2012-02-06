#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <iconv.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "key2pho8.h"
#include "key2pho-utf8.h"
#include "chewing-utf8-util.h"
#include "zhuindict.h"

#define FIELD_SIZE 125
#define BIN_HASH_SIG "CBiH"

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
gboolean is_editing_existing_phrase;
GtkTreeSelection *selection;
gchar *filename;
GtkWidget *editor_dialog;

GtkWidget *che_create_tree( GtkWindow* );
GtkWidget *che_create_menu( GtkWindow* );
void che_read_hash(gchar *filename);
void convert(char*, char*, int);

struct zhuindict *zhuin_dictionary;

gboolean is_file_saved;

/* callback */
void file_open( GtkWindow* );
void file_save_as( GtkWindow* );
void file_save( gchar* );
void cell_edited(GtkCellRendererText *cellrenderertext, gchar *arg1, gchar *arg2, gpointer column);
void che_new_phrase_dlg( GtkWidget* );
void che_save_phrase(GtkWidget *obj, gpointer vbox);
void che_remove_phrase(GtkWidget *menu);
