#include <stdio.h>
#include <unistd.h>

int main( )
{
	int	result = chdir(/Users/taehykim/workspace);

	if (result == 0 )
		printf("Directory changed\n");
	else
		perror("Directory change failed\n");
}
