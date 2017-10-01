#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sorter.h"

#define LINE_SIZE 1024

int main (int argc, char** argv) {
    if (argc != 3)
    {
        printf("Error, needs 3 arguments.\n");
        return 0;
    }
    if (strcmp(argv[1], "-c"))
    {
        printf("Error, needs flag -c\n");
        return 0;
    }

    //Get first row with column headers
    char a[LINE_SIZE];
    fgets(a, LINE_SIZE, stdin);
    int row = 0;
    //TODO:: FIND A WAY TO FIND THE RIGHT SIZE FOR BELOW
	size_t arrlen = 500;
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
        if (fgets(b, LINE_SIZE, stdin) == NULL)
            break;
        unsigned int letter = 0;
        int done = 0;
        //Each loop gets a new entry
        int entryindex = 0;
        for (;;)
        {
            if (done == 1)
                break;
            int entrysize = 128;
            char entry[entrysize];
            int index = 0;
            //Each loop gets a new letter
            int quotes = 0;
            for (;;)
            {
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
                    myinfo[row].color = malloc(index*sizeof(char));
                    myinfo[row].color = strdup(entry);
                case 1 :
                    myinfo[row].director_name = malloc(index*sizeof(char));
                    myinfo[row].director_name = strdup(entry);
                case 2 :
                    myinfo[row].num_critic_for_reviews = malloc(index*sizeof(char));
                    myinfo[row].num_critic_for_reviews = strdup(entry);
                case 3 :
                    myinfo[row].duration = malloc(index*sizeof(char));
                    myinfo[row].duration = strdup(entry);
                case 4 :
                    myinfo[row].director_facebook_likes = malloc(index*sizeof(char));
                    myinfo[row].director_facebook_likes = strdup(entry);
                case 5 :
                    myinfo[row].actor_3_facebook_likes = malloc(index*sizeof(char));
                    myinfo[row].actor_3_facebook_likes = strdup(entry);
                case 6 :
                    myinfo[row].actor_2_name = malloc(index*sizeof(char));
                    myinfo[row].actor_2_name = strdup(entry);
                case 7 :
                    myinfo[row].actor_1_facebook_likes = malloc(index*sizeof(char));
                    myinfo[row].actor_1_facebook_likes = strdup(entry);
                case 8 :
                    myinfo[row].gross = malloc(index*sizeof(char));
                    myinfo[row].gross = strdup(entry);
                case 9 :
                    myinfo[row].genres = malloc(index*sizeof(char));
                    myinfo[row].genres = strdup(entry);
                case 10 :
                    myinfo[row].actor_1_name = malloc(index*sizeof(char));
                    myinfo[row].actor_1_name = strdup(entry);
                case 11 :
					if (row < 20)
						printf("%d\n", index);
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
                    myinfo[row].movie_title = malloc(index*sizeof(char));
                    myinfo[row].movie_title = strdup(entry);
                case 12 :
                    myinfo[row].num_voted_users = malloc(index*sizeof(char));
                    myinfo[row].num_voted_users = strdup(entry);
                case 13 :
                    myinfo[row].cast_total_facebook_likes = malloc(index*sizeof(char));
                    myinfo[row].cast_total_facebook_likes = strdup(entry);
                case 14 :
                    myinfo[row].actor_3_name = malloc(index*sizeof(char));
                    myinfo[row].actor_3_name = strdup(entry);
                case 15 :
                    myinfo[row].facenumber_in_poster = malloc(index*sizeof(char));
                    myinfo[row].facenumber_in_poster = strdup(entry);
                case 16 :
                    myinfo[row].plot_keywords = malloc(index*sizeof(char));
                    myinfo[row].plot_keywords = strdup(entry);
                case 17 :
                    myinfo[row].movie_imdb_link = malloc(index*sizeof(char));
                    myinfo[row].movie_imdb_link = strdup(entry);
                case 18 :
                    myinfo[row].num_user_for_reviews = malloc(index*sizeof(char));
                    myinfo[row].num_user_for_reviews = strdup(entry);
                case 19 :
                    myinfo[row].language = malloc(index*sizeof(char));
                    myinfo[row].language = strdup(entry);
                case 20 :
                    myinfo[row].country = malloc(index*sizeof(char));
                    myinfo[row].country = strdup(entry);
                case 21 :
                    myinfo[row].content_rating = malloc(index*sizeof(char));
                    myinfo[row].content_rating = strdup(entry);
                case 22 :
                    myinfo[row].budget = malloc(index*sizeof(char));
                    myinfo[row].budget = strdup(entry);
                case 23 :
                    myinfo[row].title_year = malloc(index*sizeof(char));
                    myinfo[row].title_year = strdup(entry);
                case 24 :
                    myinfo[row].actor_2_facebook_likes = malloc(index*sizeof(char));
                    myinfo[row].actor_2_facebook_likes = strdup(entry);
                case 25 :
                    myinfo[row].imdb_score = malloc(index*sizeof(char));
                    myinfo[row].imdb_score = strdup(entry);
                case 26 :
                    myinfo[row].aspect_ratio = malloc(index*sizeof(char));
                    myinfo[row].aspect_ratio = strdup(entry);
                case 27 :
                    myinfo[row].movie_facebook_likes = malloc(index*sizeof(char));
                    myinfo[row].movie_facebook_likes = strdup(entry);
            }
            entryindex++;
        }
        row++;
    }

    char* type = "movie_title";
    mergeSortMain(type, myinfo, 0, row-1);
    //prints to a new file
    FILE *sorted;
    sorted = fopen("sorted_movie_dataset.csv", "w");
    fprintf(sorted, "%s", a);
    for (int i = 0; i < row; i++) {
        fprintf(sorted, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",myinfo[i].color, myinfo[i].director_name, myinfo[i].num_critic_for_reviews, myinfo[i].duration, myinfo[i].director_facebook_likes, myinfo[i].actor_3_facebook_likes, myinfo[i].actor_2_name, myinfo[i].actor_1_facebook_likes, myinfo[i].gross, myinfo[i].genres, myinfo[i].actor_1_name, myinfo[i].movie_title, myinfo[i].num_voted_users, myinfo[i].cast_total_facebook_likes, myinfo[i].actor_3_name, myinfo[i].facenumber_in_poster, myinfo[i].plot_keywords, myinfo[i].movie_imdb_link, myinfo[i].num_user_for_reviews, myinfo[i].language, myinfo[i].country, myinfo[i].content_rating, myinfo[i].budget, myinfo[i].title_year, myinfo[i].actor_2_facebook_likes, myinfo[i].imdb_score, myinfo[i].aspect_ratio, myinfo[i].movie_facebook_likes);
    }
    free(myinfo);
    return 0;
}
