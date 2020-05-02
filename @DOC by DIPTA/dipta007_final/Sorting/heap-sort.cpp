vector<int >A;
int heap_size;

void Max_heapify(int id){
    int lf = id*2 , rt = lf+1;
    int largest = id;
    if(lf<=heap_size && A[lf]>A[largest]) largest = lf;
    if(rt<=heap_size && A[rt]>A[largest]) largest = rt;
    if(largest!=id){
        swap(A[largest],A[id]);
        Max_heapify(largest);
    }
}

void build_max_heap(){
    heap_size = A.size()-1;
    rofba(i,1,heap_size/2){
        Max_heapify(i);
    }
}

void heap_sort(){
    build_max_heap();
    rofba(i,2,heap_size){
        swap(A[1],A[i]);
        heap_size--;
        Max_heapify(1);
    }
}

int main(){
    A.clear();
    int n = II;
    A.pb(0); //first garbage
    rep(i,n){
        int u = II;
        A.pb(u);
    }
    heap_sort();
    For(i,n) cout << A[i] << " ";
}
