#include "helpers.h"
#include <unistd.h>
#include <errno.h>

int main()
{
	int tmp, size_ = 4096;
	char* buf;
	tmp = read_(STDIN_FILENO, buf, size_);
	while (tmp > 0)
	{
		tmp = write_(STDOUT_FILENO, buf, tmp);
		if (tmp == -1) perror(EACCES);
		tmp = read_(STDIN_FILENO, buf, size_);
	}
	if (tmp == -1) perror(EACCES);
}
