# TP3-Binairo
#### C++ Simulation of the game Binairo

Il est apparu il y a quelques années un jeu nouveau dans le journal : le Binairo. Il s’agit d’une
grille de 10 carreaux horizontaux par 10 carreaux verticaux dans lesquels on peut inscrire
seulement deux chiffres : 0 et 1.

Dans le journal, on présente une grille incomplète. Le jeu consiste bien entendu à compléter la
grille en respectant les règles suivantes :
- Chacune des lignes et chacune des colonnes doit contenir autant de 0 que de 1. Ceci
signifie donc qu’il y aura 5 cases contenant la valeur 0 et 5 cases contenant la valeur 1
pour chaque ligne et chaque colonne.
- Il est interdit d’avoir une succession de plus de 2 chiffres identiques, que ce soit à
l’horizontale ou à la verticale. On ne peut donc pas avoir 3 cases consécutives
contenant la valeur 0 ni trois cases consécutives contenant la valeur 1.
- Dans la grille, chaque ligne doit être unique, i.e. deux lignes ne peuvent pas avoir la
même séquence de 1 et de 0.
- Dans la grille, chaque colonne doit être unique, i.e. deux colonnes ne peuvent pas
avoir la même séquence de 1 et de 0.
- Chaque grille n’a qu’une seule solution
