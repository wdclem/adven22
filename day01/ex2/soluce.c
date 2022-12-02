#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "libft/includes/libft.h"

int	main(int argc, char **argv)
{
	int 	count;
	int		temp0 = 0;
	int		temp1 = 0;
	int		temp2 = 0;
	int		gnl_ret;
	int		i;
	char	*gnline;
	char	**line;

	i = 0;
	count = 0;
	gnl_ret = 1;
	line = (char**)malloc(sizeof(char*) * 5000 + 1);
	while(gnl_ret)
	{
		gnl_ret = get_next_line(0, &gnline);
		if (gnl_ret == 0)
			break;
		if (gnl_ret < 0)
			return(1);
		line[i] = gnline;
		i++;
	}
	printf("line[0] == %s\n", line[0]);
	printf("ici\n");
	i = 0;
	while(line[i] != NULL)
	{
		if(line[i][0] != '\n')
			count += atoi(line[i]);
		if (!isdigit(line[i][0]))// == '\n')
		{
			if (count > temp0 || count > temp1 || count > temp2)
			{
				if(temp0 <= temp1 && temp0 <= temp2)
					temp0 = count;
				else if(temp1 <= temp2 && temp1 <= temp0)
					temp1 = count;
				else if(temp2 <= temp1 && temp2 <= temp0)
					temp2 = count;
			}
			printf("count == %d temp0 == %d, temp1 == %d temp2 == %d\n", count, temp0, temp1, temp2);
			count = 0;
		}
		i++;
//		printf("count == %d, big == %d\n", count, biggest);
	}
	count = temp0 + temp1 + temp2;
	printf("count == %d temp0 == %d, temp1 == %d temp2 == %d\n", count, temp0, temp1, temp2);
}	
