/**
    Author: Santosh Tandrothu
    Date: 2/9/2019
    Problem:Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
            If there is no solution possible, return -1.
            Example:->A : [3 5 4 2]
                    Output : 2 for the pair (3, 4)
**/
int maximumGapN_2(const vector<int> &A) {

    if(A.size()==1){return 0;}
    int revPtr = A.size()-1;
    int maxDist=0;
    int currDist=0;
    for(int i=0;i<A.size();i++){
        while(i<revPtr){
            if(A[i]<=A[revPtr]){
                currDist = revPtr-i;
                maxDist = max(maxDist,currDist);
                currDist = 0;
                break;
            }
            revPtr--;
        }
        revPtr = A.size()-1;
    }
    if(maxDist==0){return 0;}
    return maxDist;
}

class Solution {
    public:
        int maximumGap(const vector<int> &num) {
            if (num.size() == 0) return -1;
            if (num.size() == 1) return 0;
            vector<pair<int, int> > toSort;
            for (int i = 0; i < num.size(); i++) {
                toSort.push_back(make_pair(num[i], i));
            }
            sort(toSort.begin(), toSort.end());
            int len = toSort.size();
            int maxIndex = toSort[len - 1].second;
            int ans = 0;
            for (int i = len - 2; i >= 0; i--) {
                ans = max(ans, maxIndex - toSort[i].second);
                maxIndex = max(maxIndex, toSort[i].second);
            }
            return ans;
        }
};
