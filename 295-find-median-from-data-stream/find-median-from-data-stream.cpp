class MedianFinder {
private:
    priority_queue<int>left;
    priority_queue<int, vector<int>, greater<int>>right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()<=right.size()){
            left.push(num);
        }
        else{
            right.push(num);
        }
        int ls = left.size(), rs = right.size();
        while(ls>0 && rs>0){
            if(left.top() > right.top()){
                int leftMax = left.top();
                left.pop();
                int rightMin = right.top();
                right.pop();
                left.push(rightMin);
                right.push(leftMax);
            }
            else break;
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()){
            int a = left.top();
            int b = right.top();
            return double(a+ b) / 2.0;
        }
        else return (double)left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */