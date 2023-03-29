#include <stdio.h>
#include <errno.h>

int main()
{
	FILE *file_pointer;
	errno_t err;
	if ((err = fopen_s(&file_pointer, "strings_01.txt", "r")) != 0)
	{
		printf("Unable to read file.");
	}
	else
	{
		int current_line = 0;
		int current_index = 1;
		int biggest_length = 0;
		int offset = 1;
		int found_palindrome = 0;

		char line_read[150];

		while (fgets(line_read, sizeof(line_read), file_pointer) != NULL)
		{
			current_index = 1;
			biggest_length = 0;

			while (line_read[current_index] != NULL)
			{
				offset = 1;
				found_palindrome = 0;

				while (!((line_read[current_index+offset] == NULL) || offset < 0))
				{
					if (line_read[current_index+offset] == line_read[current_index-offset])
					{
						found_palindrome = 1;
						offset++;
					}
					else
					{
						break;
					}
				}

				if (found_palindrome)
				{
					biggest_length = (biggest_length > 1+(offset-1)*2) ? biggest_length : 1+(offset-1)*2;
				}

				current_index++;
			}

			if (biggest_length > 0)
			{
				printf ("The biggest palindrome found in line %d had %d letters\n", current_line, biggest_length);
			}
			else
			{
				printf("0\n");
			}

			current_line++;
		}

		fclose(file_pointer);
	}

	return 0;
}