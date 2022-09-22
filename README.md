
# Proxy DNS

L'objectif du projet consiste à développer un serveur mandataire pour les requêtes DNS (autrement dit un proxy
DNS). Ce type de service logiciel est utilisé en cybersécurité aussi bien d'un point de vue défensif que offensif. En
mode défensif, il sera utilisé pour enregistrer toutes les demandes de résolution de noms réalisées par une cible et ainsi
étudier son comportement. Cela permet également de filtrer certaines requêtes. De manière offensive, un proxy DNS
permet de leurrer une machine pour la rediriger vers une autre destination.

## Contenu du dépôt :

- **README.md** : le fichier que vous êtes en train de lire .

- **Makefile** : permet la compilation du code métier (cible main) et des tests unitaires (cible tests) .

- **Le répertoire lib** : Contenant les librairies statiques et dynamiques de fonctions définies , utilisés dans le programme .

- **Le répertoire src** : le répertoire src contient les fichiers sources .c du projet .


## Installation :

```
git clone https://github.com/Hblgrim/PROXY-DNS

cd PROXY-DNS
```

## Compilation

La commande **make all** compile tous les fichiers.

La commande **make clean** efface tous les fichiers objets et fichiers binaires.

La commande **make mrproper** efface tous les fichiers créés par la compilation du projet.



## L’usage :

Pour exécuter le programme automatiquement, il suffit juste de taper la commande suivant : 
```
LD_LIBRARY_PATH=.:../libs/dynamic ./server

```

### Le fonctionnement du programme :

1. Charger le fichier de données

2. Attendre une commande

3. Traiter la commande

4. Afficher le résultat de cette commande

5. Revenir à l'étape 2

### Les commandes :

-  Afficher le message d'aide du programme qui explique toutes les options possibles :
```
-h ou --help
````

- Modifier le port par défaut (53) utilisé par le programme pour recevoir les les questions DNS ::
```
-p PORT ou --port=PORT
```

- Spécifier un serveur DNS particulier à la place du serveur DNS par défaut:
```
-s SERVEUR ou --serveur=SERVEUR 
```

- Choisir la stratégie à charger :
```
-l STRATEGIE ou --logstrategy=STRATEGIE
```

- Passer des paramètres d'initialisation à la stratégie choisie :
```
-i INIT_ARGS_STRATEGIE ou --initlogstrategie=INIT_ARGS_STRATEGIE
```

