typedef struct cellule
{
    struct cellule *tete;
    struct cellule *queue;
} T_file;
T_file creerFile();
T_file enfiler(T_file file, int elem);
T_file defiler(T_file file);