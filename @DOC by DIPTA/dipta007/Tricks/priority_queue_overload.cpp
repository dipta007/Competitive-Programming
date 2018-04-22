///Priority queue of pairs in reverse order
typedef pair<int, int> P;
priority_queue< P, vector<P>, greater<P> > Q;
This will give the reverse ordering of the normal operator< for pair<int, int>, which will start with the smallest first tie-broken with smallest second.

If you want to sort by smallest second first and first second (!) then you'll need a new sorting functor:

struct Order
{
    bool operator()(P const& a, P const& b) const
    {
        return a.second < b.second || a.second == b.second && a.first < b.first;
    }
}
Then use:

priority_queue< P, vector<P>, Order > Q;
