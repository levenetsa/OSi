#include "helpers.h"

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
