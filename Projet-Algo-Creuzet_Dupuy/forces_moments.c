#include "rdm.h"
#include "gnuplot_i.h"

void AfficherForces(torseur* t, int i){
    int j;
    printf("\n\n---- Calcul des forces ----\n\n");
    printf("NOM : %s\n",t[i].nom);
    printf("FORCES : ");
    for (j = 0 ; j < 3 ; j++){
        printf("%f ",t[i].f[j]);
    }
    printf("\n");
}

void ResolForce2Torseurs(torseur *t){ //Cas simple

    int k = 0, i = 0;

    for (i = 0 ; i < 3 ; i++){
       if (t[k].f[i] == -1){
            t[k].f[i] = -(t[k+1].f[i]);
        }

        else if (t[k+1].f[i] == -1)
            t[k+1].f[i] = -(t[k].f[i]);
    }

    AfficherForces(t, 0);
    AfficherForces(t, 1);
}

void ResolForce3Torseurs(torseur *t){ //Cas " tors 1 inc

//test t[k+1].f.x == -2 && t[k+2].f.x != -2)

    int k = 0, i = 0;

    for (i = 0 ; i < 3 ; i++){
        if (t[k].f[i] == -1){

            t[k].f[i] = -(t[k+1].f[i] + t[k+2].f[i]);
        }

        else
            if (t[k+1].f[i] == -1)

                t[k+1].f[i] = -(t[k].f[i] + t[k+2].f[i]);

        else
            t[k+2].f[i] = -(t[k].f[i] + t[k+1].f[i]);
    }

    AfficherForces(t, 0);
    AfficherForces(t, 1);
    AfficherForces(t, 2);
}


void AfficherMoments(torseur* t, int i){
    int j;
    printf("\n\n---- Calcul des Moments en 0 ----\n\n");
    printf("NOM : %s\n",t[i].nom);
    printf("MOMENTS : ");
    for (j = 0 ; j < 3 ; j++){
        printf("%f ",t[i].m[j]);
    }
    printf("\n");
}

void babar(torseur *t, int origine){

	int k = 0, i = 0; 	// i=torseur k=x y z

  for (i = 0 ; i < 3 ; i++){
    for (k = 0 ; k < 3 ; k++){
      if(t[i].m[k] == -1)
        t[i].m[k] = 0;
    }
  }

	for (i = 0 ; i < 3 ; i++)
	{
    t[i].m[2] = t[i].m[2]+(t[i].c[0]*t[i].f[1])-(t[i].c[1]*t[i].f[0]);
		t[i].m[0] = t[i].m[0]+(t[i].c[1]*t[i].f[2])-(t[i].c[2]*t[i].f[1]);
		t[i].m[1] = t[i].m[1]+(t[i].c[2]*t[i].f[0])-(t[i].c[0]*t[i].f[2]);
	}

  for (i = 0 ; i <3 ; i++){
    if (i != origine){
      t[i].m[2] = -t[origine].m[2] - t[i].m[2];
  		t[i].m[0] = -t[origine].m[0] - t[i].m[0];
  		t[i].m[1] = -t[origine].m[1] - t[i].m[1];

    }
  }

	printf("\n");

  AfficherMoments(t,0);
	AfficherMoments(t,1); // AfficherMoments(t,2);marche pas pour 3 torseurs
  AfficherMoments(t,2);
  
}

void AfficherlesTorseurs(torseur *t, int i){

  printf("\n\n----Torseur %s----\n\n",t[i].nom);
  printf("COORD : %lf et %lf\n",t[i].c[0], t[i].c[1]);
  printf("||%lf | %lf||\n",t[i].f[0], t[i].m[0]);
  printf("||%lf | %lf||\n",t[i].f[1], t[i].m[1]);
  printf("||%lf | %lf||\n",t[i].f[2], t[i].m[2]);

}

void affichercourbe(torseur *t){

  int i,limite = 20;
  double x[157], y[157];
  gnuplot_ctrl *h;
  h = gnuplot_init();

  gnuplot_setstyle(h, "lines");

  for (i = 0 ; i < limite ; i++){

    x[i] = (double)i;
    y[i] = (double)i + 5;

  }
  gnuplot_plot_xy(h, x, y, limite, "TEST :)");
  sleep(2);

  return;
}
