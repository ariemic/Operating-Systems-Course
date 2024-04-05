#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define MAX_LINE_LENGTH 500

void reverse_line(char* line){
    size_t length = strlen(line);
    int i, j;
    for(i = 0, j = length - 1; i < j; i++, j--){
        char tmp = line[i];
        line[i] = line[j];
        line[j] = tmp;
    }
}

void search_dir(char *source_dir, char *output_dir){
    DIR *dir;
    struct dirent *dir_entry;
    char source_path[PATH_MAX], dest_path[PATH_MAX];
    dir = opendir(source_dir);
    if(dir == NULL){
        perror("Error opening source directory! \n");
        return;
    }
    while ((dir_entry = readdir(dir)) != NULL){
        //odwolujemy sie do pola d_type i sprawdzamy czy plik/podkatalog jest plikiem regularnym
        //sprawdza czy nazwa pliku konczy sie na .txt
        if(dir_entry -> d_type == DT_REG && strstr(dir_entry ->d_name, ".txt")!=NULL){

            //create the file paths
            snprintf(source_path, PATH_MAX, "%s/%s", source_dir, dir_entry->d_name);
            snprintf(dest_path, PATH_MAX, "%s/%s", output_dir, dir_entry->d_name);

            //open files
            FILE *source_file = fopen(source_path, "r");
            FILE *output_file = fopen(dest_path, "w");

            //errors handling
            if (source_file == NULL) {
                perror("Error opening source file!\n");
                fclose(source_file);
                continue;
            }

            if(output_file == NULL){
                perror("Error opening output file!\n");
                fclose(output_file);
                continue;
            }

            //create a line to store temporarily each line
            char line[MAX_LINE_LENGTH];
            int cnt_lines = 0;
            while (fgets(line, MAX_LINE_LENGTH, source_file)) {
                line[strcspn(line, "\n")] = '\0';
                reverse_line(line);
                fputs(line, output_file);
                fputs("\n", output_file);
                cnt_lines++;
            }

            printf("Processed %s: %d lines\n",dir_entry->d_name, cnt_lines);

            fclose(source_file);
            fclose(output_file);
        }
    }

}

int main(int args_num, char **argv){
    if (args_num != 3) {
        printf("Usage: %s <source_directory> <output_directory>\n", argv[0]);
        return 1;
    }

    search_dir(argv[1], argv[2]);
    return 0;

}
