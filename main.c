
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int number;
    char title[50];
};

int main(void) {
    int i;
    struct Book **bookshelf;

    // Allocate memory for 3 Book pointers
    bookshelf = (struct Book **)malloc(3 * sizeof(struct Book *));

    if (bookshelf == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    // Allocate memory for 10 Book structures for each pointer
    for (i = 0; i < 3; i++) {
        bookshelf[i] = (struct Book *)malloc(10 * sizeof(struct Book));

        if (bookshelf[i] == NULL) {
            printf("Memory allocation error\n");

            // Free previously allocated memory
            while (i > 0) {
                free(bookshelf[--i]);
            }

            free(bookshelf);
            return 1;
        }
    }

    // Store book information
    bookshelf[1][3].number = 5;
    strcpy(bookshelf[1][3].title, "C++ Programming");

    (bookshelf[2] + 4)->number = 3;
    strcpy((bookshelf[2] + 4)->title, "Communications Theory");

    // Print book information
    printf("Book (1,3): %d, %s\n",
        (bookshelf[1] + 3)->number,
        (bookshelf[1] + 3)->title);

    printf("Book (2,4): %d, %s\n",
        bookshelf[2][4].number,
        bookshelf[2][4].title);

    // Free allocated memory
    for (i = 0; i < 3; i++) {
        free(bookshelf[i]);
    }

    free(bookshelf);

    return 0;
}
