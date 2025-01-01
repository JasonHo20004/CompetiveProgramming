class Solution {
public:
    int partition(vector<string>& names, vector<int>& heights, int low, int high) {
        int pivot = heights[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (heights[j] >= pivot) {
                i++;
                swap(heights[i], heights[j]);
                swap(names[i], names[j]);
            }
        }
        swap(heights[i + 1], heights[high]);
        swap(names[i + 1], names[high]);
        return i + 1;
    }

    void quicksort(vector<string>& names, vector<int>& heights, int low, int high) {
        if (low < high) {
            int pi = partition(names, heights, low, high);

            quicksort(names, heights, low, pi - 1);
            quicksort(names, heights, pi + 1, high);
        }
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        quicksort(names, heights, 0, heights.size() - 1);
        return names;
    }
};