
#include <stdio.h>
#include <string.h>


typedef struct s_struct
{
	int dim[3];
}t_struct;



int otherlines(char *str)
{
	int i;

	
	i = 0;

	if(str[i] != '1')
		return (0);
	if(str[strlen(str) - 1] != '1')
		return (0);
	while (str[i] && (str[i] == '1' || str[i] == 'P' || str[i] == '0' || str[i] == 'C' || str[i] == 'E'))
	{
		i++;
	}
	if(i != strlen(str))
		return (0);
	return(1);
}

int main(int argc, char const *argv[])
{
	printf("%d",otherlines("1112EPCCC1"));
	return 0;
}
