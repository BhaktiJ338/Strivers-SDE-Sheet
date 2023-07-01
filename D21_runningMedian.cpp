#include <queue>

void findMedian(int *arr, int n)
{
    priority_queue<int>maxh;
    priority_queue<int, vector<int>, greater<int>>minh;

    for(int i=0; i<n; i++){
        if(maxh.empty() || arr[i]<=maxh.top()){ 
            maxh.push(arr[i]);
        }
        else{
            minh.push(arr[i]);
        }
        if(maxh.size()<minh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
        else if(maxh.size()>minh.size()+1){
            minh.push(maxh.top());
            maxh.pop();
        }

        if(maxh.size()==minh.size()){
            cout<<(maxh.top()+minh.top())/2<<" ";
        }
        else{
            cout<<maxh.top()<<" ";
        }

    }
}
