#include <stdio.h>
#include <string.h>

int func(char **str)
{	
	int i;
	int j;
	int	len;
	
	j = 1;
	while (j < 4)
	{
		len = strlen(str[j]);
		if (len != strlen(str[0]))
		{
			return (0);
		}
		j++;
	}
	return 1;
}



int main(int argc, char const *argv[])
{
	char *str[4] ={"Hello" ,"orld" , "OKAYY" ,"TESTT"};
		printf("%d",strlen(str[0]));
	if(func(str))
		printf("OKAY");

	return 0;
}
