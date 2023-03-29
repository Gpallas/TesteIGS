#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input_value[64];
    if (fgets(input_value, sizeof(input_value), stdin))
    {
        int result = 0;
        int last_addition = 0;
        int was_bigger_than_last = 0;

        for (char* c = input_value; *c = toupper(*c); ++c);

        for (int i = 0; i < strlen(input_value); i++)
        {
            if (input_value[i] == 'I')
            {
                if (input_value[i+1] != NULL)
                {
                    if (input_value[i+1] == 'V' || input_value[i+1] == 'X')
                    {
                        result -=1;
                    }
                    else
                    {
                        result += 1;
                    }
                }
                else
                {
                    result += 1;
                }
            }
            else if (input_value[i] == 'V')
            {
                result += 5;
            }
            else if (input_value[i] == 'X')
            {
                if (input_value[i+1] != NULL)
                {
                    if (input_value[i+1] == 'L' || input_value[i+1] == 'C')
                    {
                        result -= 10;
                    }
                    else
                    {
                        result += 10;
                    }
                }
                else
                {
                    result += 10;
                }
            }
            else if (input_value[i] == 'L')
            {
                result += 50;
            }
            else if (input_value[i] == 'C')
            {
                if (input_value[i+1] != NULL)
                {
                    if (input_value[i+1] == 'D' || input_value[i+1] == 'M')
                    {
                        result -= 100;
                    }
                    else
                    {
                        result += 100;
                    }
                }
                else
                {
                    result += 100;
                }
            }
            else if (input_value[i] == 'D')
            {
                result += 500;
            }
            else if (input_value[i] == 'M')
            {
                result += 1000;
            }
            else if (input_value[i] != '\n')
            {
                printf("Invalid number");

                return 0;
            }
        }

        printf("%d", result);
    }
    else
    {
        printf("Couldn't read input");
    }

    return 0;
}