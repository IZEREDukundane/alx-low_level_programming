#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 *
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 * Do not create the file if it does not exist
 * If filename is NULL return -1
 * If text_content is NULL, do not add anything to the file.
 * eturn 1 if the file exists and -1 if the file does not exist
 * or if you do not have the required permissions to write the file
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_d, no_letters, success_write;

	if (filename == NULL)
		return (-1);

	file_d = open(filename, O_WRONLY | O_APPEND);

	if (!text_content)
		text_content = "";

	for (no_letters = 0; text_content[no_letters] != '\0'; no_letters++)
		;

	success_write = write(file_d, text_content, no_letters);

	if (success_write == -1)
		return (-1);

	close(file_d);

	return (1);
}
