class NestedIterator {
	stack<NestedInteger> s;
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		for (int i = nestedList.size() - 1; i >= 0; i--)
			s.push(nestedList[i]);
	}

	int next() {
		int res = s.top().getInteger();
		s.pop();
		return res;
	}

	bool hasNext() {
		while (!s.empty()) {
			NestedInteger curr = s.top();
			if (curr.isInteger())
				return true;

			s.pop();
			vector<NestedInteger> adj = curr.getList();
			int size = adj.size();
			for (int i = size - 1; i >= 0; --i) {
				s.push(adj[i]);
			}
		}

		return false;
	}
};
