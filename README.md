*Cette activité a été créée dans le cadre du cursus 42 par mchapui, bdecourt.*

---

## Description

Push_swap est un projet algorithmique qui consiste à trier une pile d'entiers en utilisant deux piles (`a` et `b`) et un ensemble limité d'opérations, tout en minimisant le nombre total de mouvements. Le défi réside dans le choix de l'algorithme le plus efficace selon la taille et le degré de désordre de l'entrée — ce qui rend la complexité algorithmique très concrète et mesurable.

La pile `a` commence avec tous les entiers (sans doublons), la pile `b` commence vide. L'objectif est de trier la pile `a` dans l'ordre croissant en utilisant le moins d'opérations possible.

---

## Instructions

**Compilation :**
```bash
make
```

**Exécution :**
```bash
./push_swap [--simple | --medium | --complex | --adaptive] <liste d'entiers>
```

Le flag de stratégie est optionnel. Sans lui, l'algorithme adaptatif est utilisé par défaut.

**Exemples :**
```bash
./push_swap 2 1 3 6 5 8
./push_swap --simple 5 4 3 2 1
./push_swap --complex 4 67 3 87 23
./push_swap --bench --adaptive 4 67 3 87 23
```

**Mode benchmark** (`--bench`) : affiche le pourcentage de désordre, la stratégie utilisée, le nombre total d'opérations, et le détail par type d'opération sur `stderr`.

**Utilisation avec le checker :**
```bash
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
```

**Fichiers à soumettre** *(à la racine du dépôt)* :
- `Makefile`
- `*.h`
- `*.c`

---

## Opérations disponibles

| Opération | Description |
|-----------|-------------|
| `sa` / `sb` | Échange les deux premiers éléments de la pile a / b |
| `ss` | `sa` et `sb` en même temps |
| `pa` / `pb` | Pousse le sommet de b vers a / le sommet de a vers b |
| `ra` / `rb` | Rotation vers le haut de la pile a / b (le premier devient le dernier) |
| `rr` | `ra` et `rb` en même temps |
| `rra` / `rrb` | Rotation inverse de la pile a / b (le dernier devient le premier) |
| `rrr` | `rra` et `rrb` en même temps |

---

## Choix des algorithmes & Justification

Ce projet implémente quatre stratégies de tri distinctes, sélectionnées automatiquement ou via un flag.

### Mesure du désordre

Avant de trier, un score de désordre entre 0 et 1 est calculé en comptant les inversions (paires où un nombre plus grand apparaît avant un plus petit) divisé par le nombre total de paires. Un désordre de 0 signifie que la pile est déjà triée ; 1 signifie qu'elle est complètement inversée.

---

### 1. Algorithme Simple — O(n²)

**Stratégie :** Adaptation du tri par sélection.

À chaque étape, l'élément minimum de la pile `a` est localisé, amené au sommet via `ra` ou `rra` (selon ce qui est le plus court), puis poussé dans `b`. Une fois tous les éléments dans `b`, ils sont repoussés dans `a` dans l'ordre.

**Justification :** Pour chacun des n éléments, on peut effectuer jusqu'à n/2 rotations pour trouver et déplacer le minimum — ce qui donne O(n²) opérations. Simple à comprendre et à implémenter correctement. Adapté aux très petites entrées.

---

### 2. Algorithme Moyen — O(n√n)

**Stratégie :** Tri par blocs (chunks).

L'intervalle des entiers est divisé en √n blocs de taille égale. Les éléments de la pile `a` appartenant au bloc courant sont poussés dans `b` (en utilisant des rotations pour les trouver efficacement). Une fois tous les blocs traités, les éléments sont ramenés de `b` vers `a` dans l'ordre trié en cherchant le maximum à chaque étape.

**Justification :** Avec √n blocs de taille √n, chaque bloc nécessite O(√n) rotations pour localiser ses éléments, et il y a √n blocs — ce qui donne O(n√n) opérations au total. C'est une amélioration significative par rapport à O(n²) pour des entrées de taille moyenne (ex : 100–500 nombres).

---

### 3. Algorithme Complexe — O(n log n)

**Stratégie :** Adaptation du tri Radix (LSD).

Les nombres sont compressés en indices [0, n-1], puis triés bit par bit du moins significatif au plus significatif. À chaque niveau de bit, les éléments avec un bit à 0 sont poussés dans `b`, ceux avec un bit à 1 restent dans `a` via rotation ; puis tout `b` est repoussé dans `a`. Cela se répète pour log₂(n) niveaux de bit.

**Justification :** Chacun des log₂(n) passages traite n éléments une fois — ce qui donne O(n log n) opérations Push_swap. Le tri Radix s'adapte naturellement au modèle à deux piles et évite les comparaisons coûteuses. Idéal pour les grandes entrées très désordonnées.

---

### 4. Algorithme Adaptatif — Conception personnalisée

**Stratégie :** Sélection guidée par le désordre.

Le désordre est calculé en premier, puis la stratégie appropriée est choisie :

| Désordre | Régime | Méthode | Complexité |
|----------|--------|---------|------------|
| < 0,2 | Faible | Correction par insertion : seuls les éléments mal placés sont déplacés via rotations et échanges | O(n) |
| 0,2 – 0,5 | Moyen | Tri par blocs (même que l'algorithme Moyen) | O(n√n) |
| ≥ 0,5 | Élevé | Tri Radix LSD (même que l'algorithme Complexe) | O(n log n) |

**Justification des seuils :**
- En dessous de 0,2 : moins de 20% des paires sont inversées — la pile est quasi-triée. Un passage linéaire corrigeant les inversions locales suffit et est bien moins coûteux qu'un tri complet.
- Entre 0,2 et 0,5 : le désordre partiel bénéficie du regroupement par blocs sans la surcharge des passages Radix complets.
- À partir de 0,5 : la pile est suffisamment désordonnée pour que seule une stratégie logarithmique atteigne les benchmarks de performance.

**Complexité spatiale :** Toutes les stratégies utilisent O(n) d'espace auxiliaire (les deux piles), avec O(log n) pour le suivi Radix et O(√n) pour le suivi des blocs dans la stratégie moyenne.

---

## Benchmarks de performance

| Taille de l'entrée | Passage | Bon | Excellent |
|--------------------|---------|-----|-----------|
| 100 nombres | < 2000 ops | < 1500 ops | < 700 ops |
| 500 nombres | < 12000 ops | < 8000 ops | < 5500 ops |

---

## Contributions

| Login | Contributions |
|-------|---------------|
| mchapui | Algorithme simple & adaptatif, opérations sur les piles, gestion des erreurs, Makefile |
| bdecourt | Algorithme moyen & complexe, mode benchmark, mesure du désordre, tests |

---

## Ressources

- [Tri Radix — Wikipédia](https://fr.wikipedia.org/wiki/Tri_par_base)
- [Complexité des algorithmes de tri — GeeksForGeeks](https://www.geeksforgeeks.org/ing-algorithms/)
- [Visualiseur Push_swap](https://github.com/o-reo/push_swap_visualizer)

**Utilisation de l'IA :** Claude a été utilisé en mode "enseignant" pour clarifier des concepts algorithmiques (manipulation des bits pour le tri Radix, calcul de la taille des blocs pour O(n√n)), aider à structurer le README, et vérifier les arguments de complexité. Tout le code a été écrit, compris et testé par les deux apprenants avant soumission.