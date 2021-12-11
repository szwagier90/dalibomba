#include <iostream>
#include <vector>
#include <list>
#include <numeric>

std::pair<std::list<std::list<int>> ,bool> find_subsets(
    std::vector<int>::iterator it_start, 
    std::vector<int>::iterator it_end, 
    int target, 
    std::list<int> & partial)
{
    std::list<std::list<int>> partial_subsets;

    for (; it_start != it_end ; ++it_start)
    {
        partial.push_back(*it_start);
/*
        std::cout << "Partial: ";
        for(const auto & i : partial)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
*/
        int sum = std::accumulate(partial.begin(), partial.end(), 0);
        if(sum == target)
        {
            partial_subsets.push_back(std::list<int>(partial));
        }
        if (sum >= target)
        {
            int popped = partial.back();
            partial.pop_back();
            return std::make_pair(partial_subsets, true);
        }

        std::vector<int>::iterator remaining = it_start;
        
        remaining++;
        auto found = find_subsets(remaining, it_end, target, partial);
        partial_subsets.insert(partial_subsets.end(), found.first.begin(), found.first.end());
        int popped = partial.back();
        partial.pop_back();
    }

    return std::make_pair(partial_subsets, false);
}


int main()
{
    // std::vector<int> v = {2016, 2016, 2016, 2016, 2856, 2957, 5914, 48579, 48579, 529200, 617400, 65541, 69548, 705600, 71551, 71551, 124053, 253422, 270116, 357669, 365485, 375056, 1914946, 2351322, 2875653, 3115457, 3201977};
    std::vector<int> v = {100, 105, 206, 309, 555, 763, 829, 1052, 2016, 2016, 2016, 2016, 2375, 2856, 2957, 3461, 4091, 5914, 738, 10000, 20000, 30000, 48579, 48579, 52920, 61740, 65541, 69548, 70560, 71551, 71551, 124053, 253422, 270116, 357669, 365485, 375056, 1914946, 2351322, 2875653, 3115457, 3201977};

    std::list<int> partial;

    std::pair<std::list<std::list<int>>, bool> all_subsets = 
        find_subsets(v.begin(), v.end(), 56509, partial);

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
