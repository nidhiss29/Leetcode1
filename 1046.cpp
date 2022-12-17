class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        std::priority_queue<int, std::vector<int>, std::less<int>> q(stones.begin(), stones.end());
        auto toppop = [&]() -> auto
        {
            auto tmp = q.top();
            q.pop();
            return tmp;
        };
        while (std::size(q) > 1)
        {
            auto [a, b] = std::make_pair(toppop(), toppop());
            if (a == b)
                continue;
            q.push(std::abs(a - b));
        }
        return std::size(q) == 0 ? 0 : toppop();
    }
};