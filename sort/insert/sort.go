/*************************************************************************
 # File Name: sort.go
 # Author: xiezg
 # Mail: xzghyd2008@hotmail.com 
 # Created Time: 2018-01-10 10:24:13
 # Last modified: 2018-01-10 15:53:29
 ************************************************************************/

package main

import "io"
import "os"
import "fmt"
import "flag"
import "encoding/binary"

func main(){

    var fpath = flag.String( "fpath", "../input_10", "input file path" )
    flag.Parse()

    fi, err := os.Open( *fpath )
    if err != nil {
        fmt.Println( err )
        return
    }

    defer func(){
        fi.Close()
    }()

    array := make( []int32, 0 )

    for{
        var i int32
        if err := binary.Read( fi, binary.LittleEndian, &i ); err != nil {
            if err == io.EOF {
                break
            }

            fmt.Println( err )
            return
        }

        array = append( array, i )
    }

    fmt.Println( array )

    for i := 1; i < len( array );i++{
        key := array[i]

        for j := i-1; j >= 0; j-- {
            if array[j] > key {
                array[j+1] = array[j]
                array[j] = key
            }
        }
    }

    fmt.Println( array )
}

