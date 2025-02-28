#include<cstdio>

using namespace std;

#define MAX 30

char oil[MAX][MAX];

int flag[MAX][MAX];

int row;

void bfs(int i, int j);

int main()
{
    //freopen("input.txt","r",stdin);
    int i, j, k, t = 1;
    while(scanf("%d", &row) == 1)
    {
        getchar();
        for(i = 0; i < row; i++)
            for(j = 0; j < row; j++)
                flag[i][j] = 0;
        for(i = 0; i < row; i++)
            gets(oil[i]);
        for(i = 0, k = 0; i < row ; i++)
            for(j = 0; j < row; j++)
            {
                if(oil[i][j] == '1' && flag[i][j] == 0)
                {
                    k++;
                    bfs(i,j);
                }
            }
        printf("Image number %d contains %d war eagles.\n", t++, k);
    }
    return 0;
}

void bfs(int i, int j)
{
    if(oil[i][j] != '1' || flag[i][j] == 1)
        return;
    flag[i][j] = 1;
    if(i > 0)
    {
        bfs(i-1, j);
        if(j>0)
            bfs(i-1,j-1);
        if(j+1<row)
            bfs(i -1, j + 1);
    }
    if(i + 1 < row)
    {
        bfs(i+1, j);
        if(j>0)
            bfs(i+1,j-1);
        if(j+1<row)
            bfs(i+1,j+1);
    }
    if(j-1 >= 0)
        bfs(i,j-1);
    if(j+1 < row)
        bfs(i,j+1);
    return;
}
