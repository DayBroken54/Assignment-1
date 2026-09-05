/*The task of oss is to launch a certain number of user processes with
particular parameters. These numbers are determined by its own command line
arguments. Your solution will be invoked using the following command:
 oss [-h] [-n proc] [-s simul] [-t iter]

The proc parameter stands for number of total
children to launch, iter is the number to pass to the user process and the simul
parameter indicates how many children to allow to run simultaneously.

For example, if I wanted to launch oss such that it would launch 5 user
processes, never allow more than 3 to be running at the same time, and then have
each of the users do 7 iterations, it would be called with: oss -n 5 -s 3 -t 7

If called with the -h parameter, it should simply output a help message
(indicating how it is supposed to be run) and then terminating.

So now that I know what parameters it should run with, what should it do? oss
when launched should go into a loop and start doing a fork() and then an exec()
call to launch user processes. However, it should only do this up to simul
number of times. In our above example, we would launch no more than 3 initially.
The oss would then wait() until one of the children had finished before
launching another. After oss has finished launching up to n processes, it should
continue running until all children that it launched have terminated. It can do
this by wait()ing a number of times based on how many children are still in the
system. Oss should output a message whenever it launches a new process. At the
end, it should also output a summary of how many children it launched.*/

int main(int argc, char *argv[]) {
  /*
  parse command-line arguments
    n: total children to launch
    s: how many children to allow simultaneously
    t: how many iterations per child
    h: display help message, terminate
    other: send error message, terminate
  */

  /*
  if arguments are invalid (n <= 0, s <= 0, t <= 0):
    send error message
    terminate
  */

  /*
  loop whle total processes launched (tpl) < n
    loop while current running processes (crp) < s and tpl < n
      fork()
      in child process:
        exec() ./user
      in parent process:
        send message that child was launched
        update crp
        update tpl

    wait for a process to finish
    update crp
*/

  /*
  loop while crp > 0
    wait for a process to finish
    update crp
*/

  // output summary of how many children launched

  return 0;
}