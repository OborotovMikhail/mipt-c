#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Task 5 from presentation 5
// Messanger with processes

// Needed on github

// NOT DONE YET

int main(char argc, char* argv[]) {
    
    int MAX_SIZE = 1000;
    char* string = (char*) calloc(MAX_SIZE + 1, sizeof(char));    
    int fd, res, n;
    size_t size;
    char file1[] = "1.fifo", file2[] = "2.fifo";

    n = atoi(argv[1]);
    
    (void) umask(0);

    // Creating fifo
    mknod(file1, S_IFIFO | 0666, 0);
    mknod(file2, S_IFIFO | 0666, 0);

    // fork
    if ((res = fork()) < 0 ) {
		printf ( "Can\'t create child process\n" );
		exit (-1);
    }
    
    // Client number 1
    if ( n == 1 ) {
    	// fork() == 0
        if ( res == 0 ) {
	    	if (( fd = open ( file1, O_WRONLY )) < 0) {
	        	printf ( "Can't open 1to2 FIFO for writing!\n" );
                exit ( -1 );
	    	} else {
            	while ( 1 ) {
            		fgets ( string, MAX_SIZE, stdin );
		    		write ( fd, string, MAX_SIZE );
				}
	    	}
		} else {
		// fork() != 0
			if ((fd = open (file2, O_RDONLY)) < 0) {
            	printf ("Can't open 2to1 FIFO for reading!\n");
            	exit (-1);
        	} else {
				while (1) {
		    		read(fd, string, MAX_SIZE);
		    		printf("%s\n", string);
				}
	    	}
		}
    }
	
	// Client number 2    
    if (n == 2) {
	// fork() == 0	    
	if (res == 0) {
            if ((fd = open(file2, O_WRONLY)) < 0) {
                printf("Can't open 2to1 FIFO for writing!\n");
                exit(-1);
            } else {
                while (1) {
                    fgets (string, MAX_SIZE, stdin);
                    write (fd, string, MAX_SIZE);
                }
            }
		} else {
		// fork() != 0
            if ((fd = open(file1, O_RDONLY)) < 0) {
                printf("Can't open 1to2 FIFO for reading!\n");
                exit(-1);
            } else {
                while (1) {
                    read(fd, string, MAX_SIZE);
                    printf("%s\n", string);
                }
            }
        }
    }

    return 0;  
}