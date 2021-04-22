//#include "walid.h"
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


//implementation of python join function
template <typename T>
string py_join(T& v,const string& j=", "){
    auto it = v.begin();
    string res = to_string(*it);
    while (++it!=v.end())res += j+ to_string(*it);
    return res;
}

int main() {
  ios::sync_with_stdio(false);
  int tt,n,k;
  cin>>tt>>n>>k;
  for (int qq = 1; qq <= tt; qq++) {
    vector<int> ans;
    int reply;

    cout<<"1 2 3"<<endl;
    cin>>reply;
    switch(reply){
        case 1:ans={2,1,3};break;
        case 2:ans={1,2,3};break;
        case 3:ans={1,3,2};break;
    }

    for(int i=4;i<=n;i++){
        //ternary search 
        auto it_first=ans.begin();
        auto it_last=ans.end()-1;
        while (it_last>=it_first){
            int distance=(it_last-it_first+1)/3;
            auto it_third1=it_first+distance;
            auto it_third2=it_last-distance;

            //make sure the iterators are different when the distance gets less than 4
            if(it_third2<ans.end()-1)it_third2+=it_third1==it_third2;
            else it_third1-=it_third1==it_third2;

            //compare current element to both first and second thirds simultaneously
            //instead of just the middle for binary search 
            cout<<*it_third1<<" "<<*it_third2<<' '<<i<<endl;
            cin>>reply;

            //set new boundaries according to the reply
            if(reply==*it_third1){
                it_last=it_third1-1;
            }else if(reply==*it_third2){
                it_first=it_third2+1;
            }else{
                it_first=it_third1+1;
                it_last=it_third2-1;
            }
        }

        ans.insert(it_first,i);
        //a list would be more effiecient for insertion
        //but the vectors are small so it is fast enough
        //random access iterator are more convinient to work with 

    }
    cout<<py_join(ans," ")<<endl;
    cin>>reply;
    assert(reply==1);
    
    
  }

}
