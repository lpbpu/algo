#include <stdio.h>

#define INF 9999

#define MAXTOP 3	/* 3条次优路径 */
#define MAXHOP 5



int matrix[]={
    0,  1,  5,INF,INF,INF,INF,INF,INF,
    1,  0,  3,  7,  5,INF,INF,INF,INF,
    5,  3,  0,INF,  1,  7,INF,INF,INF,
    INF,  7,INF,  0,  2,INF,  3,INF,INF,
    INF,  5,  1,  2,  0,  3,  6,  9,INF,
    INF,INF,  7,INF,  3,  0,INF,  5,INF,
    INF,INF,INF,  3,  6,INF,  0,  2,  7,
    INF,INF,INF,INF,  9,  5,  2,  0,  4,
    INF,INF,INF,INF,INF,INF,  7,  4,  0
};


int omatrix[9*9];


int path1[9*9];
int path2[9*9*9];

int hop[9*9];

int top[9*9*MAXTOP];
int value[9*9*MAXTOP];




#define M(i,j)  matrix[i*9+j]		/* 原始matrix,计算最优后，为i->j的最优距离 */
#define PATH(i,j)  path1[i*9+j]		/* 最优路径 inplace,初始化(i,i)=i,(i,j)=j*/
#define PATH2(i,j,k) path2[i*9*9+j*9+k] /* 最优路径，初始化(i,j,0)=i,(i,j,1)=j,(i,j,x)=-1 */

#define HOP(i,j) hop[i*9+j]  /* i->j的跳数，初始为1 */


#define TOP(i,j,t) top[i*9*MAXTOP+j*MAXTOP+t] 	  /* 次优路径，新选择的k点,次优路径为i->k plus 最优路径(k->j) k<>PATH2(i,j,1) */
#define VALUE(i,j,t) value[i*9*MAXTOP+j*MAXTOP+t] /* 次优路径，存储i->j的次优路径对应的次优距离, VALUE(i,j,MAXTOP-1)为最次优路径 */


#define OM(i,j) omatrix[i*9+j]	/* matrix的备份 */


void init_omatrix()
{
	int i,j;
	for (i=0;i<9;i++){
		for (j=0;j<9;j++){
			OM(i,j)=M(i,j);
		}
	}
			
}


void init_path(){
	int i,j,k;
	for (i=0;i<9;i++){
		for (j=0;j<9;j++){
			if (i==j)
				PATH(i,j)=i;
			else
				PATH(i,j)=j;
		}
	}



	for (i=0;i<9;i++){
		for (j=0;j<9;j++){
			PATH2(i,j,0)=i;
			PATH2(i,j,1)=j;

			HOP(i,j)=1;

			for (k=2;k<9;k++){
				PATH2(i,j,k)=-1;
			}
		}
	}	
			

	for (i=0;i<9;i++){
		for (j=0;j<9;j++) {
			for (k=0;k<MAXTOP;k++) {
				TOP(i,j,k)=-1;
				VALUE(i,j,k)=INF;
			}
		}
	}	

}


/* fix path from i->j to i->k plus k->j */
void addpath(int i,int j,int k)
{
	int v,l;
	for (v=0;v<9;v++){
		if (PATH2(i,k,v)!=-1){
			PATH2(i,j,v)=PATH2(i,k,v);
		}else{
			break;
		}
	}

	for (l=1;l<9;l++){
		if (PATH2(k,j,l)!=-1){
			PATH2(i,j,v++)=PATH2(k,j,l);
		}else{
			PATH2(i,j,v)=-1;
			break;
		}

	}

	

}


void compute_shortest_path()
{
	int i,j,k;
	for (k=0;k<9;k++){
		for (i=0;i<9;i++){
			for (j=0;j<9;j++){
				if ((i==j) || (j==k) || (i==k))
					continue;

				if (M(i,k)+M(k,j)<M(i,j)){
					M(i,j)=M(i,k)+M(k,j);
					PATH(i,j)=PATH(i,k);
					HOP(i,j)=HOP(i,k)+HOP(k,j);
					addpath(i,j,k);
				}
			}
		}		
	}


}



void add_second_path(int i,int j,int k,int newvalue)
{
	int t;
	int t1;

	for (t=0;t<MAXTOP;t++){
		if (newvalue<VALUE(i,j,t)){
			for (t1=MAXTOP-1;t1>t;t1--) {
				TOP(i,j,t1)=TOP(i,j,t1-1);
				VALUE(i,j,t1)=VALUE(i,j,t1-1);
			}

			TOP(i,j,t)=k;
			VALUE(i,j,t)=newvalue;
			break;
		}

	}	

}


int check_second_loop(int i,int j,int k)
{
	int m;
	int exist=0;

	for (m=1;m<8;m++){
		if (PATH2(k,j,m)==-1)
			break;
		if (PATH2(k,j,m)==i){
			exist=1;
			break;
		}

	}

	return exist;

}



int check_top_loop(int i,int j,int k)
{
	//such as a-*-b-*-c with b-*-a-*-c , ensure k->j not exist i where k->j in exist top path
	int exist=0;
    int t,m,m1;

	if (k==i) return 1;


	//k->j top path:  k->TOP(k,j,t) (m) -> j

    for (t=0;t<MAXTOP;t++){
		m=TOP(k,j,t);

		if (m<=0) {
			continue;
		}

		if (m==i) {
			exist=1;
			break;
		}

		for (m1=1;m1<9;m1++){
			if (PATH2(m,j,m1)==-1) {
				break;
			}

			if (PATH2(m,j,m1)==i) {
				exist=1;
				break;
			}

		}

		if (1==exist) break;	
	

	}
	
	

	return exist;	
	
}



/* try to find another k<>PATH2(i,j,1),which HOP(i,k)=1 or OM(i,k)=1,compute second path */
void compute_second_path()
{
	int i,j,k;
	int newlen;


	for (i=0;i<9;i++){
		for (j=0;j<9;j++){
			for (k=0;k<9;k++){
				if ((i==j) || (i==k) || (j==k))
					continue;
			
				//if (HOP(i,k)!=1)	//find less path but fast
				//	continue;

				if (OM(i,k)==INF)	//find more path but slow
					continue;

				if (PATH2(i,j,1)==k)
					continue;

				newlen=OM(i,k)+M(k,j);
				
				if (newlen<VALUE(i,j,MAXTOP-1)){
					if (check_second_loop(i,j,k))		//k->j not exist i
						continue;

					if ((HOP(i,j)>1) && (check_second_loop(PATH2(i,j,1),j,k))) // hop(i,j)>1 k->j not exist i+1
						continue;

					if (check_top_loop(i,j,k)) 	//check second path loop
						continue;
					
					add_second_path(i,j,k,newlen);
					
				}



			}
		}
	}



}



void print_path()
{
	int i,j;
	for (i=0;i<9;i++){
		for (j=0;j<9;j++){
			printf("%d ",PATH(i,j));
		}
		printf("\n");
	}

	printf("\n");
	


}


void print_matrix()
{
	int i,j;
	for (i=0;i<9;i++){
		for (j=0;j<9;j++){
			printf("%d ",M(i,j));
		}
		printf("\n");
	}

	printf("\n");
}


void print_path2()
{
	int i,j,k;
	for (i=0;i<9;i++){
		for (j=0;j<9;j++){
			if (i==j) continue;
			printf("%d->%d(%d):",i,j,HOP(i,j));
			for (k=0;k<9;k++){
				if (PATH2(i,j,k)==-1) {
					printf("\n");
					break;
				}else{
					printf("%d->",PATH2(i,j,k));
				}
			}
		}
	}			
}

void print_second_path()
{
	int i,j,t,k;
	int p;

	for (i=0;i<9;i++){
		for (j=0;j<9;j++){
			if (i==j) continue;
			
			for (t=0;t<MAXTOP;t++) {
				printf("%d->%d(%d):%d->",i,j,t,i);

				p=TOP(i,j,t);
				if (p==-1){
					printf("\n");
					continue;
				}

				printf("%d->",p);

				for (k=1;k<9;k++){
					if (PATH2(p,j,k)==-1) {
						printf("\n");
						break;
					}else{
						printf("%d->",PATH2(p,j,k));
					}
				}
			}
		}
	}

	
			
}

int main()
{
	print_matrix();
	
	init_omatrix();
	init_path();
	compute_shortest_path();
	print_path();	/* inplace:0->6:1 1->6:2 2->6:4 4->6:3 3->6:6 */
	print_path2();

	printf("\n");

	compute_second_path();
	print_second_path();
		

	return 0;
}
