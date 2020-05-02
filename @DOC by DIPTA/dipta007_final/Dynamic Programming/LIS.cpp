// Given a list of numbers of length n, this routine extracts a
// longest increasing subsequence.
//
// Running time: O(n log n)
//
//   INPUT: a vector of integers
//   OUTPUT: a vector containing the longest increasing subsequence

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define STRICTLY_INCREASNG

vi LongestIncreasingSubsequence(vi v)
{
    vpii best;
    vi dad(v.size(), -1);

    for (int i = 0; i < v.size(); i++)
    {
#ifdef STRICTLY_INCREASNG
        pii item = make_pair(v[i], 0);
        vpii::iterator it = lower_bound(best.begin(), best.end(), item);
        item.second = i;
#else
        pii item = make_pair(v[i], i);
        vpii::iterator it = upper_bound(best.begin(), best.end(), item);
#endif
        if (it == best.end())
        {
            dad[i] = (best.size() == 0 ? -1 : best.back().second);
            best.push_back(item);
        }
        else
        {
            dad[i] = it == best.begin() ? -1 : prev(it)->second;
            *it = item;
        }
    }

    vi ret;
    for (int i = best.back().second; i >= 0; i = dad[i])
        ret.push_back(v[i]);
    reverse(ret.begin(), ret.end());
    return ret;
}

