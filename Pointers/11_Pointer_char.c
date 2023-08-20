#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *get_basename(char *filename)
{
	char *c;
	int len;
	char *basefilename;

	if (!filename)
		return NULL;

	len = strlen(filename);
	basefilename = (char *)malloc(len + 1);
	if (basefilename == NULL)
	{
		return NULL;
	}

	strcpy(basefilename, filename); // filename gets copied in baseefilename

	for (c = basefilename + len; c > basefilename && *c != '.'; c--) 
	{
		printf("Current basefilename: %p\n", basefilename + len);
        printf("Condition check: %d\n", c > basefilename && *c != '.');
	} // Get last .
	if (*c == '.')
		*c = 0;

	return basefilename;
}

int main(){
    char filename[] = "example.txt"; // Replace with your desired filename

    char *basename = get_basename(filename);

    if (basename)
    {
        printf("Basename: %s\n", basename);
        printf("This will print the address of the first character basename points to: %p\n", (void *)basename);
        printf("Basename points to the string. This will print the address of basename itself: %p\n", &basename);
        free(basename); // Remember to free the memory allocated by get_basename
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
    return 0;
}