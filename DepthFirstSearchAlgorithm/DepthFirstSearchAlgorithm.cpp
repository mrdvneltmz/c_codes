#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>
//Dizi olusturduk
int uzunluk=0,a=1;
int dugumSayisi; 
int Dizi[100][100];
//Ziyaret edilip edilmediðini yazdýðýmýz dizi
bool ulasilan[100];
int d[100],f[100];



void DFS(int kok, bool ulasilan[])   //Rekürsif DFS kodu
{
    int i;
    //Seçilen kök ulaþýldý olarak iþaretleniyor
    ulasilan[kok] = true;
    printf(" %d >", kok);
 	d[a-1]=a;
 	a++;
    for( i = 0; i<uzunluk; i++)
    {
    
    
        if(Dizi[kok][i] == 1 && ulasilan[i] == false)	//Eðer düðüm ziyaret edilmediyse her düðümün komþusunu yeni baþlangýç noktasýymýþ gibi tekrar çaðýrýyoruz
        {												
            DFS(i, ulasilan);
        }
    }
    f[a-1]=a;
    a++;
    printf(" << %d", kok);			//Dal bitmiþ ise geri döndüðünü göstermek için << yazdýrýlýyor.
    
}
int dugumDerecesi(int dugum){				// Düðüm derecesini bulmak için kullanýlan fonksiyon
 	int sayac=0;
 	for(int i=0;i<uzunluk;i++){
 		if(Dizi[dugum][i]==1)
 		sayac++;
	 }
	 return sayac;
 }
 void ekranaYaz(){
 
	printf("\n Isleme Zamani : ");
	for(int i=0;i<a;i++)//iþleme sýrasý
	{
		printf("%d - ",f[i]);
		
	} 
	printf("\n*******************************\n");
	printf("\n Ulasma Zamani : ");
	for(int i=0;i<a;i++){
		printf("%d - ",d[i]);
	}
	printf("\n*******************************\n");
 }
 
 int kenarSayisi(){
 		int kenarSayisi=0;
	 for(int i=0;i<uzunluk;i++){
 		kenarSayisi+=dugumDerecesi(i);
	 }
 	return kenarSayisi;
 	
 }

void dosyadanMatris()	//Dosya okunup matris oluþturuluyor
{
    int okunan;
    FILE *fp = fopen("dfsMatrix.txt", "r");
 
    for(int i=0; !feof(fp);i++){	
    fscanf(fp,"%d",&okunan);
    uzunluk++;
	}
	uzunluk=pow(uzunluk,0.5);
	dugumSayisi=uzunluk;
	
	fseek(fp,0,SEEK_SET); //Cursor baþa alýndý.
	for(int i=0;i<uzunluk;i++){
		for(int a=0;a<uzunluk;a++){
			fscanf(fp,"%d",&Dizi[i][a]);
		printf("%d ",Dizi[i][a]);	//Dosyadan okunan matris ekrana yazdýrýlýyor
		}
		printf("\n");
		
	}
	printf("\n*******************************\n");
}

void completeGraph(int dugumSayisi,int kenarSayisi){
	if(kenarSayisi==(dugumSayisi*(dugumSayisi-1))/2)
		printf("\n Tam Graftir");
	else{
		printf("\n Tam Graf Degildir");
	}
	printf("\n*******************************\n");	
}


int main()
{
 	int kok;
    dosyadanMatris();
    printf("Lutfen kok seciniz:");
    scanf("%d",&kok);
    printf("\n*******************************\n");
   	printf("Depth First Search Algoritmasi\n");
	DFS(kok, ulasilan);
	printf("\n*******************************\n");
	printf("\nDerecesini yazdirmak istediginiz dugumu seciniz : ");
	scanf("%d",&kok);
	printf("Sectiginiz dugumun derecesi : %d",dugumDerecesi(kok));
	printf("\n*******************************\n");
	printf("\nKenar Sayisi : %d \n",kenarSayisi());
	printf("\n*******************************\n");
	completeGraph(dugumSayisi,kenarSayisi());
	ekranaYaz();

    return 0;

}



