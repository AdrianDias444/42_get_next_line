#include "get_next_line.h"


int tem_new_line(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while(str[i])
    {
        if(str[i] == '\n')
            return(1);
        i++;
    }
    return(0);
}



char *ler_ate_newline(int fd, char *resto)
{
    char *buffer;
    int bytes_lidos;

    buffer = malloc(BUFFER_SIZE + 1);
    if(!buffer)
          return (NULL);
    while(!tem_new_line(resto))
    {
        bytes_lidos = read(fd, buffer, BUFFER_SIZE);
        if (bytes_lidos <= 0)
            break;
        buffer[bytes_lidos] = '\0';
        resto = ft_strjoin(resto, buffer);
    }

    //free(buffer);
    return (resto);

}


// extrair linha
// contar até \n ou fim da string
// allocar mémoria para linha + \n + \0
// copiar conteudo
// colocar \0 no final e retornar linha


char *extrair_linha(char *resto)
{
    int i;
    int j;
    char *linha;

    i = 0;
    while(resto[i] && resto[i] != '\n')
        i++;
    linha = malloc(sizeof(char) * (i + 2));
    j = 0;
    ft_strlcpy(linha, resto, (size_t)i + 2);
    return (linha);
}



char *get_next_line(int fd)
{
    static char *resto;
    char *linha;

    resto = ler_ate_newline(fd, resto);

    if(!resto)
        return (NULL);

    linha = extrair_linha(resto);
    return (linha);
}




int main(void)
{
    char* fileName = "file.txt";

    int fd = open(fileName, O_RDWR);
   
    printf("%s", get_next_line(fd));
}


