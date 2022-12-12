#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Task 5 from presentation 5
// Messanger with threads

// Needed on github

// NOT DONE YET

#define MAX_SIZE 1000

struct info {
    char* name;
};

// Read function
void* Read (void* a) {

    struct info* dummy = (struct info*) a;

    int fd;

    if ((fd = open (dummy->name, O_RDONLY)) < 0) {
        printf("Could not open FIFO for reading\n");
        exit(-1);
    }

    char string [MAX_SIZE + 5] = {};

    while (1) {
        int size = read(fd, string, MAX_SIZE);
        printf("%s", string);
        memset(string, '\0', MAX_SIZE);
    }

    return NULL;
}

// Write function
void *Write ( void* a ) {

    struct info* dummy = ( struct info* ) a;
    int fd;

    if ((fd = open (dummy->name, O_WRONLY)) < 0) {
        printf ( "Can't open FIFO for writting\n" );
        exit ( -1 );
    }

    char string [MAX_SIZE + 5] = {};

    while (1) {
        fgets(string, MAX_SIZE, stdin);
        write(fd, string, MAX_SIZE);
        memset(string, '\0', MAX_SIZE);
    }

    return NULL;
}

int main (char argc, char* argv[]) {

    int f1, f2, res;
    size_t size;
    pthread_t thid1, thid2, mythid;

    (void)umask(0);

    // Creating fifos
    mknod ("0", S_IFIFO | 0666, 0);
    mknod ("1", S_IFIFO | 0666, 0);

    char num_read [2] = {};
    char num_write [2] = {};

    // Read/write directions for each client
    int client_id = atoi(argv [1]);
    if (client_id == 1) {
        num_read[0] = '1';
        num_write[0] = '0';
    }
    if (client_id == 2) {
        num_read[0] = '0';
        num_write[0] = '1';
    }

    pthread_t read_id, write_id;
    struct info info_read, info_write;

    info_read.name = num_read;
    info_write.name = num_write;

    // Creating threads for reading and writing
    struct info info_read, info_write;
    pthread_create(&thid1, NULL, Read, &info_read);
    pthread_create(&thid2, NULL, Write, &info_write);

    pthread_join (thid1, NULL);

    return 0;

}
