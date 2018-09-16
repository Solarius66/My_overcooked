/*
** EPITECH PROJECT, 2017
** MY_GETNBR
** File description:
** Return an int and send in it as a string
*/

int my_getnbr(char const* str)
{
	int indexer = 0;
	int multiplier = 0;

	if (str[0] == '-')
		indexer++;
	while(str[indexer] != '\0') {
		if(str[indexer] < 57 && str[indexer] >= 48) {
			multiplier = multiplier * 10 + (str[indexer] - 48);
			indexer++;
		}
	}
	if (str[0] == '-')
		multiplier = multiplier * (-1);
	return multiplier;
}
