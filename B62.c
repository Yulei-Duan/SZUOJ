// Problem(B62):RPN
#include <stdio.h>
#include <string.h>

char ex[1002];
char A[1002];
char B[600];


int main()
{
	int t, i;
	int topA , topB;
	scanf("%d", &t);
	while(t--){
		topA = topB = 0;
		scanf("%s", ex);
		for(i=0;i<strlen(ex);++i)//len = strlen(ex)  这样写效率会提高10倍多
		{
			if(ex[i]>='a' && ex[i]<='z'){
				A[topA++] = ex[i];
				continue;
			}
			
			if(ex[i]=='(' ){
				B[topB++] = ex[i];
				continue;
			}

			if(ex[i]=='+' || ex[i]=='-' ){
				topB--;
				while( B[topB]=='+' || B[topB]=='-' || B[topB]=='*' ||B[topB]=='/' || B[topB]=='%'  ){
					A[topA++] = B[topB];
					topB--;
				} 
				topB++;
				B[topB++]=ex[i];

				continue;
			}

			if(ex[i]=='*' || ex[i]=='/'|| ex[i]=='%'){
				topB--;
				while(  B[topB]=='*' ||B[topB]=='/' || B[topB]=='%'  ){
					A[topA++] = B[topB];
					topB--;
				} 
				topB++;
				B[topB++]=ex[i];

				continue;
			}

			if(ex[i] == ')'){
				while(B[topB-1] !='('){
					--topB;
					A[topA++] = B[topB];
				} 
				--topB;
				continue;
			}

		}
		while(topB>0){
			topB--;
			A[topA++] = B[topB];

		}
		A[topA]='\0';
		puts(A);
	}
	return 0;
}