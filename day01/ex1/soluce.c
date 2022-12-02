#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "libft/includes/libft.h"

int	main(int argc, char **argv)
{
	int 	count;
	int		biggest;
	int		elf;
	int		gnl_ret;
	int		i;
	char	*gnline;
	char	**line;

	i = 0;
	count = 0;
	biggest = 0;
	elf = 1;
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
		printf("line[0] = %c\n", line[i][0]);
		if(line[i][0] != '\n')
			count += atoi(line[i]);
		if (!isdigit(line[i][0]))// == '\n')
		{
			printf("ici\n");
			if (count >= biggest)
				biggest = count;
			count = 0;
			elf++;
		}
		i++;
//		printf("count == %d, big == %d\n", count, biggest);
	}
	printf("elf == %d, calories == %d\n", elf, biggest);
}	
