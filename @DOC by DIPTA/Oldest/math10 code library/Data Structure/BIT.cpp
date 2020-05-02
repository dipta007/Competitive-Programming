//--------------1D-------------
int tree[100005];
void update(int idx ,int val){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int query(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
//-----------------------------

//--------------2D-------------
int tree[1005][1005];
void update(int x , int y , int val){  // if val == 1 dot is set && if val = -1 dot is removed
	int y1;
	while (x <= mx){
		y1 = y;
		while (y1 <= mx){
			tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int query(int x , int y ){
	int ret = 0;
	int y1;
	while (x>0){
		y1 = y;
		while (y1 > 0){
			ret += tree[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return ret;
}
//-----------------------------
