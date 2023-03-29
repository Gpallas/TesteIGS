#include <stdio.h>
#include <stdlib.h>

#define TOTAL_LINES 3
#define TOTAL_COLUMNS 5
#define MIN_ENTRIES_RIGHT 5

void fill_slot(int slot[TOTAL_LINES][TOTAL_COLUMNS])
{
    for(int line = 0; line < TOTAL_LINES; line++)
    {
        printf("Insira os valores da linha %d:\n", (line + 1));
        for (int col = 0; col < TOTAL_COLUMNS; col++)
        {
            scanf_s("%d", &slot[line][col]);
        }
    }
    return;
}

    int main(void)
    {
        int model_entry[TOTAL_LINES][TOTAL_COLUMNS] = {{1,0,0,0,1}, {0,1,0,1,0}, {0,0,1,0,0}};
        int slot[TOTAL_LINES][TOTAL_COLUMNS] = {{0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};
        int lines = 0;
        int columns = 0;
        int count_prize = 0;

        fill_slot(slot);

        while (lines < TOTAL_LINES && count_prize < MIN_ENTRIES_RIGHT)
        {
            while (columns < TOTAL_COLUMNS)
            {
                if (slot[lines][columns] == model_entry[lines][columns])
                {
                    count_prize++;
                }
                columns++;
            }
            columns = 0;
            lines++;

            if (lines == TOTAL_LINES && count_prize < MIN_ENTRIES_RIGHT)
            {
                printf("Que pena... Mais sorte na proxima\n");

                lines = 0;
                count_prize = 0;

                fill_slot(slot);
            }
        }

        printf("Ganhou!\n");
        return (0);
    }