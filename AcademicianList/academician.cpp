#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct akademisyen
{ 	int sicilNo;
	char ad[30];
	char soyAd[30];
	int unvanID;
	int unvanYili;
	struct akademisyen *sonraki ;
} Akademisyenler;

		int gorevlisayisi;
		Akademisyenler * ilk=NULL, * son=NULL;
 		Akademisyenler * dosyadanOku(FILE *);
 		void ekle(Akademisyenler *);
 		void listele(Akademisyenler *);
		void elemanekle();
		Akademisyenler * gorevlendir(Akademisyenler *,int );
		void sil(int );
		
int main()
{ 	int secenek,sicilNo;
	
	FILE *dp=fopen("academician.txt","r");
	dosyadanOku(dp);
	fclose(dp);
	
	aa:
	printf("1.Listeleme\n2.Gorevlendirme\n3.Ekleme\n4.Silme\n\nYapmak istediginiz islemi seciniz : ");
	scanf("%d",&secenek);
	if(secenek>4 || secenek<1)
	{
		system("CLS");
		printf("\nHatali giris yaptiniz.\n");
		printf("\nMenu'ye donmek icin bir tusa basiniz.\n");
		getch();
		system("CLS");
		goto aa;
	}
	
	switch(secenek){
		case 1 :
		{
			system("CLS");
			listele(ilk);//ok
			printf("\nMenu'ye donmek icin bir tusa basiniz.\n");
			getch();
			system("CLS");
			goto aa;
		}
		case 2 :
		{	system("CLS");
			printf("\nGorevli sayisini giriniz : ");
			scanf("%d",&gorevlisayisi); 
			system("CLS");
			gorevlendir(ilk,gorevlisayisi);//ok
			printf("\nMenu'ye donmek icin bir tusa basiniz.\n");
			getch();
			system("CLS");
			goto aa;
		}
		
		case 3 :
		{	system("CLS");
			printf("\n Eklemek istediginiz elemanin sicilNo,ad,soyAd,unvanID ve unvanYilini giriniz.\n");
			elemanekle();//ok
			printf("\nMenu'ye donmek icin bir tusa basiniz.\n");
			getch();
			system("CLS");
			goto aa;
		}
		case 4 :
		{
			system("CLS");
			printf("\nSileceginiz elemanin sicil no :");
			scanf("%d",&sicilNo);
			sil(sicilNo);
			printf("\nMenu'ye donmek icin bir tusa basiniz.\n");
			getch();
			system("CLS");
			goto aa;
		}
	}
	getch();
	return 0;
}
void ekle(Akademisyenler *gelen)
{   
	bool eklendi = 0;
	Akademisyenler *gecici1=ilk,*gecici2;
	if(gelen->unvanID<1 ||gelen->unvanID>4)
	{
		system("CLS");
		printf("\nBoyle bir unvanID yok. Islem yapilamaz\n");
	}else
	{
	if(ilk==NULL)// hiç eleman yoksa
	{
		ilk=gelen;
		son=ilk;
	}else
	{
 	gecici2=gecici1->sonraki;
	}	
	while(eklendi == 0){
		if(gelen->unvanID < ilk->unvanID || (gelen->unvanID == ilk->unvanID && gelen->unvanYili <= ilk->unvanYili))// baþa ekle
		{
			gelen->sonraki=ilk;
			ilk=gelen;
			eklendi = 1;
		}else if(gelen->unvanID < gecici2->unvanID || (gelen->unvanID == gecici2->unvanID && gelen->unvanYili <= gecici2->unvanYili))
		{
			gelen->sonraki=gecici1->sonraki;
			gecici1->sonraki=gelen;
			eklendi = 1;				
		}else if(gelen->unvanID > son->unvanID || (gelen->unvanID == son->unvanID && gelen->unvanYili > son->unvanYili) )
		{
			son->sonraki = gelen;
			son = gelen;
			eklendi = 1;
		}
		if(eklendi == 0){
			gecici1 = gecici1->sonraki;
			gecici2 = gecici2->sonraki;
		}
	}
	son->sonraki=NULL;
	}
}
Akademisyenler * dosyadanOku(FILE *fp)
 {
	while(!feof(fp)){
 		Akademisyenler * kayit=(Akademisyenler *)malloc(sizeof(Akademisyenler));
	 	fscanf(fp,"%d %s %s %d %d",&kayit->sicilNo,kayit->ad,kayit->soyAd,&kayit->unvanID,&kayit->unvanYili);
		ekle(kayit);
	}
 }
void listele(Akademisyenler * bagliListe)
{
	while(bagliListe!=NULL)
	{
		printf("%d %s %s %d %d\n",bagliListe->sicilNo,bagliListe->ad,bagliListe->soyAd,bagliListe->unvanID,bagliListe->unvanYili);
		bagliListe=bagliListe->sonraki;
	}
}
 void elemanekle()
 {
 	Akademisyenler * kayit=(Akademisyenler *)malloc(sizeof(Akademisyenler));
	scanf("%d %s %s %d %d",&kayit->sicilNo,kayit->ad,kayit->soyAd,&kayit->unvanID,&kayit->unvanYili);
	ekle(kayit);
 } 
 Akademisyenler * gorevlendir(Akademisyenler * bListe,int gSayi)
 {
 	if(bListe!=NULL)
 	{
 			gorevlendir(bListe->sonraki,gSayi);
 			if(gorevlisayisi==0) return 0;
 			else
			{
				printf("%d %s %s %d %d\n",bListe->sicilNo,bListe->ad,bListe->soyAd,bListe->unvanID,bListe->unvanYili);
 				gorevlisayisi--;
			}
	}
 }
 void sil(int aranansicil)
 {
 	Akademisyenler * gecici=ilk, *silEleman;
 	bool bayrak=0;
	 if(aranansicil==ilk->sicilNo)
		{
			ilk=ilk->sonraki;
			free(gecici);
			bayrak=1;
			system("CLS");
			printf("\nEleman basari ile silindi.\n");
		}
	while(gecici->sonraki!=NULL)
	{
		if(aranansicil==gecici->sonraki->sicilNo)
		{
			silEleman=gecici->sonraki;
			gecici->sonraki=silEleman->sonraki;
			if(silEleman==son)
				son=gecici;
			free(silEleman);
			bayrak=1;
			system("CLS");
			printf("\nEleman basari ile silindi.\n");
			break;
		}
		gecici=gecici->sonraki;
	}
	if(bayrak==0)
	{
		system("CLS");
		printf("\nAranan eleman yok. Silme yapilamaz.\n");
	}
 }
