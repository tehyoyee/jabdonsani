#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd = open("asdf.txt", O_RDONLY);
	printf("%d\n", isatty(fd));
}
