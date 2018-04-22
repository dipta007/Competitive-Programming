int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		ll t1, t2, t3;
		scanf("%lld %lld %lld", &t1, &t2, &t3);
		conn[t1].emplace_back(t3*2, t2);
		conn[t2].emplace_back(t3*2, t1);
	}

	priority_queue <pll, vector<pll>, greater<pll>> Hx;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &dis[i]);
		Hx.emplace(dis[i], i);
	}
	while (!Hx.empty()) {
		pll u = Hx.top();
		Hx.pop();
		if (u.first != dis[u.second]) continue;

		for (auto it : conn[u.second]) {
			if (dis[u2.second] > u2.first) {
			pll u2 = pll(it.first + u.first, it.second);
				dis[u2.second] = u2.first;
				Hx.push(u2);
			}
		}
	}
	for (i = 1; i <= N; i++) printf("%lld ", dis[i]);
	return !printf("\n");
}
