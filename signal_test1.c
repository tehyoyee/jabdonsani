// #include <stdio.h>
// #include <unistd.h>
// #include <signal.h>

// int main(void){
//     sigset_t mask,prev;

//     // sigemptyset(&mask);
//     sigaddset(&mask,SIGINT);
//     sigprocmask(SIG_BLOCK,&mask,&prev);

//     printf("SIGINT blocked.\n");
//     sleep(10);

//     printf("SIGINT unblocked.\n");
//     sigprocmask(SIG_SETMASK,&prev,0);
//     sleep(10);

//     printf("End\n");
// }
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main( void)
{
   sigset_t sigset;
   sigset_t oldset;

   // Ctrl-C를 블록화
   sigemptyset( &sigset);
   sigaddset( &sigset, SIGINT);
   sigprocmask( SIG_BLOCK, &sigset, &oldset);

   printf( "5초 동안 Ctrl-C를 블록화합니다.\n");
   for ( int count = 5; 0 < count; count--){
      printf( "discount %d\n", count);
      sleep( 1);
   }

   // 다시 Ctrl-C를 복구하면서 시그널 대기
   printf( "Ctrl-C를 사용할 수 있습니다.\n");
   sigsuspend( &oldset);

   while( 1){
      printf( "badayak.com\n");
   }
   return 0;
}