#include"../srcs/get_next_line.c"
#include<stdio.h>
int main()
{
	int fd;
	char *line;
	fd = open("file.txt", O_RDWR);
	for (int i = 0; i < 3; i++)
	{
		line = get_next_line(fd);
		printf("%s", line); 
	}
	
	
	close(fd);
}