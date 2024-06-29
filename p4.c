//Write your main here
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "file.h"




int main(int agrc, char *argv[]){

	if(argc < 2){
		printf("Usage: <file1> <file2> ... <filen>\n");
		return 1;
	}

	//information for files
	file files[MAX_FILES];
	int file_tot = argc-1;
	int curr_index = 0;

	for(int i = 1; i < argc; i++){
		struct stat file_stat;
		int result = stat(argv[i], &file_stat);
		
		if (result < 1){
			perror("Invalid File Name(s)");
			return 1;
		}
		strncpy(files[i-1].filename, argv[i], MAX_LENGTH);
		files[i-1].inode_number = file_stat.st_ino;
		files[i-1].size = file_stat.st_size;

	}

	char command;

	while(1){
		printf("file %s: command: ", files[curr_index].filename);
		scanf(" %c", &command);
		//clear input buffer
		getchar();

		switch(command){
			case 'l': 
				list_files(files,file_tot);
				break;
			case 'c':
				cat_file(files, curr_index);
				break;
			case 'd':
				duplicate(files, curr_index);
				break;
			case 'r':
				rename(files, curr_index);
				break;
			case 'u': 
				unlink(files, curr_index);
				break;
			case 't': 
				truncate(files, curr_index)
				break;
			case 'e':
				break;
			case 'n':
				curr_index++;
				break;
			case 'q': 
				return 0;
		}
	}



	return 0;
}
