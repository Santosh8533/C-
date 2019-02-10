bool myCompare(string a,string b){
     string ab = a.append(b);
     string ba = b.append(a);
     return ab.compare(ba)>0?1:0;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> sints;
    for(int i=0;i<A.size();i++){
        if(A.at(i)!=0)sints.push_back(to_string(A.at(i)));
    }

    //to cover if all the input elements are zeroes
    if(sints.size()==0){return string("0");}

    sort(sints.begin(),sints.end(),myCompare);

    string res;
    for(int i=0;i<sints.size();i++){
        res.append(sints.at(i));
    }
    return res;
}
