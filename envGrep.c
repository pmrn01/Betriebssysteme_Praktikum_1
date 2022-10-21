#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
int main(int argc, char* argv[]){
    if(argc <= 1){
        int i = 0;
        while(environ[i]){
            printf("%s\n", environ[i]);
            i++;
        }
    }if(argc == 2){
        int i = 0;
        while(environ[i]){
            if(strstr(environ[i],argv[1])){
                printf("%s\n", environ[i]);
                i++;
            }else{
                i++;
            }
        }
    }
    if(argc == 3 && strstr(argv[1],"-i")){
        int i = 0;
        while(environ[i]){
            char* temp = argv[2];
            int j = 0;
            while(temp[j]){
                temp[j] = toupper(temp[j]);
                j++;
            }

            if(strstr(environ[i],temp)){
                printf("%s\n", environ[i]);
                i++;
            }else{
                i++;
            }
        }
    }

     if(argc == 2 && strstr(argv[1],"-n")){
        
        int i = 0;
        while(environ[i]){
            char* temp;
            char* ptr;
            temp = environ[i];
            ptr = strchr(temp,'=');
            if(ptr != NULL){
                *ptr = '\0';
            }
            printf("%s\n", temp);
            i++;
        }
    }


    if(argc == 3 && strstr(argv[1],"-n")){
        
        int i = 0;
        while(environ[i]){
            char* temp;
            char* ptr;
            temp = environ[i];
            ptr = strchr(temp,'=');
            if(ptr != NULL){
                *ptr = '\0';
            }
            if(strstr(environ[i],argv[2])){
                printf("%s\n", temp);
            }
            i++;
        }
    }

    if(argc == 4 && strstr(argv[1], "-n") && strstr(argv[2],"-i") || argc == 4 && strstr(argv[1], "-i") && strstr(argv[2],"-n")){
        int i = 0;
        while(environ[i]){
            char* temp;
            char* temp2;
            char* ptr;
            temp = argv[3];
            int j = 0;
            while(temp[j]){
                temp[j] = toupper(temp[j]);
                j++;
            }
            if(strstr(environ[i], temp)){
                temp2 = environ[i];
                ptr = strchr(temp2,'=');
                if(ptr != NULL){
                    *ptr = '\0';
                }
                printf("%s\n",temp2);

                i++;
            }
            i++;

        }
    }

}
