#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void transition_color(uint32_t initial_color, uint32_t target_color, int steps)
{
	int difference = (target_color - initial_color);
	difference = difference/(256*256);

	int value_per_step = difference/steps;
	int remmaining = difference%steps;
	int value_to_add;
	uint32_t current_color = initial_color;

	for (int i = 1; i <= steps; i++)
	{
		if (remmaining > 0)
		{
			value_to_add = (value_per_step+1)*256*256;
			remmaining--;
		}
		else if (remmaining < 0)
		{
			value_to_add = (value_per_step-1)*256*256;
			remmaining++;
		}
		else
		{
			value_to_add = value_per_step*256*256;
		}

		current_color += value_to_add;

		printf("%08" PRIx32 "\n", current_color);
	}
}

int main()
{
	uint32_t initial_color = 0x00001A;
	uint32_t final_color = 0xFF001A;


	transition_color(initial_color, final_color, 3);

	return 0;
}