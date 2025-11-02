# Guide de programmation en C (pour débutants)

Apprentissage du plus simple au plus complexe

---

## NIVEAU 1 : Les Opérateurs et Symboles (FONDATIONS)

### Résumé des symboles

| Opérateur | Signification      |
| --------- | ------------------ |
| `>`       | plus grand que     |
| `<`       | plus petit que     |
| `>=`      | plus grand ou égal |
| `<=`      | plus petit ou égal |
| `==`      | égal à             |
| `!=`      | pas égal à         |
| `&&`      | ET logique         |
| `\|\|`    | OU logique         |
| `!`       | NON logique        |

---

## NIVEAU 2 : Affichage (printf) — Votre première commande

### printf() — Afficher du texte

- **Rôle** : afficher du texte formaté à l'écran.
- **Syntaxe** : `printf("texte %spécificateur", variable);`
- **Spécificateurs courants** :

  - `%d` : entier décimal
  - `%f` : nombre décimal (float/double)
  - `%s` : chaîne de caractères
  - `%c` : caractère unique
  - `%x` : hexadécimal
  - `%o` : octal
  - `\n` : nouvelle ligne

- **Exemples** :
  ```c
  int c = 42;
  printf("c = %d\n", c);           // affiche : c = 42
  printf("octal %o\n", c);         // affiche : octal 52
  printf("hexadecimal %x\n", c);   // affiche : hexadecimal 2a
  printf("%.2f\n", 3.14159);       // affiche : 3.14
  ```

---

## NIVEAU 3 : Entrée (scanf) — Lire le clavier

### scanf() — Lire l'entrée clavier

- **Rôle** : lire les données saisies par l'utilisateur.
- **Syntaxe** : `scanf("%spécificateur", &variable);`
- **Important** : utiliser `&` devant la variable (sauf pour chaînes).

- **Exemples** :

  ```c
  int a;
  scanf("%d", &a);  // lire un entier

  float x;
  scanf("%f", &x);  // lire un décimal

  char nom[50];
  scanf("%49s", nom);  // lire une chaîne (limiter la taille !)
  ```

---

## NIVEAU 4 : Conditions (if / else) — Prendre des décisions

### if / else if / else — Conditions simples

- **Syntaxe** :

  ```c
  if (condition) {
      // si vrai
  } else if (autre_condition) {
      // sinon si vrai
  } else {
      // sinon
  }
  ```

- **Exemple** :

  ```c
  int a, b;
  scanf("%d %d", &a, &b);

  if (a > b) {
      printf("a est plus grand\n");
  } else if (a < b) {
      printf("b est plus grand\n");
  } else {
      printf("a et b sont égaux\n");
  }
  ```

---

## NIVEAU 5 : Boucles simples (for) — Répétition de base

### for — Boucle répétée

- **Syntaxe** :

  ```c
  for (initialisation; condition; incrément) {
      // corps répété tant que condition est vraie
  }
  ```

- **Exemple** :

  ```c
  for (int i = 0; i < 10; i++) {
      printf("%d ", i);  // affiche : 0 1 2 3 4 5 6 7 8 9
  }
  ```

- **Cas courants** :
  ```c
  for (int i = 0; i < n; i++)    // compter de 0 à n-1
  for (int i = 1; i <= n; i++)   // compter de 1 à n
  for (int i = 0; i < 10; i+=2)  // compter par pas de 2
  ```

---

## NIVEAU 6 : Boucles conditionnelles (while / do while)

### while — Boucle conditionnelle

- **Syntaxe** :

  ```c
  while (condition) {
      // corps répété tant que condition est vraie
  }
  ```

- **Exemple** :
  ```c
  int i = 0;
  while (i < 5) {
      printf("%d\n", i);
      i++;
  }
  ```

### do while — Boucle (au moins une fois)

- **Syntaxe** :

  ```c
  do {
      // corps exécuté au moins une fois
  } while (condition);
  ```

- **Exemple (validation entrée)** :
  ```c
  int x;
  do {
      printf("Saisir un nombre entre 0 et 9 : ");
      scanf("%d", &x);
  } while (x < 0 || x >= 10);
  ```

---

## NIVEAU 7 : Tableaux — Stocker plusieurs valeurs

### Déclaration et utilisation de tableaux

- **Syntaxe** :

  ```c
  int t[10];           // tableau de 10 entiers
  int t[] = {1,2,3};   // tableau de taille 3
  ```

- **Indexation** : commence à 0.

  ```c
  t[0] = 5;    // première case
  t[9] = 10;   // dixième case
  printf("%d\n", t[0]);  // affiche : 5
  ```

- **En paramètre de fonction** :
  ```c
  void afficher_tableau(int t[], int n) {
      for (int i = 0; i < n; i++) {
          printf("%d ", t[i]);
      }
  }
  ```

---

## NIVEAU 8 : switch — Choix multi-cas avancé

### switch — Choix multi-cas

- **Syntaxe** :

  ```c
  switch (valeur) {
      case 1:
          printf("Cas 1\n");
          break;
      case 2:
          printf("Cas 2\n");
          break;
      default:
          printf("Autre cas\n");
  }
  ```

- **Important** : ne pas oublier `break;` pour sortir du switch (sinon chute au cas suivant).

---

## NIVEAU 9 : Nombres aléatoires — Générer de l'imprévisibilité

### srand() et rand() — Générer des nombres aléatoires

- **Rôle** : `srand()` initialise le générateur aléatoire (une fois au début), `rand()` génère des nombres aléatoires.
- **Syntaxe** :

  ```c
  #include <stdlib.h>
  #include <time.h>

  srand(time(NULL));  // initialiser une fois
  int x = rand();     // obtenir un nombre aléatoire
  ```

- **Exemple (nombre entre min et max)** :

  ```c
  int min = 10, max = 50;
  int random_num = min + rand() % (max - min + 1);
  ```

- **Conseil** : appeler `srand()` une seule fois au début du programme, pas à chaque fois qu'on veut un nombre aléatoire.

---

## NIVEAU 10 : Mathématiques avancées — sqrt() et pow()

### sqrt() et pow() — Racine carrée et puissance

- **Rôle** : calculs mathématiques simples.
- **Syntaxe** :

  ```c
  #include <math.h>

  double r = sqrt(9.0);      // racine carrée : 3.0
  double p = pow(2.0, 3.0);  // 2 à la puissance 3 : 8.0
  ```

- **À compiler** : ajouter `-lm` à la fin : `gcc prog.c -lm`

---

## ANNEXE : "Dictionnaire" (associative map)

- En C il n'existe pas de type natif `dict` (clé→valeur). On utilise plutôt :

  - un tableau de paires (struct) pour petits jeux de données ;
  - un tableau trié + recherche binaire pour accès rapide en lecture ;
  - une table de hachage (hash table) pour accès moyen O(1) — soit l'implémenter, soit utiliser une petite bibliothèque (par ex. `uthash.h` ou `glib`).

- Exemple simple (table naïve : tableau de paires + recherche linéaire) :

  ```c
  #include <string.h>
  #include <stdio.h>

  typedef struct { char key[32]; int value; } Pair;

  Pair dict[100];
  int dict_n = 0;

  void set_pair(const char *k, int v) {
      for (int i = 0; i < dict_n; ++i)
          if (strcmp(dict[i].key, k) == 0) { dict[i].value = v; return; }
      strncpy(dict[dict_n].key, k, 31);
      dict[dict_n].key[31] = '\0';
      dict[dict_n].value = v;
      dict_n++;
  }

  int get_pair(const char *k, int *out) {
      for (int i = 0; i < dict_n; ++i)
          if (strcmp(dict[i].key, k) == 0) { *out = dict[i].value; return 1; }
      return 0; // absent
  }
  ```

- Exemple court avec `uthash` (bibliothèque très légère pour tables de hachage en C) :

  ```c
  // require: https://troydhanson.github.io/uthash/ (ajouter uthash.h au projet)
  #include "uthash.h"
  #include <stdlib.h>
  #include <string.h>

  typedef struct {
      char key[32];
      int value;
      UT_hash_handle hh; // macro pour uthash
  } HashItem;

  HashItem *map = NULL; // pointeur vers la table

  void set_hash(const char *k, int v) {
      HashItem *s;
      HASH_FIND_STR(map, k, s);
      if (!s) {
          s = malloc(sizeof *s);
          strncpy(s->key, k, 31); s->key[31] = '\0';
          s->value = v;
          HASH_ADD_STR(map, key, s);
      } else s->value = v;
  }

  int get_hash(const char *k, int *out) {
      HashItem *s;
      HASH_FIND_STR(map, k, s);
      if (s) { *out = s->value; return 1; }
      return 0;
  }
  ```

- Remarques pratiques :
  - Pour de petits programmes, un tableau de paires suffit et est simple à comprendre.
  - Pour des usages réels (beaucoup d'éléments / performances), préférez une table de hachage (`uthash` ou `glib`).
  - Les clés en C sont souvent des chaînes (`char *`) ou des entiers ; attention à la gestion mémoire (copier les clés si nécessaire).

---

## Bonnes pratiques (à appliquer dès le début)

1. **Toujours initialiser** les variables avant de les utiliser.
2. **Vérifier `scanf`** pour détecter les erreurs d'entrée.
3. **Inclure les en-têtes** : `<stdio.h>`, `<stdlib.h>`, `<time.h>`, `<math.h>`.
4. **Documenter** avec des commentaires.
5. **Utiliser des noms clairs** pour les variables.
6. **Limiter les tailles** de chaînes : `scanf("%99s", buffer);` si buffer[100].
7. **Appeler `srand()` une fois** au démarrage.
8. **Compiler avec `-lm`** si vous utilisez `sqrt()` ou `pow()`.

