#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    int count;
    struct node* point;
};

int main() {

    char line[256];
    int firstnum = 0;
    int secondnum = 0;

    struct node* ptr[9];

    int vars;

    scanf("%d", &vars);
    //printf("%d", vars);

    struct node* arr = (struct node*) malloc(vars * sizeof(struct node));
    if (arr == NULL) {
        printf("Memory not allocated\n");
        exit(0);
    }
    for (int j = 0; j < vars; j++) {
        arr[j].count = 0;
    }

    struct node* null;

    fgets(line, 256, stdin);

    while (fgets(line, 256, stdin)) {

			
			//printf("%s", line);
            int i = 0;
            if(line[0] == 'V') {
                
                for(i = 2; isdigit(line[i]); i++) {
                    firstnum = firstnum * 10 + line[i] - '0'; //algorithm from '@chqrlie for yellow blockquotes' on stackoverflow
                }
                // printf("%d\n", firstnum);

                if (firstnum > 9 || firstnum < 1) {
                    printf("Invalid input\n");
                    exit(0);
                }

                for(i+=2; isdigit(line[i]); i++) {
                    secondnum = secondnum * 10 + line[i] - '0'; //algorithm from '@chqrlie for yellow blockquotes' on stackoverflow
                }

                if (secondnum > vars|| secondnum < 0) {
                    printf("Invalid input\n");
                    exit(0);
                }
                // printf("%d\n", secondnum);

                if (secondnum == 0) {
                    ptr[firstnum]->count -= 1;
                    ptr[firstnum] = null;
                }
                else {
                    ptr[firstnum] = &arr[secondnum - 1];
                    arr[secondnum - 1].count+=1;
                    // printf("%d, %d\n", secondnum-1, arr[secondnum - 1].count);
                }
                firstnum = 0;
                secondnum = 0;
                i = 0;
            }
            else if (line[0] == 'L') {
                for(i = 2; isdigit(line[i]); i++) {
                    firstnum = firstnum * 10 + line[i] - '0'; //algorithm from '@chqrlie for yellow blockquotes' on stackoverflow
                }

                if (secondnum > vars|| secondnum < 0) {
                    printf("Invalid input\n");
                    exit(0);
                }

                // printf("%d\n", firstnum);
                for(i+=2; isdigit(line[i]); i++) {
                    secondnum = secondnum * 10 + line[i] - '0'; //algorithm from '@chqrlie for yellow blockquotes' on stackoverflow
                }

                if (secondnum > vars|| secondnum < 0) {
                    printf("Invalid input\n");
                    exit(0);
                }
                // printf("%d\n", secondnum);

                if (secondnum == 0) {
                    arr[firstnum - 1].point->count -= 1;
                    arr[firstnum - 1].point = null;
                }
                else {
                    arr[firstnum - 1].point = &arr[secondnum - 1];
                    arr[secondnum - 1].count+=1;
                    // printf("%d, %d\n", secondnum - 1, arr[secondnum - 1].count);
                }
                firstnum = 0;
                secondnum = 0;
                i = 0;
            }
            else {
                printf("Document format incorrect\n");
                exit(0);
            }
            

		}
        //printf("%d\n", vars);
		for (int k = 0; k < vars; k++) {
            
            //printf("%d, %d\n", k, arr[k].count);
            if (arr[k].count != 0) {
                printf("Node %d has %d incoming pointers\n", k + 1, arr[k].count);
            }
        }
        free(arr);

    return 0;
}