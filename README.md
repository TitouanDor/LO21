# LO21

## But du projet
Ce projet fais partie de l'UE LO21 de l'UTBM lors du semestre P25.\
Il s'agit de faire un système expert qui est composé d’une base de connaissances (une expertise sur un domaine donné), une base de faits (des faits certains concernant un domaine donné) et un moteur d’inférence (un système permettant de déduire de nouveaux faits certains à partir de la base de connaissances et de la base de faits).

## Pour lancer le projet
Créez un dossier build dans le projet
```mkdir build && cd build```\
Initialiser CMake avec 
```cmake ..```\
Pour compiler le projet faites
```cmake --build .```

## option
Si vous voulez tester le projet avec une base de fait et de connaissance déjà préfaite, lancer le projet avec ```./projet ex``` sinon faites simplement ```./projet```