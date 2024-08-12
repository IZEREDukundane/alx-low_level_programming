#include "main.h"

/**
 * file_error - checks for file errors
 *
 * @file_from: file_from descriptor
 * @file_to: file_to descriptor
 * @argv: argument
 *
 * Return: void
 */
void file_error(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}


/**
 * main - copies the content of a file to another file
 *
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: Always 0;
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, file_close;
	ssize_t no_letters, success_write;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	file_error(file_from, file_to, argv);

	no_letters = 1024;
	while (no_letters == 1024)
	{
		no_letters = read(file_from, buffer, 1024);
		if (no_letters == -1)
			file_error(-1, 0, argv);
		success_write = write(file_to, buffer, no_letters);
		if (success_write == -1)
			file_error(0, -1, argv);
	}

	file_close = close(file_from);
	if (file_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	file_close = close(file_to);
	if (file_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}

	return (0);
}
