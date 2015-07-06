#include <stdio.h>
#include <stdlib.h>
#include "ga_retas.h"

main(void)
{
	int v1[3]={-2,1,-1},v2[3]={2,-1,1},p1[3]={2,0,1},p2[3]={0,1,0};
	int res=is_Coplanar(v1,v2,p1,p2);
	if(find_Lambda(v1,v2)!=666)
	{
		printf("lambda=%d\n",find_Lambda(v1,v2));
	}else printf("Nao existe lamba valido\n");
	printf("Resmain=%d\n",res);
	if(res==1)
	{
		printf("E coplanar");		
	}else 
	{
		printf("nao e coplanar");
	}
}