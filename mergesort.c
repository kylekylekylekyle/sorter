#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sorter.h"

//the part of merge sort where you break down the main array
info mergeSortHelper (char * type,info *array, int first, int middle, int end) {
    
    //these are the length of the split arrays
    int len1 = middle;
    int len2 = end - middle;

    //merge sort breaks the initial array down so these are temp arrays
    info* arr1;
    arr1 = (info*)malloc(len1 * sizeof(info));
    for (int i =0; i<len1; i++) {
        arr1[i] = array[i+first];
    }

    info* arr2;
    arr2 = (info*)malloc(len2 * sizeof(info));
    for (int j =0; j<len2; j++) {
        arr2[j] = array[j + middle +first];
    }

    //index of arr1, arr2, and the original array
    int x = 0;
    int y = 0;
    int z = 1;

    //breaks down the sorting part case by case
    switch(type) {
        case 'color':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->color, arr2[y]->color) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->color, arr2[y]->color) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'director_name':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->director_name, arr2[y]->director_name) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->director_name, arr2[y]->director_name) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'num_critic_for_reviews':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->num_critic_for_reviews, arr2[y]->num_critic_for_reviews) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->num_critic_for_reviews, arr2[y]->num_critic_for_reviews) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'duration':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->duration, arr2[y]->duration) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->duration, arr2[y]->duration) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'director_facebook_likes':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->director_facebook_likes, arr2[y]->director_facebook_likes) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->director_facebook_likes, arr2[y]->director_facebook_likes) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'actor_3_facebook_likes':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->actor_3_facebook_likes, arr2[y]->actor_3_facebook_likes) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->actor_3_facebook_likes, arr2[y]->actor_3_facebook_likes) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'actor_2_name':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->actor_2_name, arr2[y]->actor_2_name) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->actor_2_name, arr2[y]->actor_2_name) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'actor_1_facebook_likes':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->actor_1_facebook_likes, arr2[y]->actor_1_facebook_likes) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->actor_1_facebook_likes, arr2[y]->actor_1_facebook_likes) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'gross':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->gross, arr2[y]->gross) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->gross, arr2[y]->gross) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'genres':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->genres, arr2[y]->genres) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->genres, arr2[y]->genres) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'actor_1_name':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->actor_1_name, arr2[y]->actor_1_name) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->actor_1_name, arr2[y]->actor_1_name) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'movie_title':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->movie_title, arr2[y]->movie_title) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->movie_title, arr2[y]->movie_title) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'num_voted_users':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->num_voted_users, arr2[y]->num_voted_users) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->num_voted_users, arr2[y]->num_voted_users) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'cast_total_facebook_likes':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->cast_total_facebook_likes, arr2[y]->cast_total_facebook_likes) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->cast_total_facebook_likes, arr2[y]->cast_total_facebook_likes) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'actor_3_name':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->actor_3_name, arr2[y]->actor_3_name) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->actor_3_name, arr2[y]->actor_3_name) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'facenumber_in_poster':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->facenumber_in_poster, arr2[y]->facenumber_in_poster) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->facenumber_in_poster, arr2[y]->facenumber_in_poster) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'plot_keywords':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->plot_keywords, arr2[y]->plot_keywords) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->plot_keywords, arr2[y]->plot_keywords) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'movie_imdb_link':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->movie_imdb_link, arr2[y]->movie_imdb_link) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->movie_imdb_link, arr2[y]->movie_imdb_link) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'num_user_for_reviews':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->num_user_for_reviews, arr2[y]->num_user_for_reviews) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->num_user_for_reviews, arr2[y]->num_user_for_reviews) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'language':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->language, arr2[y]->language) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->language, arr2[y]->language) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'country':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->country, arr2[y]->country) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->country, arr2[y]->country) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'content_rating':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->content_rating, arr2[y]->content_rating) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->content_rating, arr2[y]->content_rating) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'budget':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->budget, arr2[y]->budget) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->budget, arr2[y]->budget) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'title_year':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->title_year, arr2[y]->title_year) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->title_year, arr2[y]->title_year) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'actor_2_facebook_likes':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->actor_2_facebook_likes, arr2[y]->actor_2_facebook_likes) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->actor_2_facebook_likes, arr2[y]->actor_2_facebook_likes) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'imdb_score':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->imdb_score, arr2[y]->imdb_score) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->imdb_score, arr2[y]->imdb_score) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'aspect_ratio':
           while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->aspect_ratio, arr2[y]->aspect_ratio) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->aspect_ratio, arr2[y]->aspect_ratio) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 'movie_facebook_likes':
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x]->movie_facebook_likes, arr2[y]->movie_facebook_likes) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else (strcmp(arr1[x]->movie_facebook_likes, arr2[y]->movie_facebook_likes) > 0) {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        default : printf("Invalid type to sort by\n");
    }

    //copy rest of the subarrays into main array
    while (x < len1) {
        array[z] = arr1[x];
        z++;
        x++;
    }
    while (y < len2) {
        array[z] = arr2[y];
        z++;
        y++;
    }

    free[arr1];
    free[arr2];
}

//USE THIS TO ACTUALLY USE MERGE SORT@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//format it like this:
//mergeSortMain (type, array, 0, arraySize - 1);
void mergeSortMain(char* type, info * array, int first, int end) {
    if (first < end) {
        int middle = r/2;
        //split the array
        mergeSortMain(type, array, first, middle);
        mergeSortMain(type, array, middle+1, end);

        //merge
        merge(type, array, first, middle, end);
    }
}

int main (int argc; char** argv) {
    return 0;
}