#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
#define WORD_IN_EACH_LINE 100

int main(int argc, char* argv[])
{
	FILE* fp = 0;
	int m_switch = 0;
	int len = 200;
	int mode = 0;
	int col = 100;
	char* word = new char[WORD_IN_EACH_LINE]();
	char* path_to_save[260] = "";
	time_t t = 0;
	bool tosave = false;
	const char* args[4] = {
		"-mode",
		"-option",
		"-save",
		"-lines",
	};
	
	for (int i = 0; i < 10, i++)
	{
		if (strcmp(argv[i], args[0]) == 0)
		{
			switch (argv[i + 1])
			{
			case "a":
				mode = 0;
				break;
			case "A":
				mode = 1;
				break;
			case "0":
				mode = 2;
				break;
			case "aA":
				mode = 3;
				break;
			case "A0":
				mode = 4;
				break;
			case "aA0":
				mode = 5;
				break;
			default:
				continue;
			}
		}
		else if (strcmp(argv[i], args[1]) == 0)
		{

		}
		else if (strcmp(argv[i], args[2]) == 0)
		{
			strcpy(path_to_save, argv[i + 1]);
			tosave = true;
		}
		else if (strcmp(argv[i], args[3]) == 0)
		{
			len = stoi(argv[i + 1], 0, 10);
		}
		else
		{

		}
	}

	srand((unsigned)time(&t));
	for (size_t i = 0; i < len; i++)
	{
		for (int i = 0; i < WORD_IN_EACH_LINE - 1; i++)
		{
			m_switch = rand() % 3;
			switch (m_switch)
			{
			case 0:
				word[i] = '0' + rand() % 10;
				break;
			case 1:
				word[i] = 'a' + rand() % 26;
				break;
			case 2:
				word[i] = 'A' + rand() % 26;
				break;
			default:
				continue;
			}
		}
		printf("%s\n", word);
	}
	return 0;
}
