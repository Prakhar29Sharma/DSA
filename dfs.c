#include<stdio.h>
#include<stdlib.h>

int visited[7] = {0,0,0,0,0,0,0};
    
  int a[7][7] = {
            {0,1,1,1,0,0,0},
            {1,0,1,0,0,0,0},
            {1,1,0,1,1,0,0},
            {1,0,1,0,1,0,0},
            {0,0,1,1,0,1,1},
            {0,0,0,0,1,0,0},
            {0,0,0,0,1,0,0} };


void DFS(int i)
{
    int j;
    printf("%d", i);
    visited[i] = 1;
    for(j = 0; i < 7; j++)
    {
        if(a[i][j] == 1 && visited[j] == 1) {
            DFS(j);
        }
    }

}

int main()
{
    DFS(0);
}