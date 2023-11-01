#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int velicina_broja(int n){
    int brojac=0;
    if(n<0)n=-n;
    while(1){
            if(n<=0)
            break;
    n/=10;
    brojac++;
    }


    return brojac;
}
//popraviti sto upisuje 42 umesto 24 invertuje
void dodaj_broj(char* izraz,int broj){
    if(broj<=0)broj=-broj;
    while(1){

        *izraz=broj%10+'0';
        izraz--;

        if(broj/10<=0)break;
        broj/=10;
    }
}
void izbrisi_karaktere(char* izraz,int brojac ){

    char* temp= izraz;
    for(int i=0;i<brojac;i++){


        while(1){

            if(*izraz == 0)
               break;

            *izraz=*(izraz+1);

            izraz++;
        }

         izraz = temp;
    }


}
void dodaj_mesto(char* izraz,int broj){


    char* temp= izraz;

    int provera=0;
    for(int i=0;i<broj;i++){
        izraz=temp;
        provera=0;
        while(1){
        if(*izraz ==0){
            while(1){
                *(izraz+1)=*izraz;
                if(izraz == temp)break;
                izraz--;
                provera=1;
                }
            }
        if(provera)break;
        izraz++;
        }
    }
}
void resi_izraz(char* izraz){
    int v;
    int broj=0;
    int v2;
    int broj2=0;

   while(*izraz !=0){

        if(*izraz=='*'){

        broj=atoi(izraz+1);
        v=velicina_broja(broj);

        izraz--;

            while(*izraz>='0' && *izraz<='9')
                izraz--;


        broj2=atoi(izraz+1);
        v2=velicina_broja(broj2);
        izbrisi_karaktere(izraz+1,v+v2+1); //+1 za *

        dodaj_mesto(izraz,velicina_broja(broj*broj2));
        dodaj_broj(izraz+velicina_broja(broj*broj2),broj*broj2);
        printf("Proizvod: %d\nVelicina broja: %d\n",broj2*broj,velicina_broja(broj*broj2));
        }


    izraz++;
   }

}
// primer 2+3*8+3*5
int main(){

    char izraz[128];
    fgets(izraz,128,stdin);

    izraz[strlen(izraz)-1]=0;

   // izbrisi_karaktere(izraz+2,3);
   resi_izraz(izraz);

   printf("%s",izraz);

}
