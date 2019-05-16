#include <unistd.h>
#include <stdio.h>
int main()
{
    // Linux has a maximum filename length of 255 characters for most filesystems (including EXT4), 
    // and a maximum path of 4096 characters. 
    // https://serverfault.com/questions/9546/filename-length-limits-on-linux
    char path[4096];
    getcwd(path, sizeof(path));
    printf("%s", path);
    return 0;
}

