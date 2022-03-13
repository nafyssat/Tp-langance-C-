#include<stdio.h>

int occ (int nbr, int t[], int v){
    for (int i = 0; i < nbr; i++)
    {
       if(t[i]==v){
           return i;
       }
    }
    return -1;
    
}
int *occ_ptr (int nbr, int t[], int v){
    int x=occ(nbr,t,v);
    if(x!=-1){
        return &x;
    }
    return NULL;
}
int main(int argc, char const *argv[])
{
    int tab[]={2,5,8,4,2};
    printf("%d\n",occ(5,tab,8));
    /* code */
    return 0;
}
