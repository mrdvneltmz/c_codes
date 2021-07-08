#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>
//Dizi olusturduk
int uzunluk=0,a=1;
 
int Dizi[100][100];
//Ziyaret edilip edilmedi�ini tutaca��m�z dizi
bool gidildi[100];
int d[100],f[100];




void DepthFirst(int kok, bool gidildi[])   //Depth First Search Algoritmas�
{
    int i;
    //Se�ilen k�k gidildi olarak i�aretleniyor
    gidildi[kok] = true;
    printf(" %d >", kok);
 	d[a-1]=a;
 	a++;
    for( i = 0; i<uzunluk; i++)
    {
    
    
        if(Dizi[kok][i] == 1 && gidildi[i] == false)	//E�er d���m ziyaret edilmediyse her d���m�n kom�usunu yeni ba�lang�� noktas�ym�� gibi tekrar �a��r�yoruz
        {												
           DepthFirst(i, gidildi);
        }
    }
    f[a-1]=a;
    a++;
    printf(" <-- %d", kok);			//Dal bitmi� ise geri d�nd���n� g�stermek i�in << yazd�r�l�yor.
    
}
int dugumDerece(int dugum){				// D���m derecesini bulmak i�in kullan�lan fonksiyon
 	int sayac=0;
 	for(int i=0;i<uzunluk;i++){
 		if(Dizi[dugum][i]==1)
 		sayac++;
	 }
	 return sayac;
 }
 void Yaz(){
 
	printf("\n Isleme Sirasi--> ");
	for(int i=0;i<a;i++)//i�leme s�ras�
	{
		printf("%d - ",f[i]);
		
	} 
	printf("\n Ulasma Sirasi--> ");
	for(int i=0;i<a;i++){
		printf("%d - ",d[i]);
	}
 }
 
 int toplamkenar(){
 		int toplamkenar=0;
	 for(int i=0;i<uzunluk;i++){
 		toplamkenar+=dugumDerece(i);
	 }
 	return toplamkenar;
 	
 }

void matrisOlustur()	//Dosya okunup matris olu�turuluyor
{
    int okunan;
    FILE *fp = fopen("dfsMatrix.txt", "r");
 
    for(int i=0; !feof(fp);i++){	
    fscanf(fp,"%d",&okunan);
    uzunluk++;
	}
	uzunluk=pow(uzunluk,0.5);
	
	fseek(fp,0,0); //Cursor ba�a al�n�yor
	for(int i=0;i<uzunluk;i++){
		for(int a=0;a<uzunluk;a++){
			fscanf(fp,"%d",&Dizi[i][a]);
		printf("%d ",Dizi[i][a]);	//Dosyadan okunan matris ekrana yazd�r�l�yor
		}
		printf("\n");
	
		
	}

}




int main()
{
 	int kok;
    matrisOlustur();
    printf("\n\n");
    printf("Secilen kok:");
    scanf("%d",&kok);
	DepthFirst(kok, gidildi);
	printf("\n\n");
	printf("\nDerecesini istenilen dugum : ");
	scanf("%d",&kok);
	printf("Dugumun derecesi : %d",dugumDerece(kok));
	printf("\n\n");
	printf("\nToplam Kenar Sayisi : %d \n",toplamkenar());
	printf("\n\n");
	Yaz();
	printf("\n\n");

    return 0;

}



