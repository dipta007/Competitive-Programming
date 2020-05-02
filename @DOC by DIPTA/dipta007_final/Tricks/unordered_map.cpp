/// Hash function for pair <int, int>
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()( ((long long)x.first) ^ (((long long)x.second)<<32) );
  }
};
unordered_map<pair<int,int>,int,HASH>mp;

/// Make unordered_map faster
unordered_map<int,int>mp;
mp.reserve(1024);
mp.max_load_factor(0.25);


