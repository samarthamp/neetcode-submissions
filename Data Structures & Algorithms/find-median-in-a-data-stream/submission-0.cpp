class MedianFinder {
private:
    vector<int> data;
    priority_queue<int> maxheap_left;
    priority_queue<int, vector<int>, greater<int>> minheap_right;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (data.size() == 0)
        {
            maxheap_left.push(num);
            minheap_right.push(num);
        }
        
        else if (data.size() % 2 == 0)
        {
            if (num < maxheap_left.top())
            {
                maxheap_left.push(num);
                int temp = maxheap_left.top();
                minheap_right.push(temp);
            }
            else
            {
                minheap_right.push(num);  
                int temp = minheap_right.top();
                maxheap_left.push(temp);       
            }
        }

        else
        {
            if (num < maxheap_left.top())
            {
               maxheap_left.pop();
               maxheap_left.push(num);
            }
            else
            {
                minheap_right.pop();
                minheap_right.push(num);
            }
        }

        data.push_back(num);
    }
    
    double findMedian() {
        // cout << maxheap_left.top() << " " << minheap_right.top() << "\n";
        double ans = ((double)minheap_right.top() + maxheap_left.top())/2;
        return ans;
    }
};
