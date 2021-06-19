# CTF-5A
## _Introduction_
Ce CTF a été concu pour pouvoir être monté très facilement, directement en local ou sur un serveur.
Un Dockerfile et un docker-compose ont été créés à cet effet.

### _Configuration_
Par défault, les ports sont :
#### _Fornum (box du CTF)_
| Service | Port |
| ------ | ------ |
| **SSH** | **3222** |
| **HTTP** | **80** |

#### _CTFd (plateforme de gestion de CTF)_
| Service | Port |
| ------ | ------ |
| **HTTP** | **8000** |

> NB: Les redirections de ports peuvent être modifiées à votre convenance au sein du fichier docker-compose.yml.

## _Installation_
L'installation permet de lancer directement 2 conteneurs, l'un hébergeant la plateforme CTFd et l'autre la box du CTF.
```
git clone https://github.com/Daniel-Zeitoun/CTF/
cd CTF/docker
docker-compose up -d
```

## _La Plateforme CTFd_
L'archive CTFd.zip contient les challenges, les indices, etc. et est conçue pour être directement importée sur la plateforme CTFd une fois le conteneur lancé.

## _Le CTF_
Le CTF commence par l’exécutable CTF_protected.exe qui se trouve à la racine du repos ou en téléchargement dans le challenge Windows Binary de la plateforme CTFd.
> NB: Pour ne pas regarder d'indices et/ou de mots de passe, il est préférable de ne pas regarder les fichiers hormis docker-compose.yml pour la configuration des redirections de ports.

Bon jeu !
