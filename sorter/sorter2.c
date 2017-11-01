#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include "sorter.h"

#define LINE_SIZE 1024

int status;

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
//movie_dataset-sorted-movie_title.csv
//movie_dataset.csv
//x.csv
//x-sorted-movie_dataset.csv
int notSorted(const char* name, char * type) {//0 sorted 1 not sorted
	int length = strlen(name);
	int length2 = strlen(type);
	if (length < 12+length2) {
		return 1; 
	}
	else {
		char sorted[9] = "-sorted-";
		for (int i = 0; i < 8; i++) {
			if (sorted[i] != name[length - 12 + i - length2]) {
				return 1;
			}
		}
		return 0;
	}
}

void recurse (const char* name, char* type, char* pathName, char* fileName) {
	int counter = 0;
	pid_t pid;
	DIR * dir;
	if ((dir = opendir(name)) == NULL) {
        if (isCSV(name) == 1) {
        	if (notSorted(name, type) == 1){
        		pid = fork();
        		counter++;
        		if (pid == 0) {
        			FILE *unsorted;
					unsorted = fopen(name, "r");
					size_t linesize = 40;
				    //Get first row with column headers
				    char a[LINE_SIZE];
				    fgets(a, LINE_SIZE, unsorted);
				    int row = 0;
				    //TODO:: FIND A WAY TO FIND THE RIGHT SIZE FOR BELOW
				    size_t arrlen = 200;
				    info* myinfo = malloc(arrlen*sizeof(info));
				    //Each loop gets a new row
				    for (;;)
				    {
				        if (row >= arrlen)
				        {
				            arrlen = arrlen*2;
				            myinfo = (info*)realloc(myinfo, arrlen*sizeof(info));
				        }
				        char b[LINE_SIZE];
				        if (fgets(b, LINE_SIZE, unsorted) == NULL)
				            break;
				        unsigned int letter = 0;
				        int done = 0;
				        //Each loop gets a new entry
				        int entryindex = 0;
				        for (;;)
				        {
				            if (done == 1)
				                break;
				            size_t entrysize = 8;
				            char* entry = malloc(entrysize*sizeof(char));
				            int index = 0;
				            //Each loop gets a new letter
				            int quotes = 0;
				            for (;;)
				            {
				                if (index >= entrysize)
				                {
				                    entrysize = 2*entrysize;
				                    entry = realloc(entry, entrysize*sizeof(char));
				                }
				                if (b[letter] == '\"')
				                {
				                    if (quotes == 0)
				                        quotes = 1;
				                    else 
				                        quotes = 0;
				                }
				                else if (b[letter] == ',' && quotes == 0)
				                {
				                    letter++;
				                    entry[index] = '\0';
				                    break;
				                }
				                else if (b[letter] == '\0' || b[letter] == '\n')
				                {
				                    entry[index] = '\0';
				                    done = 1;
				                    break;
				                }
				                entry[index] = b[letter];
				                letter++;
				                index++;
				            }
				    
				            switch(entryindex) {
				                case 0 :
				                    if (entry[0] == ' ')
				                    {
				                        int i = 0;
				                        while(i < index)
				                        {
				                            if (entry[i] == '\n' || entry[i] == '\0')
				                                break;
				                            entry[i] = entry[i+1];
				                            i++;
				                        }
				                    }   
				                    myinfo[row].color = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].color,entry);
				                case 1 :
				                    myinfo[row].director_name = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].director_name,entry);
				                case 2 :
				                    myinfo[row].num_critic_for_reviews = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].num_critic_for_reviews,entry);
				                case 3 :
				                    myinfo[row].duration = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].duration,entry);
				                case 4 :
				                    myinfo[row].director_facebook_likes = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].director_facebook_likes,entry);
				                case 5 :
				                    myinfo[row].actor_3_facebook_likes = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].actor_3_facebook_likes,entry);
				                case 6 :
				                    myinfo[row].actor_2_name = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].actor_2_name,entry);
				                case 7 :
				                    myinfo[row].actor_1_facebook_likes = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].actor_1_facebook_likes,entry);
				                case 8 :
				                    myinfo[row].gross = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].gross,entry);
				                case 9 :
				                    myinfo[row].genres = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].genres,entry);
				                case 10 :
				                    myinfo[row].actor_1_name = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].actor_1_name,entry);
				                case 11 :
				                    if (index > 1)
				                    {
				                        if (entry[index - 1] == '\"')
				                        {
				                            entry[index - 3] = '\"';
				                            entry[index - 2] = '\0';
				                        }
				                        else
				                        {
				                            if (index > 1)
				                                entry[index - 2] = '\0';
				                        }
				                    }
				                    myinfo[row].movie_title = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].movie_title,entry);
				                case 12 :
				                    myinfo[row].num_voted_users = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].num_voted_users,entry);
				                case 13 :
				                    myinfo[row].cast_total_facebook_likes = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].cast_total_facebook_likes,entry);
				                case 14 :
				                    myinfo[row].actor_3_name = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].actor_3_name,entry);
				                case 15 :
				                    myinfo[row].facenumber_in_poster = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].facenumber_in_poster,entry);
				                case 16 :
				                    myinfo[row].plot_keywords = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].plot_keywords,entry);
				                case 17 :
				                    myinfo[row].movie_imdb_link = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].movie_imdb_link,entry);
				                case 18 :
				                    myinfo[row].num_user_for_reviews = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].num_user_for_reviews,entry);
				                case 19 :
				                    myinfo[row].language = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].language,entry);
				                case 20 :
				                    myinfo[row].country = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].country,entry);
				                case 21 :
				                    myinfo[row].content_rating = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].content_rating,entry);
				                case 22 :
				                    myinfo[row].budget = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].budget,entry);
				                case 23 :
				                    myinfo[row].title_year = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].title_year,entry);
				                case 24 :
				                    myinfo[row].actor_2_facebook_likes = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].actor_2_facebook_likes,entry);
				                case 25 :
				                    myinfo[row].imdb_score = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].imdb_score,entry);
				                case 26 :
				                    myinfo[row].aspect_ratio = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].aspect_ratio,entry);
				                case 27 :
				                    myinfo[row].movie_facebook_likes = malloc((index+1)*sizeof(char));
				                    strcpy(myinfo[row].movie_facebook_likes,entry);
				            }
				            free(entry);
				            entryindex++;
				        }
				        row++;
				    }

				    mergeSortMain(type, myinfo, 0, row-1);


				    char newFile[1024];
				    if (strcmp(pathName, "") == 0) {
					    for (int z = 0; z < (strlen(name) - 4); z++) {
					    	newFile[z] = name[z];
					    }
					    newFile[strlen(name) - 4] = '-';
					    newFile[strlen(name) - 3] = 's';
					    newFile[strlen(name) - 2] = 'o';
					    newFile[strlen(name) - 1] = 'r';
					    newFile[strlen(name)] = 't';
					    newFile[strlen(name) + 1] = 'e';
					    newFile[strlen(name) + 2] = 'd';
					    newFile[strlen(name) + 3] = '-';
					    for (int blah = 0; blah < strlen(type); blah++) {
					    	newFile[strlen(name)+4+blah] = type[blah];
					    }
					    newFile[strlen(name) + strlen(type) + 4] = '.';
					    newFile[strlen(name) + strlen(type) + 5] = 'c';
					    newFile[strlen(name) + strlen(type) + 6] = 's';
					    newFile[strlen(name) + strlen(type) + 7] = 'v';
					    newFile[strlen(name) + strlen(type) + 8] = '\0';
					}
					else {
						for (int z = 0; z < strlen(pathName); z++) {
							newFile[z] = pathName[z];
						}
						for (int g = 0; g < strlen(fileName) - 4; g++) {
							newFile[g + strlen(pathName)] = fileName[g];
						}
						newFile[strlen(fileName) + strlen(pathName)- 4] = '-';
					    newFile[strlen(fileName) + strlen(pathName)- 3] = 's';
					    newFile[strlen(fileName) + strlen(pathName)- 2] = 'o';
					    newFile[strlen(fileName) + strlen(pathName)- 1] = 'r';
					    newFile[strlen(fileName)+ strlen(pathName)] = 't';
					    newFile[strlen(fileName) + strlen(pathName)+ 1] = 'e';
					    newFile[strlen(fileName) + strlen(pathName)+ 2] = 'd';
					    newFile[strlen(fileName) + strlen(pathName)+ 3] = '-';
					    for (int blah = 0; blah < strlen(type); blah++) {
					    	newFile[strlen(fileName)+4+blah + strlen(pathName)] = type[blah];
					    }
					    newFile[strlen(fileName) + strlen(type) + strlen(pathName) + 4] = '.';
					    newFile[strlen(fileName) + strlen(type) + strlen(pathName)+ 5] = 'c';
					    newFile[strlen(fileName) + strlen(type) + strlen(pathName)+ 6] = 's';
					    newFile[strlen(fileName) + strlen(type) + strlen(pathName)+ 7] = 'v';
					    newFile[strlen(fileName) + strlen(type) + strlen(pathName)+ 8] = '\0';
					}

				    //prints to a new file
				    FILE *sorted;
				    sorted = fopen(newFile, "w");
				    fprintf(sorted, "%s", a);
				    for (int i = 0; i < row; i++) {
				        //printf("%s\n", myinfo[i].director_name);
				        fprintf(sorted, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",myinfo[i].color, myinfo[i].director_name, myinfo[i].num_critic_for_reviews, myinfo[i].duration, myinfo[i].director_facebook_likes, myinfo[i].actor_3_facebook_likes, myinfo[i].actor_2_name, myinfo[i].actor_1_facebook_likes, myinfo[i].gross, myinfo[i].genres, myinfo[i].actor_1_name, myinfo[i].movie_title, myinfo[i].num_voted_users, myinfo[i].cast_total_facebook_likes, myinfo[i].actor_3_name, myinfo[i].facenumber_in_poster, myinfo[i].plot_keywords, myinfo[i].movie_imdb_link, myinfo[i].num_user_for_reviews, myinfo[i].language, myinfo[i].country, myinfo[i].content_rating, myinfo[i].budget, myinfo[i].title_year, myinfo[i].actor_2_facebook_likes, myinfo[i].imdb_score, myinfo[i].aspect_ratio, myinfo[i].movie_facebook_likes);
				    }
				    fclose(sorted);
				    fclose(unsorted);
				    free(myinfo);
        			return;
        		}
        		if (pid > 0) {
        			fflush(0);
        			printf("%d,", pid);
        			fflush(0);
        		}		
        	}
        	else {
        		return;
        	}
        }
        else {
        	return;
        }
	}
	else {
		struct dirent * entry;
		while ((entry = readdir(dir)) != NULL) {
	        char path[1024];
	        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
	            continue;
	        }
	        pid = fork();
	        counter++;
	        if (pid == 0) {
	            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
	            recurse(path, type, pathName, entry->d_name);
	            return;
	        }
	        if (pid > 0) {
	        	fflush(0);
	        	printf("%d,", pid);
	        	fflush(0);
	        }	
        }
	}
	for (int count = 0; count <= counter; count++) {
    	wait(NULL);
    }
    closedir(dir);
}

int main (int argc, char** argv) {
	char * pathName;
	char * name;
	char * type;
	if (argc < 3) {
		return -1;
	}
	else {
		if (argc == 3 || argc == 5 || argc == 7) {
			if (argc == 3) {

				if (strcmp(argv[1], "-c") != 0) {
					return -1;
				}
				else {
					type = argv[2];
					pathName = "";
					name = getcwd(0,0);
				}
			}
			else if (argc == 5) {
				if (strcmp(argv[1], "-c") != 0) {
					return -1;
				}
				else {
					type = argv[2];
					if (strcmp(argv[3], "-d") == 0) {
						name = argv[4];
						pathName = "";
					}
					else if (strcmp(argv[3], "-o") == 0) {
						pathName = argv[4];
						name = getcwd(0,0); 
					}
					else {
						return -1;
					}
				}
			}
			else {
				if (strcmp(argv[1], "-c") != 0) {
					return -1;
				}
				else {
					type = argv[2];
					if (strcmp(argv[3], "-d") == 0) {
						name = argv[4];
						if (strcmp(argv[5], "-o") == 0) {
							pathName = argv[6];
						}
						else {
							return -1;
						}
					}
					else {
						return -1;
					}
				}
			}
		}
		else {
			return -1;
		}
	}
	fflush(0);
	printf("%s\n", pathName);
	fflush(0);
	//printf("Initial PID: %d\n", getPid());
	fflush(0);
	printf("PIDs of all child processes: ");
	fflush(0);
	recurse(name, type, pathName, "a");
	//recurse("/Users/kyleshin/Desktop/sorter/testdirect", "movie_title", "/Users/kyleshin/Desktop/sorter/", "a");
	fflush(0);
	return 0;
}
