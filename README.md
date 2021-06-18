# Introduction
Le CTF a été concu pour pouvoir être monter directement en local, ou sur un serveur, et cela très facilement.
Un Dockerfile a été créé à cet effet.

Par défault, les ports sont :
fornum
- SSH 3222
- HTTP 80
ctfd
- 8000 HTTP

N.B. Les redirections de ports peuvent être modifiées à votre convenance au sein du fichier docker-compose.yml.
N.B.bis. Nous recommandons d'éviter de changer le port SSH 3222 si possible.


# Installation
L'installation permet de lancer directement 2 conteneurs, l'un hébergeant la plateforme CTFd et l'autre une partie du CTF.

git clone https://github.com/Daniel-Zeitoun/CTF/
cd CTF/docker
docker-compose up -d


# La Plateforme CTFd
L'archive CTFd.zip contient les challenges, les indices, etc. et est conçue pour être directement importée sur la plateforme CTFd une fois le conteneur lancé.

# Le CTF
Le CTF commence par l’exécutable CTF_protected.exe qui se trouve à la racine ou en téléchargement dans le challenge Windows Binary de la plateforme CTFd.
