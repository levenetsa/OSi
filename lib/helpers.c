#include "helpers.h"

#include <stdio.h>
ssize_t read_(int fd, void *buf, size_t count)
{
	int readed = 0;
	int tmp;
	for (;;)
	{
		tmp = read(fd, buf + readed, count - readed);	
		if (tmp == -1) return -1;
		if (tmp == 0) return readed;
		readed += tmp; 	
	}
}

ssize_t write_(int fd, void *buf, size_t count)
{
	int wrote = 0;
	int tmp;
	for (;;)
	{
		tmp = write(fd, buf + wrote, count - wrote);
		if (tmp == -1) return -1;
		if (tmp == 0) return wrote;
		wrote += tmp; 	
	}
}

ssize_t read_until(int fd, void * buf, size_t count, char delimiter)
{
	int readed = 0;
	int tmp;
	while(readed < count)
	{
		tmp = read(fd, buf + readed, 1);
		if (tmp == -1) return -1;
		if (((char*)buf)[readed] == delimiter) return readed+1;
		if (tmp == 0) return readed;
		readed += 1; 	
	}
	return count;
}
