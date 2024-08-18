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


//MAXIMUM PRODUCT SUBARRAY
	long long maxProduct(vector<int> arr, int n) {
    long long maxProduct = arr[0], minProduct = arr[0], result = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) {
            swap(maxProduct, minProduct);
        }
        maxProduct = max((long long)arr[i], maxProduct * arr[i]);
        minProduct = min((long long)arr[i], minProduct * arr[i]);

        // Update the result to be the maximum of maxProduct and result
        result = max(result, maxProduct);
    }

    return result;
	}


// REVERSE STRING USING STACK
char* reverse(char *S, int len)
{
    stack<char> c;
    for (int i=0;i<len;i++) {
        c.push(S[i]);
    }
    for (int i=0;i<len;i++) {
        S[i] = c.top();
        c.pop();
    }
   return S;
}


//SWAP THE ARRAY ELEMENTS
    void swapElements(int arr[], int n){
        for (int i=0;i<n-2;i++) {
        // Swap elements at index i and i + 2
        int temp = arr[i];
        arr[i] = arr[i + 2];
        arr[i + 2] = temp;
    }
}

//EQUILIBIRIUM POINT
    int equilibriumPoint(vector<long long> &arr) {
        long long sum=0;
        if(arr.size()==1) return 1;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        long long l_sum=0;
        for(int i=0;i<arr.size();i++){
            if(l_sum == sum - l_sum - arr[i]){
                return i+1;
            }
            l_sum+=arr[i];
        }
        return -1;
    }

// CHECK PANAGRAM
    bool checkPangram (string s) {
        bool ans[26]={false};
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (char ch : s) {
        if (isalpha(ch)) {
            ans[ch - 'a'] = true;
        }
    }
    for (bool b : ans) {
        if (!b) {
            return false;
        }
    }
  return true; 
}

// NUMBER OF INTERSECTION IN 2 ARRAYS
   int NumberofElementsInIntersection(int a[], int b[], int n, int m)
    {
    unordered_set<int> setA(a, a + n);
    unordered_set<int> setB(b, b + m);
    int c = 0;
   for (int i=0;i<m; i++) {
        if (setA.find(b[i]) != setA.end()) {
            c++;
            setA.erase(b[i]);  // Remove the element to avoid counting duplicates
        }
    }
    return c;
}

// FIRST NON-REPEATING ELEMENT
   int firstNonRepeating(vector<int>& arr) {
        map<int,int> result;
        for(auto num: arr){
            result[num]++;
        }
        for(auto num: arr){
            if(result[num]==1){
                return num;
            }
        }
        return 0;
    }


// COMMON IN 3 SORTED ARRAY
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,vector<int> &arr3) {
        vector<int> r;
        int i=0,j=0,k=0;
        while(i<arr1.size() && j<arr2.size() && k<arr3.size()){
            if(arr1[i]==arr2[j] && arr1[i]==arr3[k]){
                 if (r.empty() || r.back() != arr1[i]) {
                 r.push_back(arr1[i]);
            }
                i++;
                j++;
                k++;
            }
        
            else if(arr1[i]<arr2[j])
                i++;
                
            else if(arr2[j]<arr3[k])
                j++;
                
            else
                k++;
            
        }
        return r;
  }


// REVERSE LINKED LIST
struct Node
{
    int data;
    struct Node *next;
}

class Solution {
  public:
    struct Node* reverseList(struct Node* head) {
        struct Node* prev = nullptr;
        struct Node* current = head;
        struct Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;  // Store the next node
            current->next = prev;   // Reverse the current node's pointer
            prev = current;         // Move the prev pointer forward
            current = next;         // Move the current pointer forward
        }
    return prev;
    }
};
