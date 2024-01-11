#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

char *get_next_line(int fd) {
	static char buffer[BUFFER_SIZE];
	char *line = NULL;
	char *newline_ptr = NULL;
	ssize_t bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	if (bytes_read <= 0) {
		return NULL;
	}

	buffer[bytes_read] = '\0';
	newline_ptr = strchr(buffer, '\n');
	if (newline_ptr) {
		*newline_ptr = '\0';
	}

	line = strdup(buffer);
	if (!line) {
		return NULL;
	}

	if (newline_ptr && *(newline_ptr + 1) != '\0') {
		memmove(buffer, newline_ptr + 1, strlen(newline_ptr + 1) + 1);
	} else {
		buffer[0] = '\0';
	}

	return line;
}