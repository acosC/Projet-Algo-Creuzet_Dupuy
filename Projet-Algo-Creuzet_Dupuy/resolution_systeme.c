#include "fonctions.h"
const int valmax = 10;

void lectureVect(int dim, double vect[]) //Permet à l'utilisateur de remplir un vecteur
{
    int i;

    for (i = 0 ; i < dim ; i++){
        scanf("%lf",&vect[i]);
    }
}

void afficheVect(int dim, double vect[]) //Permet d'afficher à l'écran un vecteur
{
    int i;

    for (i = 0 ; i < dim ; i++){
        printf("%lf\n",vect[i]);
    }
}

void lectureMat(int dim, double mat[][valmax]) //permet à l'utilisateur de remplir une matrice ligne par ligne
{
    int i, j; //i->ligne, j->colonne;

    for (i = 0 ; i < dim ; i++){

        for (j = 0 ; j < dim ; j++){
            scanf("%lf",&mat[i][j]);
        }
    }
}

void afficheMat(int dim, double mat[][valmax]) //Permet d'afficher à l'écran une matrice
{
    int i, j;

    for (i = 0 ; i < dim ; i++){

        for (j = 0 ; j < dim ; j++){
            printf("%lf ",mat[i][j]);
        }
        printf("\n");
    }
}

void resolSys(int dim, double A[][valmax], double b[], double x[])//Résolution d'un système triangulaire supérieur
{
    int i, k, n = dim -1;
    double S; //initialisation du vecteur x (solution)

    for (i = 0 ; i < dim ; i++)// fixe la ligne pour laquelle on cherche la solution (on commence par le bas)
    {
        S = 0; // initialise S=0 pour effectuer la somme

        for (k = 0 ; k < i ; k ++){
            S = A[n-i][n-k]*x[n-k]+S;  // Calcul la somme des produits des éléments de x par leur coéfficient (élément de A)
        }
        x[n-i] = (b[n-i]-S)/A[n-i][n-i];// résolution de A[n-i][n-i]*x[n-i] + S = b[n-i]
    }
}

double maximum(int dim, int *i, double A[][valmax], int k)  // Retourne l'élément maximum de la colonne k d'une matrice à partir de la ligne k
{                                                       //et indique dans *i l'indice de cet élément
    int j;
    double max = abs(A[k][k]); //initialisation de max

    for (j = k+1 ; j < dim ; j++){
        if (abs(A[j][k]) > max)   // Si l'élément A[j][k] k étant fixé  est plus grand que l'élément précédent
        {
            max = abs(A[j][k]);                     //max vaut alors l'élément actuel
            *i = j;                                 //et l'indice est écrit dans *i
        }
    }
    return max;
    }

void changeLigne(int dim, int j, int i, double A[][valmax], double b[]) //change deux lignes i et j d'une matrice et deux éléments d'un vecteur
{
    int k;
    double v;   // variable de transition

    for(k = 0 ; k < dim ; k++){
        v = A[j][k];
        A[j][k] = A[i][k];//on intervertit les éléments colonnes par colonnes
        A[i][k] = v;
    }

    v = b[i];
    b[i] = b[j]; // on intervertit les éléments du vecteur
    b[j] = v;
}

void Metzero(int dim, double A[][valmax], double b[], int k) // Applique le pivot situé en A[k][k]
{
    int i, j;
    double r, pivot = A[k][k];  // r est le rapport A[i][k]/pivot qui sera fixé pour chaque ligne

    for (i = k+1 ; i < dim ; i++)  //on effectue le calcul pour les lignes et colonnes inférieures  à l'élément pivot
    {
        r = A[i][k]/pivot; //calcul du rapport pour la ligne actuelle
        for (j = k ; j < dim ; j++){

            A[i][j] = A[i][j]-A[k][j]*r; //on effectue Ligne[i]-r*Ligne[k]
        }
        b[i] = b[i]-b[k]*r;  //De même pour les solutions afin de garder l'équivalence entre le nouveau système et l'ancien
    }
}


int Triangularisation(int dim, double A[][valmax], double b[])//Permet de triangularisé le système Ax=b (A devient triangulaire supérieure)
{                               // la fonction retourne 0 le cas où il est impossible de calculer les solutions (déterminant nul)
    int j = 0, i;
    double max = -1;

    while (j < dim && max != 0) //l'opération s'effectue sur toutes les colonnes et la fonction doit s'arrêter dans le cas où le déterminant est nul
    {                      // car dans ce cas il est impossible de trouver de solution
        if (A[j][j] == 0)       //dans le cas où le pivot de la colonne est nul on lance la recherche du maximum qui renvoie le maximum
        {
            max = maximum(dim, &i, A, j);  // si tous les élément de la colonne sont nul max =0 et on sort du programme
            if (max != 0)
                changeLigne(dim, j, i, A, b);  // Dans le cas ou il y a un maximum on intervertit les lignes
        }
        if (A[j][j] != 0)
            Metzero(dim, A, b, j); // si le déterminant n'est pas nul,et le pivot n'est plus nul,on applique la fonction metzero
        j++; //on change de colonne
    }
    if(max == 0)
        return 0;
    else
        return 1;
}

void systeme()//demande des données à l'utilisateur
{
    int val;

    double A[valmax][valmax];//matrica rentrée par l'utilisateur
    double b[valmax], x[valmax];//b->vecteur rentré par l'utilisateur      x-> vecteur solution du système

    printf("Nombre d'inconnues?\n");//le nombre d'inconnues sera égale à la dimension de la matrice et du vecteur
    scanf("%d",&val);

    printf("Saisie Matrice en ligne\n");
    lectureMat(val, A);

    printf("Saisie du vecteur(solution) \n");
    lectureVect(val, b);

    printf("\n");
    printf("Votre matrice:\n");//affiche la matrice rentrée
    afficheMat(val, A);

    printf("Votre vecteur:\n");//affiche le vecteur rentré
    afficheVect(val, b);
    printf("\n");

    if(Triangularisation(val, A, b)){
        resolSys(val, A, b, x);
        printf("Solution:\n");
        afficheVect(val, x);
    }
    else
        printf("Le déterminant est nul, le système n'est pas de Cramer\n");
}
