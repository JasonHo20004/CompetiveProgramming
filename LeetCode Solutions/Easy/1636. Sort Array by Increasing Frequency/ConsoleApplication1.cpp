public:
    vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    // Using a max heap to sort by frequency descending
    auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

    for (auto& it : freq) {
        pq.push(it);
    }

    vector<int> result;
    while (!pq.empty()) {
        auto [num, count] = pq.top();
        pq.pop();
        while (count--) {
            result.push_back(num);
        }
    }
    return result;
}

};