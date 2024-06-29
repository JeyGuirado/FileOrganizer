# PA4 Grading

Grade: 60/100 - 30% late = 42

## Comments and Format(16 points)

| Earned | Possible | Requirement                                   | Grading Comments |
|--------|----------|-----------------------------------------------|------------------|
|     0   | 2        | Intro comments complete and clear |                  
|     0   | 2        | Appropriate in-line commentary given |                  
|     2   | 2        | Proper use of underscores |                  
|      2  | 2        | Appropriate use of whitespace |                
|     3   | 3        | Functions are implemented in file.c | 
|     5   | 5        | Comments for each function header |


## Correctness and Completeness (59 points)

| Earned | Possible | Requirement                                   | Grading Comments |
|--------|----------|-----------------------------------------------|------------------|
|     2   | 2        | Code uses argc and argv correctly |                  
|    3   | 4        | Struct file is implemented correctly | missing typedef
|     2   | 2        | filename in the struct is big enough | 
|     2   | 2        | reasonable enough slots to store  all the files given by users | 
|     5   | 5        | List all files with inode # and size |                  
|     2   | 5        | Cat content of a file to stdout |read from input not 1                  
|     2   | 5        | Duplicate a file successfully| wrong input file descriptor                 
|     2   | 5        | Rename a file|   should rename rename function              
|      0  | 2        | Update the file name in a struct after renaming |                 
|      2 | 5        | Unlink a file |  should rename unlink function                |
|      0 | 1        | Unlink also removes the file from the list |                
|      1 | 4        | Truncate a file|      truncate takes a string not a file struct         
|      0 | 1        | Truncate a file also change the size of the file in the struct| 
|      0 | 5        | Display the last 100 bytes|                
|      0 | 2        | Display the last 100 bytes works with file with less than 100 bytes |  
|      2 | 2        | Go to the next file |  
|      2 | 2        | Quit the program |  
|      2 | 2        | Skip invalid command |  
|      3 | 3        | No other logical errors |  

             

## Design Issues(20 points)
     

| Earned | Possible | Requirement                                   | Grading Comments |
|--------|----------|-----------------------------------------------|------------------|
|     5   | 5        | Reasonable prompts |                  
|     4   | 5        | Resonable errors (perror) | missing checking for error in some places                 
|     0   | 2        | Compiles without warnings |                  
|      3  | 3        | Appropriate variable names |                 
|      0 | 5        | Clear and well formatted output |     
           

## Others(5 points)
     

| Earned | Possible | Requirement                                   | Grading Comments |
|--------|----------|-----------------------------------------------|------------------|
|     3   | 3        | Commit and push to git regularly |                  
|     1   | 2        | Reasonable Makefile |                  


## Additional Comments
