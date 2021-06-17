#include <stdio.h>
#include <json-c/json.h>
#include <stdbool.h>
#include <string.h>
#include "constants.h"
#include "headers.h"

bool cont_now(int* counters, int* lengths, int size);

int main (int argc, char** argv)
{
    if (argc <= 1)
    {
        printf ("There needs to be at least one search term!\n");
        exit (1);
    }

    json_object *root = json_object_from_file(INDEX_JSON);
    if (root == NULL)
    {
        printf ("File: %s not found!\n", INDEX_JSON);
        return 1;
    }

    json_object *value[argc-1] ;
    int lengths[argc - 1];
    int counters[argc - 1];
    memset(counters, 0, sizeof(int) * (argc - 1));

    for (int i = 1; i < argc; i ++)
    {
        value[i-1] = json_object_object_get(root, argv[i]);
        lengths[i - 1] = json_object_array_length(value[i -1]); 
    }

    //int length_obj2 = json_object_array_length(value[1]);
    //int length_obj1 = json_object_array_length(value[0]);
    //printf ("The length of the first input thingy is %d\n", length_obj1 );
    //printf ("The length of the first input thingy is %d\n", length_obj2 );
    // int i = 0, j = 0, k = 0;
    // int answer[(length_obj1+ length_obj2)];
    // while ( (i != length_obj1) || (j != length_obj2))
    // {
    //     if (get_val(value[0], i) == get_val(value[1], j))
    //     {
    //         answer[k] = get_val(value[0], i);
    //         i++;
    //         j++;
    //         k++;
    //     }

    //     else if ((get_val(value[0], i)) < (get_val(value[1], j)))
    //     {
    //         i++;
    //     }
        
    //     else
    //     {
    //         j++;
    //     }

    //     printf ("The files containing both the inputted words are:\n");
    //     for (int l = 0; l <= k; l++ )
    //     {
    //         printf ("%d", answer[l]);
    //     }
    
    // }

    do {
        int val = get_val(value[0], counters[0]);
        int count = 1;
        // printf("The value of val: %d\n", val);

        for (int i = 1; i < argc - 1; i++) {
            // printf("The initial value of counters[%d] is %d\n", i, counters[i]);
            int posting = get_val(value[i], counters[i]); 
            // printf("Current posting for %d at index %d is %d\n", i, counters[i], posting);
            // printf("Lengths[%d] is %d", i, lengths[i]);
            while (counters[i] < lengths[i] && posting < val) {
                counters[i]++;
                posting = get_val(value[i], counters[i]);
                // printf("Current posting for %d at index %d is %d\n", i, counters[i], posting);
            }

            if (posting == val) {
                count++;
            }
        }
        
        if (count == argc - 1) {
            printf("Success: %d\n", val);
            for (int i = 0; i < argc -1; i++) {
                counters[i]++;
            }
        }
        else {
            counters[0]++;
        }
    }while(cont_now(counters, lengths, argc -1));
}

bool cont_now(int* counters, int* lengths, int size){
    
    // printf("current lengths\n");
    for (int i = 0; i < size;i ++) {
        // printf("%d ", counters[i]);
        if (counters[i] >= lengths[i]) {
            // printf("\n");
            return false;
        }
    }
    // printf("\n");
    return true;
}