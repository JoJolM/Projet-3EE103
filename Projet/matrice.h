#ifndef _matrice_h_
#define _matrice_h_

#include <stdlib.h>
#include <stdio.h>
#include "myBmpGris.h"


/** Construction de Matrice
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  */
double** createMatrice(int dimX, int dimY);

/**Destruction de Matrice
  * @param Matrice � detruire
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  */
void destroyMatrice(double** matrice, int dimX, int dimY);

/** Impression de matrice
  * @param Matrice � imprimer
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  */
void printMatrice(double** matrice, int dimX, int dimY);

/** Conversion bmp vers une matrice de double
  * @param Structure d'une image de type Bmp � convertir
  */
double** bmpToMatrice(BmpImg bmpImg);



#endif


//extern struct BmpImg BmpImg;

/*typedef struct{
	int dimX;	    // Dimension en x (hauteur)
	int dimY;		// Dimension en y (largeur)
	double** data;	// Matrice contenant les donn�es (double)
} Matrice;*/

