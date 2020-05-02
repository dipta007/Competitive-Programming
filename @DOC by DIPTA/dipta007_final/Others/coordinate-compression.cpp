/// not necessarily sorted
void compress(int n, int* in, int* out){ /// 0 based index
    unordered_map <int, int> mp;
    for (int i = 0; i < n; i++) out[i] = mp.emplace(in[i], mp.size()).first->second;
}

int main(){
    int data[] = {3, 10, 20, 15, 5, 2, 100, 10, 25, 2, 5};
    map <int, int> mp;
    int ar[100];

    for (int i = 0; i < 11; i++){
        ar[i] = mp.emplace(data[i], mp.size()).first->second;
        dbg(ar[i]);
    }
}

