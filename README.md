# 🐍 Snake Console Game (C++)

Un petit jeu **Snake** entièrement codé en **C++**, jouable dans la **console Windows**.  
Projet réalisé dans le but de s'améliorer en algorithmie, logique de jeu, et manipulation de la console.

---

## 🎮 Fonctions principales

- 🟢 Mouvement libre du serpent (touches `Z`, `Q`, `S`, `D`)
- 🍎 Système de fruit aléatoire
- 🧠 Gestion du score
- 💀 Collision avec soi-même(pas fait) ou les murs = Game Over
- 🔁 Boucle de jeu fluide avec affichage dynamique en console

---

## 🧰 Technologies utilisées

- Langage : **C++26**
- Compilation : **CMake + CLion**
- Plateforme : **Windows**
- Console native (`<conio.h>` et `system("cls")`)

---

## 🚀 Lancer le jeu

### 🔨 Compilation

```bash
# Depuis le dossier du projet :
cmake -B build
cmake --build build
