#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int input, output, readfile;

    if (argc < 3)
    {
        exit (2);
    }
    
    char buffer[256];

    output = open(argv[2], O_CREAT | O_APPEND | O_RDWR);
    
    
    input = open(argv[1], O_RDONLY);
    if (input == -1)
    {
        printf("input file does not exist!!!");
        exit (2);
    }

    while ((readfile = read(input, buffer , sizeof(buffer))) > 0)
    {
        write(output, buffer, sizeof(buffer));
    }

    close(input);
    close(output);
}
