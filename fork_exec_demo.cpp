

/*
This demo is to show how fork() and exec() work together to replace the child process with a new process.
Author: Minh Luu

Demo notes:
- The child process is replaced by the simple_print binary
- The parent process waits for the child process to finish
- The parent process continues after the child process finishes
- The parent process and the child process have different process IDs
- The parent process and the child process have different return values of pid
- The parent process and the child process have different cout statements
*/
#include <iostream>

// You need these imports for fork + exec and waitpid
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork(); // Make a child process that is a carbon copy of the parent

    if (pid < 0) // When fork() fails
    {
        std::cerr << "Fork failed" << std::endl;
        return 1;
    }
    else if (pid == 0) // When fork() succeeds and we are in the child process
    {
        std::cout << "The return value of pid is " << pid << std::endl;
        // Replace the child process with the simple_print binary
        char *args[] = {const_cast<char *>("./simple_print"), nullptr};
        if (execvp(args[0], args) < 0)
        {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
        std::cout << "This is the child process" << std::endl;
    }
    else // When fork() succeeds and we are in the parent process
    {
        std::cout << "The return value of pid is " << pid << std::endl;
        std::cout << "Waiting for child process to finish..." << std::endl;
        // Wait for the child process to finish
        waitpid(pid, nullptr, 0); // wait(NULL) is the same as waitpid(pid, NULL, 0);
    } 
    return 0;
}


