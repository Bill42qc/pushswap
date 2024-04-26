Push_swap

Push_swap est un projet de l'école 42 qui consiste à trier des nombres dans une pile à l'aide d'un ensemble de règles prédéfinies. Le défi est de trier efficacement les nombres avec le moins d'opérations possibles.
Description

Le projet se compose de deux programmes : push_swap et checker.

    push_swap : Trie les nombres et affiche une liste d'instructions pour les trier.
    checker : Vérifie si la liste d'instructions fournie trie effectivement les nombres.

Règles

    sa : Swap a - Échanger les deux premiers éléments de la pile a.
    sb : Swap b - Échanger les deux premiers éléments de la pile b.
    ss : sa et sb en même temps.
    pa : Push a - Prend le premier élément de la pile b et le place au début de la pile a.
    pb : Push b - Prend le premier élément de la pile a et le place au début de la pile b.
    ra : Rotate a - Décale d'une position vers le haut tous les éléments de la pile a.
    rb : Rotate b - Décale d'une position vers le haut tous les éléments de la pile b.
    rr : ra et rb en même temps.
    rra : Reverse rotate a - Décale d'une position vers le bas tous les éléments de la pile a.
    rrb : Reverse rotate b - Décale d'une position vers le bas tous les éléments de la pile b.
    rrr : rra et rrb en même temps.

Prérequis

    GCC (ou tout autre compilateur C compatible)

Installation

    Clonez le dépôt :

bash

git clone https://github.com/bill42qc/push_swap.git

    Accédez au répertoire du projet :

bash

cd push_swap

    Compilez les programmes :

bash

make

Utilisation
push_swap

Pour utiliser le programme push_swap, exécutez la commande suivante :

bash

./push_swap [list of integers]

Exemple :

bash

./push_swap 4 67 3 87 23

checker

Pour utiliser le programme checker, exécutez la commande suivante :

bash

./checker [list of integers]

Vous pouvez également fournir une série d'instructions pour vérifier si elles trient correctement les nombres. Par exemple :

bash

./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23

Contribution

Les contributions sont les bienvenues ! Pour des modifications majeures, veuillez ouvrir une issue pour discuter des changements proposés.
