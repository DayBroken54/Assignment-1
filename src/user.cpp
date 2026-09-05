/*The user takes in one command line argument. For example, if you were running
it directly you would call it like:
./user 5
As it is being called with the number 5, it would do 5 iterations over a loop.
So what does it do in that loop? Each iteration it will output its PID, its
parents PID, and what iteration of the loop it is in. For example, suppose its
PID is 6577, its parents PID is 6576 and it is the 3rd iteration of the loop, it
would output: USER PID:6577 PPID:6576 Iteration:3 before sleeping After doing
this output, it should do sleep(1), to sleep for one second, and then output:
USER PID:6577 PPID:6576 Iteration:3 after sleeping*/

int main(int argc, char *argv[]) {
  // parse command-line arguments
  // ensure argc == 2
  // ensure argv[1] is an integer

  // loop from 1 to argv[1] inclusive:
  // output before sleep message
  // sleep(1)
  // output after sleep message

  return 0;
}