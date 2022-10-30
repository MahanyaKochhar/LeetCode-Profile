

int minSideJumps(int* obstacles, int obstaclesSize)
{
    int dp[obstaclesSize][4];
    for(int i=0;i<obstaclesSize;i++)
    {
        for(int j=0;j<4;j++)
        {
            dp[i][j]=1e6;
        }
    }
    dp[0][2]=0;
    dp[0][1]=1;
    dp[0][3]=1;
    for(int i=1;i<obstaclesSize;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(obstacles[i]==j)
                continue;
            dp[i][j]=(dp[i-1][j]);
            for(int k=1;k<=3;k++)
            {
                if(j==k)
                    continue;
                if(obstacles[i]!=k)
                    dp[i][j]=fmin(dp[i][j],dp[i-1][k]+1);
            }
        }
    }
    return fmin(dp[obstaclesSize-1][1],fmin(dp[obstaclesSize-1][2],dp[obstaclesSize-1][3]));
}
