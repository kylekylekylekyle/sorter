#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sorter.h"
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

#define LINE_SIZE 1024

int isCSV(const char* name) {//0 not csv 1 csv
	int length = strlen(name);
	char extension[5];
	if (length < 4) {
		return 0;
	}
	else {
		for (int i = 0; i < 5; i++)  {
			extension[i] = name[length - 4 + i];
		}
		if (strcmp(extension, ".csv") == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
}
int notSorted(const char* name) {//0 sorted 1 not sorted
	int length = strlen(name);
	if (length < 11) {
		return 1; 
	}
	else {
		char sorted[8] = "-sorted";
		for (int i = 0; i < 7; i++) {
			if (sorted[i] != name[length - 11 + i]) {
				return 1;
			}
		}
		return 0;
	}
}

void recurse(const char *name, char * type) {
	pid_t pid;
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(name))){
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
	        char path[1024];
	        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
	            continue;
	        }
	        pid = fork();
	        if (pid == 0) {
	            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
	            recurse(path, type);
	        }
        	
        } 
        else {
        	if (pid == 0) {
        		if (isCSV(entry->d_name) == 1) {
        			if (notSorted(entry->d_name) == 1){
        				pid = fork();
        				if (pid == 0) {
        					printf("%s %d\n", entry->d_name, pid);
        					return;
        				}		
        			}
        		}
        	}
        }

    }
    wait(NULL);
    closedir(dir);
}

int main (int argc, char** argv) {
	recurse("/Users/kyleshin/Desktop/sorter", "movie_title");
	return 0;
}
