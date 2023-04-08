
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

void print(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			j==n-1?printf(" %d%d",i,j):printf(" %d%d |",i,j);
		}
		printf("\n");
	}
}


int check(int A[100][100],int n,int c)
{
	int i,j,c1=0,c2=0,c3=0,c4=0,p=0;
	for(i=0;i<n;i++)
	{
		c1=c2=0;
		for(j=0;j<n;j++)
		{
			if(A[i][j]==0 || A[i][j]==c)
			{
				c1++;
			}
			if(A[j][i]==0 || A[i][j]==c)
			{
				c2++;
			}
		}
		if(c1==n)
			p++;
		if(c2==n)
			p++;
	}
	for(i=0,j=n-1;i<n;i++,j--)
	{
		if(A[i][j]==0 || A[i][j]==c)
			c3++;
		if(A[i][i]==0 || A[i][j]==c)
			c4++;
	}
	if(c3==n)
		p++;
	if(c4==n)
		p++;
	return p;
}


int termi(int A[100][100],int n,int c)
{
	int i,j,c1=0,c2=0,c3=0,c4=0,p=0;
	for(i=0;i<n;i++)
	{
		c1=0;
		c2=0;
		for(j=0;j<n;j++)
		{
			if(A[i][j]==c)
				c1++;
			if(A[j][i]==c)
				c2++;
		}
		if(c1==n)
			return n;
		if(c2==n)
			return n;
	}
	for(i=0,j=n-1;i<n;i++,j--)
	{
		if(A[i][i]==c)
			c3++;
		if(A[j][i]==c)
			c4++;
	}
	if(c3==n)
		return n;
	if(c4==n)
		return n;
	return 0;
}


int toss()
{
	int c;
	char A[100];
	struct tm *ptr;
	time_t t;
	t=time(NULL);
	ptr=localtime(&t);
	strcpy(A,asctime(ptr));
	c=A[18]+A[17];
	if(c%2==0)
		return 1;
	else
		return 2;			
}

void display(int A[100][100],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			if(j!=n-1)
			{
				if(A[i][j]==0)
					printf("   |");
				if(A[i][j]==1)
					printf(" X |");
				if(A[i][j]==-1)
					printf(" O |");
			}
			else
			{
				if(A[i][j]==0)
					printf("  ");
				if(A[i][j]==1)
					printf(" X");
				if(A[i][j]==-1)
					printf(" O");
			}
		}
	}
}


int win(int A[100][100],int n)
{
	int x,y;
	x=termi(A,n,1);
	y=termi(A,n,-1);
	/*printf("%d %d\n",x,y);*/
	if(y==n)
	{
		printf("\n\ncomputer wins!!!!!!!!");
		/*display(A,n);*/
		return 0;
	}
	if(x==n)
	{
		printf("\n\nuser won!!!!!!!!!");
		/*display(A,n);*/
		return 0;		
	}
	return 1;
}


int cancel(int A[100][100],int n,int pos[2],int c)
{
	int i,j,c1=0,c2=0,c3=0,c4=0,z1=0,z2=0,z3=0,z4=0;
	for(i=0;i<n;i++)
	{
		c1=0;
		z1=0;
		for(j=0;j<n;j++)
		{
			if(A[i][j]==c)
				c1++;
			if(A[i][j]==0)
			{
				pos[0]=i;
				pos[1]=j;
				z1++;
			}
		}
		if(c1==n-1 && z1==1)
			return 1;
	}
	for(i=0;i<n;i++)
	{
		c2=0;
		z2=0;
		for(j=0;j<n;j++)
		{
			if(A[j][i]==c)
				c2++;
			if(A[j][i]==0)
			{
				pos[0]=j;
				pos[1]=i;
				z2++;
			}
		}
		if(c2==n-1 && z2==1)
			return 1;
	}
	for(i=0,j=n-1;i<n;i++,j--)
	{
		if(A[i][j]==c)
			c3++;
		if(A[i][j]==0)
		{
			pos[0]=i;
			pos[1]=j;
			z3++;
		}
	}
	if(c3==n-1 && z3==1)
		return 1;
	for(i=0;i<n;i++)
	{
		if(A[i][i]==c)
			c4++;
		if(A[i][i]==0)
		{
			pos[0]=i;
			pos[1]=i;
			z4++;
		}
	}
	if(c4==n-1 && z4==1)
		return 1;
	return 0;
}



void userchoice(int A[100][100],int n)
{
	int m1,n1;
	if(win(A,n)==0)
		exit(0);
	printf("\nenter the postion you want X:");
	scanf("%d%d",&m1,&n1);
	if(A[m1][n1]==0)
	{
		A[m1][n1]=1;
		display(A,n);
	}
	else
	{
		printf("the entered position is unavailable:");
		userchoice(A,n);
	}
}


int compchoice(int A[100][100],int n)
{
	int pos[2];
	int i1,j1,i,j,max=0,p;
	if(cancel(A,n,pos,-1)==1)
	{
		A[pos[0]][pos[1]]=-1;
		display(A,n);
	}
	if(win(A,n)==0)
		exit(0);
	if(cancel(A,n,pos,1)==1)
	{
		A[pos[0]][pos[1]]=-1;
		display(A,n);
		return 1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(A[i][j]==0)
			{
				A[i][j]=-1;
				p=check(A,n,-1);
				if(p>max)
				{
					max=p;
					i1=i;
					j1=j;
				}
				A[i][j]=0;
			}
		}
	}
	/*printf("%d %d",i1,j1);*/
	A[i1][j1]=-1;
	display(A,n);
	return 1;
}


int main()
{
	int A[100][100],n,i,j,a,m1,n1,z[100],f=0;
	char h;
	printf("Enter the dimension of XO matrix:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A[i][j]=0;
		}
	}
	printf("\nHEADS : h\nTAILS : t\n\nEnter your choice:");
	fflush(stdin);
	scanf("%c",&h);
	a=toss();
	print(n);
	while(1)
	{
		if(a==(n*n)+1)
		{
			printf("\nMATCH TIED!!!!!\n");
			exit(0);
		}
		if(a%2==0)
		{
			if(f==0)
			{
				printf("\nYOU START!!!!!!\n");
				f=1;
			}
			printf("\n\nUSER's TURN'!!!!\n");	
			userchoice(A,n);
			if(win(A,n)==0)
				exit(0);
			else
			{
				system("cls");
				print(n);
			}	
		}
		else
		{
			if(f==0)
			{
				printf("\nCOMPUTER STARTS!!!!!!\n");
				f=1;
			}
			printf("\nCOMPUTER's TURN!!!\n");
			compchoice(A,n);
			if(win(A,n)==0)
				exit(0);
		}
		a++;
	}
	return 1;
}
