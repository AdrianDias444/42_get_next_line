#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
    
    char* fileName = "file.txt";

    int fd = open(fileName, O_RDWR);
    
    if(fd == -1){
        printf("\nError Opening File!!\n");
        exit(1);
    }
    else{
        printf("\nFile %s opened sucessfully!\n", fileName);
    }

    char buffer[1024];

    int bytesRead = read(fd, buffer, sizeof(buffer));

    printf("%d bytes read!\n", bytesRead);
    // printf("File Contents: %s\n", buffer);
    
    int i = 0;
    while (i < bytesRead)
    {
        write (1, &buffer[i], 1);
        i++;
    }

    return 0;
}
