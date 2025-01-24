#include <stdio.h>
#include <ctype.h>
#define size 100
void convertToUppercase( char *sPtr ); // prototype
int main(void)
{
    char string[size];
    scanf("%s",string);
    convertToUppercase(string);
    printf("%s\n", string);
}
void convertToUppercase( char *sPtr )
{
    while ( *sPtr!= '\0' ) {
        if(islower(*sPtr)){
            *sPtr = toupper(*sPtr);
        }
        else if(isupper(*sPtr)){
            *sPtr=tolower(*sPtr);}
        ++sPtr; 
    }
}
