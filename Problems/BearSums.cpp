// Problem link: https://csacademy.com/ieeextreme-practice/task/bear-sums
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v; // first is the value, second is the index 
int s,e;

int indexOfSameValue(int x, int idx){
    // this function will find the minimum index of the value x other than idx
    int lo=0, hi=v.size()-1, mid, answer=1e9;
    while(lo<=hi){
        mid = (lo+hi)/2;
        if(v[mid].first == x){
            if(v[mid].second!=idx) // save it only when the index is different
                answer = min(answer, v[mid].second);
            hi=mid-1;
        }
        else if(v[mid].first > x){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    if(answer==1e9) // no other value found
        return -1;
    else
        return answer;
}

int findOtherNumber(int x, int idx){
    // this function will check for the same value (both x and s-x are equal)
    if(x*2 == s)
        return indexOfSameValue(x,idx);
    
    int lo=0, hi=v.size()-1, mid; // search the whole range from 0 to size-1
    while(lo<=hi){
        mid =(lo+hi) /2;
        if(v[mid].first == s-x){
            return v[mid].second; // return the actual index of mid that is stored in the second
        }
        else if(v[mid].first > s-x){ // lo-mid-hi
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        cin >> s >> e;
        v.clear();
        v.resize(e);
        for(int i=0;i<e;i++){
            cin >> v[i].first;
            v[i].second=i;
        }
        if(e==0){
            cout << "!OK" << endl;
            continue;
        }
        sort(v.begin(),v.end());
        int firstNumber, secondNumber;
        int minimumIndex = 1e9;
        for(int i=0;i<e;i++){
            int x=v[i].first;
            int idx=v[i].second;
            int newSecondIndex = findOtherNumber(x,idx);
            if(newSecondIndex != -1){
                int newIndex = max(idx,newSecondIndex);
                if(newIndex < minimumIndex){
                    firstNumber = min(x,s-x);
                    secondNumber = max(x,s-x);
                    minimumIndex = newIndex;
                }
            }
        }
        if(minimumIndex == 1e9){
            cout << "!OK" << endl;
        }
        else{
            cout << firstNumber << " " << secondNumber << endl;
        }
    }
    return 0;
}
