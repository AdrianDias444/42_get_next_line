#include "get_next_line.h"

int count_total_bytes(char *fileName)
{
    int fd = open(fileName, O_RDONLY);

    int size_file = 0;
    int bytes_read;
    char buff[1024];
    
    while ((bytes_read = read(fd, buff, sizeof(buff))) > 0)
        size_file += bytes_read;
    printf("Total bytes of file: %d\n", size_file);
    return (size_file);
}

char* linelen(char *fileName, int size_file)
{
    int fd = open(fileName, O_RDONLY);
    int len;
    int len_max;
    char *buffer;

    buffer = malloc(size_file + 1);
    if(!buffer)
        return(NULL);
    len = 0;
    len_max = read(fd, buffer, size_file);
    while(buffer[len] != '\n' && len < size_file)
        len++;
    buffer[len] = '\0';
    // free(buffer);
    printf("LINE LEN: %d", len);
    return(buffer);
}

char *get_next_line(int fd, char *fileName)
{
    
    int total_bytes = count_total_bytes(fileName);

    printf("\nRETURNED LINE: %s", linelen(fileName, total_bytes));
    return (fileName);

}

int main(void)
{
    char* fileName = "file.txt";

    int fd = open(fileName, O_RDWR);

    
    get_next_line(fd, fileName);
}