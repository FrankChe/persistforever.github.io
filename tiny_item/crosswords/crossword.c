#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int math[9][9] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 ,
                   4 , 5 , 6 , 7 , 8 , 9 , 1 , 2 , 3 ,
				   7 , 8 , 9 , 1 , 2 , 3 , 4 , 5 , 6 ,
				   2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 1 ,
				   5 , 6 , 7 , 8 , 9 , 1 , 2 , 3 , 4 ,
				   8 , 9 , 1 , 2 , 3 , 4 , 5 , 6 , 7 ,
				   3 , 4 , 5 , 6 , 7 , 8 , 9 , 1 , 2 ,
				   6 , 7 , 8 , 9 , 1 , 2 , 3 , 4 , 5 ,
				   9 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , } ;    //��������򵥳���

int sign[9][9] = { 0 } ;
int grid1[9] = { 0 , 0 , 0 , 3 , 3 , 3 , 6 , 6 , 6 } ;
int grid2[9] = { 0 , 3 , 6 , 0 , 3 , 6 , 0 , 3 , 6 } ;
int N ;
int num_all = 0 ;    //������Ҫ���ĸ���
int disc = 0 ;    //��ĸ���
int blank_row[50] = {0} ;
int blank_col[50] = {0} ;
int solved[50] ;

void change()    //��������
{
	int i , j , row , col ;

	row = rand() % 9 + 1 ;
	col = rand() % 9 + 1 ;
	for( i = 0 ; i <= 8 ; i++)
	{
		for( j = 0 ; j <= 8 ; j++)
		{
			if( math[i][j] == row ) 
			{
				math[i][j] = col ;
				continue ;
			}

			if( math[i][j] == col ) 
			{
				math[i][j] = row ;
				continue ;
			}
		}
	}
}


void deletemath()    //��ÿһ���������ѡ�񼸸���ȥ��
{
	int row , col , n , i ;
	
	for( i = 0 ; i <= 8 ; i++)
	{
		for(n = 1 ; n <= N ; n++)
		{
			do 
			{
				row = rand() % 3 ;
		        col = rand() % 3 ;
			}while( sign[ row + grid1[i] ][ col + grid2[i] ] == 1 ) ;
			sign[ row + grid1[i] ][ col + grid2[i] ] = 1 ;
			num_all++ ;
			blank_row[ num_all ] = row + grid1[i] ;
			blank_col[ num_all ] = col + grid2[i] ;
		}
	}
}


void print()    //��ʽ�����
{
	int i , j ;

	printf("-----------------------------\n");
    for(i = 0; i <= 8; i++)
	{
		for(j = 0; j <= 8; j++)
		{
			if( (j+1) % 3 == 0 )
			{
				if( sign[i][j] != 1 )
					printf("%d | " , math[i][j]);
				else
					printf("  | ");
			}
			else
			{
            	if( sign[i][j] != 1 )
					printf("%d  " , math[i][j]);
				else
					printf("   ");
			}
		}
		printf("\n");
		if( (i+1) % 3 == 0 )
		{
			printf("-----------------------------");
		    printf("\n");
		}
	}
}


void getans()    //��ʽ�������ȷ��
{
	int i , j ;
    for(i = 0; i <= 8; i++)
	{
		for(j = 0; j <= 8; j++)
			if( (j+1) % 3 == 0 )
					printf("%d | " , math[i][j]);
			else
					printf("%d  " , math[i][j]);
		printf("\n");
		if( (i+1) % 3 == 0 )
		{
			printf("-----------------------------");
		    printf("\n");
		}
	}
}


int remine(int row , int col , int N)    //���row��col�е���ΪNʱ����һ����һ�к���һ���Ƿ�������������
{
	int i , j , num = 0 ; 
	
	for( i = 0 ; i <= 8 ; i++ )
	{
		if( math[ row ][ i ] == N && sign[ row ][ i ] == 0 )
			num++;
		if( math[ i ][ col ] == N && sign[ i ][ col ] == 0 )
			num++;
	}

	for( i = (row / 3) * 3 ; i <= (row / 3) * 3 +2 ; i++)
		for( j = (col / 3) * 3 ; j <= (col / 3) * 3 +2 ; j++)
			if( math[ i ][ j ] == N && sign[ i ][ j ] == 0)
				num++;
	if( num != 0 )
		return 0 ;
	else
		return 1 ;
}


void DFS( int num_yes )    //��ÿһ���ڵ㿪ʼ�������
{
	int t ;

	if( num_yes >= num_all + 1 )
		disc++ ;
	for( N = 1 ; N <= 9 ; N++)
	{
		if( remine( blank_row[ num_yes ] , blank_col[ num_yes ] , N ) == 1 )    //�жϴ˵��Ƿ�������������
		{
			math[ blank_row[ num_yes ] ][ blank_col[ num_yes ] ] = N ;
			t = N ;
			sign[ blank_row[ num_yes ] ][ blank_col[ num_yes ] ] = 0 ;
		    DFS( num_yes + 1 ) ;
			sign[ blank_row[ num_yes ] ][ blank_col[ num_yes ] ] = 1 ;    //�ֳ��ػ�
			N = t ;
		}
	}
}


void solve()
{
	int n , leap = 0 ;
	char con ;
	while( leap == 0 )
	{
		for( n = 1 ; n <= num_all ; n++ )
		{
	    	printf( "��%d��%d����������" , blank_row[ n ] + 1 , blank_col[ n ] + 1 ) ;
		    scanf( "%d" , &solved[n] ) ;
		    if( solved[n] != math[ blank_row[ n ] ][ blank_col[ n ] ]) 
		    	leap = 1 ;
		}
     	if( leap == 1 )
	    	printf( "\n�𰸴���\n\n" ) ;
     	else
		{
			printf( "\n����ȷ\n\n" ) ;
			break ;
		}
		printf( "�Ƿ���Ҫ�ۿ���? Y? N? \n") ;
		scanf( "%s" , &con ) ;
		if( con == 'Y' )
		{
			getans() ;
			break ;
		}

	}
}


int main()
{
    int i ;
	printf("��ѡ���Ѷ�\n����-1  ��-2  ����-3  ����-4  ��������-5\n") ; 
	scanf("%d" , &N) ;  
    srand( time(0) ) ;
	for( i = 1 ; i <= 50 ; i++)
		change() ;    //������������
	deletemath() ; 
	printf("�ܹ�ȡ��%d������\n" , num_all ) ;
	print() ;
	DFS( 1 ) ;
	if( disc == 1 )
	{
		printf( "\n\n������Ϊ��Ψһ����������֣��밴��˳��д��ÿ����\n\n") ;
	    solve() ;
	}
	else
		printf( "\n\n��������%d���,�����¿�ʼ\n\n" , disc ) ; 
	return 0;
}
