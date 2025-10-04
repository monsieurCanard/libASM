<img width="2000" height="626" alt="Image" src="https://github.com/user-attachments/assets/a94317b3-134b-4f77-8767-566b44f9b625" />

# libASM

[![Language](https://img.shields.io/badge/language-Assembly-red.svg)](https://en.wikipedia.org/wiki/Assembly_language)
[![Architecture](https://img.shields.io/badge/architecture-x86--64-green.svg)](https://en.wikipedia.org/wiki/X86-64)

Une bibliothèque de fonctions standard C réécrites en assembleur x86-64.

## 📋 Résumé du projet

Ce projet consiste à réécrire des fonctions C essentielles en assembleur 64-bit, en respectant les conventions d'appel System V AMD64. L'objectif est de comprendre le fonctionnement bas niveau des fonctions standard et d'apprendre l'assembleur Intel.

### 🎯 Fonctions implémentées

| Fonction | Description | Man page |
|----------|-------------|----------|
| `ft_strlen` | Calcule la longueur d'une chaîne | `man 3 strlen` |
| `ft_strcpy` | Copie une chaîne vers une autre | `man 3 strcpy` |
| `ft_strcmp` | Compare deux chaînes | `man 3 strcmp` |
| `ft_write` | Écrit des données vers un descripteur de fichier | `man 2 write` |
| `ft_read` | Lit des données depuis un descripteur de fichier | `man 2 read` |
| `ft_strdup` | Duplique une chaîne en allouant de la mémoire | `man 3 strdup` |

### ⚙️ Spécifications techniques

- **Architecture** : x86-64 (64-bit)
- **Syntaxe** : Intel (non AT&T)
- **Assembleur** : NASM
- **Format** : Position Independent Executable (PIE)
- **Bibliothèque** : `libasm.a`
- **Convention d'appel** : System V AMD64
- **Gestion d'erreurs** : Gestion correcte d'`errno` via `__errno_location`

### 🚀 Compilation et utilisation

```bash
# Compilation de la bibliothèque
make

# Test des fonctions
make test
```

### 📁 Structure du projet

```
libASM/
├── srcs/
│   ├── asm/          # Fichiers source assembleur (.s)
│   ├── objs/         # Fichiers objets (.o)
│   └── tester/       # Programme de test
├── libasm.a          # Bibliothèque compilée
├── Makefile
└── README.md
```

### 📋 Contraintes du projet

- ✅ Assembleur 64-bit uniquement
- ✅ Fichiers `.s` séparés (pas d'inline ASM)
- ✅ Compilation avec NASM
- ✅ Syntaxe Intel obligatoire
- ✅ Gestion des erreurs système (syscalls)
- ✅ Configuration correcte d'`errno`
- ✅ Programme de test inclus

---

## 📚 Documentation technique

### 🔧 Registres x86-64

#### Registres généraux

| Rôle | 64-bit | 32-bit | 16-bit | 8-bit bas | 8-bit haut |
|------|--------|--------|--------|-----------|------------|
| Accumulateur | `rax` | `eax` | `ax` | `al` | `ah` |
| Base | `rbx` | `ebx` | `bx` | `bl` | `bh` |
| Compteur | `rcx` | `ecx` | `cx` | `cl` | `ch` |
| Données | `rdx` | `edx` | `dx` | `dl` | `dh` |
| Destination Index | `rdi` | `edi` | `di` | — | — |
| Source Index | `rsi` | `esi` | `si` | — | — |
| Base Pointer | `rbp` | `ebp` | `bp` | — | — |
| Stack Pointer | `rsp` | `esp` | `sp` | — | — |
| Étendus | `r8–r15` | `r8d–r15d` | `r8w–r15w` | `r8b–r15b` | — |

#### Utilisation des registres

- **`rax`** : Registre principal (retours de fonction, calculs)
- **`rbx`, `rcx`, `rdx`** : Registres de travail
- **`rdi`, `rsi`** : Passage d'arguments (pointeurs)
- **`rsp`** : Stack pointer (sommet de la pile)
- **`rbp`** : Base pointer (variables locales)
- **`r8–r15`** : Registres supplémentaires x86-64

### 🔄 Instructions de comparaison et saut

#### Instruction CMP

```assembly
cmp A, B    ; Effectue A - B sans stocker le résultat
            ; Met à jour les flags du processeur
```

#### Instruction TEST

```assembly
test A, B    ; Effectue A & B sans stocker le résultat
             ; Met à jour les flags du processeur
```

#### Flags du processeur

| Flag | Description | Condition |
|------|-------------|-----------|
| `ZF` | Zero Flag | 1 si résultat = 0 |
| `SF` | Sign Flag | 1 si résultat < 0 (négatif) |
| `CF` | Carry Flag | 1 si dépassement non signé |
| `OF` | Overflow Flag | 1 si dépassement signé |

#### Instructions de saut conditionnel

| Instruction | Description | Condition |
|-------------|-------------|-----------|
| `je LABEL` | Jump if Equal | `ZF = 1` (résultat = 0) |
| `jne LABEL` | Jump if Not Equal | `ZF = 0` (résultat ≠ 0) |
| `jl LABEL` | Jump if Less | `SF ≠ OF` (signé < 0) |
| `jg LABEL` | Jump if Greater | `ZF=0 et SF=OF` (signé > 0) |
| `jz LABEL` | Jump if Zero | Identique à `je` |
| `jnz LABEL` | Jump if Not Zero | Identique à `jne` |

### 💾 Instructions de manipulation d'adresses

#### LEA (Load Effective Address)

```assembly
lea rsi, [rsi]  ; Charge l'adresse effective dans le registre
                ; Ne lit pas le contenu mémoire
                ; Calcule l'adresse et la stocke dans le registre
```

**Note** : `lea rsi, [rsi]` ne modifie pas `rsi` car il charge l'adresse actuelle.

### 🔗 Liaison dynamique (PLT/GOT)

#### Concepts

- **PLT (Procedure Linkage Table)** : Trampoline de code dans le binaire
- **GOT (Global Offset Table)** : Table contenant les vraies adresses remplies par le loader

#### Mécanisme d'appel

```assembly
call __errno_location wrt ..plt
```

**Processus** :
1. Saut dans le trampoline PLT
2. Lecture de l'entrée correspondante dans la GOT
3. Redirection vers la vraie fonction dans la libc

### 🛠️ Convention d'appel System V AMD64

- **Arguments** : `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9`
- **Valeur de retour** : `rax`
- **Sauvegarde caller** : `rax`, `rcx`, `rdx`, `rsi`, `rdi`, `r8-r11`
- **Sauvegarde callee** : `rbx`, `rbp`, `r12-r15`

### 🚨 Gestion des erreurs

Pour les syscalls, la gestion d'erreur se fait via :
- Appel à `__errno_location` pour obtenir l'adresse d'`errno`
- Configuration de la valeur d'erreur appropriée
- Retour de -1 en cas d'erreur
