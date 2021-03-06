#include "matrice.h"


/** Construction de Matrice
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  */
double** createMatrice(int dimX, int dimY){
    int i;
    double** res;                                           // r�sultat
    res = malloc(dimX*sizeof(double*));                     // lignes
    for(i = 0; i < dimX; i++){
        res[i] = calloc(dimY, sizeof(double));              // colonnes
    }
    return res;
}

/** Remplissage de matrice avec une valeur particuli�re
  * @param Matrice
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  * @param valeur
  */
void fillMatrice(double** matrice, int dimX, int dimY, double value){
    int i, j;
    for(i = 0; i < dimX; i++){
        for(j = 0; j < dimY; j++){
            matrice[i][j] = value;                //valeur dans la matrice
        }
    }
}

/**Destruction de Matrice
  * @param Matrice � detruire
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  */
void destroyMatrice(double** matrice, int dimX, int dimY){
    int i;
    for(i =0; i < dimX; i++){
        free(matrice[i]);
    }
    free(matrice);
    matrice = NULL;
}

/** Impression de matrice
  * @param Matrice � imprimer
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  */
void printMatrice(double** matrice, int dimX, int dimY){
    int i, j;
    for(i = 0; i < dimX; i++){
        for(j = 0; j < dimY; j++){
            printf("%.2f\t", matrice[i][j]);                //affichage du pixel
        }
        printf("\n");
    }
}

/** Conversion bmp vers une matrice de double
  * @param Structure d'une image de type Bmp � convertir
  */
double** bmpToMatrice(BmpImg bmpImg){
    int i, j;
    double** res = createMatrice(bmpImg.dimX, bmpImg.dimY); //initialisation r�sultat
    for(i = 0; i < bmpImg.dimX; i++){
        for(j = 0; j < bmpImg.dimY; j++){
            res[i][j] = 1.0*getPixel(bmpImg, i, j);         //recuperation valeur pixel aux coord correspondantes
        }
    }
    return res;
}

/** Ecriture sur un fichier texte
  * @param Matrice source
  * @param dimension X de la matrice
  * @param dimension Y de la matrice
  * @param Fichier a remplir
  */
void MatriceToTxt(double** matrice, int dimX, int dimY, FILE *fichier){
    int i, j;
    fprintf(fichier, "%d\t%d\n", dimX, dimY);               //�criture des dimensions
    for(i = 0; i < dimX; i++){
        for(j = 0; j < dimY; j++){
            fprintf(fichier,"%.2f\t", matrice[i][j]);               //�criture du pixel
        }
        fprintf(fichier,"\n");
    }
}

