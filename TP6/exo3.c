#include <stdio.h>
#include <string.h>
typedef struct{
    size_t indice;
    size_t len;
}mutation;

int nboc(const char *s,const char *sub){
    int n=0;
    
    size_t n1=strlen(sub);
    size_t n2=strlen(s);
    for(size_t i =0;i<n2;i++){
        int x=i;
        printf("i=%ld\n",i);
       for(size_t j=0;j<n1;j++){
           
           
            printf("j=%ld\n",j);
            printf("x=%d\n",x);
           if(s[x]!=sub[j]){
                printf("%d\n",32);
                x=i+1;
               break;
           }else{
                printf("n2=%ld\n",n1);

              
               if(j==n1-1){
                    printf("%d\n",34);
                     n+=1;
                   printf("n=%d\n",n);
               }
              
           }
           x+=1;
           
        }
       
        
    }

    return n;
}
mutation diff(const char *s,const char *t){
    return NULL;
}
/*mutation longest(const char *s, const char *t){
    return NULL;
}
char *longest_string(const char *s, const char *t){
    return NULL;
}*/
int main(int argc, char const *argv[])
{
   char * p="sos";
   char *q="sossosos";
   printf("nbocc = %d\n",nboc(q,p));

    return 0;
}
