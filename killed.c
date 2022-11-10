#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("pid = %d\n", getpid());
	while (1)
	{
    	printf("tehyoyee\n");
		sleep(1);
	}
}
