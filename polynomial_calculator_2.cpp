# include <stdio.h>
# include <math.h>

# define MAX 6

typedef struct p{
	int coef;	//계수 
	int expon;	//차수  
}pol;

void add(pol*,pol*,pol*);
void attach(int, int, pol*);
void multi(pol* , pol*,pol* );
int cal(pol*,int,int);

int main(void)
{
	pol poly1[MAX]={{0,0}},poly2[MAX]={{0,0}};
	pol added[MAX]={{0,0}};
	pol multied[MAX*2-1]={{0,0}};
	int wp,val,answer;

	int degree1,degree2; 
	
	printf("수식 1은 몇 개의 항으로 구성되어 있나요? : ");
	scanf("%d",&degree1);
	
	printf("수식 1을 입력하세요 : ");
	for(int i=0;i<degree1;i++)
	{
		scanf("%d",&poly1[i].coef);
		scanf("%d",&poly1[i].expon);
	 } 
	 
	printf("수식 2는  몇 개의 항으로 구성되어 있나요? : ");
	scanf("%d",&degree2);
	
	printf("수식 2를 입력하세요 : ");
	for(int i=0;i<degree2;i++)
	{
		scanf("%d",&poly2[i].coef);
		scanf("%d",&poly2[i].expon);
	 } 
	
	add(poly1,poly2,added);
	printf("\n수식 1 + 2는 ");
	for(int i=0;i<MAX-1;i++)
	{
		if(added[i].coef != 0)
			printf("%d %d ", added[i].coef,added[i].expon);
	}
	printf("(이것을 수식 3이라 하자)\n"); 
	
	multi(poly1,poly2,multied);
	printf("수식 1 * 2는 ");
	for(int i=0;i<MAX*2 - 1;i++)
	{
		if(multied[i].coef != 0)
			printf("%d %d ", multied[i].coef,multied[i].expon);
	}	
	printf("(이것을 수식 4라 하자)\n\n\n");
	
	
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
 
 void add(pol* poly1,pol* poly2,pol* added)
 {
 	int i=0,j=0;
 	
 	while(i<MAX && j<MAX)
 		{
			if(poly1[i].coef == 0 && poly2[j].coef == 0)
 				break;
 			else if(poly1[i].expon > poly2[j].expon)
 			{
 				attach(poly1[i].coef,poly1[i].expon,added);
 				i++;
			 }
			else if(poly1[i].expon == poly2[j].expon)
			{
				attach(poly1[i].coef + poly2[j].coef, poly1[i].expon, added);
				i++;
				j++;
			}
			else 
			{
				attach(poly2[j].coef,poly2[j].expon,added);
				j++;
			}
		}
 			
	return;
 }
 
 void attach(int coef, int expon, pol* poly)
 {
 	int count=0;
 	
 	for(count=0;count<MAX*2;count++)
 	{
 		if(poly[count].coef !=0)
 			continue;
 		else
 			break;
	 }
	 
	poly[count].coef = coef;
	poly[count].expon = expon;
	
	return; 
 }
 
 void multi(pol* poly1, pol* poly2,pol* multied)
 {
 	for(int i=0;i<MAX;i++)
 	{
 		if(poly1[i].coef == 0)
 			break;
 		else
 			for(int j=0;j<MAX;j++)
 			{
 				if(poly2[j].coef == 0)
 					break;
 				else
 				{
 					for(int k=0;k<MAX*2 -1;k++)
 					{
 						if(multied[k].coef == 0)
 						{
							 attach(poly1[i].coef * poly2[j].coef,poly1[i].expon + poly2[j].expon,multied);
							 break;
						}
 						else if(multied[k].expon == poly1[i].expon + poly2[j].expon)
 						{
 							multied[k].coef += poly1[i].coef * poly2[j].coef;
 							break;
						 } 
					 }
				 }
			 }
	 }
	 return;
 }
 
 int cal(pol* poly, int a, int d)
 {
 	int answer=0;
 	
 	for(int i=0;i<d;i++)
 	{
 		if(poly[i].coef != 0)
 			answer += poly[i].coef * pow(a,poly[i].expon); 			
 		else
 			break;
	 }
	 return answer;
 }
