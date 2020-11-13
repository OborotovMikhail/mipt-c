#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>


// Task 1 from presentation 9
// Program prints info about the files in the directory
// (terminal input argument)
// (adress relative to the compiled program)

// Not needed on git

// DONE

int main(int argc, char *argv[]) {

    // Opening a directory
    DIR *pDir;
    pDir = opendir (argv[1]);
    if (pDir == NULL) {
        printf ("Could not open directory %s\n", argv[1]);
        return 1;
    }

    // Printing file names
    struct dirent *pDirent;
    while ((pDirent = readdir(pDir)) != NULL) {
    	// Printing name of the file
    	printf("Name: %s\n", pDirent->d_name);

    	// Printing type of the file
        if (pDirent->d_type == DT_BLK) {
        	printf("Type: block device\n");
        }
        if (pDirent->d_type == DT_CHR) {
        	printf("Type: character device\n");
        }
        if (pDirent->d_type == DT_DIR) {
        	printf("Type: directory\n");
        }
        if (pDirent->d_type == DT_FIFO) {
        	printf("Type: named pipe (FIFO)\n");
        }
        if (pDirent->d_type == DT_LNK) {
        	printf("Type: symbolic link\n");
        }
        if (pDirent->d_type == DT_REG) {
        	printf("Type: regular file\n");
        }
        if (pDirent->d_type == DT_SOCK) {
        	printf("Type: UNIX domain socket\n");
        }
        if (pDirent->d_type == DT_UNKNOWN) {
        	printf("Type: could not be determined\n");
        }

        // Getting a pathname for the file
        char *pathname = calloc(50, sizeof(char));
        strcat(pathname, argv[1]);
        strcat(pathname, "/");
        strcat(pathname, pDirent->d_name);

        // Getting stat for the file
        struct stat *pStatbuf = calloc(1, sizeof(struct stat));
        if (stat(pathname, pStatbuf) == -1) {
        	printf("Could not get stat for [%s]\n", pathname);
        	return 2;
        }

        // Printing size of the file
        printf("Size: %ld bytes\n", pStatbuf->st_size);
		printf ("\n");

        free(pStatbuf);
    	free(pathname);
    }

    // Closing directory
    closedir (pDir);

	return 0;
}