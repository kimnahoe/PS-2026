#include <stdio.h>
#include <stdlib.h>

void arrArr(char a[]) 
{
	int i, j, min, minIndex = 0, temp; 
	for (i = 0; a[i] != '\0'; i++) { 
		min = a[i]; 
		minIndex = i; 
	for (j = i + 1; a[j] != '\0'; j++) { 
		if (a[j] < min) { 
			min = a[j]; 
			minIndex = j; 
		} 
	}
	temp = a[i]; 
	a[i] = a[minIndex]; 
	a[minIndex] = temp;
	}
} 

void stringArr(char *str)
{
	char *s1=(char*)malloc(sizeof(char)*500000);
	char *s2=(char*)malloc(sizeof(char)*500000);
	char *s3=(char*)malloc(sizeof(char)*500000);
	int index1, index2, index3;
	index1=index2=index3=0;
	
	int i, j; i=j=0;
	while(str[i] != '\0'){
		if('A' <= str[i] && str[i] <= 'Z') {
			s1[index1]=str[i];
			index1++;
		}
		else if('a' <= str[i] && str[i] <= 'z') {
			s2[index2]=str[i];
			index2++;
		}
		else if('0' <= str[i] && str[i] <= '9') {
			s3[index3]=str[i];
			index3++;
		}
		i++;
	}
	s1[index1]='\0';
	arrArr(s1);
	s2[index2]='\0';
	arrArr(s2);
	s3[index3]='\0';
	arrArr(s3);
	
	printf("%s%s%s", s1, s2, s3);
}



int main(void)
{
	char *string=(char*)malloc(sizeof(char)*500000);
	scanf("%s", string);
	
	stringArr(string);
	
	free(string);
	
	return 0;
}
