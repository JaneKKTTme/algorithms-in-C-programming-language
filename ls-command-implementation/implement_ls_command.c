#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <locale.h>
#include <string.h>

int main(int argc, char **argv)/*Enter a directory or not*/
{
	setlocale(LC_ALL, "Rus");
	DIR *dr;
	struct dirent *drn;
	char direct[100];

	if (argc==1)
	{
		strcpy(direct, ".");
		dr = opendir(direct);
		printf("Contents of directory: .\n");
	}
	else if (argc==2)
	{
		dr = opendir(argv[1]);
		printf("Contents of directory: %s\n", argv[1]);
	}
	else 
	{
		printf("LOSER!");
		return -1;
	}
	if (dr!=NULL)
		while ((drn=readdir(dr)) != NULL)
			printf("%s\n", drn->d_name);	
	else
		printf("Dir error occured.");
	
	closedir(dr); 
	
	return 0;
}
