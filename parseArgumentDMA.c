#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *read_command_heap(int);
char **parse_command_heap(char *);
int main()
{
	char *d = read_command_heap(1024);
//	printf("address of d is =%p \nand value is %s", d, d);
	char **x=parse_command_heap(d);
	int i=0;
	while(1){
	printf("%s ",x[i]);

	
	if(x[i]==NULL){
		break;
		
	}
	
	i++;
	}
//	system(d);
//	free(d);
	return 0;
}

char *read_command_heap(int number_of_character)
{
	char *address_str;
	while (1)
	{
		address_str = (char *)malloc(number_of_character * sizeof(char));
		fgets(address_str, number_of_character, stdin);
		//remove back slashn\n
		//printf("%d",strlen(address_str)-1);
		//printf("%p\n",address_str);
		if ((strlen(address_str) - 1) < 1)
		{
			continue;
		}
		else
		{
			if (address_str[(strlen(address_str) - 1)] == '\n')
			{
				address_str[(strlen(address_str) - 1)] = '\0';
			}

			if (address_str != NULL)
			{
				return address_str;
			}
			else
			{
				return NULL;
			}
		}
	}
}

char **parse_command_heap(char *str){
	int i=0;
	char **args=malloc(100*sizeof(char*));
	char *token=strtok(str," ");
//	printf("%s\n",args[i]);
	while(token!=NULL){
	  args[i]=token;
	  token=strtok(NULL," ");
	  i++;	
	}
	args[i]=NULL;
	return args; 
	
	
	
}
		
	