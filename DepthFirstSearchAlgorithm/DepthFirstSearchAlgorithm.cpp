#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>
//Dizi olusturduk
int uzunluk=0,a=1;
 
int Dizi[100][100];
//Ziyaret edilip edilmediðini tutacaðýmýz dizi
bool gidildi[100];
int d[100],f[100];




void DepthFirst(int kok, bool gidildi[])   //Depth First Search Algoritmasý
{
    int i;
    //Seçilen kök gidildi olarak iþaretleniyor
    gidildi[kok] = true;
    printf(" %d >", kok);
 	d[a-1]=a;
 	a++;
    for( i = 0; i<uzunluk; i++)
    {
    
    
        if(Dizi[kok][i] == 1 && gidildi[i] == false)	//Eðer düðüm ziyaret edilmediyse her düðümün komþusunu yeni baþlangýç noktasýymýþ gibi tekrar çaðýrýyoruz
        {												
           DepthFirst(i, gidildi);
        }
    }
    f[a-1]=a;
    a++;
    printf(" <-- %d", kok);			//Dal bitmiþ ise geri döndüðünü göstermek için << yazdýrýlýyor.
    
}
int dugumDerece(int dugum){				// Düðüm derecesini bulmak için kullanýlan fonksiyon
 	int sayac=0;
 	for(int i=0;i<uzunluk;i++){
 		if(Dizi[dugum][i]==1)
 		sayac++;
	 }
	 return sayac;
 }
 void Yaz(){
 
	printf("\n Isleme Sirasi--> ");
	for(int i=0;i<a;i++)//iþleme sýrasý
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

void matrisOlustur()	//Dosya okunup matris oluþturuluyor
{
    int okunan;
    FILE *fp = fopen("dfsMatrix.txt", "r");
 
    for(int i=0; !feof(fp);i++){	
    fscanf(fp,"%d",&okunan);
    uzunluk++;
	}
	uzunluk=pow(uzunluk,0.5);
	
	fseek(fp,0,0); //Cursor baþa alýnýyor
	for(int i=0;i<uzunluk;i++){
		for(int a=0;a<uzunluk;a++){
			fscanf(fp,"%d",&Dizi[i][a]);
		printf("%d ",Dizi[i][a]);	//Dosyadan okunan matris ekrana yazdýrýlýyor
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



