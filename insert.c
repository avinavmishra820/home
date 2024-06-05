#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insertion_sort(long a[],int n){
	int i,j;
	long v;
	for(i=1;i<n;i++){
		v=a[i];
		j=i-1;
		while(j>=0 && a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
	}
	printf("\nThe phoneNumber in the sorted forms \n");
	for(i=0;i<n;i++){
		printf("%ld\t",a[i]);
	}
}

int main(){
	double clk;
	clock_t starttime,endtime;
	int i,j,n;
	long a[100];
	printf("Enter the number of phone Number \n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		a[i]=900000000+(rand()%9999999999)+1;
		printf("%ld\t",a[i]);
	}

	starttime=clock();
	insertion_sort(a,n);
	endtime=clock();
	clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	printf("\nThe time %f",clk);
}
