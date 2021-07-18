#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.c"
#include "get_next_line_utils.c"


int main(void)
{
	int fd;
	int fd2;
	int i;
	i = 0;

	fd = open("alph", O_RDONLY);
	fd2 = open("beth", O_RDONLY);
	while(i < 20)
	{
	printf("%s", (get_next_line(fd)));
	printf("%s", (get_next_line(fd2)));
	i++;
	}
	return(0);
}
