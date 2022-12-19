class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int currentBestScore = values[0] + values[1] - 1;
        int maxScore = currentBestScore;

        for (int i = 2; i < values.size(); i++)
        {
            currentBestScore = max(currentBestScore - values[i - 1], values[i - 1]) + values[i] - 1;
            maxScore = max(maxScore, currentBestScore);
        }

        return maxScore;
    }
};