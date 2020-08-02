# include <stdio.h>
# include <math.h>

# define MAX 6

void add(int*,int*,int*);
void multi(int*,int*,int*);
int cal(int*,int,int);

int main(void)
{
	int tem1[MAX*2] = { 0 }, tem2[MAX*2] = { 0 };
	int poly1[MAX] = { 0 }, poly2[MAX] = { 0 };
	int added[MAX] = { 0 };
	int multied[2*MAX-1] = { 0 };
	int degree1, degree2;
	int wp, val, answer;			//계산 하고 싶은 식, 계산 하고 싶은 값, 답  

	printf("수식 1은 몇개의 항으로 구성되어 있나요? : ");
	scanf("%d", &degree1);

	printf("수식 1을 입력하세요 : ");
	for (int i = 0; i < degree1*2; i++)
		scanf("%d", &tem1[i]);

	printf("수식 2는 몇개의 항으로 구성되어 있나요? : ");
	scanf("%d", &degree2);

	printf("수식 2를 입력하세요 : ");
	for (int i = 0; i < degree2*2; i++)
		scanf("%d", &tem2[i]);
		
	for (int i = 0; i < degree1; i++)
	{
		int j;
		j = tem1[2 * i + 1];
		poly1[j] = tem1[2 * i];

		if (j == 0)
			break;
	}
	
	for (int i = 0; i < degree2; i++)
	{
		int j;
		j = tem2[2 * i + 1];
		poly2[j] = tem2[2 * i];

		if (j == 0)
			break;
	}
			
	add(poly1,poly2,added);
	
	printf("\n수식 1 + 2는 ");
	for(int i=MAX-1;i>=0;i--)
	{
		if(added[i]!=0)
			{
				printf("%d %d ",added[i],i);	
			}
		else
		continue;
	}
	printf(" (이것을 수식 3이라 하자)\n");

	multi(poly1,poly2,multied);
	
	printf("수식 1 * 2 는 ");
	for(int i=2*MAX-1;i>=0;i--)
	{
		if(multied[i]!=0)
			{
				printf("%d %d ",multied[i],i);	
			}
		else
		continue;
	}
	printf(" (이것을 수식 4라 하자)\n\n\n");
	
	while(1)
	{
	printf("수식에 값을 넣으세요 : ");
	scanf("%d %d",&wp,&val); 
	
	switch(wp)
	{
		case 1:
			answer=cal(poly1,val,MAX);
			break;
		case 2:
			answer=cal(poly2,val,MAX);
			break;
		case 3:
			answer=cal(added,val,MAX);
			break;
		case 4:
			answer=cal(multied,val,MAX*2-1);
			break;		 
	}
	
	printf("결과값은 %d \n",answer);
    }

	return 0;
}

void add(int*poly1, int* poly2,int* added)
{
	for(int i=0;i<MAX;i++)
	{
		added[i]=poly1[i]+poly2[i];
	}
	return;
 } 
 
 void multi(int*poly1, int* poly2,int* multied) 
 {
 	for(int i=0;i<MAX;i++)
 		for(int j=0;j<MAX;j++)
	 		multied[i+j] += poly1[i] * poly2[j];
	 		
	return;	
 }
 
int cal(int* poly, int a, int d)
 {
 	int answer=0;
 	
 	for(int i=0;i<d;i++)
 	{
 		if(poly[i] != 0)
 			answer += poly[i] * pow(a,i); 			
 		else
 			continue;
	 }
	 return answer;
 }
