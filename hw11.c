#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int random_number() {
    int file = open("/dev/urandom", O_RDONLY);
    if(file == -1){
        printf("\nError, Message: %s\n", strerror(errno));
        return -1;
    }int rand;
    int read_file = read(file, &rand, sizeof(int));
    if(read_file == -1){
        printf("\nError, Message: %s\n", strerror(errno));
        return -1;
    }return rand;
}

int main(){
    int rand[10];
    int x;
    printf("\nPrinting Array\n");
    for(x = 0; x < 10; x++){
        rand[x] = random_number();
        printf("%d\n", rand[x]);
    }

    printf("\nWriting Numbers to File");
    int file = open("rand_num.txt", O_WRONLY | O_CREAT, 0644);
    if(file == -1){
        printf("\nError, Message: %s\n", strerror(errno));
        return -1;
    }int after = write(file, rand, sizeof(int) * 10);
    if(after == -1){
        printf("\nError, Message: %s\n", strerror(errno));
        return -1;
    }

    int rand2[10];
    printf("\nReading Numbers from File");
    file = open("rand_num.txt", O_RDONLY);
    if(file == -1){
        printf("\nError, Message: %s\n", strerror(errno));
        return -1;
    }after = read(file, rand2, sizeof(int) * 10);
    if(after == -1){
        printf("\nError, Message: %s\n", strerror(errno));
        return -1;
    }
    printf("\nPrinting Array\n");
    for(x = 0; x < 10; x++){
        rand2[x] = random_number();
        printf("%d\n", rand[x]);
    }
    

}