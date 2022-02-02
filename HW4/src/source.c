#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Auto {
    int capacity;
    int transport;
    int additional;
    double spending;
    double distance;
};

//extern void sort(struct Auto*, int);
extern double func(double*, int);

const char* names[3] = {"Car", "Bus", "Truck"};

void input(FILE* in, int size, struct Auto* container) {
    for (int item = 0; item < size; item++) {
        scanf("%d ", &container[item].capacity);
        scanf("%lf ", &container[item].spending);
        scanf("%d ", &container[item].transport);
        scanf("%d\n", &container[item].additional);
    }
}

void output(FILE* out, int size, struct Auto* container) {
    for (int item = 0; item < size; item++) {
        printf(
                "%s maxDistance = %lf\n",
                names[container[item].transport - 1],
                func(&container[item].spending, container[item].capacity)
        );
    }
}

void calc(struct Auto* container, int size) {
    for (int item = 0; item < size; item++) {
        container[item].distance = func(&container[item].spending, container[item].capacity);
    }
}

void mov(struct Auto* from, struct Auto* to) {
    to->capacity = from->capacity;
    to->transport = from->transport;
    to->additional = from->additional;
    to->spending = from->spending;
    to->distance = from->distance;
}

void sort(struct Auto* container, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && (container[j].distance < container[j - 1].distance); j--) {
            struct Auto current;
            mov(&container[j], &current);
            mov(&container[j - 1], &container[j]);
            mov(&current, &container[j - 1]);
        }
    }
}

double val1, val2;

double func1(double* x, int y) {
    val1 = (double)y;
    val2 = *x;
    return val1 * 100 / val2;
}

int main(int argc, char** argv) {
    int size;
    struct Auto* container = NULL;

    int LN = 1e9;
    double DB = 3.4;

    double c1 = clock();

    for (int i = 0; i < LN; ++i) {
        func1(&DB, i);
    }

    double c2 = clock();
    printf("%lf\n", (c2 - c1) / CLOCKS_PER_SEC);

    for (int i = 0; i < LN; ++i) {
        func(&DB, i);
    }

    double c3 = clock();
    printf("%lf\n", (c3 - c2) / CLOCKS_PER_SEC);

//    FILE* in = fopen("../tests/test-suits/generated/test1.txt", "r");
//    FILE* out = fopen("../results/generated/result1.txt", "w");
//    FILE* in = fopen(argv[1], "r");
//    FILE* out = fopen(argv[2], "w");
//
//    fscanf(in, "%d\n", &size);
//    container = malloc(sizeof(struct Auto) * size);
//    input(in, size, container);
//
//    calc(container, size);
//    sort(container, size);
//
//    output(out, size, container);
//    free(container);
//    container = NULL;
//
//    fclose(in);
//    fclose(out);

    return 0;
}

// terminal params example:
// ../tests/test-suits/generated/test1.txt ../results/generated/result1.txt
