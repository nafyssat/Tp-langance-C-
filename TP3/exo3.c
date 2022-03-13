#include<stdio.h>
    int nbr_occ (int nbr, int t[], int v){
        int x=0;
        for (int i = 0; i < nbr; i++) {
            if(t[i]==v){
                 x+=1;
           }
        }
     return x;
    
    }
    void nbr_occ_op (int nbr, int t[], int v, int *pnv){
        for (int i = 0; i < nbr; i++){
            if(&t[i]==pnv){
                t[i]=nbr_occ(nbr,t,v);
            }
        }
            
            
    }
    void min_max_op (int nbr, int t[], int *pmin, int *pmax){
        int min=t[0];
        int max=t[0];
        for (int i = 0; i < nbr; i++){
            if(t[i]>=max){
                max=t[i];
            }
            if(t[i]<=min){
                min=t[i];
            }
        }
        *pmax=max;
        *pmin=min;
      
          
        
    }
    int main(int argc, char const *argv[])
    {
        int t[]={1,5,2,5,2,5,9};
        
        // printf("nombreDOccurence :%d\n",nbr_occ(7,t,5));
        // nbr_occ_op(7,t,5,&t[0]);
        // printf("%d\n",t[0]);
        int pmax ,pmin;
        min_max_op(7,t,&pmin,&pmax);
        printf("min =%d\n",pmin);
        printf("max=%d\n",pmax);

        return 0;
    }
