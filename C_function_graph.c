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
int izracunaj_izraz(char* izraz){
    int rezultat=0;
    int broj=0;
    while(*izraz !=0){

        if(strncmp(izraz,"-",1)==0){
            broj=atoi(izraz);
            rezultat+=broj;
            izraz+=velicina_broja(broj)+1;

        }
        else if(strncmp(izraz,"+",1)==0){
            broj=atoi(izraz+1);
            rezultat+=broj;
            izraz+=velicina_broja(broj)+1;

        }
        else {
            broj=atoi(izraz);
            rezultat+=broj;
            izraz+=velicina_broja(broj);

        }

    }

    return rezultat;

}
void resi_izraz(char* izraz,int vrednost){
    int v;
    int v2;
    int v3;
    int broj=0;
    int broj2=0;
    int broj3=0;

    char* temp =izraz;
    printf("Usao je u resi_izraz\n");
   while(*izraz !=0){
         printf("while u resi izraz\n");
        //resavanje x
        if(*izraz =='x'){
            izraz--;
             while(*izraz>='0' && *izraz<='9'){
                    if(izraz==temp)break;
                izraz--;
             }

             broj3=atoi(izraz);
             izbrisi_karaktere(izraz,velicina_broja(broj3)+1);//+1 za x
             dodaj_mesto(izraz,velicina_broja(broj3*vrednost));
             dodaj_broj(izraz+velicina_broja(broj3*vrednost)-1,broj3*vrednost);
            izraz+=velicina_broja(broj3*vrednost);
        }


        // mnozenje
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

        }


    izraz++;
   }
    printf("izasao je i treba da printa rezultat\n");
    izraz=temp;
    printf("Sredjen izraz: %s\n",izraz);
    printf("Resenje: %d\n",izracunaj_izraz(izraz));
}
// primer 2x+2*4+3*5

int main(){
    printf("Unesi funkciju tipa 2x+4*3+2\n");
    char izraz[128];
    fgets(izraz,128,stdin);
    izraz[strlen(izraz)-1]=0;

    //ovo ne radi



    //ovo radi
        resi_izraz(izraz,5);





   //resi_izraz(izraz,2);



}
