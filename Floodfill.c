#include <stdio.h>
#include <stdlib.h>

typedef struct s_struct
{
    char **str;
}t_struct;


t_struct floodFill(char **map, int x, int y, int lines, int colum, t_struct data)
 {
    int i;
    int j;

    i = 0;
    while (i < lines)
    {
        j = 0;
        while (j < colum)
        {
            data.str[i][j] = map[i][j];
            j++;
        }
    i++;
    }
    if (x < 0 || x >= lines || y < 0 || y >= colum || (data.str[x][y] != '0' && data.str[x][y] != 'P' && data.str[x][y] != 'C' && data.str[x][y] != 'E'))
        return (data);
    data.str[x][y] = 'D';
    data = floodFill(data.str, x + 1, y, lines, colum,data);
    data = floodFill(data.str, x - 1, y, lines, colum, data);
    data = floodFill(data.str, x, y + 1, lines, colum, data);
    data = floodFill(data.str, x, y - 1, lines, colum, data);
    return (data);
}

int main() {
    
    int i;
    int lines;
    int colum;
    int startX;
    int startY;
    t_struct data;

    lines = 4;
    colum = 13;
    startX = 2;
    startY = 1;

    data.str = (char **)malloc(sizeof (char *) * lines);
    i = 0;
    while(i < lines)
        data.str[i++] = (char *)malloc(colum);

    char *map[] = 
    {
        "111111111111",
        "100000000001",
        "1PCE11111011",
        "111111111111",
    };
    i = 0;
    while (i < lines)
        printf("%s\n",map[i++]);
    printf("-----\n");
    data = floodFill(map, startX, startY, lines, colum, data);
    i = 0;
    while (i < lines)
        printf("%s\n",data.str[i++]);
    i = 0;
    while (i < lines)
        free(data.str[i++]);
    free(data.str);
    return (0);
}
