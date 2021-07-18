#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <stdlib.h>

int main(void)
{
	int fd;
	int fd2;
	char *line;
	int i;
	i = 0;
	fd = open("alph", O_RDONLY);
	fd2 = open("beth", O_RDONLY);
	while (i < 20)
	{
	line = get_next_line(fd);
	printf("%s", line);
	//free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	//free(line);
	i++;
	}
	
	
	return(0);
}
