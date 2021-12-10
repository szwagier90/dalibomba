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
    std::cout << "it_start val: " << *it_start << std::endl;
    std::cout << "it_start: " << &*it_start << std::endl;
    std::cout << "it_end: " << &*it_end << std::endl;

    for (; it_start != it_end ; ++it_start)
    std::cout << std::endl << "Partial: ";
    for(const auto & i : partial)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::list<std::list<int>> partial_subsets;

    int sum = std::accumulate(partial.begin(), partial.end(), 0);
    std::cout << "Sum: " << sum << std::endl;

    if(sum == target)
    {
        partial_subsets.push_back(std::list<int>(partial));
    }
    if (sum >= target)
    {
        return std::make_pair(partial_subsets, true);
    }

    std::vector<int>::iterator remaining;
    {
        std::cout << "It: " << *it << std::endl;
        std::cout << "remaining: " << *remaining << std::endl;
        auto pin = *remaining++;
        if (remaining == data.end())
        {
            std::cout << "remaining == data.end()" << std::endl;
            break;
        }
        std::cout << "inc" << std::endl;
        std::cout << "It: " << *it << std::endl;
        std::cout << "remaining: " << *remaining << std::endl;
        std::cout << "Inserting to partial: " << pin << std::endl;
        partial.push_back(pin);
        auto found = find_subsets(data, remaining, target, partial);
        partial_subsets.insert(partial_subsets.end(), found.first.begin(), found.first.end());
        if (found.second == true)
        {
            break;
        }
    }
    int popped = partial.back();
    partial.pop_back();
    std::cout << "Popped from partial: " << popped << std::endl;

    return std::make_pair(partial_subsets, false);
}


int main()
{
    // std::vector<int> v = {2016, 2016, 2016, 2016, 2856, 2957, 5914, 48579, 48579, 5292, 6174, 65541, 69548, 7056, 71551, 71551, 124053, 253422, 270116, 357669, 365485, 375056, 1914946, 2351322, 2875653, 3115457, 3201977};
    std::vector<int> v = {1, 2, 4, 8};

    std::list<int> partial;

    std::pair<std::list<std::list<int>>, bool> all_subsets = 
        find_subsets(v.begin(), v.end(), 6, partial);

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