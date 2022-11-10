// #include <stdio.h>
// #include <readline/history.h>
// #include <readline/readline.h>
// #include <string.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	*str;
// 	while(1)
// 	{
// 		str = readline("Enter the string : ");
// 		if (!strcmp(str, "exit"))
// 			break ;
// 		else
// 			printf("%s\n", str);
// 		add_history(str);
// 		// free(str);
// 	}
// 	system("leaks a.out");
// 	return (0);
// }

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	int	wstatus;
	pid_t	pid;
	pid_t	pid_child;

	pid = fork();
	if (pid == -1)
	{
		printf("자식 프로세스 생성 실패.\n");
		return (-1);
	}
	else if (pid == 0)
	{
		printf("자식 프로세스 : 3초 카운트.\n");
		for (int i = 0; i < 3; i++)
		{
			printf("%d\n", i);
			sleep(1);
		}
		return(15);
	}
	else
	{
		printf("부모프로세스 : 자식 프로세스가 끝날 때까지 대기.\n");
		pid_child = wait(&wstatus);
		printf("자식 프로세스 종료.\n");
		printf("자식 프로세스 pid = %d ,   반환값 = %d\n", pid_child, wstatus >> 8);
		printf("부모 프로세스 시작.\n");
		for (int i = 0; i < 3; i++)
		{
			printf("%d\n", i);
			sleep(1);
		}
	}
	
}