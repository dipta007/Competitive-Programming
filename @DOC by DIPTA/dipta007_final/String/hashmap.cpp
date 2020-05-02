#define ran(a, b) (((unsigned)((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))

struct hashmap{
    int t, sz, hmod;
    vector <int> id;
    vector <long long> key, val;

    inline int nextPrime(int n){
        for (int i = n; ;i++){
            for (int j = 2; ;j++){
                if ((j * j) > i) return i;
                if ((i % j) == 0) break;
            }
        }
        return -1;
    }

    inline int pos(unsigned long long x){
        int i = x % hmod;
        while (id[i] == t && key[i] != x) i++;
        return i;
    }

    /// clears hashmap, equivalent to map.clear()
    void clear(){t++;}

    /// insert key x and set it to v, equivalent to map[x] = v
    inline void insert(long long x, long long v){
        int i = pos(x);
        if (id[i] != t) sz++;
        key[i] = x, val[i] = v, id[i] = t;
    }

    /// erase key x from the hashmap if exists
    inline void erase(long long x){
        int i = pos(x);
        if (id[i] == t) key[i] = 0, val[i] = 0, id[i] = 0, sz--;
    }

    /// returns the value assigned to key x, -1 if no value is assigned, equivalent to map[x]
    inline long long find(long long x){
        int i = pos(x);
        return (id[i] != t) ? -1 : val[i];
    }

    /// check if x contained in hashmap, equivalent to map.count(x)
    inline bool contains(long long x){
        int i = pos(x);
        return (id[i] == t);
    }

    /// add v to index x, equivalent to map[x] += v
    inline void add(long long x, long long v){
        int i = pos(x);
        (id[i] == t) ? (val[i] += v) : (key[i] = x, val[i] = v, id[i] = t, sz++);
    }

    /// size of hashmap, equivalent to map.size()
    inline int size(){
        return sz;
    }

    hashmap(){}
    hashmap(int m){ /// m = maximum number of keys to be inserted in hashmap
        srand(time(0));
        m = m * 3 - ran(1, m);
        hmod = nextPrime(max(100, m));

        sz = 0, t = 1;
        id.resize(hmod + 0x1FF, 0);
        key.resize(hmod + 0x1FF, 0), val.resize(hmod + 0x1FF, 0);
    }
};

int main(){
}


