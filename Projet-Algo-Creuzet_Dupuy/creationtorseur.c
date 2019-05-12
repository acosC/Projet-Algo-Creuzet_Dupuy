#include "rdm.h"
// test update github sur la partie Brouillon
const int valMax = 4;

void NombrePoints(int nombre_point){

    while (nombre_point > 4 || nombre_point <= 0){
        while (nombre_point <= 0){
        printf("Vous ne pouvez pas avoir un nombre de point negatif, combien de points avez-vous dans votre exercice ? ");
        scanf("%i",&nombre_point);
        }
        while (nombre_point > 3){
        printf("Vous ne pouvez pas nous donner trop de points, combien de poins avez-vous dans ton exercice ? ");
        scanf("%i",&nombre_point);
        }
    }
}

void Initialisation(int i, torseur* t){

    int j;

    for (j = 0 ; j < 3 ; j++){
        t[i].f[j] = 1;
        t[i].m[j] = 1;
    }
   }

void Localisation(int var, torseur* t, int i, int origine){

    if (var == 2){
        t[i].c[2] = 0;
        t[i].inconnu_f = 2;
        t[i].inconnu_m = 1;
        if (origine==0)
        {
          t[i].c[0] = 0;
          t[i].c[1] = 0;
        }
        else {
          printf("Ou est-il localise ?\n");
          printf("en x : ");
          scanf("%lf",&t[i].c[0]);
          printf("en y : ");
          scanf("%lf",&t[i].c[1]);

          }

    }

    if (var == 3){
        t[i].inconnu_f = 3;
        t[i].inconnu_m = 3;
        if (origine==0)
        {
          t[i].c[0] = 0;
          t[i].c[1] = 0;
          t[i].c[2] = 0;
        }
        else
        {
          printf("Ou est-il localise ?\n");
           printf("en x : ");
           scanf("%lf",&t[i].c[0]);
           printf("en y : ");
           scanf("%lf",&t[i].c[1]);
           printf("en z : ");
           scanf("%lf",&t[i].c[2]);

        }
    }
}

void Liaison(int liaison, torseur* t, int i, int var){
    switch (liaison){
    case 0:
        if (var == 2){
            t[i].inconnu_f = 2;
            t[i].inconnu_m = 1;
            t[i].f[2] = 0;
            t[i].m[0] = 0;
            t[i].m[1] = 0;
        }
        if (var == 3){
            t[i].inconnu_f = 3;
            t[i].inconnu_m = 3;
        }
        break;

    case 1:
        if (var == 2){
            t[i].inconnu_f = 1;
            t[i].inconnu_m = 1;
            t[i].f[2] = 0;
            t[i].m[0] = 0;
            t[i].m[1] = 0;
        }
        if (var == 3){
            t[i].inconnu_f = 2;
            t[i].inconnu_m = 3;
        }
        t[i].f[0] = 0;
        break;

    case 2 :
        if (var == 2){
            t[i].inconnu_f = 2;
            t[i].inconnu_m = 1;
            t[i].f[2] = 0;
            t[i].m[1] = 0;
        }
        if (var == 3){
            t[i].inconnu_f = 3;
            t[i].inconnu_m = 2;
        }
        t[i].m[0] = 0;
        break;

    case 3 :
        if (var == 2){
            t[i].inconnu_f = 1;
            t[i].inconnu_m = 1;
            t[i].f[2] = 0;
            t[i].m[1] = 0;
        }
        if (var == 3){
            t[i].inconnu_f = 2;
            t[i].inconnu_m = 2;
        }
        t[i].m[0] = 0;
        t[i].f[0] = 0;
        break;

    case 4 :
        if (var == 2){
            t[i].inconnu_f = 1;
            t[i].inconnu_m = 1;
            t[i].f[2] = 0;
        }
        if (var == 3){
            t[i].inconnu_f = 2;
            t[i].inconnu_m = 2;
        }
        t[i].m[0] = 0;
        t[i].m[1] = 0;
        t[i].m[2] = 0;
        break;

    case 5 :
        if (var == 2){
            t[i].inconnu_f = 1;
            t[i].inconnu_m = 1;
        }
        if (var == 3){
            t[i].inconnu_f = 2;
            t[i].inconnu_m = 2;
        }
        t[i].m[0] = 0;
        t[i].m[1] = 0;
        t[i].f[2] = 0;
        t[i].f[0] = 0;
        break;

    case 6 :
        if (var == 2){
            t[i].inconnu_f = 1;
            t[i].inconnu_m = 0;
            t[i].f[2] = 0;
        }
        if (var == 3){
            t[i].inconnu_f = 2;
            t[i].inconnu_m = 0;
        }
        t[i].m[2] = 0;
        t[i].m[0] = 0;
        t[i].m[1] = 0;
        t[i].f[0] = 0;
        break;

    case 7 :
        if (var == 2){
            t[i].inconnu_f = 0;
            t[i].inconnu_m = 0;
            t[i].f[2] = 0;
        }
        if (var == 3){
            t[i].inconnu_f = 1;
            t[i].inconnu_m = 0;
        }
        t[i].m[2] = 0;
        t[i].m[1] = 0;
        t[i].m[0] = 0;
        t[i].f[2] = 0;
        t[i].f[0] = 0;
        break;
    }
}

void Forces(int var, torseur* t, int i, int forces){

    int j = 0;

    switch(forces){
    case 0 :
        while (j < 3){
            if (t[i].f[j] != 0){
                if (j == 0)
                    printf("Force en X : ");
                if (j == 1)
                    printf("Force en Y : ");
                if (j == 2)
                    printf("Force en Z : ");
                scanf("%lf", &t[i].f[j]);
            }
            j++;
        }
        j = 0;
        while (j < 3){
            if (t[i].m[j] != 0){
                if (j == 0)
                    printf("Moment en X : ");
                if (j == 1)
                    printf("Moment en Y : ");
                if (j == 2)
                    printf("Moment en Z : ");
                scanf("%lf", &t[i].m[j]);
            }
            j++;
        }
        break;

    case 1 :
        for (j = 0 ; j < 3 ; j++){
            if (t[i].f[j] != 0)
                t[i].f[j] = -1;
            if (t[i].m[j] != 0)
                t[i].m[j] = -1;
        }
        break;
    }
}


int EntrerTorseurInit(int i, torseur t[valMax], int var, int origine){
    origine = -1;

    Initialisation(i, t);

    printf("Comment s'appelle votre point ? ");
    scanf("%s",t[i].nom);

    if (origine == -1 ){
      printf("Est-ce le point d'origine ? (0 : oui | -1 : non)\n");
      scanf("%i",&origine);
      if (origine == 0){
        origine = i;
      }
    }
    Localisation(var, t, i, origine);

    return origine;
    }

  void EntrerTorseurFin(int i, torseur t[valMax], int var, int origine){

    int  liaison = -1, forces = -1;


    printf("Quelle est la liaison de votre point ?\n");
    printf("0 - Encastrement\n");
    printf("1 - Glissiere\n");
    printf("2 - Pivot\n");
    printf("3 - Pivot Glissant\n");
    printf("4 - Rotule\n");
    printf("5 - Lineaire rectitiligne\n");
    printf("6 - Lineaire annulaire\n");
    printf("7 - Ponctuelle\n");
    scanf("%i", &liaison);
    t[i].l = liaison;              //choix type de liaison

    Liaison(liaison, t,i, var);

    printf("Connaissez-vous les forces/moments qui s'appliquent sur ce point ?\n"); //-1
    printf("0 - oui\n");
    printf("1 - non\n");
    scanf("%i", &forces);

    Forces(var, t, i, forces);
    AfficherTorseur(t, i);

}

void AfficherTorseur(torseur* t, int i){
    printf("\n\n----RECAP Torseur----\n\n");
    printf("NOM : %s\n",t[i].nom);
    printf("TYPE : %i\n",t[i].l);
    printf("COORD : %lf et %lf\n",t[i].c[0], t[i].c[1]);
    printf("INC : %i\n",t[i].inconnu_f);
    printf("FORCES : %lf, %lf et %lf\n\n",t[i].f[0], t[i].f[1], t[i].f[2]);
    printf("MOMENTS : %lf, %lf et %lf\n\n",t[i].m[0], t[i].m[1], t[i].m[2]);
}
