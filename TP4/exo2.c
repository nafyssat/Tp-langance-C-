#include <stdio.h>
#include <stdlib.h>
/*struct array
{
    int *ptr;
    unsigned int capacite;
    unsigned int taille;
};
typedef struct array array;
array* array_init(unsigned int cap){

    array *a =malloc(sizeof(array));
    if(a!=NULL){
        int *pt=malloc(cap*sizeof(int));
        if(pt!=NULL){


        a->ptr=pt;
        a->capacite=cap;
        a->taille=0;
        return a;
        }
    free(a);
    return NULL;
    }
   return NULL;
}

void array_destroy(array *t){

    free((t->ptr));
    free(t);
}
int array_get(array *t,unsigned int index){
    if(index <= t->taille){
        return (t->ptr);
    }
    return assert();

}
void array_set(array *t,unsigned int index,int valeur){
     if(index <= t->taille){
        t->ptr=valeur;
    }



}
void array_append(array*t, int val){
    if(t->capacite>0){
        t->taille+=1;
        t->ptr=val;
    }
}
*/


int main(int argc, char const *argv[])
{
    /* code */
    printf("%d",7);
    return 0;
}

