#include "main.h"

int splitCommands(data_shell *dataShell, char *inputString);
char **tokenizeString(char *inputString);
void goToNext(sep_list **separatorList,
		line_list **lineList, data_shell *dataShell);
void addSeparatorsAndLines(sep_list **separatorListHead,
		line_list **lineListHead, char *inputString);
char *swapChars(char *inputString, int swapType);

/**
 * swapChars - swaps | and & for non-printed chars
 *
 * @inputString: input string
 * @swapType: type of swap
 * Return: swapped string
 */
char *swapChars(char *inputString, int swapType)
{
	int i;

	if (swapType == 0)
	{
		for (i = 0; inputString[i]; i++)
		{
			if (inputString[i] == '|')
			{
				if (inputString[i + 1] != '|')
					inputString[i] = 16;
				else
					i++;
			}

			if (inputString[i] == '&')
			{
				if (inputString[i + 1] != '&')
					inputString[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; inputString[i]; i++)
		{
			inputString[i] = (inputString[i] == 16 ? '|' : inputString[i]);
			inputString[i] = (inputString[i] == 12 ? '&' : inputString[i]);
		}
	}
	return (inputString);
}

/**
 * addSeparatorsAndLines - add separators and command lines in the lists
 *
 * @separatorListHead: head of separator list
 * @lineListHead: head of command lines list
 * @inputString: input string
 * Return: no return
 */
void addSeparatorsAndLines(sep_list **separatorListHead,
		line_list **lineListHead, char *inputString)
{
	int i;
	char *line;

	inputString = swapChars(inputString, 0);

	for (i = 0; inputString[i]; i++)
	{
		if (inputString[i] == ';')
			addSeparatorNodeAtEnd(separatorListHead, inputString[i]);

		if (inputString[i] == '|' || inputString[i] == '&')
		{
			addSeparatorNodeAtEnd(separatorListHead, inputString[i]);
			i++;
		}
	}

	line = tokenizeString(inputString, ";|&");
	do {
		line = swapChars(line, 1);
		addLineNodeAtEnd(lineListHead, line);
		line = tokenizeString(NULL, ";|&");
	} while (line != NULL);
}

/**
 * goToNext - go to the next command line stored
 *
 * @separatorList: separator list
 * @lineList: command line list
 * @dataShell: data structure
 * Return: no return
 */
void goToNext(sep_list **separatorList, line_list **lineList,
		data_shell *dataShell)
{
	int loopSeparator;
	sep_list *listSeparator;
	line_list *listLine;

	loopSeparator = 1;
	listSeparator = *separatorList;
	listLine = *lineList;

	while (listSeparator != NULL && loopSeparator)
	{
		if (dataShell->status == 0)
		{
			if (listSeparator->separator == '&' || listSeparator->separator == ';')
				loopSeparator = 0;
			if (listSeparator->separator == '|')
				listLine = listLine->next, listSeparator = listSeparator->next;
		}
		else
		{
			if (listSeparator->separator == '|' || listSeparator->separator == ';')
				loopSeparator = 0;
			if (listSeparator->separator == '&')
				listLine = listLine->next, listSeparator = listSeparator->next;
		}
		if (listSeparator != NULL && !loopSeparator)
			listSeparator = listSeparator->next;
	}

	*separatorList = listSeparator;
	*lineList = listLine;
}

/**
 * splitCommands - splits command lines according to
 * the separators ;, | and &, and executes them
 *
 * @dataShell: data structure
 * @inputString: input string
 * Return: 0 to exit, 1 to continue
 */
int splitCommands(data_shell *dataShell, char *inputString)
{

	sep_list *separatorListHead, *listSeparator;
	line_list *lineListHead, *listLine;
	int loop;

	separatorListHead = NULL;
	lineListHead = NULL;

	addSeparatorsAndLines(&separatorListHead, &lineListHead, inputString);

	listSeparator = separatorListHead;
	listLine = lineListHead;

	while (listLine != NULL)
	{
		dataShell->input = listLine->line;
		dataShell->args = tokenizeString(dataShell->input);
		loop = exec_line(dataShell);
		free(dataShell->args);

		if (loop == 0)
			break;

		goToNext(&listSeparator, &listLine, dataShell);

		if (listLine != NULL)
			listLine = listLine->next;
	}

	freeSeparatorList(&separatorListHead);
	free_line_list(&lineListHead);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * tokenizeString - tokenizes the input string
 *
 * @inputString: input string.
 * Return: string splitted.
 */
char **tokenizeString(char *inputString)
{
	size_t bufferSize;
	size_t i;
	char **tokens;
	char **token;

	bufferSize = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (bufferSize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(inputString, TOK_DELIM);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bufferSize)
		{
			bufferSize += TOK_BUFSIZE;
			tokens = realloc(tokens, sizeof(char *) * bufferSize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOK_DELIM);
		tokens[i] = token;
	}

	return (tokens);
}
