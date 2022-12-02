#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "libft/includes/libft.h"

int	main(int argc, char **argv)
{
	int 	count;
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
	/* 
	 * A  = ROCK > 1
	 * B  = PAPER > 2
	 * C  = SCISSORS > 3
	 * X = LOOSE
	 * Y = DRAW
	 * X = WIN
	 */
	printf("line[0][1] == %c\n", line[0][1]);
	printf("line[0][2] == %c\n", line[0][2]);
	printf("ici\n");
	i = 0;
	while(line[i] != NULL)
	{
		if (line[i][2] == 'Y')
		{
			if(line[i][0] == 'A')
				count += 1;
			else if(line[i][0] == 'B')
				count += 2;
			else if(line[i][0] == 'C')
				count += 3;
			count += 3;
		}
		else if (line[i][2] == 'Z')
		{
			if(line[i][0] == 'A')
				count += 2;
			else if(line[i][0] == 'B')
				count += 3;
			else if(line[i][0] == 'C')
				count += 1;
			count += 6;
		}
		else if (line[i][2] == 'X')
		{
			if(line[i][0] == 'A')
				count += 3;
			else if(line[i][0] == 'B')
				count += 1;
			else if(line[i][0] == 'C')
				count += 2;
		}
		printf("count == %d\n", count);
		i++;
//		printf("count == %d, big == %d\n", count, biggest);
	}
	printf("i == %d\n", i);
	printf("count == %d\n", count);
}	
