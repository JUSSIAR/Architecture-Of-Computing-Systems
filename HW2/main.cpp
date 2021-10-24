#include "src/solution.h"

int main(int argc, char** argv) {

  std::ifstream input;
  std::ofstream output;

  input.open(argv[1], std::ios::in);
  output.open(argv[2], std::ios::out);

  Container container;

  InteractiveController::input(input, container);
  sorting::inclusionSort(container);
  InteractiveController::output(output, container);
  
  input.close();
  output.close();

  return 0;
}