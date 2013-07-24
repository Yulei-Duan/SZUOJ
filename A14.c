// author : Levi  7.24

#include <stdio.h>
#include <math.h>
int A[102];
int main()
{

  	int t, n, m, i;
	double d;
	scanf("%d", &t);
	while(t--){
  		scanf("%d%d", &n, &m);
  		for (int i = 0; i < n; ++i){
  			d = floor(m/n);
  			A[i] = (m%n + d);
  			printf("%d ", A[i]);
  			m-=A[i];
  		}
	printf("\n%d\n", m);
	}
	return 0;
}	
