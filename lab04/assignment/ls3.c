#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <unistd.h>

void do_ls(char []);
void dostat(char *);
void save_file_info(char *, struct stat*);
void mode_to_letters(int, char[]);
char *uid_to_name(uid_t);
char *gid_to_name(gid_t);

char option[100];
long long totalFileSize=0;
int FileCount=0;

typedef struct FileData{
	char modestr[1000];
	int st_nlink;
	char  uid_to_name[1000];
	char gid_to_name[1000];
	long long size;
	time_t time;
	char name[1000];
	
} FileData;

void show_file_info(FileData array[],int size);
int compareTime(const void *a, const void *b);
int compareSize(const void *a, const void *b);
void select_option(char *option);
	
FileData data[1000];

int main(int argc, char *argv[]) {
	int loop=argc-2;
	
	if(argc == 1) {
		do_ls(".");
	}
       
	else if (argc==2){
		strcpy(option,*++argv);		
		if(strcmp(option,"-t")==0||strcmp(option,"-b")==0){
			printf("option: %s\n",option);
			do_ls(".");
		}
		else
			do_ls(*argv);
	
	}
	
	else{
		strcpy(option,*++argv);	
		printf("option: %s\n",option);
		while (loop--){	
		    	do_ls(*++argv);
			FileCount=0;
			totalFileSize=0;
		}
	}

	return 0;
}

void select_option(char *option){
	if(strcmp(option,"-t")==0)
		qsort(data,FileCount,sizeof(FileData),compareTime);
	else if(strcmp(option,"-b")==0)
		qsort(data,FileCount,sizeof(FileData),compareSize);

	else
		return ;
}

int compareTime(const void *a, const void *b)
{
	return ((FileData *)a)->time - ((FileData *)b)->time;
}

int compareSize(const void *a, const void *b)
{
	return (int)((long)((FileData *)a)->size - (long)((FileData *)b)->size);
}

void do_ls(char dirname[]) {
	DIR *dir_ptr;
	struct dirent* direntp;

	  if((dir_ptr = opendir(dirname)) == NULL)  {
                  fprintf(stderr, "ls3: cannot open %s\n", dirname);
         } 
	else { 
		chdir(dirname);
		while( (direntp = readdir(dir_ptr)) != NULL)
			dostat(direntp->d_name);
		closedir(dir_ptr);
		show_file_info(data,FileCount);
	}
	
}

void dostat(char *filename) {
	struct stat info;
	if(stat(filename, &info) == -1)
		perror(filename);
	else
		save_file_info(filename, &info);
}


void save_file_info(char *filename, struct stat *info_p) {
	char *uid_to_name(), *ctime(), *gid_to_name(), *filemode();
	void mode_to_letters();
	char modestr[11];
	
	mode_to_letters(info_p->st_mode, modestr);
	strcpy(data[FileCount].modestr,modestr);
	data[FileCount].st_nlink=(int)info_p->st_nlink;
	strcpy(data[FileCount].uid_to_name,uid_to_name(info_p->st_uid));
	strcpy(data[FileCount].gid_to_name, gid_to_name(info_p->st_gid));
	data[FileCount].size=(long) info_p->st_size;
	data[FileCount].time=info_p->st_mtime;
	strcpy(data[FileCount++].name,filename);
	totalFileSize+=info_p->st_size;
}

void show_file_info(FileData array[],int size) {
	 select_option(option);
	printf("FileCount: %d\n",size);
	printf("totalFileSize: %lld\n",totalFileSize);

	for(int i=0;i<size;i++){
		printf("%s", array[i].modestr);
		printf("%4d ", array[i].st_nlink);
		printf("%-8s ", array[i].uid_to_name);
		printf("%-8s ", array[i].gid_to_name);
		printf("%-8lld ", array[i].size);
		printf("%.12s ", 4+ctime(&array[i].time));
		printf("%s \n", array[i].name);
	}
}

void mode_to_letters(int mode, char str[]) {
	strcpy(str, "----------");

	if(S_ISDIR(mode)) str[0] = 'd'; /* directory? */
	if(S_ISCHR(mode)) str[0] = 'c'; /* char devices? */
	if(S_ISBLK(mode)) str[0] = 'b'; /* block device? */

	if(mode & S_IRUSR) str[1] = 'r'; /* 3 bits for user */
	if(mode & S_IWUSR) str[2] = 'w';
	if(mode & S_IXUSR) str[3] = 'x';

	if(mode & S_IRGRP) str[4] = 'r'; /* 3 bits for group */
	if(mode & S_IWGRP) str[5] = 'w';
	if(mode & S_IXGRP) str[6] = 'x';


	if(mode & S_IROTH) str[7] = 'r'; /* 3 bits for other */
	if(mode & S_IWOTH) str[8] = 'w';
	if(mode & S_IXOTH) str[9] = 'x';
}



char *uid_to_name(uid_t uid) {
	struct passwd *getpwuid(), *pw_ptr;
	static char numstr[10];

	if((pw_ptr = getpwuid(uid)) == NULL) {
		sprintf(numstr, "%d", uid);
		return numstr;
	} else
		return pw_ptr->pw_name;
}

char *gid_to_name(gid_t gid) {
	struct group *getgrid(), *grp_ptr;
	static char numstr[10];

	if((grp_ptr = getgrgid(gid)) == NULL ) {
		sprintf(numstr, "%d", gid);
		return numstr;
	}  else
		return grp_ptr->gr_name;
}


