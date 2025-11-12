#include "get_next_line.h"

int count_total_bytes(/*int fd, */char *fileName)
{
    int fd = open(fileName, O_RDONLY);

    int total_bytes = 0;
    int bytes_read;
    char buff[1024];
    
    while ((bytes_read = read(fd, buff, sizeof(buff))) > 0)
        total_bytes += bytes_read;
    printf("Total bytes of file: %d\n", total_bytes);
    return (total_bytes);
}


char *get_next_line(int fd, char *fileName)
{
    char *buffer;
    int len = 0;
    int total_bytes = count_total_bytes(/*fd, */fileName);
    int len_max;
    
    buffer = malloc(total_bytes + 1);
    if(!buffer)
        return(NULL);
    len_max = read(fd, buffer, total_bytes);
    while(buffer[len] != '\n' && len < total_bytes)
        len++;
    buffer[len] = '\0';    
    return (buffer);
}

int main(void)
{
    char* fileName = "file.txt";

    int fd = open(fileName, O_RDWR);
   
    printf("%s", get_next_line(fd, fileName));
}