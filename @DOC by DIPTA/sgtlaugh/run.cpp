#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <assert.h>

char global_name[100000];
char final[1000000];
char str[2];
char title[10000];

const bool flag = true;


int listdir(const char *path) {
    struct dirent *entry;
    DIR *dp;
    
    dp = opendir(path);
    if (dp == NULL) {
		puts(path); 	
		
		FILE *fp; 
		fp = fopen(global_name, "r");		
		if(fp == NULL) {assert(0); return 0;} 
		
		strcpy(title, path); 		
		strcat(final, title); 
		if(flag){
			strcat(final, "\n");
			return 0; 
		}
		strcat(final, "\n---------------------------------------------------------------------------------\n");
		
		while(1) {			
			char c = fgetc(fp);			
			if( feof(fp) ) { 
				break ;
			}
			str[0] = c;
			strcat(final, str);
		}
		fclose(fp);
		strcat(final, "\n---------------------------------------------------------------------------------\n");
   
        return -1;
    }

    while ((entry = readdir(dp)))
    {
		if(entry->d_name[0] != '.')
		{
			int p = strlen(global_name); 
			str[0] = '/';
			if(path[0] != '.') strcat(global_name, str);
			
			strcat(global_name, entry->d_name);			
			listdir(entry->d_name);
			global_name[p] = 0;			
		}
	}

    closedir(dp);
    return 0;
}


int main()
{
	listdir("."); 
	
	freopen("names.txt", "w", stdout); 
	
	puts(final); 
	return 0;
}
