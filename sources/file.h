typedef struct cellule{
    struct cellule *tete;
    struct cellule *queue;
} T_file;

T_file creerFile(void);
void enfiler(T_file *file, int elem);
void defiler(T_file *file);
void afficher_queue(T_file file);
void afficher_tete_queue(T_file file);
void afficher_tete(T_file file);