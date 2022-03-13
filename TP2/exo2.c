#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define NBC 10

enum etat {VALIDEE, ENCOURS, EXPEDIEE};
typedef enum etat etat;
struct commande {
int num_com;
int prix_exp;
int prix_prod;
etat etat_com;};
typedef struct commande commande;

commande com_alea(int num){
    struct commande maCommande;
    maCommande.num_com=num;
    maCommande.prix_exp=rand()%20;
    maCommande.prix_prod=rand()%2000;
    maCommande.etat_com=rand()%4;
    return maCommande;
}
void affiche_com(commande c){
    printf("num=%d\n",c.num_com);
    printf("prix-exp=%d\n",c.prix_exp);
    printf("prix_prod=%d\n",c.prix_prod);

    int ic =c.etat_com;
    switch( ic ){
    case VALIDEE:
        printf("VALIDEE\n");
        break;
    case ENCOURS:
       printf("ENCOURS\n");
        break;
    case EXPEDIEE:
      printf("EXPEDIEE/n");
        break;
    }
}
void affiche_exp(commande t[],int taille){
    for(int i=0;i<taille;i++){
        if(t[i].etat_com==ENCOURS){
            affiche_com(t[i]);
        }
    }
}
int nbr_en_cours(commande t[],int taille){
    int x=0;
    for(int i=0;i<taille;i++){
        if(t[i].etat_com==ENCOURS){
            x+=1;
        }
    }
    return x;
}
int cout_validees(commande t[],int taille){
    int x=0;
    for(int i=0;i<taille;i++){
        if(t[i].etat_com==VALIDEE){
          x+=t[i].prix_exp;
        }
    }
    return x;
}
int main(int argc, char const *argv[])
{
    srand(time(NULL));

    /**
     * @brief tableau de NBC commandes
     * 
     */
    commande t[NBC];
    for (int i = 0; i < NBC; i++)
    {
        t[i]=com_alea(i);
    }
    affiche_exp(t,NBC);
    printf("nbr_encours=%d\n",nbr_en_cours(t,NBC));
    printf("prix_exp=%d\n",cout_validees(t,NBC));
    
    
   


      
}
