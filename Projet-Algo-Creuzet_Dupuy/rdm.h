#ifndef RDM_H_INCLUDED
#define RDM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef enum {ENCASTREMENT = 0, GLISSIERE, PIVOT, PIVOT_GLISSANT, ROTULE,
LINEAIRE_RECT, LINEAIRE_ANNULAIRE, PONCTUELLE}liaison;

typedef struct{
    double m[3];
    double f[3];
    double c[3];
    char nom[1];
    liaison l;
    int inconnu_f;
    int inconnu_m;
}torseur;

void NombrePoints(int nombre_point);
void Initialisation(int i,torseur* t);
void Localisation(int pb_plan, torseur* t, int i, int origine);

//int Orientation(torseur* t, int var);
void Liaison(int liaison, torseur* t, int i, int var);
void Forces(int var, torseur* t, int i, int forces);
int EntrerTorseurInit(int numero_torseur, torseur t[5], int variation, int origine);
void EntrerTorseurFin(int i, torseur t[5], int var, int origine);
void AfficherTorseur(torseur* t, int i);

//Résultante
void ResolForce2Torseurs(torseur* t);
void ResolForce3Torseurs(torseur* t);
void AfficherForces(torseur* t, int i);

//Moments
void babar(torseur *t, int origine);
void AfficherMoments(torseur* t, int i);

//torseurs
void AfficherlesTorseurs(torseur *t, int i);

//Graphique
void affichercourbe(torseur *t);

#endif // RDM_H_INCLUDED
