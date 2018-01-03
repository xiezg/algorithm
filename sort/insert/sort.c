/*************************************************************************
 # File Name: sort.c
 # Author: xiezg
 # Mail: xzghyd2008@hotmail.com 
 # Created Time: 2017-12-28 11:17:15
 # Last modified: 2018-01-03 14:29:30
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/timeb.h>

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

    struct timeb begin_tp;
    ftime( &begin_tp );

    for( int i = 1; i < number; i++ ){
        int temp = num[i];

        for( int j = i-1; j >= 0; j-- ){
            if( temp < num[j] ){
                num[j+1] = num[j];
                num[j] = temp;
            }
        }
    }

    struct timeb end_tp;
    ftime( &end_tp );

    for( int i = 0;i < number;i++ ){
        printf( "%d\n", num[i] );
    }

    __int64_t begin_milliseconds =  begin_tp.time*1000 + begin_tp.millitm;
    __int64_t end_milliseconds =  end_tp.time*1000 + end_tp.millitm;

    printf( "time:%ld milliseconds\n", end_milliseconds - begin_milliseconds );

    return 0;
}


