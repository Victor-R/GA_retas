#include <stdio.h>
#include <stdlib.h>


int is_Coplanar(int* v1,int* v2,int* ponto1,int* ponto2)
{
	int v3[3],m[3][3],res=0;
	int i=0,det=0,x=0;

	for(i=0;i<3;i++)
	{
		v3[i]=ponto2[i]-ponto1[i]; // vetor entre retas OBS: se o vetor for igual o vetor nulo são coincidentes? ou já são consideradas coplanares?
	}
	for(i=0;i<3;i++)
	{
		m[0][i]=v1[i];
		m[1][i]=v2[i];    // preenche a matriz determinante
		m[2][i]=v3[i];
	}	
	do
	{
		if(x==0)
		{
			det+=v1[0]*v2[1]*v3[2];
		}else if(x==1)
		{
			det+=v1[1]*v2[2]*v3[0];		//calcula o determinando na area positiva
		}else
		{
			det+=v1[2]*v2[0]*v3[1];
		}
		x++;

	}while(x<3);
	x=0;
	do
	{
		if(x==0)
		{
			det+=(-1)*(v1[2]*v2[1]*v3[0]);
		}else if(x==1)
		{
			det+=(-1)*(v1[1]*v2[0]*v3[2]);		//calcula o determinando na area negativa
		}else
		{
			det+=(-1)*(v1[0]*v2[2]*v3[1]);
		}
		x++;
	}while(x<3);
	printf("determinante=%d\n",det);

	if(det==0) res=1;   //é coplanar
	else res=0;  // não é coplanar

	return res;
}

int aux_Escalar(int* v1,int* v2)  // calcula o escalar entre 2 vetores
{
	int res=0,i;
	for(i=0;i<3;i++)
	{
		res+=v1[i]*v2[i];
	}
}

aux_vetorial(int* v1,int* v2,int* vr)
{	
	vr[0]=(v1[1]*v2[2])+((-1)*(v1[2]*v2[1]));
	vr[1]=(v1[2]*v2[0])+((-1)*(v1[0]*v2[2]));
	vr[2]=(v1[0]*v2[1])+((-1)*(v1[1]*v2[0]));
}

int find_Lambda(int* v1,int* v2)
{
	int lbda1=0,lbda2=0,lbda3=0;
	lbda1=(int)v1[0]/v2[0];
	lbda2=(int)v1[1]/v2[1];
	lbda3=(int)v1[2]/v2[2];
	if(lbda1==lbda2 && lbda1==lbda3)	//se os 3 lambdas encontrados forem iguais entao existe um lambda válido
	{
		return lbda1;
	}
	else
	{
		return 666;   // se 666 entao o lambda não existe :D
	}
}
