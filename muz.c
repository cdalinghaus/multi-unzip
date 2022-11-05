#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int system(const char *command);
char *strcat(char *dest, const char *src);

int endsWith(char *string, char *end) {
    string = strrchr(string, '.');

    if( string != NULL )
        return( strcmp(string, end) );

    return( -1 );
}

int main(int argc, char *argv[]) {

    if(argc <= 1) {
        printf("Please specify an archive for input");
        return 1;
    }

    char cmd[1024];
    cmd[0] = '\0';

    // .zip archive
    if(endsWith(argv[1], "zip")) {
        strcat(cmd, "unzip ");
        strcat(cmd, argv[1]);

        system(cmd);
        return 0;
    }

    // .tar.gz
    if(endsWith(argv[1], "tar.gz")) {
        strcat(cmd, "tar -zxvf ");
        strcat(cmd, argv[1]);

        system(cmd);
        return 0;
    }

    // .gz
    if(endsWith(argv[1], "gz")) {
        strcat(cmd, "gzip -d ");
        strcat(cmd, argv[1]);

        system(cmd);
        return 0;
    }

}
