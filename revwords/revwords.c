#include "helpers.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char * ret;

void mistake()
{
	write_(STDERR_FILENO, "error", 5);
}

char * rev(char* buf, int tmp)
{	
	int i = 0;
	int k = tmp;
	if (buf[k-1] == ' ')
	{
		ret[k-1] = ' ';
		k--;	
	}		
	while (i < k)
	{
		ret[k - i - 1] = buf[i];
		i++;	
	}
	i=1;
	char h;
	while (i < k)
	{
		if (ret[i] == (char)92 &&((ret[i-1] == 't')||(ret[i-1] == 'n')))
		{
			h = ret[i];
			ret[i] = ret[i-1];
			ret[i-1] = h;
		}
		i++;	
	}
	return ret;
}

int main()
{
	int tmp, size_ = 4096;
	char* buf;
	ret = (char*) malloc(size_);
	buf = (char*) malloc(size_);
	tmp = read_until(STDIN_FILENO, buf, size_, ' ');
	while (tmp > 0)
	{	
		if (tmp == -1) mistake();
		tmp = write_(STDOUT_FILENO, rev(buf,tmp), tmp);
		if (tmp == -1) mistake();
		tmp = read_until(STDIN_FILENO, buf, size_, ' ');
	}
	if (tmp == -1) mistake();
}
