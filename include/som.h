#ifndef SOM_INCLUDED
#define SOM_INCLUDED
/** @file som.h
    SOM algorithme et ses fonctions
*/

#include "include/utilities.h"
#include "include/randomize.h"
#include "include/readpng.h"
#include "include/display.h"
#include "include/mainwindow.h"

extern int MY_HSV, MY_HSL, MY_HSVRGB, MY_HSVL, POST_PROCESS;

/**
 * Récupérer les vecteurs de caractéristiques dans un ficher
 * @param  rowImg   image
 * @param  nx       taille du vecteur retourné
 * @param  lenx     taille des vecteurs du vecteur
 * @param  width    largeur image
 * @param  height   hauteur image
 * @return          vecteur de vecteurs
 */
float ** getPoints(png_bytep * rowImg, int * lenx, int *nx, int width, int height);

/**
 * Algo SOM
 * @param  allx         vecteurs d'entrée
 * @param  lenx         taille d'un vecteur
 * @param  nx           nombre de capteurs
 * @param  nw           nombre de neurone
 * @param  progressBar  bar de progression
 * @param  verbose
 * @return              vecteur de neurone
 */
float ** som(float ** allx, int lenx, int nx, int nw, QProgressBar *progressBar, int verbose);

/**
 * Décroitre le coefficient d'apprentissage
 * @param a coefficient
 * @param a0 coefficient initiale
 * @param t temps
 * @param T tems total
 */
void decreaseA(float * a, float a0, int t, int T);

/**
 * Décroitre le rayon du voisinage
 * @param NhdSize rayon
 * @param N0      taille initiale du voisinage
 * @param t       temps
 * @param T       temps total
 */
void decreaseNhdSize(float * NhdSize, int N0, int t, int T);

/**
 * Fonction de voisinage
 * @param  dist    ||j-j*||
 * @param  a       coef d'apprentissage
 * @return         coef
 */
float h(float dist, float a);

/**
 * Recherche l'index du bmu
 * @param  x    vecteur d'entrée
 * @param  w    vecteur de vecteurs
 * @param  lenx taille du vecteur x
 * @param  lenw taille du vecteur w
 * @return      index du bmu
 */
int findBmuIndex(float ** w, float * x, int lenx, int lenw);

/**
 * Renvoie les voisins d'un neurone
 * @param  w        vecteurs de neurones
 * @param  bmuIndex nième neurone
 * @param  r        rayon
 * @param  nw       nombre de neurones
 * @param  lenx     taille d'un neurone
 * @param  l        nombre de voisins
 * @return          voisins du neurone
 */
float ** getNei(float ** w, int bmuIndex, int r, int nw, int lenx, int * l);

/**
 * Normaliser ts les vecteurs d'un vecteur
 * @param w      vecteurs de vecteurs
 * @param lenw   taille de w
 * @param lenx   taille des vecteurs de w
 */
void normalizeAll(float ** w, int lenw, int lenx);

#endif
