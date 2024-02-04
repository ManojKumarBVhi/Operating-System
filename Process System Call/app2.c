#include<stdio.h>
#include<string.h>

int main(){
	char str[100];
	printf("Enter the string : ");
	scanf("%s",str);
	int len = strlen(str);
	printf("The origianl string is : %s\n",str);
	for(int i = 0,j=len-1; i <= j; i++,j--){
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
	printf("The reversed  string is  : %s\n",str);
	
	return 0;
}
