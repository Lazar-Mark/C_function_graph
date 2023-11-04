#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int velicina_broja(int n){
    int brojac=0;
    if(n<0)n=-n;
    if(n==0)return 1;
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

   while(*izraz !=0){

        //resavanje x
        if(*izraz =='x'){
            if(izraz!=temp){
                izraz--;
                 while(*izraz>='0' && *izraz<='9'){
                        if(izraz==temp)break;
                    izraz--;
                 }

            }
            if(*izraz=='-')izraz++;
             //ako je pointer na x samo uzima vrednost
             if(*izraz=='x'){
                broj3=1;
                izbrisi_karaktere(izraz,velicina_broja(broj3));//+1 za x
                dodaj_mesto(izraz,velicina_broja(broj3*vrednost));
                dodaj_broj(izraz,broj3*vrednost);

             }

            else{

            broj3=atoi(izraz);
            izbrisi_karaktere(izraz,velicina_broja(broj3)+1); //+1 za x
            dodaj_mesto(izraz,velicina_broja(broj3*vrednost));
            dodaj_broj(izraz,broj3*vrednost);

            }



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

    izraz=temp;
    printf("Sredjen izraz: %s\n",izraz);
    printf("Resenje: %d\n",izracunaj_izraz(izraz));
}
// primer 2x+2*2-1
void ispisi_sistem(int n,int* x,int* y){

     for(int i=0;i<n;i++){

         for(int j=0;j<n;j++){

        if(i==(n/2  - *(y+j)) && j==(*(x+j) + n/2   )){ // greska?
           // printf("Usao sam");
           printf(".");
           //printf("%d", *(x+j));

        }
        else if(j==n/2)printf("%c",186);
        else if(i==n/2)printf("%c",205);

        else printf(" ");
        }


        printf("\n");

    }

}
int main(){
   //uzimam izraz
    printf("Unesi funkciju tipa 2x+4*3+2\n");
    char izraz[128];
    fgets(izraz,128,stdin);
    izraz[strlen(izraz)-1]=0;
    //pravim backup izraza
    char izraz1[128];
    strcpy(izraz1, izraz);
    //pravim niz resenja
    int y[1024];
    int x[1024];
    //kretanje kroz niz i ubacivanje resenja i x promenljive
    int brojac=0;
    int broj_vrednosti = 30;

   // resi_izraz(izraz,2);

    for(int i=0;i<broj_vrednosti;i++){
    resi_izraz(izraz,i);
    y[brojac]=izracunaj_izraz(izraz);
    x[brojac]=i - broj_vrednosti / 2; // da opseg od npr 30 ide od -15 do 14 da bi se na grafiku printovalo skroz od levo do skroz desno
    strcpy(izraz, izraz1);
    brojac++;

    }

    ispisi_sistem(broj_vrednosti,x,y);

//getchar();



}
