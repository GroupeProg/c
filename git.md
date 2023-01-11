# Comment créer une demande GIT

Sachez les gars que vous avez tous les droits pour git sur ce projet

## Prérequis

Savoir utiliser un terminal et pas se tromper de dossier de travail, et surtout, avoir git d'installé !

## Comment installer git

Aller sur https://git-scm.com/download/win et prendre la version 64bits puis suivre l'instruction

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
git remote origin https://github.com/GroupeProg/c.git
```

Ça permet de faire un alias, le projet s'appellera origin, nom commun utilisé pour les projet git

## Comment faire pour mettre en ligne son projet

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

## Bonus

### C'est quoi .gitignore ?

Le fichier .gitignore va juste ignorer les fichiers séparés en allant à la ligne :

`.gitignore`
```.gitignore
a.exe
main.exe
```

### Comment créer une nouvelle branche ou les fusionner ?

Créer une nouvelle branche 
```git
git branch <branch>
```

Supprimer une branche
```git
git branch -d <branch>
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

Allez regarder ce cours, j'ai un peu la flemme d'en donner plus :
https://git-scm.com/book/fr/v2/Commandes-Git-Cr%C3%A9ation-de-branches-et-fusion

De préférence, cloner le projet autre part des deux branches pour éviter les pertes, même s'il est possible de revenir en arrière, d'où la puissance de git.

![Texte sur ordinateur](http://www.netplume.net/wp-content/uploads/2021/01/clavier_0.jpg "Comment ajouter, modifier ou fusionner une branche").

### Plus

Sans doute prochainement, déjà vous pouvez bosser normalement avec ça.