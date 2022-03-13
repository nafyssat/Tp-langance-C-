#include<stdio.h>
/*void print_tab (int t[], int start, int end){
    for(int i=start;i<end;i++){
        printf("%p : %d \n",&t[i],t[i]);
    }
 
}*/
void print_tab (int *pstart, int *pend){
    while(pstart<pend){
        printf("%p : %d\n",&pstart,*pstart);
        pstart++;
    }
  
}
int main(int argc, char const *argv[])
{    int t[]={1,5,2,8,2,5,9};
    int *pstart =&t[2];
    int *pend=&t[6];
    print_tab(pstart,pend);
    /* code */
    return 0;
}
