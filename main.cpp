#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
#define WORD_IN_EACH_LINE 100	//Max words each line!

int main(int argc, char* argv[])
{
	FILE* fp = 0;
	int m_switch = 0;
	int len = 200;
	int mode = 5;
	int col = 100;
	char* word = new char[WORD_IN_EACH_LINE]();
	char write[100] = "";
	char path_to_save[260] = "";
	time_t t = 0;
	bool tosave = false;
	const char* args[4] = {						//Args
		"-mode",
		"-column",
		"-save",
		"-lines",
	};
	
	//Detecting args and values
	for (int i = 1; i < 11; i++)
	{
		if (argv[i] == NULL) 
		{
			if (i == 1)
			{
				printf("Please input at least one synax to run, exiting!\n");
				printf("Usage: rsg [-mode] a/A/0/aA/a0/A0/aA0(Default)\n");
				printf("           [-lines] line\n");
				printf("           [-column] words_count_each_line\n");
				printf("           [-save] /path/to/your/file\n");
				goto end;
			}
			break;
		}
		else if (i % 2 == 1)
		{
			if (argv[i + 1] == NULL)
			{
				printf("Synax error, Please check your input!\n");
				printf("Usage: rsg [-mode] a/A/0/aA/a0/A0/aA0(Default)\n");
				printf("           [-lines] line\n");
				printf("           [-column] words_count_each_line\n");
				printf("           [-save] /path/to/your/file\n");
				goto end;
			}
		}

		if (strcmp(argv[i], args[0]) == 0)			//-mode a A 0 aA a0 A0 aA0
		{
			if (strcmp(argv[i + 1], "a") == 0)
			{
				mode = 0;
			}
			else if (strcmp(argv[i + 1], "A") == 0)
			{
				mode = 1;
			}
			else if (strcmp(argv[i + 1], "0") == 0)
			{
				mode = 2;
			}
			else if (strcmp(argv[i + 1], "aA") == 0)
			{
				mode = 3;
			}
			else if (strcmp(argv[i + 1], "a0") == 0)
			{
				mode = 4;
			}
			else if (strcmp(argv[i + 1], "A0") == 0)
			{
				mode = 5;
			}
			else if (strcmp(argv[i + 1], "aA0") == 0)
			{
				mode = 6;
			}
		}
		else if (strcmp(argv[i], args[1]) == 0)		//Word counts each line
		{
			try 
			{
				col = stoi(argv[i + 1], 0, 10);
			}
		       	catch (const std::exception& e) 
			{
				printf("Invalid column value: '%s' (must be an integer).\n", argv[i + 1]);
				goto end;
			}
			if (col <= 0 || col > WORD_IN_EACH_LINE)
			{
				printf("column must be between 1 and %d\n", WORD_IN_EACH_LINE);
				goto end;
			}
		}
		else if (strcmp(argv[i], args[2]) == 0)		//Save as file
		{
			strcpy(path_to_save, argv[i + 1]);
			tosave = true;
			fp = fopen(path_to_save, "w+");
		}
		else if (strcmp(argv[i], args[3]) == 0)		//Line count to gen.
		{
			try {
				len = stoi(argv[i + 1], 0, 10);
			} catch (const std::exception& e) {
				printf("Invalid lines value: '%s' (must be an integer).\n", argv[i + 1]);
				goto end;
			}
			if (len <= 0) {
				printf("lines must be positive\n");
				goto end;
			}
		}
	}

	srand((unsigned)time(&t));
	for (size_t i = 0; i < len; i++)		//Start generation
	{
		for (int j = 0; j < col - 1; j++)
		{
			switch (mode)			//Switch Generating mode
			{
			case 0:
				m_switch = 1;
				break;
			case 1:
				m_switch = 2;
				break;
			case 2:
				m_switch = 0;
				break;
			case 3:
				m_switch = rand() % 2 + 1;
				break;
			case 4:
				m_switch = rand() % 2;
				break;
			case 5:
				m_switch = (rand() % 2) * 2;
				break;
			case 6:
				m_switch = rand() % 3;
				break;
			default:
				break;
			}

			switch (m_switch)		//Essential Codes!
			{
			case 0:
				word[j] = '0' + rand() % 10;
				break;
			case 1:
				word[j] = 'a' + rand() % 26;
				break;
			case 2:
				word[j] = 'A' + rand() % 26;
				break;
			default:
				continue;
			}
		}
		if (!tosave)
		{
			printf("%s\n", word);
		}
		else
		{
			if (fp != NULL)
			{
				fwrite(word, 1, col, fp);
				fwrite("\n", 1, 1, fp);
			}
			else
		       	{
				break;
			}
		}
	}
end:
	if (tosave && (fp != NULL)) fclose(fp);
	delete[] word;
	return 0;
}
