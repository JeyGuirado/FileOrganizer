//use it for implementation of any function related to struct file
#include "file.h"
#define MAX 64

/* This function prints out all the files in the list entered by the user
 * 
 * param: list of files, total file count
 * return: void; uses printf functtion
 */
void list_filess(struct file files[], int file_tot){
	for(int i = 0; i < file_tot; i++){
		printf("%s %d %ld", files[i].name, files[i].inode_number, files[i].size);
	}

}

/* This function prints out all the contents of a file, just like the cat command
 *
 * param: list of files, index of current file
 * return: void; uses system call to output contents
 */
void cat_files(struct file files[], int curr_index){	
		int input = open(files[current_index].name, O_RDONLY);
		char buff[MAX];

		while(1){
			int result = read(1, buff, sizeof(buff));

			if (result == 0){
				break;
			
			}
		
			write(1, buff, result);
		}

		close(input);

}

/* Duplicates the current file. Will create or truncate file depending 
 * on user input
 *
 * param: list of files, current file index
 * return: none
 */
void duplicate(struct file files[], int curr_index){
	char* src = files[curr_index].filename;
	
	int input_file = open(src, O_RDONLY);

	// if not able to be read, return error
	if (input_file < 0){
		perror("Invalid File Name");
		return; 
	}	
	
	// Gets the name of destination file
	char dest_file[MAX_LENGTH];
	printf("Enter the Destination: ");
	fgets(dest_file, sizeof(dest_file), stdin);
	
	int outfile = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (outfile < 1){
		perror("Cannot Open");
		return;
	}
	
	char buff[MAX];

	//write to file 64 bytes at a time
	while(1){
		int result = read(infile, buff, sizeof(buff));
		if (result == 0){
			break;
		}
		write (outfile, buff, result);
	}

	close(input_file);
	close(outfile);


}

/* Renames the current file
 *
 * param: list of files, current file index
 * return: void
 */
void rename(struct file files[], int curr_index){
	
	char new_name[MAX_LENGTH];
	printf("Enter the new name for this file: ");
	fgets(new_name, sizeof(new_name), stdin);

	int re_name = rename(files[curr_index].filename, new_name);

	if(re_name < 0){
		perror("Error renaming file");
		return;
	}
	
	printf("rename succesful \n");

}

/* Deletes the current files path name
 *
 * param: list of files, index of current file
 * return: void 
 */
void unlink(struct file files[], int curr_index, int file_tot){
	int result = unlink(files[curr_index].filename);

	if(result < 1){
		perror("Cannot Unlink");
		return;
	}

	printf("unlink succesful \n");
	
}
/* Truncates the current file; makes file length 0 bytes
 * 
 * param: list of files, current file index
 * return: void
 */
void truncate(struct file files[], int curr_index){
	int result = truncate(files[curr_index], 0);

	if (result < 0){
		perror("Error truncating file");
		return;
	}

	printf("truncation succesful \n");
}

void last_100_bytes(struct file files[], int curr_index){
	

}

void next(struct file files[], int curr_index, int file_tot){
	if(curr_index < file_tot-1){
		curr_index++;
	}
	else{
		printf("the current file is the last");
	}
}


