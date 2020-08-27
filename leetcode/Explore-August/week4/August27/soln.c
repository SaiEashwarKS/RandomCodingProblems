
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize){
    int diff; int diff2; int ind;
    int* res = (int*)malloc(intervalsSize * sizeof(int));
    for(int i = 0; i < intervalsSize; ++i)
    {
    
        diff = 99999999; //assume a large initial value for the difference between the two intervals which match the requirements
        ind = -1;
        for(int j = 0; j < intervalsSize; ++j)
        {
            diff2 = intervals[j][0] - intervals[i][1];
            if(diff2 >=0 && diff2 < diff)
            {
                ind = j;
                diff = diff2;
                if(diff == 0)
                    break;
            }
        }
        res[i] = ind;
    }
    *returnSize = intervalsSize;
    return res;

}
