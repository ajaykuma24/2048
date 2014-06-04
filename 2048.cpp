#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
using namespace std;
void disp(int[4][4]);
void equ(int[4][4], int[4][4]);

int main()
{
	int ar[4][4] = {0};
	int test[4][4] = {0};
	char dir;
	int score = 0;
	int equals = 0;
	int ranum;
	srand(time(NULL));
	int row = rand()%4;
	int col = rand()%4;
	ranum = rand()%2;
	if(ar[row][col] == 0)
	{
		if(ranum)
		ar[row][col] = 2;
		else ar[row][col] = 4;
	}
	row = rand()%4;
	col = rand()%4;
	ranum = rand()%2;
	if(ar[row][col] == 0)
	{
		if(ranum)
		ar[row][col] = 2;
		else ar[row][col] = 4;
	}
		
	disp(ar);
	equ(ar, test);
	
	for(;;)
	{
	do
	{
		equals = 0;
		equ(ar, test);
	cin>>dir;
	if(dir == 's')
	{
		for(int c = 0; c<3;++c)
		{
		for(int i = 2; i>=0;--i)
		for(int j = 0; j<4; ++j)
		{
		if(ar[i][j]!=0)
			if(ar[i+1][j]==0)
				{
					ar[i+1][j] = ar[i][j];
					ar[i][j] = 0;
				}
				
		}
	}
	for(int i = 3; i>0;--i)
		for(int j = 0; j<4; ++j)
		{
		if(ar[i][j]== ar[i-1][j])
			{
				ar[i][j]*=2;
				score+=ar[i][j];
				for(int k = i-1; k>0;--k)
				{
					ar[k][j] = ar[k-1][j];
				}
				ar[0][j] = 0;	
			}
		}
}
	if(dir == 'w')
	{
		for(int c = 0; c<3;++c)
		{
		for(int i = 1; i<4;++i)
		for(int j = 0; j<4; ++j)
		{
		if(ar[i][j]!=0)
			if(ar[i-1][j]==0)
				{
					ar[i-1][j] = ar[i][j];
					ar[i][j] = 0;
				}
				
		}
		}
		for(int i = 0; i<3;++i)
		for(int j = 0; j<4; ++j)
		{
		if(ar[i][j]== ar[i+1][j])
			{
				ar[i][j]*=2;
				score+=ar[i][j];
				for(int k = i+1; k<3;++k)
				{
					ar[k][j] = ar[k+1][j];
				}
				ar[3][j] = 0;	
			}
		}
	}
	if(dir == 'a')
	{	
		for(int c = 0; c<3;++c)
		{
	
		for(int j = 1; j<4;++j)
		for(int i = 0; i<4; ++i)
		{
		if(ar[i][j]!=0)
			if(ar[i][j-1]==0)
				{
					ar[i][j-1] = ar[i][j];
					ar[i][j] = 0;
				}
				
		}
		}
		for(int j = 0; j<3;++j)
		for(int i = 0; i<4; ++i)
		{
		if(ar[i][j]== ar[i][j+1])
			{
				ar[i][j]*=2;
				score+=ar[i][j];
				for(int k = j+1; k<3;++k)
				{
					ar[i][k] = ar[i][k+1];
				}
				ar[i][3] = 0;	
			}
		}
	}
		if(dir == 'd')
	{
		for(int c = 0; c<3;++c)
		{
		for(int j = 2; j>=0;--j)
		for(int i = 0; i<4; ++i)
		{
		if(ar[i][j]!=0)
			if(ar[i][j+1]==0)
				{
					ar[i][j+1] = ar[i][j];
					ar[i][j] = 0;
				}
				
		}
		}
		for(int j = 3; j>0;--j)
		for(int i = 0; i<4; ++i)
		{
		if(ar[i][j]== ar[i][j-1])
			{
				ar[i][j]*=2;
				score+=ar[i][j];
				for(int k = j-1; k>0;--k)
				{
					ar[i][k] = ar[i][k-1];
				}
				ar[i][0] = 0;	
			}
		}
	}
		for(int i = 0; i<4; ++i)
	{
		for(int j = 0; j<4; ++j)
		{
		if(test[i][j] == ar[i][j])
		++equals;
		}
	}

}while(equals==16);
	cout<<score<<endl;
	do{
	row = rand()%4;
	col = rand()%4;	
	}while(ar[row][col] != 0);
	ranum = rand()%10;
	if(ranum)
		ar[row][col] = 2;
	else ar[row][col] = 4;
	disp(ar);
	}
			
	return 0;
	
}

void disp(int ar[4][4])
{
		for(int i = 0; i<4; ++i)
	{
		for(int j = 0; j<4; ++j)
			cout<< setw(4)<< ar[i][j]<<"   ";
			
		cout<< endl;
	}
	return;
}
void equ(int ar[4][4], int test[4][4])
{
			for(int i = 0; i<4; ++i)
	{
		for(int j = 0; j<4; ++j)
		test[i][j] = ar[i][j];
		
	}
}
