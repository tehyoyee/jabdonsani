#include <sys/stat.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int result;
    char *file_name;
    struct stat file_info;

    struct passwd *my_passwd;
    struct group  *my_group;

    mode_t file_mode;
    
    if (argc != 2 )
    {
        printf("Usage : ./file_info [file name]\n");
        exit(0);
    }
    file_name = argv[1];
    if ((result = stat(file_name, &file_info)) == -1)
    {
        perror("Error : ");
        exit(0);
    }

    file_mode = file_info.st_mode;
    printf("파일이름 : %s\n", file_name);
    printf("=======================================\n");
    printf("파일 타입 : ");
    if (S_ISREG(file_mode))
        printf("정규파일\n");
    else if (S_ISLNK(file_mode))
        printf("심볼릭 링크\n");
    else if (S_ISDIR(file_mode))
        printf("디렉토리\n");    
    else if (S_ISCHR(file_mode))
        printf("문자 디바이스\n");
    else if (S_ISBLK(file_mode))
        printf("블럭 디바이스\n");
    else if (S_ISFIFO(file_mode))
        printf("FIFO\n");
    else if (S_ISSOCK(file_mode))
        printf("소켓\n");

    my_passwd = getpwuid(file_info.st_uid);
    my_group  = getgrgid(file_info.st_gid);
    printf("OWNER : %s\n", my_passwd->pw_name);
    printf("GROUP : %s\n", my_group->gr_name);
    printf("FILE SIZE IS : %lld\n", file_info.st_size);
    printf("마지막 읽은 시간 : %ld\n", file_info.st_atime);
    printf("마지막 수정 시간 : %ld\n", file_info.st_mtime);
    printf("하드링크된 파일수 : %d\n", file_info.st_nlink);
}
