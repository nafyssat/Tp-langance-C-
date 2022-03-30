/** 
 * fichier contenant les definitions des fonctions données dans polynomes.h 
 * **/
 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

#include"polynomes.h"
polynome* creer_polynome_vide(){
	polynome *p=malloc(sizeof(polynome));
	if(p==NULL){return NULL;}
	p->suiv=NULL;
	p->coef=0;
	p->degre=-1;
	return p;
	
}
polynome* creer_monome(double c, int d){
	polynome *p=malloc(sizeof(polynome));
	if(p==NULL){return NULL;}
	p->suiv=NULL;
	p->coef=c;
	p->degre=d;
	return p;
}
void annuler(polynome* p){
	polynome *tmp=p;
	if(p->suiv->suiv==NULL){
		free(p->suiv);
		p->suiv=NULL;
		tmp=p;

	}
	tmp=tmp->suiv;
	annuler(tmp);
}
double evaluer_polynome(polynome* p,double x){
	int y =0;
	y=p->coef*pow(x,p->degre);
	if(p->suiv!=NULL){
		y+=evaluer_polynome(p->suiv,x);
	}
	return y;
}
void afficher_polynome(polynome* p){
	if(p->coef>=0){
		printf("+%lfX^%d",p->coef,p->degre);
	}else{
		printf("%lfX^%d",p->coef,p->degre);
	}
	if(p->suiv!=NULL){
	
		afficher_polynome(p->suiv);
	}
	//printf("%d",'\n');
}
void ajouter_monome (polynome* p , double c, int d){
	polynome *q=creer_monome(c,d);
	
	if(p->suiv==NULL){
		p->suiv=q;
		return;
	}
	
	if(p->suiv->degre>q->degre){
		
		ajouter_monome(p->suiv,c,d);
		
	}

	else if(p->suiv->degre < q->degre){
		
		
		q->suiv=p->suiv;
		p->suiv=q;
		
		
		return ;
	}else if(p->suiv->degre == q->degre){
		p->suiv->coef+=q->coef;
		if(p->suiv->coef==0){
			p->suiv=p->suiv->suiv;
		}
		
	}
}
polynome* copie(polynome* p){
	
	polynome *q=creer_polynome_vide();
	polynome *tmp=p->suiv;
	

	while(tmp!=NULL){
		ajouter_monome(q,tmp->coef,tmp->degre);
		
		tmp=tmp->suiv;
		}
		return q;
	
}
polynome* somme(polynome* p1, polynome* p2){
	polynome *p=creer_polynome_vide();
	polynome *tmp=p1->suiv;
	while(tmp!=NULL){
		ajouter_monome(p,tmp->coef,tmp->degre);
		tmp=tmp->suiv;
	}
	tmp=p2->suiv;
	while(tmp!=NULL){
		ajouter_monome(p,tmp->coef,tmp->degre);
		tmp=tmp->suiv;
	}
	return p;

}
polynome* soustraction(polynome* p1, polynome* p2){
	polynome* tmp=p1->suiv;
	polynome *tmp1=p2->suiv;
	while(tmp1!=NULL){
		if(tmp->degre==tmp1->degre){
			tmp->coef-=tmp1->coef;
			tmp=tmp->suiv;
			tmp1=tmp1->suiv;
		}else if (tmp->degre>tmp1->degre){
			if(tmp->suiv!=NULL){
				tmp=tmp->suiv;
			}else{
				ajouter_monome(tmp,tmp1->coef,tmp1->degre);
				tmp1=tmp1->suiv;
			}
			
		}
		else{
			ajouter_monome(tmp,tmp1->coef,tmp1->degre);
			tmp=tmp->suiv;
			tmp1=tmp1->suiv;

		}
	}
	
	return p1;

}
polynome* produit(polynome* p1 ,polynome* p2){
	polynome *q=creer_polynome_vide();
	polynome *tmp=p1->suiv;
	polynome *tmp1=p2->suiv;
	while(tmp!=NULL){
		while(tmp1!=NULL){
			ajouter_monome(q,tmp->coef*tmp1->coef,tmp->degre+tmp1->degre);
			tmp1=tmp1->suiv;
		}
		tmp=tmp->suiv;
		tmp1=p2->suiv;
	}
	return q;
}
polynome* puissance(polynome* p, int n){
	polynome *tmp=p;
	for(int i=1;i<n;i++){
		p=produit(p,tmp);
	}
	return p;
}
polynome* derive(polynome* p){
	polynome *derive=creer_polynome_vide();
	polynome *tmp=p->suiv;
	while(tmp!=NULL){
		int n=tmp->degre-1;
		if(n<0){
			tmp=tmp->suiv;
		}else{
			ajouter_monome(derive,tmp->coef,n);
			tmp=tmp->suiv;
		}
		

	}
	return derive;
}
polynome* composition(polynome* p1,polynome *p2){
polynome* p=creer_polynome_vide();
polynome *tmp=p1->suiv;
while(tmp!=NULL){
	
	if(tmp->degre!=0){
		ajouter_monome(p,puissance(p2,tmp->degre)->coef,puissance(p2,tmp->degre)->coef);
	}}

}
double evaluer_Horner(polynome *p,double x){
	polynome *tmp=p->suiv;
	double t=tmp->coef;
	while(tmp!=NULL){
		if(tmp->suiv==NULL){
			
			t=t*x;
			break;
		}else{
			tmp=tmp->suiv;
			t=t*x+tmp->coef;
		
		}
	}
	return t;
}


void test(){	
	polynome* p = creer_polynome_vide();
	ajouter_monome (p,1,2);
	ajouter_monome (p,6,6);
	ajouter_monome (p,-6,6);
	ajouter_monome (p,3,3);
	ajouter_monome (p,-1,0);
	printf("\n---------\n p :");
	afficher_polynome(p);

	
	
	
	
	polynome* q = creer_polynome_vide();
	ajouter_monome (q,-1,2);
	ajouter_monome (q,3,1);
	printf("\n---------\n Q =");
	afficher_polynome(q);
	
	printf("\n---------\n Q(34) = %f ",evaluer_Horner(q,34));
	printf("\n---------\n Q(34) = %f (methode de Horner) ",evaluer_polynome(q,34));
	
	printf("\n---------\n");
	polynome* r=somme(p,q);
	printf("P+Q =");
	afficher_polynome(r);
	
	printf("\n---------\n");
	polynome* rc = copie(r);
	printf("copie P+Q =");
	afficher_polynome(rc);
	
	printf("\n---------\n");
	polynome* pp = produit(p,p);
	printf("P*P =");
	afficher_polynome(pp);
		
	printf("\n---------\n");
	polynome* p2 = puissance(p,3);
	printf("P^3 =");
	afficher_polynome(p2);	


	printf("\n---------\n");
	polynome* dq = derive(q);
	printf("Q'=");
	afficher_polynome(dq);
	
	/*printf("\n---------\n");
	polynome* comp = composition(q,p);
	printf("q rond p=");
	afficher_polynome(comp);
	
		
	printf("\n---------\n end\n");*/
	
}




int main(void){
	test();
	return 0;
}

