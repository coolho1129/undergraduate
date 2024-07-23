#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void do_ls (char name[])
{
	DIR *dirptr;
	struct dirent *direntp;

	dirptr = opendir (name);
	if (dirptr != NULL) {
		while ((direntp = readdir(dirptr)) != NULL) 
			printf ("%s\n", direntp->d_name);
		closedir (dirptr);
	}
}

int main (int argc, char* argv[])
{
	int i;

	printf ("argc = %d \n", argc);
	for (i = 0; i < argc; i++)
		printf ("%s\n", argv[i]);	

	do_ls (".");
}
