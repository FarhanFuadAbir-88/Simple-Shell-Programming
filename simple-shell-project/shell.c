/*
 * Simple Shell - A small command-line shell written in C.
 * Designed to build and run from MSYS2 on Windows.
 *
 * Features:
 *   - Interactive prompt
 *   - cd
 *   - pwd
 *   - echo
 *   - help
 *   - history
 *   - clear
 *   - exit
 *   - External commands through the system command processor
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>

#define MAX_INPUT 1024
#define MAX_HISTORY 50

static char history[MAX_HISTORY][MAX_INPUT];
static int history_count = 0;

void print_prompt(void) {
    char cwd[512];

    if (_getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("simple-shell:%s> ", cwd);
    } else {
        printf("simple-shell> ");
    }

    fflush(stdout);
}

void add_history(const char *command) {
    if (command == NULL || command[0] == '\0') {
        return;
    }

    if (history_count < MAX_HISTORY) {
        strncpy(history[history_count], command, MAX_INPUT - 1);
        history[history_count][MAX_INPUT - 1] = '\0';
        history_count++;
    } else {
        for (int i = 1; i < MAX_HISTORY; i++) {
            strcpy(history[i - 1], history[i]);
        }

        strncpy(history[MAX_HISTORY - 1], command, MAX_INPUT - 1);
        history[MAX_HISTORY - 1][MAX_INPUT - 1] = '\0';
    }
}

void show_history(void) {
    if (history_count == 0) {
        printf("No commands in history.\n");
        return;
    }

    for (int i = 0; i < history_count; i++) {
        printf("%2d  %s\n", i + 1, history[i]);
    }
}

void show_help(void) {
    printf("\nSimple Shell - available commands\n");
    printf("----------------------------------\n");
    printf("cd <dir>       Change the current directory\n");
    printf("pwd            Print the current directory\n");
    printf("echo <text>    Print text\n");
    printf("history        Show previously entered commands\n");
    printf("clear          Clear the terminal screen\n");
    printf("help           Show this help message\n");
    printf("exit           Close the shell\n");
    printf("<command>      Run an external command\n\n");
}

int handle_builtin(char *input) {
    char buffer[MAX_INPUT];
    char *command;
    char *argument;

    strncpy(buffer, input, MAX_INPUT - 1);
    buffer[MAX_INPUT - 1] = '\0';

    command = strtok(buffer, " \t");

    if (command == NULL) {
        return 1;
    }

    if (strcmp(command, "exit") == 0) {
        return 0;
    }

    if (strcmp(command, "help") == 0) {
        show_help();
        return 1;
    }

    if (strcmp(command, "history") == 0) {
        show_history();
        return 1;
    }

    if (strcmp(command, "pwd") == 0) {
        char cwd[512];

        if (_getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s\n", cwd);
        } else {
            perror("pwd");
        }

        return 1;
    }

    if (strcmp(command, "clear") == 0) {
        system("cls");
        return 1;
    }

    if (strcmp(command, "echo") == 0) {
        argument = strtok(NULL, "");

        if (argument != NULL) {
            printf("%s\n", argument);
        } else {
            printf("\n");
        }

        return 1;
    }

    if (strcmp(command, "cd") == 0) {
        argument = strtok(NULL, "");

        if (argument == NULL) {
            printf("Usage: cd <directory>\n");
        } else if (_chdir(argument) != 0) {
            perror("cd");
        }

        return 1;
    }

    return -1; /* Not a built-in command. */
}

int main(void) {
    char input[MAX_INPUT];

    printf("============================================\n");
    printf("           SIMPLE SHELL - C PROJECT         \n");
    printf("============================================\n");
    printf("Type 'help' to see available commands.\n\n");

    while (1) {
        int result;

        print_prompt();

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nGoodbye!\n");
            break;
        }

        input[strcspn(input, "\r\n")] = '\0';

        if (input[0] == '\0') {
            continue;
        }

        add_history(input);

        result = handle_builtin(input);

        if (result == 0) {
            printf("Goodbye!\n");
            break;
        }

        if (result == -1) {
            int exit_code = system(input);

            if (exit_code == -1) {
                printf("Could not execute command.\n");
            }
        }
    }

    return 0;
}
