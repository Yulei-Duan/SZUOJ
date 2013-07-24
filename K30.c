//author : Levi

#include <stdio.h>

int A[100002];
int B[100002];

int k;


int main() {
	int m,n,i,flag;
	k=0;
	while (~scanf("%d %d", &m ,&n)) {
		for (i=0;i<n;++i) {
			scanf("%d", &A[i]);
		}
		
		for (i=0;i<n;++i) {
			scanf("%d", &B[i]);
		}

		flag = 1;
		for (i = 0; i < n; ++i)
		{
			if (A[i]==B[i])
				continue;
			if(A[i]<B[i]){
				flag = 0;
				break;
			}

			if(A[i] > B[i]){
				if(i+m < n)
					A[i+m] += A[i] - B[i];
				else{
					flag = 0;
					break;
				}
			}

			
		}
		k++;	
		printf("Case %d:\n", k);	
		if(flag ==0) printf("No\n"); 
		else printf("Yes\n");
		
	}
}