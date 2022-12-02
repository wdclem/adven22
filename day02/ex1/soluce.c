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
	 * A X = ROCK > 1
	 * B Y = PAPER > 2
	 * C Z = SCISSORS > 3
	 */
	printf("line[0][1] == %c\n", line[0][1]);
	printf("line[0][2] == %c\n", line[0][2]);
	printf("ici\n");
	i = 0;
	while(line[i] != NULL)
	{
		if (line[i][2] == 'X')
			count += 1;
		else if (line[i][2] == 'Y')
			count += 2;
		else if (line[i][2] == 'Z')
			count += 3;
		if (line[i][2] == 'X' && line[i][0] == 'A' || line[i][2] == 'Y' && line[i][0] == 'B' || line[i][2] == 'Z' && line[i][0] == 'C')
			count += 3;
		else if (line[i][0] == 'A' && line[i][2] == 'Y')
			count += 6;
		else if (line[i][0] == 'B' && line[i][2] == 'Z')
			count += 6;
		else if (line[i][0] == 'C' && line[i][2] == 'X')
			count += 6;
		printf("count == %d\n", count);
		i++;
//		printf("count == %d, big == %d\n", count, biggest);
	}
	printf("i == %d\n", i);
	printf("count == %d\n", count);
}	
