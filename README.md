# Game-Of-Life-ENSAE
c++ Game Of Life

## principe du code

La bibliothéque SQL permet de gerer les graphismes.
Après une initialisation du programme, est appellé en boucle une mise à jour des composants du programme puis une étude des inputs de l'utilisateur et enfin un affichage de graphismes.

La complexité de la mise à jour du jeu de la vie est linéaire en le nombre de case en vie. On met à jour toute les cases en vie puis leur proche voisins. Cela nous évite de mettre à jour toute la grille.

## Structure globale du code

### Classe Game : 

Cette classe sert à manipuler l'ensemble des objets du code. Après avoir initialiser ces objets, la classe va les mettre à jour, gerer les inputs de l'utilisateur et afficher les graphismes.

 - la fonction init innitialise les composants en particulier SQL
 - la fonction handle event gère les inputs du joueur
 - la fonction update met à jour les objet
 - la fonction draw les affichent
 - la fonction clean tue toute les case du jeu

### Classe World : 

Cette classe stocke une Map c'est à dire une grille de Case. La classe sert à mettre à jour ces cases en fonction de leur état (mort / vivant)

 - La fonction newWorld permet de changer la taille de la grille de case affiché.
 - La fonction Clear tue toute les cases
 - La fonction Update les mets à jour

### Classe Painter

Cette classe sert à afficher les différents objets du code.

 - la fonction drawRect permet de dessiner un rectangle
 - la fonction draworld permet de dessiner les tuiles et les aides à l'édition de l'environnement
 - la fonction drawDrawer dessine les cases sur la gauche permettant de selectionner des motifs à dessiner
 - la fonction drawitem permet de dessiner l'un des motifs du drawer
 - la variable xmargin corespond à la largeur de la marge

### Classe Map

Cette classe stocke et manipule un damier de case.

- La fonction extend permet d'agrandir le damier
- la fonction cleat permet de tuer toute les cases
- Get_neighbours renvoie les proches voisins d'une case. Le programme devrait marcher en renvoyant seulement les plus proches voisins mais dans quelques rares cas lorsqu'il y a un grand nombre de case en vie, il est neccessaire de renvoyer les voisins proches de deux case au lieu d'une. Ceci ne devrait pas être le cas et est surement duà une erreur d'indexage que nous n'avons toujours pas réussit à trouver. Ce détour nous permet de faire marcher notre code mais multiplie la complexité par 4.
- neighbours renvoie le nombre de proche voisin d'une case en vie


### Classe Tile

Classe élémentaire du projet. Stocke l'état d'une case (position, vie/mort) et permet de modifier cette état. Stocke également la dernière fois que cette case à été modifié, ce qui est utile dans la mise à jour des autres tuiles.

### Classe Drawer

Cette classe gère les élément dans la marge du programme, les carré correspondent à des motifs pour éditer la grille.

### La classe Item

Cette classe décrit un motif utilisé par la classe drawer.
