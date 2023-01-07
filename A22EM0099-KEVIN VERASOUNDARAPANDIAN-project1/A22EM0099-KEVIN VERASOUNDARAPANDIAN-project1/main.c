#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Function Header Declaration
void showMain();
float calculateMOIcx(char, float, float);
float calculateMOIcy(char, float, float);
float calculateMOIx(char, float, float);
float calculateMOIy(char, float, float);

int main()
{
	showMain();

	return 0;
}

void showMain()
{
	char fileName[20], outputFileName[20];

	//Variables used for Read File
	int i;
	int countNumber = 0;
	char str[20];
	char str2[20];
	char str3[20];
	char characterTxt;
	float numberB, numberH;
	float valueCX, valueCY, valueX, valueY;

	//Constraint For Looping
	bool fileLoop = true;

	FILE* readFile;
	FILE* outFile;

	//Header of the Screen
	printf("----------------------------------------\n");
	printf("MOI CALCULATOR\n");
	printf("----------------------------------------\n");
	printf("INPUT:\n");

	printf("Please enter input file name: ");
	scanf("%s", &fileName);
	//printf("File Name: %s", fileName);

	//Validation for Text File
	do
	{
		readFile = fopen(fileName, "r");

		if (NULL == readFile)
		{
			fflush(stdin);
			printf("ERROR: Input file not exist...\n");
			printf("Please re-enter input file name: ");
			scanf("%s", &fileName);
		}
		else
		{
			fileLoop = false;
		}

	} while (fileLoop);

	//Open OutPut File
	printf("Please enter output file name: ");
	scanf("%s", &outputFileName);
	outFile = fopen(outputFileName,"w");
	printf("----------------------------------------\n");
	printf("OUTPUT:\n\n");

	//int c = getc(readFile);
	//for (i = 0; i < 10; i++)
	while (1)
	{
		//If read the First Line of the File
		if (i == 0)
		{
			fscanf(readFile, "%s %s %s\n", str, str2, str3);
			//fscanf(readFile,"\n");
			printf("%s %s %s MOIcx MOIcy MOIx MOIy\n", str, str2, str3);
			fprintf(outFile, "%s %s %s MOIcx MOIcy MOIx MOIy\n", str, str2, str3);
			i++;
		}
		//If read the Second Line or Above of the File
		else
		{
			fscanf(readFile, "%c %f %f\n", &characterTxt, &numberB, &numberH);

			printf("%c ", characterTxt);
			fprintf(outFile, "%c ", characterTxt);

			printf("%9.3e ", numberB);
			fprintf(outFile, "%9.3e ", numberB);

			printf("%9.3e ", numberH);
			fprintf(outFile, "%9.3e ", numberH);

			//If the Character not equal to A or B
			if (characterTxt != 'A' && characterTxt != 'B')
			{
				printf("%s \n", "\"INPUT_ERROR\"");
				fprintf(outFile, "%s \n", "\"INPUT_ERROR\"");
			}
			//If the NumberB or NumberH equal to 0
			else if (numberB == 0 || numberH == 0)
			{
				printf("%s \n", "\"INPUT_ERROR\"");
				fprintf(outFile, "%s \n", "\"INPUT_ERROR\"");
			}
			//If the NumberB or NumberH less than 0
			else if (numberB < 0 || numberH < 0)
			{
				printf("%s \n", "\"INPUT_ERROR\"");
				fprintf(outFile, "%s \n", "\"INPUT_ERROR\"");
			}
			else
			{
				//Pass those required value to the function to calculate the outcome
				valueCX = calculateMOIcx(characterTxt, numberB, numberH);
				valueCY = calculateMOIcy(characterTxt, numberB, numberH);
				valueX = calculateMOIx(characterTxt, numberB, numberH);
				valueY = calculateMOIy(characterTxt, numberB, numberH);

				//Print the Result
				printf("%9.3e ", valueX);
				printf("%9.3e ", valueY);
				printf("%9.3e ", valueCX);
				printf("%9.3e\n", valueCY);

				//Paste the Info into the Output File
				fprintf(outFile, "%9.3e ", valueX);
				fprintf(outFile, "%9.3e ", valueY);
				fprintf(outFile, "%9.3e ", valueCX);
				fprintf(outFile, "%9.3e\n", valueCY);

			}
		}

		if (feof(readFile))
		{
			break;
		}
	}

	//Closing the File
	fclose(readFile);
	fclose(outFile);
}

float calculateMOIx(char cType, float numberB, float numberH)
{
	float valueX;

	if (cType == 'A')
	{
		valueX = 1.0/12.0 * numberB * pow(numberH,3);
	}
	else if (cType == 'B')
	{
		valueX = 1.0/36.0 * numberB * pow(numberH,3);
	}

	return valueX;
}

float calculateMOIy(char cType, float numberB, float numberH)
{
	float valueY;

	if (cType == 'A')
	{
		valueY = 1.0/12.0 * pow(numberB,3) * numberH;
	}
	else if (cType == 'B')
	{
		valueY = 1.0/36.0 * pow(numberB,3) * numberH;
	}

	return valueY;
}

float calculateMOIcx(char cType, float numberB, float numberH)
{
	float valueCX;

	if (cType == 'A')
	{
		valueCX = 1.0/3.0 * numberB * pow(numberH,3);
	}
	else if (cType == 'B')
	{
		valueCX = 1.0/12.0 * numberB * pow(numberH,3);
	}

	return valueCX;
}

float calculateMOIcy(char cType, float numberB, float numberH)
{
	float valueCY;

	if (cType == 'A')
	{
		valueCY = 1.0/3.0 * pow(numberB,3) * numberH;
	}
	else if (cType == 'B')
	{
		valueCY = 1.0/12.0 * pow(numberB,3) * numberH;
	}

	return valueCY;
}

