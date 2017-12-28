/*************************************************************************
 # File Name: generate_rand_new.c
 # Author: xiezg
 # Mail: xzghyd2008@hotmail.com 
 # Created Time: 2017-12-28 10:08:52
 # Last modified: 2017-12-28 15:30:02
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main( int argc, char ** argv )
{
    srandom( time( NULL ) );

    char filename[1024] = {0};
    int number = 1000000;

    if( argc >= 2 ){
       number = atoi( argv[1] );
    }

    snprintf( filename, sizeof(filename), "./input_%d", number );

    int fd = open( filename,  O_RDWR|O_CREAT|O_TRUNC, S_IRUSR );
    if( fd == -1 ){
        printf( "open file failed.%d\n", errno );
        return 1;
    }

    for( int i = 0;i < number; i++ ){
        int num = random();

        if( write( fd, &num, sizeof(num) ) != sizeof(num) ){
            printf( "write file failed.%d\n", errno );
            return 1;
        }
    }
    
    close( fd );

    return 0;
}


