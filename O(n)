#include <iterator>
#include <unordered_set>

template <typename Iterator, typename T>
std::pair<bool, std::pair<Iterator, Iterator> > find_two_elements_with_sum(Iterator first, Iterator last, T c)
{
    std::unordered_set<T> my_set;
    std::pair<bool, std::pair<Iterator, Iterator> > p;
    Iterator one = last;
    Iterator two = last;
    p = std::make_pair(false, std::make_pair(one, two));
    for (auto i = first; i != last; ++i) {
        if (my_set.find(*i) != my_set.end()) {
            p.first = true;
            one = i;
            p.second = std::make_pair(one, two);
            return p;
        }
        else {
            my_set.insert(c - (*i));
            two = i;
        }
    }
    return p;
}
