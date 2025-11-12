#include "get_next_line.h"

int count_total_bytes(char *fileName)
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

int linelen(char *fileName, int total_bytes, char *buffer)
{
    int fd = open(fileName, O_RDONLY);
    int len;
    int len_max;

    len = 0;
    len_max = read(fd, buffer, total_bytes);
    while(buffer[len] != '\n' && len < total_bytes)
        len++;
    buffer[len] = '\0';
    // free(buffer);
    printf("LINE LEN: %d", len);
    return(len);
}

char *get_next_line(int fd, char *fileName)
{
    char *buffer;
    int total_bytes = count_total_bytes(fileName);
    
    buffer = malloc(total_bytes + 1);
    if(!buffer)
        return(NULL);
    linelen(fileName, total_bytes, buffer);
    
    printf("\n%s", buffer);
    return (buffer);
}

int main(void)
{
    char* fileName = "file.txt";

    int fd = open(fileName, O_RDWR);

    
    get_next_line(fd, fileName);
}