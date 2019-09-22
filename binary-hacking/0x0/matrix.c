#include <stdio.h>

int main(int argc, char * argv[]){
    if(argc==3){
        printf("Knock, knock, %s, %s\n", argv[1], argv[2]);
    } else {
        fprintf(stderr, "Usage %s <name>\n", argv[0]);    
        return 1;
    }
    return 0;
}
