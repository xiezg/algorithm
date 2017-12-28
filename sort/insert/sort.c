/*************************************************************************
 # File Name: sort.c
 # Author: xiezg
 # Mail: xzghyd2008@hotmail.com 
 # Created Time: 2017-12-28 11:17:15
 # Last modified: 2017-12-28 16:40:19
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
    if( argc <3 ){
        return 1;
    }

    int fd = open( argv[1], O_RDONLY );
    if( fd == -1 ){
        return 1;
    }

    int number = atoi( argv[2] );
    int *num = (int *)malloc( sizeof(int) * number );
    int i;
    int index = 0;

    while( read( fd, &i, sizeof(i) ) == sizeof(i) && index < number ){
        num[index++] = i;
    }

    close(fd);

    for( int i = 1; i < number; i++ ){
        int temp = num[i];

        for( int j = i-1; j >= 0; j-- ){
            if( temp < num[j] ){
                num[j+1] = num[j];
                num[j] = temp;
            }
        }
    }

    for( int i = 0;i < number;i++ ){
        printf( "%d\n", num[i] );
    }

    return 0;
}


