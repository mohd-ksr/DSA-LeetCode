class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long sum=0;
        for(int b:batteries)sum+=b;
        long s=1, e=sum/n;
        while(s<e){
            long target = e-(e-s)/2;
            long extra = 0;
            for(int b:batteries)extra+=min((long)b,target);
            if(extra>=(long)(n*target))s=target;
            else e=target-1;
        }
        return s;
    }
};