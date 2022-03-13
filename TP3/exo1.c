#include<stdio.h>
#include<limits.h>
void swap (int *p, int *q){
    int x=*p;
    *p=*q;
    *q=x;

}
int main(){
    
    int x, y;
    x = 5;
    y = 6;
printf ("(avant) x : %d, y :  %d\n", x, y);

swap (&x, &y);
printf ("(apres) x : %d, y :  %d\n", x, y);
int t[] = {2,4};
swap(&t[0],&t[1]);
printf("t[0]=%d\n",t[0]);
printf("t[1]=%d\n",t[1]);

    return 0;
}