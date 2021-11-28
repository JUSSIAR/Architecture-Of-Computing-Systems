#include <stdio.h>
#include <stdlib.h>

struct X {
    int x;
    char y;
};

extern char sort(struct X*);

int main()
{
    printf("\n\n%d\n\n", sizeof (struct X));

    struct X* arr = malloc(sizeof(struct X) * 5);
    char* s = "bdcea";
    int i[5] = {2, 4, 3, 5, 1};
    for (int g = 0; g < 5; ++g) {
        arr[g].x = i[g];
        arr[g].y = s[g];
    }

    printf("\n\n%c\n\n", sort(arr));

//    printf("\n\n\n");
//    for (int g = 0; g< l; g++) {
//        printf("%c", s[g]);
//    }
//    printf("\n\n\n");

    return 0;
}
