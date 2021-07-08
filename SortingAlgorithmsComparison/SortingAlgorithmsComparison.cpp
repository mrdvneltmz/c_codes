#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


void Selection(int dizi[],int n){
	int i,j,min,gecici;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++)
			if(dizi[j]<dizi[min]) min=j;
		gecici=dizi[min];
		dizi[min]=dizi[i];
		dizi[i]=gecici;	
	}
}

void swap(int *q, int *p){
 int temp=*p;
 *p=*q;
 *q=temp;
}

void Bubble(int dizi[],int n){
	int i,takas=0;
	while(takas==0){
		takas=1;
		for(i=0;i<n-1;i++){
			if(dizi[i]>dizi[i+1]){
				swap(&dizi[i],&dizi[i+1]);
				takas=0;
			}
		}
		n=n-1;
	}
}

void Insertion(int dizi[],int n){
	int i,j,mevcut;
	for(i=1;i<n;i++){
		mevcut=dizi[i]; j=i;
		while(j>0 && mevcut<dizi[j-1]){
			dizi[j]=dizi[j-1];
			j--;
		}
		dizi[j]=mevcut;
	}
}


int partition(int A[],int p, int r){
    int tmp;
    int x = A[r];
    int i = p-1;

    for(int j=p; j<=r-1; j++)
    {
        if(A[j]<=x)
        {
            i++;
            tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        }
    }
    tmp=A[i+1];
    A[i+1]=A[r];
    A[r]=tmp;
    return i+1;
}

void quickSort(int dizi[],int p, int r){
    int q;
    if(p<r)
    {
        q=partition(dizi,p, r);
        quickSort(dizi,p, q-1);
        quickSort(dizi,q+1, r);
    }
}

void Merge(int dizi[],int ilk,int orta,int son){
	int tempArray[100000];
	int ilk1=ilk; int son1=orta;
	int ilk2=orta+1; int son2=son;
	int index=ilk1;
	for(;(ilk1<=son1) && (ilk2<=son2);index++){
		if(dizi[ilk1]<dizi[ilk2]){
			tempArray[index]=dizi[ilk1]; 
			ilk1++;
		}
		else{ 
			tempArray[index]=dizi[ilk2];
			ilk2++;
		}				
	}
	
	for(;ilk1<=son1;ilk1++,index++)
		tempArray[index]=dizi[ilk1];
	for(;ilk2<=son2;ilk2++,index++)
		tempArray[index]=dizi[ilk2];
	for(index=ilk;index<=son;index++)
	dizi[index]=tempArray[index];
			
}

void Mergesort(int dizi[],int ilk,int son){
	if(ilk<son){
		int orta=(ilk+son)/2;
		Mergesort(dizi,ilk,orta);
		Mergesort(dizi,orta+1,son);
		Merge(dizi,ilk,orta,son);
		}
}
void kopyala(int dizi[],int dizi1[],int x){
	for(int i=0;i<x;i++)
	dizi[i]=dizi1[i];
}
int main(){
	srand(time(NULL));
	int dizi1[10000];
	int tsira1[10000];
	int dizi2[20000];
	int tsira2[20000];
	int dizi3[40000];
	int tsira3[40000];
	int yedek1[10000];
	int yedek2[20000];
	int yedek3[40000];
	
    
    for(int i=0; i<10000; i++){
        dizi1[i] = rand()%100;
    }
    for(int i=0; i<20000; i++){
        dizi2[i] = rand()%100;
    }
    for(int i=0; i<40000; i++){
        dizi3[i] = rand()%100;
    }
	for(int i=9999;i>-1;i--){
        tsira1[i] = i;
    }
	for(int i=19999;i>-1;i--){
        tsira2[i] = i;
    }
    for(int i=39999;i>-1;i--){
        tsira3[i] = i;
    }
    
    kopyala(yedek1,dizi1,10000);
    kopyala(yedek2,dizi2,20000);
    kopyala(yedek3,dizi3,40000);
    
	clock_t  ilk_z, son_z;

	printf("  Random Listeler\n");
	printf("------------------\n");	
//Bubble
	ilk_z = clock();
	Bubble(yedek1,10000);
	son_z = clock();
	printf("Bubblesort 10000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Bubble(yedek2,20000);
	son_z = clock();
	printf("Bubblesort 20000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Bubble(yedek3,40000);
	son_z = clock();
	printf("Bubblesort 40000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	printf("----------------------------------------------\n\n");
//selection
	
	kopyala(yedek1,dizi1,10000);
    kopyala(yedek2,dizi2,20000);
    kopyala(yedek3,dizi3,40000);
    
    ilk_z = clock();
	Selection(yedek1,10000);
	son_z = clock();
	printf("Selectionsort 10000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Selection(yedek2,20000);
	son_z = clock();
	printf("Selectionsort 20000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Selection(yedek3,40000);
	son_z = clock();
	printf("Selectionsort 40000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	printf("-------------------------------------------------\n\n");
	//insertion
	
	kopyala(yedek1,dizi1,10000);
    kopyala(yedek2,dizi2,20000);
    kopyala(yedek3,dizi3,40000);
    
    ilk_z = clock();
	Insertion(yedek1,10000);
	son_z = clock();
	printf("Insertionsort 10000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Insertion(yedek2,20000);
	son_z = clock();
	printf("Insertionsort 20000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Insertion(yedek3,40000);
	son_z = clock();
	printf("Insertionsort 40000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	printf("-------------------------------------------------\n\n");
	//Mergesort
	
	kopyala(yedek1,dizi1,10000);
    kopyala(yedek2,dizi2,20000);
    kopyala(yedek3,dizi3,40000);
    
    ilk_z = clock();
	Mergesort(yedek1,0,9999);
	son_z = clock();
	printf("Mergesort 10000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Mergesort(yedek2,0,19999);
	son_z = clock();
	printf("Mergesort 20000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Mergesort(yedek3,0,39999);
	son_z = clock();
	printf("Mergesort 40000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	printf("--------------------------------------------\n\n");
    
    
	//quickSort
	
	kopyala(yedek1,dizi1,10000);
    kopyala(yedek2,dizi2,20000);
    kopyala(yedek3,dizi3,40000);
    
    ilk_z = clock();
	quickSort(yedek1,0,9999);
	son_z = clock();
	printf("quickSort 10000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	quickSort(yedek2,0,19999);
	son_z = clock();
	printf("quickSort 20000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);

	ilk_z = clock();
	quickSort(yedek3,0,39999);
	son_z = clock();
	printf("quickSort 40000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	printf("---------------------------------------------\n\n\n");
//Sýralý listeler
	printf("  Sirali Listeler \n  ");
	printf("-------------------\n");
//Bubble
	ilk_z = clock();
	Bubble(yedek1,10000);
	son_z = clock();
	printf("Bubblesort 10000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Bubble(yedek2,20000);
	son_z = clock();
	printf("Bubblesort 20000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Bubble(yedek3,40000);
	son_z = clock();
	printf("Bubblesort 400000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	printf("---------------------------------------------\n\n");
//selection

    ilk_z = clock();
	Selection(yedek1,10000);
	son_z = clock();
	printf("Selectionsort 10000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Selection(yedek2,20000);
	son_z = clock();
	printf("Selectionsort 20000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Selection(yedek3,40000);
	son_z = clock();
	printf("Selectionsort 400000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	printf("-------------------------------------------------\n\n");
//insertion
	
    ilk_z = clock();
	Insertion(yedek1,10000);
	son_z = clock();
	printf("Insertionsort 10000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Insertion(yedek2,20000);
	son_z = clock();
	printf("Insertionsort 20000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Insertion(yedek3,40000);
	son_z = clock();
	printf("Insertionsort 40000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	printf("------------------------------------------------\n\n");
//Mergesort
	
    ilk_z = clock();
	Mergesort(yedek1,0,9999);
	son_z = clock();
	printf("Mergesort 10000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Mergesort(yedek2,0,19999);
	son_z = clock();
	printf("Mergesort 20000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Mergesort(yedek3,0,39999);
	son_z = clock();
	printf("Mergesort 40000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	printf("--------------------------------------------\n\n");
    
    
//quickSort
	
    ilk_z = clock();
	quickSort(yedek1,0,9999);
	son_z = clock();
	printf("quickSort 10000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	quickSort(yedek2,0,19999);
	son_z = clock();
	printf("quickSort 20000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
/*
	ilk_z = clock();
	quickSort(yedek3,0,39999);
	son_z = clock();
	printf("quickSort 40000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);	
*/	
	printf("--------------------------------------------\n\n");

//Ters sýralý listeler
 	printf("  Ters Sirali Listeler\n ");
 	printf("-----------------------\n");
//Bubble
	ilk_z = clock();
	Bubble(tsira1,10000);
	son_z = clock();
	printf("Bubblesort 10000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Bubble(tsira2,20000);
	son_z = clock();
	printf("Bubblesort 20000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Bubble(tsira3,40000);
	son_z = clock();
	printf("Bubblesort 40000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	printf("---------------------------------------------\n\n");
//selection
	
	ilk_z = clock();
	Selection(tsira1,10000);
	son_z = clock();
	printf("Selectionsort 10000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Selection(tsira2,20000);
	son_z = clock();
	printf("Selectionsort 20000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Selection(tsira3,40000);
	son_z = clock();
	printf("Selectionsort 40000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	printf("------------------------------------------------\n\n");
//insertion
	
    ilk_z = clock();
	Insertion(tsira1,10000);
	son_z = clock();
	printf("Insertionsort 10000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Insertion(tsira2,20000);
	son_z = clock();
	printf("Insertionsort 20000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Insertion(tsira3,40000);
	son_z = clock();
	printf("Insertionsort 40000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	printf("------------------------------------------------\n\n");
//Mergesort
	
    ilk_z = clock();
	Mergesort(tsira1,0,9999);
	son_z = clock();
	printf("Mergesort 10000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Mergesort(tsira2,0,19999);
	son_z = clock();
	printf("Mergesort 20000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	Mergesort(tsira3,0,39999);
	son_z = clock();
	printf("Mergesort 40000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	printf("--------------------------------------------\n\n");
   
//quickSort
	
    ilk_z = clock();
	quickSort(tsira1,0,9999);
	son_z = clock();
	printf("quickSort 10000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
	
	ilk_z = clock();
	quickSort(tsira2,0,19999);
	son_z = clock();
	printf("quickSort 20000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);
/*
	ilk_z = clock();
	quickSort(tsira3,0,39999);
	son_z = clock();
	printf("quickSort 40000 lik listeyi %f s de siraladi \n",((double)son_z-ilk_z)/1000);	
*/
	printf("--------------------------------------------\n");
	
	
	
	getch();
	return 0;
	
	
	
	
}



