#include <iostream>
#include <string>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int opt;

  int n_proc{0};
  int s_simul{0};
  int t_iter{0};
  char *t_iter_ptr{nullptr};

  // parse command-line arguments
  while ((opt = getopt(argc, argv, "n:s:t:h")) != -1) {
    try {
      switch (opt) {
      case 'n':
        n_proc = std::stoi(optarg);
        break;
      case 's':
        s_simul = std::stoi(optarg);
        break;
      case 't':
        t_iter = std::stoi(optarg);
        t_iter_ptr = optarg;
        break;
      case 'h':
        std::cout << "Usage\n\n"
                  << "\t-n: number of processes.\n"
                  << "\t-s: number of simultaneous processes\n"
                  << "\t-t: number of iterations per process\n"
                  << "\t-h: display help menu\n";
        return 0;
      default:
        std::cerr << "Invalid argument flags detected. Use -h for help. STOP"
                  << std::endl;
        return 1;
      }

    } catch (const std::exception &e) {
      std::cerr << "Invalid argument flags detected. Use -h for help. STOP"
                << std::endl;
      return 1;
    }
  }

  // check for valid argument values
  if (n_proc <= 0 || s_simul <= 0 || t_iter <= 0) {
    std::cerr << "Invalid argument values detected. Provide values greater "
                 "than 0. STOP"
              << std::endl;
    return 1;
  }

  int total_launched{0};
  int current_running{0};

  // launch processes simultaneously
  while (total_launched < n_proc) {
    while (current_running < s_simul && total_launched < n_proc) {
      auto pid = fork();

      // fork failed
      if (pid == -1) {
        std::cerr << "fork failed" << std::endl;
        return 1;
      }
      // child
      if (pid == 0) {
        execl("./user", "user", t_iter_ptr, (char *)nullptr);

        // execl failed
        std::cerr << "execl failed" << std::endl;
        return 1;
      }
      // parent
      else {
        std::cout << "child process launched" << std::endl;
        ++current_running;
        ++total_launched;
      }
    }

    int status;

    if (wait(&status) == -1) {
      std::cerr << "wait failed" << std::endl;
      return 1;
    }

    --current_running;
  }

  // wait for final processes to finish
  while (current_running > 0) {
    int status;

    if (wait(&status) == -1) {
      std::cerr << "wait failed" << std::endl;
      return 1;
    }

    --current_running;
  }

  std::cout << "total children launched: " << total_launched << std::endl;
  return 0;
}