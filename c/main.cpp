#include <iostream>
#include <vector>
#include <list>
#include <numeric>

std::pair<std::list<std::list<int>> ,bool> find_subsets(
    const std::vector<int> & data, 
    std::vector<int>::iterator it, 
    int target, 
    std::list<int> & partial)
{
    std::list<std::list<int>> partial_subsets;

    int sum = std::accumulate(partial.begin(), partial.end(), 0);

    if(sum == target)
    {
        partial_subsets.push_back(std::list<int>(partial));
    }
    if (sum >= target)
    {
        return std::make_pair(partial_subsets, true);
    }

    std::vector<int>::iterator remaining;
    for (remaining = it; remaining != data.end(); ++remaining)
    {
        partial.push_back(*(++remaining));
        auto found = find_subsets(data, remaining, target, partial);
        partial.pop_back();
        partial_subsets.insert(partial_subsets.end(), found.first.begin(), found.first.end());
        if (found.second == true)
        {
            break;
        }
    }

    return std::make_pair(partial_subsets, false);
}


int main()
{
    // std::vector<int> v = {2016, 2016, 2016, 2016, 2856, 2957, 5914, 48579, 48579, 5292, 6174, 65541, 69548, 7056, 71551, 71551, 124053, 253422, 270116, 357669, 365485, 375056, 1914946, 2351322, 2875653, 3115457, 3201977};
    std::vector<int> v = {5, 7, 20, 23};

    std::list<int> partial;

    std::pair<std::list<std::list<int>>, bool> all_subsets = find_subsets(v, v.begin(), 30, partial);

    for(const auto & subset : all_subsets.first)
    {
        std::cout << "[ ";
        for(const auto & s : subset)
        {
            std::cout << s << ", ";
        }
        std::cout << " ]" << std::endl;
    }

    return 0;
}