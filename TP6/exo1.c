#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
char * dupliquer(const char *s){
    char *p=malloc(sizeof(char));
    if(p!=NULL){
        memmove(&p,&s,strlen(s));
    }
    return p;
}
int ordrealpha(const char*s1,const char * s2){
    int n1=strlen(s1);
    int n2=strlen(s2);
    if(n1<n2){
         
        for(int i=0;i<n1;i++){
            char s= toupper(s1[i]);
            char t = toupper(s2[i]);
           if(s>t){
               return 1;
           }else if(s<t){
              
               return -1;
           }
        }
        
    }else if(n1>n2){
    
            for(int i=0;i<n2;i++){
                char s= toupper(s1[i]);
                char t = toupper(s2[i]);
                 if(s>t){
                   
                    return 1;
                }else if (s<t){
                  
                    return -1;
                }
            }
       
    }else{
    
        for(int i=0;i<n2;i++){
            char s= toupper(s1[i]);
            char t = toupper(s2[i]);
            if(s>t){
            
                return 1;
            }else if(s<t){
               
                return -1;
            }
        }
        
        return 0;

    }
    
    return 0;
}
char * multiplier(const char *s,unsigned int n){
    
    int x=strlen(s);
    char * conc=malloc((n*x+1)*sizeof(char));
    int t=0;
    for(int i=0;i<n;i++){
        memmove(conc+t,s,x);
        t+=x;
    
    }
    conc[t]='\0';
    return conc;
   
}


int main(int argc, char const *argv[])
{
    if(argc>=3){
        //int x =ordrealpha(argv[1],argv[2]);
        char *s=multiplier(argv[1],argc);
        printf("%s\n",s);
        //exit(1);
    }
   
 /*   char * p ="hello";
     char * t ="hello";
  char *s=dupliquer(p);
  printf("s=%s\n",s);
  printf("p=%s\n",p);
  int x=ordrealpha(t,p);
  printf("ordre = %d\n",x);
  char * f = multiplier(t,5);
  printf("%s\n",f);*/

}
