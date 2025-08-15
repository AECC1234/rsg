#include <iostream>
#include <math.h>
using namespace std;
#define WORD_IN_EACH_LINE 100

int main(int argc, char* argv[])
{
	int m_switch = 0;
	int len = 200;
	char* word = new char[WORD_IN_EACH_LINE]();
	time_t t = 0;
	const char* args[5] = {
		"-mode",
		"-option",
		"-save",
		"-lines",
		"-coloms"
	};

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
