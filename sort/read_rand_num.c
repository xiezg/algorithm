/*************************************************************************
 # File Name: read_rand_num.c
 # Author: xiezg
 # Mail: xzghyd2008@hotmail.com 
 # Created Time: 2017-12-28 10:28:06
 # Last modified: 2017-12-28 15:33:16
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main( int argc, char ** argv )
{
    int fd = open( argv[1], O_RDONLY );
    if ( fd == -1 ){
        printf( "open file filed.%d\n", errno );
        return 1;
    }

    int num = 0;

    while( read( fd, &num, sizeof(num) ) == sizeof(num) ){
        printf( "%d\n", num );
    }

    close( fd );
    return 0;
}
