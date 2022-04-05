#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef struct node node;
struct node {
  int val;
  node *gauche;
  node *droite;
};

void print_head (int depth, int addr) {
    if (depth > 1) {
	int pre = addr / 2;
	print_head (depth - 1, pre);
	printf ("%s", (pre % 2) != (addr % 2) ? "|    " : "     ");
	return;
    }
    if (depth == 1)
	printf ("     ");
}

void pretty_rec (node *t, int depth, int addr) {
    if (t == NULL) {
	print_head (depth, addr);
	printf ("|----N\n");
	return;
    }
    pretty_rec (t -> droite, depth + 1, 2 * addr  + 1);
    print_head (depth, addr);
    char c =
	(depth == 0) ? '-' : '|';
    printf ("%c----%d\n", c, t -> val);
    pretty_rec (t -> gauche, depth + 1, 2 * addr);
}

// fonction principale d'affichage.
void pretty_print (node *t) {
    pretty_rec (t, 0, 0);
}
node *cons_tree(int val,node *tl,node *tr){
    node *p=malloc(sizeof(node));
    assert(p!=NULL);
    p->val=val;
    p->droite=tr;
    p->gauche=tl;
    return p;
}
void free_tree(node *t){
    if(t->gauche!=NULL){
        free_tree(t->gauche);
    }
    if(t->droite!=NULL){
        free_tree(t->droite);
    }
    free(t);
}
int size_tree(node *t){
    int x=0;
    int y=0;
     if(t->gauche!=NULL){
        x+=size_tree(t->gauche);
    }
    if(t->droite!=NULL){
        y+=size_tree(t->droite);
    }
    return 1+x+y;
}
int sum_tree(node *t){
    int x=t->val;
     if(t->gauche!=NULL){
        x+=sum_tree(t->gauche);
    }
    if(t->droite!=NULL){
        x+=sum_tree(t->droite);
    }
   return x;
}
int maxM(int a,int b){
    if(a<b){
        return b;
    }else{
        return a;
    }
}
int depth_tree(node *t){
    int x=0;
    int y=0;
     if(t->gauche!=NULL){
        x=1+depth_tree(t->gauche);
    }
    if(t->droite!=NULL){
        y=1+depth_tree(t->droite);
    }
   return maxM(x,y);
}
//arbr binaire
void print_abr(node *t){
    if(t->gauche!=NULL){
        print_abr(t->gauche);
    }
    printf("%d",t->val);
    if(t->droite!=NULL){
        print_abr(t->droite);
    }
  
}
node *insert_abr(node *t,int val){
    node *tmp=t;
    if(t==NULL){
        t=cons_tree(val,NULL,NULL);
        return t;
    }
    if(tmp->val>val){
        if(tmp->gauche!=NULL){
            
            insert_abr(tmp->gauche,val);
        }else{
            
            tmp->gauche= cons_tree(val,NULL,NULL);
            return t;
        }
    }
    if(tmp->val<val){
        if(tmp->droite!=NULL){
           
            insert_abr(tmp->droite,val);
        }else{
           
            tmp->droite= cons_tree(val,NULL,NULL);
            return t;
        }
      
    }
    return t;
    
}
node *search_abr(node *t,int val){
     node *tmp=t;
    if(t==NULL){
        return t;
    }
    if(tmp->val==val){
        return tmp;
    }
    if(tmp->val>val){
        if(tmp->gauche!=NULL){
           return search_abr(tmp->gauche,val);
        }else{
            return NULL;
        }
    }
    if(tmp->val<val){
        if(tmp->droite!=NULL){
           return search_abr(tmp->droite,val);
        }else{
           return NULL;
        }
    }
    return NULL;

}
node* max_abr(node *t){
     if(t==NULL){
        return t;
    }
    if(t->droite==NULL){
       return t;
    }
    return max_abr(t->droite);
}
node* min_abr(node *t){
    if(t==NULL){
        return t;
    }
    if(t->gauche==NULL){
       return t;
    }
    return min_abr(t->gauche);
}
int check_abr(node *t){
    node * tmp=t;
    int x=max_abr(tmp);
    int y=min_abr(tmp);
    if(x<tmp->val && y<tmp->val){
        return 1;
    }
    if(t==NULL){
        return 1;
    }
    int n=0;
    int z=0;
    if(tmp->gauche!=NULL){
       n=check_abr(tmp->gauche);

    }
    if(tmp->droite!=NULL){
       z=check_abr(tmp->droite);

    }
    
    
    return (t&&z);
}
node*abr_supprimer_racine( node*a ){
  node*c;
  
  if( a -> gauche == NULL ){
    c = a->droite;
    free( a );
    return c;
  }else if( a -> droite == NULL ){
    c = a ->gauche;
    free(a);
    return c;
  }
  
  node* parent_c;

 
  for( c = a -> gauche, parent_c = NULL ; c->droite != NULL; parent_c = c, c=c->droite )
    ; 
  if( parent_c == NULL ){ 
    c->droite = a->gauche;
    free( a );
    return c;
  }

  a->val = c->val; 
  parent_c -> droite = c->gauche; 
  free( c );
  return a;
}
node * abr_supprimer_valeur(node * a, int v){
  node * c = a;
  node * parent_c = NULL;
  while( c != NULL ){
    if(c->val < v){
      parent_c = c;
      c = c->droite;
    }
    else if(c->val > v){
      parent_c = c;
      c = c -> gauche;
    }
    else break;
  }

  if( c == NULL )
    return a; /* rien à supprimer */
  
  if( c -> val == v ){
    if( parent_c == NULL )
      return abr_supprimer_racine(c) ;
    else if( parent_c->gauche == c ){
      parent_c -> gauche = abr_supprimer_racine(c) ;
    } else if( parent_c -> droite == c ){
      parent_c -> droite = abr_supprimer_racine(c) ;
    }
  }

  return a;
}
void padding ( char ch, int n )
{
  int i;

  for ( i = 0; i < n; i++ )
    putchar ( ch );
}

void structure ( struct node *root, int level )
{
  int i;

  if ( root == NULL ) {
    padding ( '\t', level );
    puts ( "Null" );
  }
  else {
    structure ( root->droite, level + 1 );
  
    padding ( '\t', level );
    printf ( "%d\n", root->val );
    structure ( root->gauche, level + 1 );
  }
}











int main(int argc, char const *argv[])
{
    node *p;
    p = cons_tree (1, cons_tree (3, NULL, NULL),cons_tree (6, cons_tree (4, NULL, NULL), NULL));
    int x=depth_tree(p);
    printf("%d",x);
    //abr
    
    node *t=NULL;
    
    int vals[10] = {8, 3, 1, 2, 6, 4, 7, 10, 14, 13};
    for (int i = 0; i < 10; i++) {
       
        t = insert_abr (t, vals[i]);
    }
    print_abr(t);
      printf(" \n");
   /* node *p=search_abr(t,8);
    print_abr(p);*/
      printf(" \n");
    node *q=min_abr(t);
    print_abr(q);
    printf(" \n");
    
    printf("p= %d",check_abr(p));
    printf(" \n");
    printf("t= %d",check_abr(t));
    return 0;
}
