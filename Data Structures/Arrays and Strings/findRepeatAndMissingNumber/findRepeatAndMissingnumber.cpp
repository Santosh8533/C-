vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> res;
    vector<int> input(A.begin(),A.end());
    sort(input.begin(),input.end());
    /*for(int i:input){
        cout<<i<<"\t";
    }*/

    int missing = 0;
    for(int i=0;i<input.size()-1;i++){
        int current = input[i];
        //if first number is missing
        if(i==0 && current!=1){missing = 1;}
        int next = input[i+1];
        if(current == next){
            res.push_back(current);
        }

        //missing number in the middle
        if(next - current>1){
            missing = current+1;
        }
    }
    //if last number is missing
    if(missing ==0){missing = input.size();}
    res.push_back(missing);
    return res;
}
