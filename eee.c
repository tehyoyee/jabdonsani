// #include <stdio.h>
// #include <unistd.h>
// #include <signal.h>

// void (*old_fun) (int);

// void sigint_handler( int signo)
// {
//    printf("Ctrl-C 키를 눌루셨죠!!\n");
//    printf("또 누르시면 종료됩니다.\n");
//    signal(SIGINT, 0);   // 또는 signal( SIGINT, SIG_DFL);
// }

// int main( void)
// {
//    old_fun = signal(SIGINT, sigint_handler);
//    while (1)
//    {
//       printf("asdf\n");
//       sleep(1);
//    }
// }

#include <signal.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdio.h> 

void sig_int(int signo);
void sig_usr(int signo);

int main()
{
    int i = 0;
    struct sigaction intsig, usrsig;

    printf("PID : %d\n", getpid());
    // SIGUSR2 시그널의 처리 ----------
    usrsig.sa_handler = sig_usr;  // 시그널 핸들러 등록
    sigemptyset(&usrsig.sa_mask); // 시그널 마스크 초기화
    usrsig.sa_flags = 0;
    if (sigaction(SIGUSR2, &usrsig, 0) == -1)
    {
        printf ("signal(SIGUSR2) error");
        return -1;
    }    
    // ---------------------------------

    // SIGINT (CTRL+C) 시그널의 처리 ---
    intsig.sa_handler = sig_int;
    sigemptyset(&intsig.sa_mask);
    intsig.sa_flags = 0;
    if (sigaction(SIGINT, &intsig, 0) == -1)
    {
        printf ("signal(SIGINT) error");
        return -1;
    }    
    // ---------------------------------

    while(1)
    {
        printf("%d\n", i);
        i++;
        sleep(1);
    }
}

void sig_int(int signo)
{
    sigset_t sigset, oldset;
    sigemptyset(&oldset);

    // SIGUSR2와 SIGUSR1은 블럭된다.
    // 이들 시그널은 핸들러가 종료되면 전달된다.
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGUSR2);
    sigaddset(&sigset, SIGUSR1);
    if (sigprocmask(SIG_BLOCK, &sigset, &oldset) < 0)
    {
        printf("sigprocmask %d error \n", signo);
    }

    // SIGINT 를 UNBLOCK 한다.
    // 핸들러가 수행중이더라도 즉시 전달된다.
   //  sigemptyset(&sigset);
   //  sigaddset(&sigset, SIGINT);
   //  if (sigprocmask(SIG_UNBLOCK, &sigset, &oldset) < 0)
   //  {
   //      printf("sigprocmask %d error \n", signo);
   //  }

    printf("sig_int\n");
    sleep(5);
}

void sig_usr(int signo)
{
    printf("sig_usr2\n");
}