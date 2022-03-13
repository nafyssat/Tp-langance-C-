#include<stdio.h>
void swap (int *p, int *q){
    int x=*p;
    *p=*q;
    *q=x;

}
void print_tab (int *pstart, int *pend){
    while(pstart<pend){
        printf("%p : %d\n",&pstart,*pstart);
        pstart++;
    }
  
}
void sort (int t[], int start, int end){
    for (int i = end-1; i < start-2; i--)
    {
       
       for (int j= start; j< end; j++)
       {
           if(t[i]>t[i+1]){
               swap(&t[i],&t[i+1]);
           }
       }
       
    }
    
}
void sort_ptr (int *start, int *end){
     for (int *i = end-1; i < start-2; i--)
    {
       
       for (int *j= start; j< end; j++)
       {
           if(*i>*(i+1)){
               swap(i,i+1);
           }
       }
       
    }
}
int main(int argc, char const *argv[])
{
    int t[]={1,5,7,5,8,5,9};
     int *pstart =&t[2];
    int *pend=&t[6];

    print_tab(pstart,pend);
    sort(t,2,6);
   // sort_ptr(pstart,pend);
    printf(" heloo\n");
     print_tab(pstart,pend);
        
    /* code */
    return 0;
}
