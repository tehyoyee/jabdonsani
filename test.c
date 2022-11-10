#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	pid_t	pid_child;
	int		wstatus;
	int		cnt = 1;

	pid = fork();
	if (pid == -1)
	{
		printf("프로세스 생성 실패 \n");
		return (-1);
	}
	else if (pid == 0)
	{
		printf("자식프로세스 시작\n");
		for (int i = 0; i < 5; cnt++, i++)
		{
			sleep(1);
			printf("자식프로세스 : cnt = %d\n", cnt);
		}
		return (15);
	}
	else
	{
		printf("부모프로세스 시작\n");
		for (int i = 0; i < 10; cnt++, i++)
		{
			pid_child = waitpid(pid, &wstatus, WNOHANG);
			if (pid_child != 0)				// 자식 프로세스 종료상태 감시
			{
				printf("부모프로세스 : 자식 프로세스가 종료됨.\n");
				return (0);
			}
			sleep(1);
			printf("부모프로세스 : cnt = %d\n", cnt);
		}
	}
}
