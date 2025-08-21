#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
#define VERSION "1.2.0"
#define WORD_IN_EACH_LINE 100	//Max words each line!

int main(int argc, char* argv[])
{
	FILE* fp = 0;
	int m_switch = 0;
	int len = 200;
	int mode = 6;
	int col = 100;
	char* word = new char[WORD_IN_EACH_LINE]();
	char path_to_save[260] = "";
	time_t t = 0;
	bool tosave = false;
	const char* args[6] = {"-m", "-c", "-s", "-l", "-v", "-h"};		//Arguments
	
	//Detecting args and values
	for (int i = 1; i < 13; i++)
	{
		if (argv[i] == NULL) 
		{
			if (i == 1)
			{
				printf("No parameters, Exiting...\n");
				printf("Please use -h to get help.\n");
				goto end;
			}
			break;
		}

		if (strcmp(argv[i], args[0]) == 0)			//-mode a A 0 aA a0 A0 aA0
		{
			if (argv[i + 1] == NULL)
			{
				printf("No such mode, Please check your input!\n");
				goto end;
			}
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
			else
			{
				printf("No such mode, Please check your input!\n");
				goto end;
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
			if (argv[i + 1] == NULL)
			{
				printf("Please provide a number!\n");
				goto end;
			}
		}
		else if (strcmp(argv[i], args[2]) == 0)		//Save as file
		{
			if (argv[i + 1] != NULL)
			{
				strcpy(path_to_save, argv[i + 1]);
				tosave = true;
				fp = fopen(path_to_save, "w+");
				if (fp == NULL)
				{
					printf("Invalid path about %s, please check!\n", path_to_save);
					goto end;
				}
			}
			else
			{
				printf("Invalid path about %s, please check!\n", path_to_save);
				goto end;
			}
		}
		else if (strcmp(argv[i], args[3]) == 0)		//Line count to gen.
		{
			try {
				if (argv[i + 1] != NULL)
				{
					len = stoi(argv[i + 1], 0, 10);
				}
				else
				{
					printf("Please provide a number!\n");
					goto end;
				}
			} catch (const std::exception& e) {
				printf("Invalid lines value: '%s' (must be an integer).\n", argv[i + 1]);
				goto end;
			}
			if (len <= 0) {
				printf("lines must be positive\n");
				goto end;
			}
		}
		else if (strcmp(argv[i], args[4]) == 0)		//Version	
		{
			printf("Version %s Release\n", VERSION);
			goto end;
		}
		else if (strcmp(argv[i], args[5]) == 0)		//Help
		{
			printf("Usage: rsg [-m] a/A/0/aA/a0/A0/aA0(Default)\n");
			printf("           [-l] line\n");
			printf("           [-c] words_count_each_line\n");
			printf("           [-s] /path/to/your/file\n");
			printf("           [-v] version\n");
			printf("           [-h] help\n");
			goto end;
		}
		else if (i % 2 == 1)						//If the arg is not recognized
		{
			printf("No such parameter:%s, please check your input!\n", argv[i]);
			goto end;
		}
	}

	srand((unsigned)time(&t));
	for (int i = 0; i < len; i++)			//Start generation
	{
		for (int j = 0; j < col; j++)
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
		word[col] = '\0';
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
				printf("Invalid path, please check your input!");
				break;
			}
		}
	}
end:
	if (tosave && (fp != NULL)) fclose(fp);
	delete[] word;
	return 0;
}
