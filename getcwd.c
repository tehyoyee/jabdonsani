#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int	main(void)
{
	char path[1024];

	if (getcwd(path, 1) == NULL)
	{
		fprintf(stderr, "Error: %s\n", strerror(errno));
		return -1;
	}
	printf("dir = %s\n", path);
}
