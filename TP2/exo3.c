#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
struct fraction{
long int num;
long int den;
};
typedef struct fraction fraction;
fraction build(long int n,long int d){
    fraction mafraction ;
    assert(d!=0);
    mafraction.den=d;
    mafraction.num=n;
    return mafraction;
}
int eq_fraction(fraction f,fraction g){
    if(f.num*g.den==f.den*g.num){
        return 1;
    }
    return 0;
}
int is_int(fraction f){
    if(f.num%f.den==0){
        return 1;
    }
    return 0;
}
fraction sum(fraction f,fraction g){
     fraction tmp;
    if(f.den==g.den){
        tmp.num=f.num+g.num;
        tmp.den=f.den;
    }else{
        tmp.num=(f.num*g.den + g.num*f.den);
        tmp.den=f.den*g.den;
    }
    return tmp;
}
fraction sub(fraction f,fraction g){
    fraction tmp;
    if(f.den==g.den){
        tmp.num=f.num-g.num;
        tmp.den=f.den;
    }else{
        tmp.num=(f.num*g.den - g.num*f.den);
        tmp.den=f.den*g.den;
    }
    return tmp;
}
fraction mul(fraction f,fraction g){
    fraction mul;
    mul.num=f.num*g.num;
    mul.den=f.den*g.den;
    return mul;
}
long pgcd(long a,long b){
    long x=a;
    long y=b;
    while(y!=0){
        int r=x%y;
        x=y;
        y=x;
    }
    return x;

}
fraction reduce(fraction f){

}

int main(int argc, char const *argv[])
{
    printf("%d",pgcd(4,2));
   
   // fraction ex_fractions[]={ build(1,1),build(1,2),build(2,4),build(-9,3),build(8,-20),build(-5,-1),build(1,-3)};
    return 0;
}
