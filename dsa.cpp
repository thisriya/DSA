#include<bits/stdc++.h>
using namespace std;
//UNION OF SORTED ARRAY
class solution{
    public:
   vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
    set<int> set_result;
    for(int i=0;i<n;i++){
        set_result.insert(arr1[i]);
    }
    for(int j=0;j<m;j++){
        set_result.insert(arr2[j]);
    }
    vector<int> result(set_result.begin(),set_result.end());
    return result;
    }
};


//REMOVE DUPLICATE FROM ARRAY
int remove_duplicate(vector<int> &arr) {
    auto last = unique(arr.begin(), arr.end());
    arr.erase(last, arr.end());
    return arr.size();
}


//MERGE SORTED ARRAY
vector<int> mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;
    int n1 = arr1.size(), n2 = arr2.size();
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n1) {
        merged.push_back(arr1[i]);
        i++;
    }
    while (j < n2) {
        merged.push_back(arr2[j]);
        j++;
    }
    return merged;
}

//BUBBLE SORT
    void swap(int &a,int &b){
        int t=a;
        a=b;
        b=t;
    }
    void bubbleSort(int arr[], int n) {
        bool swaping=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    swaping=true;
                }
            }
             if(swaping==false) {
                break;
            }
        }
           
    }

