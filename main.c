#include <stdio.h>
#include <stdlib.h>
#include "ga_retas.h"

main(void)
{
	int v1[3]={0,0,0},v2[3]={0,0,0},p1[3]={0,0,0},p2[3]={0,0,0},troca=0;
	char control='0',control2='0';
	int res;
	menu_OP(p1,p2,v1,v2,1);
	do
	{		
		switch(control)
		{
			case '0': printf("Type A: x="); scanf("%d",&p1[0]); control='1'; break;
			case '1': printf("Type A: y="); scanf("%d",&p1[1]); control='2'; break;
			case '2': printf("Type A: z="); scanf("%d",&p1[2]); control='3'; break;
			case '3': printf("Type V1: x="); scanf("%d",&v1[0]); control='4'; break;
			case '4': printf("Type V1: y="); scanf("%d",&v1[1]); control='5'; break;
			case '5': printf("Type V1: z="); scanf("%d",&v1[2]); control='7';/*control2='0';*/  break;
			default: break;
		}
		menu_OP(p1,p2,v1,v2,0);
		if(control=='7'){
			switch(control2)
			{
				case '0': printf("Type B: x="); scanf("%d",&p2[0]); control2='1'; break;
				case '1': printf("Type B: y="); scanf("%d",&p2[1]); control2='2'; break;
				case '2': printf("Type B: z="); scanf("%d",&p2[2]); control2='3'; break;
				case '3': printf("Type V2: x="); scanf("%d",&v2[0]); control2='4'; break;
				case '4': printf("Type V2: y="); scanf("%d",&v2[1]); control2='5'; break;
				case '5': printf("Type V2: z="); scanf("%d",&v2[2]); control2='6'; break;
				default: break;
			}
		}
	}while(control2!='6' && control!='6');
	menu_OP(p1,p2,v1,v2,0);
	res=is_Coplanar(v1,v2,p1,p2);
	if(res)
	{
		printf("They are coplanar lines\n");
	}else
	{
		printf("They aren't coplanar lines\n");
	}


	
}