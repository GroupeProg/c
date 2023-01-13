# Comment créer une demande GIT

Sachez les gars que vous avez tous les droits pour git sur ce projet

## Prérequis

Savoir utiliser un terminal et pas se tromper de dossier de travail, et surtout, avoir git d'installé !

## Comment installer git

Aller sur https://git-scm.com/download/win et prendre la version 64bits puis suivre l'instruction

## Avant de démarrer après l'installation

Git aime bien retracer les modifications ainsi que les changements suivant les personnes qui ont contribué au projet. Et pour cela, il faut qu'il sache qui vous êtes. C'est une procédure à faire en une seule fois et c'est pour paramétrer votre git tout simplement.

```git
git --global user.name <ton nom>
git --global user.mail <ton mail>
```

Si tu ne veux renseigner ça que pour le projet en cours, fait le après le init (expliqué après) sans le --global.


## Comment faire pour clone ce projet

```git
git clone "https://github.com/GroupeProg/c.git"
```

## Comment faire pour initialiser un projet

Sachez que git fonctionne en branche, pour éviter d'écraser le travail des autres.
Donc, quand vous voulez bosser et modifier sérieusement un projet, créez une nouvelle branche, qui va copier les fichiers dans un espace rien qu'à vous pour que vous vous amusiez comme des petits fous

Mais avant ça fait dire à git que votre dossier c'est un dossier git :
```git
git init
```

Rien de plus simple. Pour ajouter le projet, faites :

```git
git remote add <name> <lien_git>
```

En vérité, voici ce que vous taperez pour le projet `C`

```git
git remote origin https://github.com/GroupeProg/c.git
```

Ça permet de faire un alias, le projet s'appellera origin, nom commun utilisé pour les projet git

## Comment faire pour récupérer le projet en ligne, d'une branche annexe

Après avoir tout réalisé au dessus, faire :

```git
git fetch origin <branch>
```

Tout simplement

## Comment faire pour mettre en ligne son projet

Vous devez en premier ajouter les fichiers modifiés dans l'empaquetage. Le fichier `.gitignore` va être regardé en premier pour voir ce qu'il doit ignorer si un dossier est renseigné en entier.

```git
git add <fichiers_dossiers>
```

Mais si tout votre dossier c'est le projet, ne renseignez pas fichier par fichier :

```git
git add .
```


Sachez qu'il y a deux envoies en même temps pour envoyer un projet en ligne

 - Commit
 - Push

Commit permet d'empaqueter et push d'envoyer sur internet

```git
git commit -m "MESSAGE"
git push origin <branch>
```
`<branch>` étant le nom de la branch en question
Si ça ne marche pas, c'est qu'il y a un problème de synchronisation avec la branche en question, faites ceci avant `push` :

```git
git pull origin <branch> --allow-unrelated-histories
```

`git pull` fait deux choses en vérité, il va récupérer le projet (quitte à écraser les fichiers existants qui ont le même nom) avec `git fetch` et va `git merge` ce qui fait fusionner deux branches (Celle locale avec celle en ligne).


## Bonus

### C'est quoi .gitignore ?

Le fichier .gitignore va juste ignorer les fichiers séparés en allant à la ligne :

`.gitignore`
```.gitignore
a.exe
main.exe
```
### A savoir

Pour que le projeet soit viable, et que vous avez de grosses modifications, faites une nouvelle branche. Si vous êtes assez confiant, faites un `merge`, sinon, laissez les autres s'en occuper.

### Comment créer une nouvelle branche ou les fusionner ?

Créer une nouvelle branche 
```git
git branch <branch>
```

Supprimer une branche locale
```git
git branch -d <branch>
```

Supprimer une branche remote
```git
git push origin --delete <branch>
```

Basculer de branche

```git
git checkout <branch>
```

Renommer une branche

```git
git checkout <branch>
git branch -m <new-name>
```

Fusionner une branche avec la principale

```git
git checkout <branch>
git merge
```
Qui ne fonctionne s'il y a vraiment des modifications

Allez regarder ce cours, j'ai un peu la flemme d'en donner plus :
https://git-scm.com/book/fr/v2/Commandes-Git-Cr%C3%A9ation-de-branches-et-fusion

De préférence, cloner le projet autre part des deux branches pour éviter les pertes, même s'il est possible de revenir en arrière, d'où la puissance de git.

![Texte sur ordinateur](http://www.netplume.net/wp-content/uploads/2021/01/clavier_0.jpg "Comment ajouter, modifier ou fusionner une branche")

### Plus

Sans doute prochainement, déjà vous pouvez bosser normalement avec ça.