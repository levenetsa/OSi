#include "helpers.h"
#include <unistd.h>
#include <errno.h>

void mistake()
{
	write_(STDERR_FILENO, "error", 5);
}

int main()
{
	int tmp, size_ = 4096;
	char* buf;
	tmp = read_(STDIN_FILENO, buf, size_);
	while (tmp > 0)
	{	
		if (tmp == -1) mistake();
		tmp = write_(STDOUT_FILENO, buf, tmp);
		if (tmp == -1) mistake();
		tmp = read_(STDIN_FILENO, buf, size_);
	}
	if (tmp == -1) mistake();
}
