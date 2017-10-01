#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sorter.h"

//the part of merge sort where you break down the main array
void mergeSortHelper (char * type,info  * array, int first, int middle, int end) {
    int typeInt = -1;
    //associates type with a number
    if (strcmp(type, "color") == 0) {
    	typeInt = 0;
    }
    else if (strcmp(type, "director_name") == 0) {
    	typeInt = 1;
    }
    else if (strcmp(type, "num_critic_for_reviews") == 0) {
    	typeInt = 2;
    }
    else if (strcmp(type, "duration") == 0) {
    	typeInt = 3;
    }
    else if (strcmp(type, "director_facebook_likes") == 0) {
    	typeInt = 4;
    }
    else if (strcmp(type, "actor_3_facebook_likes") == 0) {
    	typeInt = 5;
    }
    else if (strcmp(type, "actor_2_name") == 0) {
    	typeInt = 6;
    }
    else if (strcmp(type, "actor_1_facebook_likes") == 0) {
    	typeInt = 7;
    }
    else if (strcmp(type, "gross") == 0) {
    	typeInt = 8;
    }
    else if (strcmp(type, "genres") == 0) {
    	typeInt = 9;
    }
    else if (strcmp(type, "actor_1_name") == 0) {
    	typeInt = 10;
    }
    else if (strcmp(type, "movie_title") == 0) {
    	typeInt = 11;
    }
    else if (strcmp(type, "num_voted_users") == 0) {
    	typeInt = 12;
    }
    else if (strcmp(type, "cast_total_facebook_likes") == 0) {
    	typeInt = 13;
    }
    else if (strcmp(type, "actor_3_name") == 0) {
    	typeInt = 14;
    }
    else if (strcmp(type, "facenumber_in_poster") == 0) {
    	typeInt = 15;
    }
    else if (strcmp(type, "plot_keywords") == 0) {
    	typeInt = 16;
    }
    else if (strcmp(type, "movie_imdb_link") == 0) {
    	typeInt = 17;
    }
    else if (strcmp(type, "num_user_for_reviews") == 0) {
    	typeInt = 18;
    }
    else if (strcmp(type, "language") == 0) {
    	typeInt = 19;
    }
    else if (strcmp(type, "country") == 0) {
    	typeInt = 20;
    }
    else if (strcmp(type, "content_rating") == 0) {
    	typeInt = 21;
    }
    else if (strcmp(type, "budget") == 0) {
    	typeInt = 22;
    }
    else if (strcmp(type, "title_year") == 0) {
    	typeInt = 23;
    }
    else if (strcmp(type, "actor_2_facebook_likes") == 0) {
    	typeInt = 24;
    }
    else if (strcmp(type, "imdb_score") == 0) {
    	typeInt = 25;
    }
    else if (strcmp(type, "aspect_ratio") == 0) {
    	typeInt = 26;
    }
    else if (strcmp(type, "movie_facebook_likes") == 0) {
    	typeInt = 27;
    }


    //these are the length of the split arrays
    int len1 = middle - first + 1;
    int len2 = end - middle;
    

    //merge sort breaks the initial array down so these are temp arrays
    info arr1[len1];
    for (int i =0; i<len1; i++) {
        arr1[i] = array[i+first];
    }

    info arr2[len2];
    for (int j =0; j<len2; j++) {   
        arr2[j] = array[j + middle + 1];
    }

    //index of arr1, arr2, and the original array
    int x = 0;
    int y = 0;
    int z = first;

    //breaks down the sorting part case by case
    switch(typeInt) {
        case 0:
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x].color, arr2[y].color) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 1:
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x].director_name, arr2[y].director_name) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 2:
            while (x < len1 && y < len2) {
                if (atoi(arr1[x].num_critic_for_reviews) <= atoi(arr2[y].num_critic_for_reviews)) {
                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 3:
            while (x < len1 && y < len2) {
                if (atoi(arr1[x].duration) <= atoi(arr2[y].duration)) {
                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 4:
            while (x < len1 && y < len2) {
                if (atoi(arr1[x].director_facebook_likes) <= atoi(arr2[y].director_facebook_likes)) {
                    array[z] = arr1[x];
                    x++;
                }
                else  {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 5:
            while (x < len1 && y < len2) {
                if (atoi(arr1[x].actor_3_facebook_likes) <= atoi(arr2[y].actor_3_facebook_likes)) {                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 6:
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x].actor_2_name, arr2[y].actor_2_name) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else  {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 7:
            while (x < len1 && y < len2) {
                if (atoi(arr1[x].actor_1_facebook_likes) <= atoi(arr2[y].actor_1_facebook_likes)) {
                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 8:
            while (x < len1 && y < len2) {
                if (atoi(arr1[x].gross) <= atoi(arr2[y].gross)) {
                    array[z] = arr1[x];
                    x++;
                }
                else  {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 9:
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x].genres, arr2[y].genres) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else  {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 10:
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x].actor_1_name, arr2[y].actor_1_name) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 11:
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x].movie_title, arr2[y].movie_title) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 12:
            while (x < len1 && y < len2) {
                if (atoi(arr1[x].num_voted_users) <= atoi(arr2[y].num_voted_users)) {
                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 13:
            while (x < len1 && y < len2) {
                if (atoi(arr1[x].cast_total_facebook_likes) <= atoi(arr2[y].cast_total_facebook_likes)) {
                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 14:
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x].actor_3_name, arr2[y].actor_3_name) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 15:
            while (x < len1 && y < len2) {
                if (atoi(arr1[x].facenumber_in_poster) <= atoi(arr2[y].facenumber_in_poster)) {
                    array[z] = arr1[x];
                    x++;
                }
                else  {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 16:
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x].plot_keywords, arr2[y].plot_keywords) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else  {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 17:
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x].movie_imdb_link, arr2[y].movie_imdb_link) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else  {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 18:
            while (x < len1 && y < len2) {
                if (atoi(arr1[x].num_user_for_reviews) <= atoi(arr2[y].num_user_for_reviews)) {
                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 19:
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x].language, arr2[y].language) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 20:
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x].country, arr2[y].country) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else  {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 21:
            while (x < len1 && y < len2) {
                if (strcmp(arr1[x].content_rating, arr2[y].content_rating) <= 0) {
                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 22:
            while (x < len1 && y < len2) {
                if (atoi(arr1[x].budget) <= atoi(arr2[y].budget)) {
                    array[z] = arr1[x];
                    x++;
                }
                else  {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 23:
            while (x < len1 && y < len2) {
                if (atoi(arr1[x].title_year) <= atoi(arr2[y].title_year)) {
                    array[z] = arr1[x];
                    x++;
                }
                else  {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 24:
            while (x < len1 && y < len2) {
                if (atoi(arr1[x].actor_2_facebook_likes) <= atoi(arr2[y].actor_2_facebook_likes)) {
                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 25:
            while (x < len1 && y < len2) {
                if (atof(arr1[x].imdb_score) <= atoi(arr2[y].imdb_score)) {
                    array[z] = arr1[x];
                    x++;
                }
                else {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 26:
           while (x < len1 && y < len2) {
                if (atof(arr1[x].aspect_ratio) <= atoi(arr2[y].aspect_ratio)) {
                    array[z] = arr1[x];
                    x++;
                }
                else  {
                    array[z] = arr2[y];
                    y++;
                }
                z++;
            }
            break;
        case 27:
            while (x < len1 && y < len2) {
                if (atoi(arr1[x].movie_facebook_likes) <= atoi(arr2[y].movie_facebook_likes)) {                    array[z] = arr1[x];
                    x++;
                }
                else  {
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

}

//USE THIS TO ACTUALLY USE MERGE SORT@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//format it like this:
//mergeSortMain (type, array, 0, arraySize - 1);
void mergeSortMain(char* type, info * array, int first, int end) {
    if (first < end) {
        int middle = first + (end-first)/2;
        //split the array
        mergeSortMain(type, array, first, middle);
        mergeSortMain(type, array, middle+1, end);

        //merge
        mergeSortHelper(type, array, first, middle, end);
    }
}