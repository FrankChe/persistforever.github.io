#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int ptc[10][9],ptc1[10][9],ptc2[10][9],g[9],p[10][9],v[10][9],tim[9]={81,40,26,4,65,98,53,71,15},suitx[10],suitp[10],suitg,R1[9],R2[9];

int max1(int a,int b,int c)
{
	a=a>b?a:b;
	c=c>a?c:a;
	return c;
}

void O12(int n)   //O-���ŵĺ��������������ռ�ʸ������(ȫ�ּ�ֵ�����).
{
	int i;
	for(i=0;i<9;i++)
	{
		if(ptc[n][i]!=g[i])
			ptc1[n][i]=g[i];
		else
			ptc1[n][i]=0;
	}
}

void O11(int n)   //O-���ŵĺ��������������ռ�ʸ������(���弫ֵ�����).
{
	int i;
	for(i=0;i<9;i++)
	{
		if(ptc[n][i]!=p[n][i])
			ptc2[n][i]=p[n][i];
		else
			ptc2[n][i]=0;
	}
}

void O21(int n)   //O*���ŵĺ��������������ռ�ʸ������(R1�����). 
{
	int i;
	for(i=0;i<9;i++)
	{
		if(R1[i]==0)
			ptc1[n][i]=0;
	}
}

void O22(int n)   //O*���ŵĺ��������������ռ�ʸ������(R2�����). 
{
	int i;
	for(i=0;i<9;i++)
	{
		if(R2[i]==0)
			ptc2[n][i]=0;
	}
}

void O31(int n)   //O+���ŵĺ��������������ռ�ʸ������(���º���������).
{
	int i,rad1,rad2;
	srand(time(0));
	rad1=rand()%9;
	rad2=rand()%9;
	for(i=rad1;i<=rad2;i++)
		ptc1[n][i]=ptc2[n][i];
}

void O32(int n)    //O+���ŵĺ��������������ռ�ʸ������(�����ٶ�����).
{
	int i,rad1,rad2;
	srand(time(0));
	rad1=rand()%9;
	rad2=rand()%9;
	for(i=rad1;i<=rad2;i++)
		v[n][i]=ptc1[n][i];
}

void O33(int n)    //O+���ŵĺ��������������ռ�ʸ������(����ptc).
{
	int i,rad1,rad2;
	srand(time(0));
	rad1=rand()%9;
	rad2=rand()%9;
	for(i=rad1;i<=rad2;i++)
		ptc[n][i]=v[n][i];
}

void calsuit_x(int n)    //����������ӵ���Ӧֵ
{
	int i,t1=0,t2=0,t3=0;
	for(i=0;i<9;i++)
	{
		if(ptc[n][i]==1)
			t1+=tim[i];
        else if(ptc[n][i]==2)
			t2+=tim[i];
		else
			t3+=tim[i];
	}
	suitx[n]=max1(t1,t2,t3);
}

void calsuit_p(int n)    //������弫ֵ���ӵ���Ӧֵ
{
	int i,t1=0,t2=0,t3=0;
	for(i=0;i<9;i++)
	{
		if(p[n][i]==1)
			t1+=tim[i];
        else if(p[n][i]==2)
			t2+=tim[i];
		else
			t3+=tim[i];
	}
	suitp[n]=max1(t1,t2,t3);
}

void calsuit_g(int n)    //����ȫ�ּ�ֵ���ӵ���Ӧֵ
{
	int i,t1=0,t2=0,t3=0;
	for(i=0;i<9;i++)
	{
		if(g[i]==1)
			t1+=tim[i];
        else if(g[i]==2)
			t2+=tim[i];
		else
			t3+=tim[i];
	}
	suitg=max1(t1,t2,t3);
}

void cmpx_p(int n)    //�Ƚ�������Ӻ͸��弫ֵ�����Ż�����ȡ����֮
{
	int i;
	if(suitx[n]<suitp[n])
	{
		for(i=0;i<9;i++)
			p[n][i]=ptc[n][i];
		suitp[n]=suitx[n];
	}
}

void cmpp_g()    //�Ƚ�������Ӻ�ȫ�ּ�ֵ�����Ż�����ȡ����֮
{
	int i,min=32767,t;
	for(i=0;i<10;i++)
		if(suitp[i]<min)
		{
			min=suitp[i];
			t=i;
		}
	if(suitp[t]<suitg)
		suitg=suitp[t];
}

int main()
{
	int i,j,k,m=100,min=32767,t;
	srand(time(0));
	for(j=0;j<10;j++)
	{
		for(k=0;k<9;k++)
		{
			ptc[j][k]=rand()%3+1;
			/*printf("%d",ptc[j][k]);*/
			p[j][k]=ptc[j][k];    //��ʼ�����弫ֵ
		}
		/*printf("\n");*/
		calsuit_p(j);
		if(suitp[j]<min)    //������弫ֵ����С��
		{
			min=suitp[j];
			t=j;
		}
	}
	suitg=suitp[t];    //�����弫ֵ����С�ĸ���ȫ�ּ�ֵ
	for(j=0;j<9;j++)
	{
		g[j]=p[t][j];
		for(k=0;k<9;k++)
			v[j][k]=rand()%3+1;    //���ٶȳ�ʼ��
	}
	/*for(j=0;j<9;j++)
		printf("%d",g[j]);*/
	printf("��%d��ѭ����ȫ�ּ�ֵ��%d\n",1,suitg);
    /*��ʼ������ֵ����������ѭ������*/
    for(i=0;i<m-1;i++)
	{
        srand(i);
		for(j=0;j<10;j++)
		{
			for(k=0;k<9;k++)
            {
				ptc[j][k]=rand()%3+1;
		    	/*printf("%d",ptc[j][k]);*/
				R1[k]=rand()%1;
				R2[k]=rand()%1;
			}
	    	/*printf("\n");*/
		}
		for(j=0;j<10;j++)
		{
			O11(j);    //p(j)(O-)ptc(j)
		    O21(j);    //ptc1(j)(O*)r1(j)
			O12(j);    //g(j)(O-)ptc(j)
			O22(j);    //ptc2(j)(O*)r2(j)
			O31(j);    //ptc1(j)(O+)ptc2(j)
			O32(j);    //ptc1(j)(O+)v(j)
			O33(j);    //v(j)(0+)ptc(j)
            calsuit_x(j);    //�����������Ӧֵ
			calsuit_p(j);    //������弫ֵ����Ӧֵ
            cmpx_p(j);    //���¸��弫ֵ
		}
        cmpp_g();    //����ȫ�ּ�ֵ
	    printf("��%d��ѭ����ȫ�ּ�ֵ��%d\n",i+2,suitg);
	}
	printf("------------------------------------------");
	printf("\n\n%d\n",suitg);
	return 0;
}