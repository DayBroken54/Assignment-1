#include <exception>
#include <iostream>
#include <string>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // parse command-line arguments
  if (argc != 2) {
    std::cerr << "Expected 1 argument but found " << argc - 1 << std::endl;
    return 1;
  }

  int iterations;

  try {
    iterations = std::stoi(argv[1]);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  // output messages
  auto pid = getpid();
  auto ppid = getppid();

  for (int i{1}; i <= iterations; ++i) {
    std::cout << "USER PID:" << pid << " PPID:" << ppid << " Iteration:" << i
              << " before sleeping" << std::endl;

    sleep(1);

    std::cout << "USER PID:" << pid << " PPID:" << ppid << " Iteration:" << i
              << " after sleeping" << std::endl;
  }

  return 0;
}