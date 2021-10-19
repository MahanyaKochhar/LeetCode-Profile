class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2)
    {
        for(int i=x1;i<=x2;i++)
        {
            for(int j=y1;j<=y2;j++)
            {
                if((i-x_center)*(i-x_center)+(j-y_center)*(j-y_center)-radius*radius<=0)
                    return true;
            }
        }
        return false;
    }
};
