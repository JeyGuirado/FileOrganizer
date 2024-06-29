//use this for struct file header
#ifndef _FILE_H_
#define _FILE_H_
#define MAX_LENGTH 256
#define MAX_FILES 100
struct file{
	
	char filename[MAX_LENGTH];
	int inode_number;
	long size;

		


}file;

void list_files(struct file files[], int file_tot);
void cat_file(struct file files[], int curr_index);
void duplicate(struct file files[], int curr_index);
void rename(struct file files[], int curr_index);
void unlink(struct file files[], int curr_index);
void truncate(struct file files[], int curr_index);
void last_100_bytes(struct file files[], int curr_index);
void next(struct file files[], int curr_index, int file_tot);









#endif
