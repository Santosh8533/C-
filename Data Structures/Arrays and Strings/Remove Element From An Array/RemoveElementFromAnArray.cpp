int Solution::removeElement(vector<int> &A, int B) {
    sort(A.begin(),A.end()); //111243
    int start=-1,end=0;
    queue<int> q;
    for(int i=0;i<A.size();i++){
        if(A[i]==B){
            if(start==0)start = i; //0
            else end=start+1; //2
        }
        else if(start>=0){
            q.push(A[i]);
        }
    }
    int len = A.size()-1;
    int count = len-end; //
    while(count>0){
        A.pop_back();
        count--;
    }

    for(int i=end;i>=start;i--){
        A.pop_back();
    }

    while(!q.empty()){
        A.push_back(q.front());
        q.pop();
    }
    return A.size();
}
