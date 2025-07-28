// My appraoch Less optimal
int countHillValley(vector<int> &nums)
{
    int idx1, idx2, count = 0;
    for (int i = 1; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i - 1]) // To Void Flat area example [1,1] inside an array
            continue;
        idx1 = i - 1, idx2 = i + 1;
        while (idx1 >= 0 && nums[idx1] == nums[i])
        {
            idx1--;
        }
        while (idx2 < nums.size() && nums[idx2] == nums[i])
        {
            idx2++;
        }
        if (idx1 >= 0 && idx2 < nums.size())
        {
            if (nums[i] < nums[idx1] && nums[i] < nums[idx2] ||
                nums[i] > nums[idx1] && nums[i] > nums[idx2])
            {
                count++;
            }
        }
    }
    return count;
}

// Oprimal Appraoch Short and Simple
int countHillValley(std::vector<int> &nums)
{
    int count = 0;
    int left = 0;

    for (int i = 1; i < nums.size() - 1; ++i)
    {
        if (nums[i] != nums[i + 1])
        {
            if ((nums[i] > nums[left] && nums[i] > nums[i + 1]) ||
                (nums[i] < nums[left] && nums[i] < nums[i + 1]))
            {
                ++count;
            }
            left = i;
        }
    }

    return count;
}
