#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sorter.h"
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

int isDIR(const char* name) {
	DIR* directory = opendir(name);
    if (directory != NULL)
    {
    	closedir(directory);
    	return 1;
    }
    if (errno == ENOTDIR)
    {
     return 0;
    }
    return -1;
}
int isCSV(const char* name) {
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

void recurse(const char* name, int pidCount) { //pidCount should start with 1
	pid_t pid;
	if (isDIR(name) == 1) {//is a directory
		DIR * directory;
		struct dirent * dir;
		directory = opendir(name);

		while ((dir = readdir(directory)) != NULL) {
			pid = fork();
			if (pid == 0) {//child process
				pidCount++;
				recurse(dir->d_name, pidCount);
			}
		}
		wait(NULL);
		closedir(directory);
	}
	else if (isDIR(name) == 0) {//file
		if (isCSV(name) == 1) {// if its a csv file
			pid = fork();
			if (pid == 0) {//child

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

			    char* type = argv[2];
			    mergeSortMain(type, myinfo, 0, row-1);
			    //prints to a new file
			    FILE *sorted;
			    sorted = fopen("sorted_movie_dataset.csv", "w");
			    fprintf(sorted, "%s", a);
			    for (int i = 0; i < row; i++) {
			        //printf("%s\n", myinfo[i].director_name);
			        fprintf(sorted, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",myinfo[i].color, myinfo[i].director_name, myinfo[i].num_critic_for_reviews, myinfo[i].duration, myinfo[i].director_facebook_likes, myinfo[i].actor_3_facebook_likes, myinfo[i].actor_2_name, myinfo[i].actor_1_facebook_likes, myinfo[i].gross, myinfo[i].genres, myinfo[i].actor_1_name, myinfo[i].movie_title, myinfo[i].num_voted_users, myinfo[i].cast_total_facebook_likes, myinfo[i].actor_3_name, myinfo[i].facenumber_in_poster, myinfo[i].plot_keywords, myinfo[i].movie_imdb_link, myinfo[i].num_user_for_reviews, myinfo[i].language, myinfo[i].country, myinfo[i].content_rating, myinfo[i].budget, myinfo[i].title_year, myinfo[i].actor_2_facebook_likes, myinfo[i].imdb_score, myinfo[i].aspect_ratio, myinfo[i].movie_facebook_likes);
			    }
			    fclose(sorted);
			    fclose(unsorted);
			    free(myinfo);
			    pidCount++;
			    return 0;
			}
			else if (pid > 0) {
			}

		}
	}
	return;	
}