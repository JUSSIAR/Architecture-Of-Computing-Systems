#include "src/solution.h"

int main(int argc, char** argv) {

  freopen(argv[1], "r", stdin);
  freopen(argv[2], "w", stdout);

  int count;
  scanf("%d\n", &count);

  Container container;
  container.array = new Auto[count];
  container.size = count;

  for (size_t item = 0; item < count; item++) {
    input(container.array[item]);
  }

  inclusionSort(container);

  for (size_t item = 0; item < count; item++) {
    output(container.array[item]);
  }

  return 0;
}