#include <stdio.h>
#include <stdlib.h>
#include "ga_retas.h"

main(void)
{
	int v1[3]={0,0,0},v2[3]={0,0,0},p1[3]={0,0,0},p2[3]={0,0,0},v3[3],det;  //declaração de variáveis
	char control='0',control2='0';
	int res,lambda=666,i;
	menu_OP(p1,p2,v1,v2,1);  //  função de geração do menu e retas
	do
	{
		switch(control)
		{
			case '0': printf("Type A: x="); scanf("%d",&p1[0]); control='1'; break;
			case '1': printf("Type A: y="); scanf("%d",&p1[1]); control='2'; break;						//obtenção de dados da Reta 1
			case '2': printf("Type A: z="); scanf("%d",&p1[2]); control='3'; break;
			case '3': printf("Type V1: x="); scanf("%d",&v1[0]); control='4'; break;
			case '4': printf("Type V1: y="); scanf("%d",&v1[1]); control='5'; break;
			case '5': printf("Type V1: z="); scanf("%d",&v1[2]); control='7'; break;
			default: break;
		}
		menu_OP(p1,p2,v1,v2,0);
		if(control=='7'){
			switch(control2)
			{
				case '0': printf("Type B: x="); scanf("%d",&p2[0]); control2='1'; break;
				case '1': printf("Type B: y="); scanf("%d",&p2[1]); control2='2'; break;
				case '2': printf("Type B: z="); scanf("%d",&p2[2]); control2='3'; break;				//obtenção de dados da Reta 2
				case '3': printf("Type V2: x="); scanf("%d",&v2[0]); control2='4'; break;
				case '4': printf("Type V2: y="); scanf("%d",&v2[1]); control2='5'; break;
				case '5': printf("Type V2: z="); scanf("%d",&v2[2]); control2='6'; break;
				default: break;
			}
		}
	}while(control2!='6' && control!='6');
	menu_OP(p1,p2,v1,v2,0);
	for(i=0;i<3;i++)
	{
		v3[i]=p2[i]-p1[i]; // vetor entre retas
	}
	det=is_Coplanar(v1,v2,p1,p2,v3);						//Teste de coplanaridade
	printf("| %d  %d  %d |\n",v1[0],v1[1],v1[2]);
	printf("| %d  %d  %d | det=%d \n",v2[0],v2[1],v2[2],det); // Quando esta retornando o valor de dois determinantes diferentes
	printf("| %d  %d  %d |\n",v3[0],v3[1],v3[2]);
	if(det==0)
	{
		printf("\nThey are coplanar lines\n");
		lambda=find_Lambda(v1,v2);
		if(lambda!=666)
		{
			//achou lambda válido = paralelo
			printf("\nThey are parallel vectors and the K=%d \n", lambda);// os lambdas também estão dando valores errados ou sempre zero
			//Representação retas paralelas//
		    printf("\n  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		    printf("\n\n");
		    printf("  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		    printf("\n\n");
		}else
		{
			printf("Elas nao sao paralelas,entao só podem ser concorrentes\n");
			//Representação retas congruentes
		    printf("      \xDB     \xDB\n");
		    printf("       \xDB   \xDB\n");
		    printf("        \xDB \xDB\n");
		    printf("         \xDB\n");
		    printf("        \xDB \xDB\n");
		    printf("       \xDB   \xDB\n");
		    printf("      \xDB     \xDB\n");

	        aux_Escalar(v1,v2);
	        if(aux_Escalar == 0)
	        {
	            printf("Além de concorrentes elas são ortogonais");
	                        //Representação retas ortogonais//
	            printf("       \xDB\n       \xDB\n       \xDB\n  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	            printf("        \n       \xDB\n       \xDB\n");
	            printf("\n\n");
	        }
		}
	}else
	{
		printf("\nThey aren't coplanar lines\n");
		printf("So, they are reverses lines\n");
			printf("         \xDB                \xDB\n");
		    printf("          \xDB               \xDB\n");
		    printf("           \xDB              \xDB\n");
		    printf("            \xDB             \xDB\n");
		    printf("             \xDB 		  \xDB\n");
		    printf("              \xDB   	  \xDB\n");
		    printf("               \xDB          \xDB\n");
	}
}
