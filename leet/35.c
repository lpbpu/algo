#include <stdio.h>
#include <stdlib.h>

int searchInsert(int *sums,int numsSize,int target){
	int l=0,r;
	int n;
	int n1;

	if (numsSize<=1) return 0;
	

	r=numsSize-1;
	if (target<sums[l]) return 0;
	if (target>sums[r]) return numsSize;
	
	

	while(l<r){
		if (r-l==1){
			if (target==sums[r]){
				n=r;
			}else{
				n=l+1;
			}

			break;
		}


		n1=(l+r)/2;

		if (target>sums[n1])	l=n1;
		if (target<sums[n1])	r=n1;
		if (target==sums[n1]) {
			n=n1;
			break;
		}

	}

	return n;	


}


int main(int argc,char **argv){
	//int a[5]={1,3,4,7,9};
	int a[]={1,3,5,6};
	int target;
	int n;

	if (argc<2)  return -1;

	target=atoi(argv[1]);	


	n=searchInsert(a,sizeof(a)/sizeof(a[0]),target);

	printf("a=[1,3,5,6],target=%d,index=%d\n",target,n);
	return 0;
}
