#include <MT2D/ObjectCore/Sprites.h>

void insert_score_on_display(int number, int pos_y, int pos_x, Sprite** Sprites) {
	// Based on a generic itoa code without the null termination
	unsigned char str[] = { 0,0,0,0,0,0,0,0 };
	unsigned char buffer = 0;
	int i = 0;
	int j = 0;
	int a = 0;


	/* Handle 0 explicitely, otherwise empty string is printed for 0 */
	if (number == 0)
	{
		Sprite_Render_on_Window(Sprites[0], 0, pos_x, pos_y);
		return;
	}


	// Process individual digits
	while (number != 0)
	{
		int rem = number % 10;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		number = number / 10;
		a++;
	}


	// Reverse the string
	i--;
	while (j < a) {
		Sprite_Render_on_Window(Sprites[str[i] - '0'], 0, pos_x + j * (Sprites[0]->size.X >> 1), pos_y);
		j++;
		i--;
		
	}
}