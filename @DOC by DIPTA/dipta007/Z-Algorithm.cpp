/*Z[i] = max length of the substring starting
from i that is also the prefix of the string*/
int Z[N];
void ZAlgo(string s){
    int len = s.size();
    int l = 0, r = 0;
    Z[0] = 0;
    for(int i = 1; i < len; i++){
        if(i > r){
            l = r = i;
            while(r < len && s[r] == s[r-l])++r;
            Z[i] = r-l, --r;
        }
        else{
            int k = i-l;
            if(Z[k] < r-i+1) Z[i] = Z[k];
            else{
                l = i;
                while(r < len && s[r] == s[r-l])++r;
                Z[i] = r-l, --r;
            }
        }
    }
}
