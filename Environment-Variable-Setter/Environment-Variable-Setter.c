#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char *envVar;
char buf[200], var[200], varName[200];

void setEnv(char *envName){
	printf("enter value for %s :", envName);
	gets(buf);
	sprintf(var, "%s=%s", envName, buf);
	putenv(var);
	printf("\n%s\n", var);
}

int main(int argc, char *argv[])
{
    printf("Enter variable name to change(check): ");
    gets(buf);
    strcpy(varName, buf);

    if((envVar = getenv(buf)) == NULL){
        printf("variable %s is not defined\n", varName);
        setEnv(varName);
    } else {
        printf("%s=%s. Do you want to change it? [N]:", varName, envVar);
        gets(buf);
        if(buf[0] == 'Y' || buf[0] == 'y'){
            setEnv(varName);
        }
    }
}
