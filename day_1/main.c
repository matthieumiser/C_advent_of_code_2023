#include <stdio.h>
#include <ctype.h>
#include <string.h>

int concatDigits(int x, int y) {
    return (x * 10) + y; 
}

int main() {
    FILE *fptr;
    fptr = fopen("codes.txt", "r");
    char fileText[100] = {0};
    int digits[2] = {0};
    int values[1500] = {0};

    int j = 0;
    int len;
    while(fgets(fileText, 100, fptr)) {
        len = strlen(fileText);
        for(int i = 0; i < len; i++){
            if(isdigit(fileText[i])) {
                digits[0] = fileText[i] - '0';
                break;
            }
        }
        for(int i = len - 1; i >= 0; i--){
            if(isdigit(fileText[i])) {
                digits[1] = fileText[i] - '0';
                break;
            }
        }
        values[j] = concatDigits(digits[0], digits[1]);
        j++;
    }
    int result = 0;
    for(int z = 0; z < j; z++){
        result += values[z];
    }
    printf("%d", result);
    
    fclose(fptr);
    return 0;
}


