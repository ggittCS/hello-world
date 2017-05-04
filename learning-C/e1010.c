#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct entry
{
	char word[15];
	char definition[50];
};

void dictionarySort (struct entry dictionary[])
{
	int i, j;
	struct entry temp[100];
	
	for (i=0; i<9; ++i)
		for (j=i+1; j<10; ++j)
		{
			if (strcmp (dictionary[i].word, dictionary[j].word) > 0)
			{
				strcpy (temp[i].word, dictionary[i].word);
				strcpy (temp[i].definition, dictionary[i].definition);
				strcpy (dictionary[i].word, dictionary[j].word);
				strcpy (dictionary[i].definition, dictionary[j].definition);
				strcpy (dictionary[j].word, temp[i].word);
				strcpy (dictionary[j].definition, temp[i].definition);
			}
		}
		
	
}

int main (void)
{
	int i;
	struct entry dictionary[100] = 
	{ {"acumen", "mentally sharp; keen"},
		{"addle", "to become confused"},
		{ "aardvark", "a burrowing African mammal"},
		{"agar", "a jelly made from seaweed"},
		{"ahoy", "a nautical call of greeting"},
		{"abyss", "a bottomless pit"},		
		{"aerie", "a high nest"},
		{"affix", "to append; attach"},		
		{"aigrette", "an ornamental cluster of feathers"},
		{"ajar", "partially opened"} };
		
	dictionarySort (dictionary);
		
	for (i=0; i<10; ++i)
		printf ("%s	%s\n", dictionary[i].word, dictionary[i].definition);
	
	return 0;
}