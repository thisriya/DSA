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


// HEIGHT OF BINARY TREE
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution{
    public:
    int height(struct Node* node){
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    
    }
};

// IDENTICAL TREES
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1==nullptr && r2==nullptr){
            return true;
        }
        if(r1==nullptr || r2==nullptr){
            return false;
        }
        
        return (r1->data == r2->data) && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
    }
};


// INDENTICAL MATRICES
    int areMatricesIdentical(int N, vector<vector<int>> Grid1,
                             vector<vector<int>> Grid2) {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(Grid1[i][j]!=Grid2[i][j]){
                    return 0;
                }
            }
        }
        return 1;
    }


// IDENTICAL LINKED LIST USING NEXT 
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
bool areIdentical(struct Node *head1, struct Node *head2) {
  while(head1!=nullptr && head2!=nullptr){
      if(head1->data!=head2->data){
          return false;
      }
      head1=head1->next;
      head2=head2->next;
  }
  return head1==nullptr && head2==nullptr;
}


// COUNT NUMBER OF LINKED LISTS
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; 
class Solution {
  public:
    int getCount(struct Node* head) {
        int c=0;
        while(head!=nullptr){
            c++;
            head=head->next;
        }
        return c;
    }
};


// INSERT AT LAST
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node* newnode= new Node(x);
        if(head==nullptr) return newnode;
        Node* curent=head;
        while(curent->next!=nullptr){
            curent=curent->next;
        }
        curent->next=newnode;
        return head;
    }
};


// FIND IF LENGTH IS EVEN
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        int c=0;
        Node* current=*head;
        while(current!=nullptr){
            c++;
            current=current->next;
        }
        return c%2==0;
    }
};


// DISPLAY DOUBLY LINKED LIST
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};
vector<int> displayList(Node *head)
{
    vector<int> result1;
    vector<int> result2;
    Node* current=head;
    Node* last=nullptr;
    while(current!=nullptr){
        result1.push_back(current->data);
        last=current;
        current=current->next;
    }
    current=last;
     while(current!=nullptr){
        result2.push_back(current->data);
        current=current->prev;
    }
    return result1;
    return result2;
}


// IMMEDIATE SMALLER NUMBER
class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    for(int i=0;i<n;i++){
	        if(arr[i]>arr[i+1]){
	            arr[i]=arr[i+1];
	        }
	        else{
	            arr[i]=-1;
	        }
	    }
	    arr[n-1]=-1;
	}

};


// PAIRWISE CONSECUTIVE
bool pairWiseConsecutive(stack<int> s)
{
   bool ans=true;
   vector<int> elements;
   stack<int> temp;
   while(!s.empty()){
       temp.push(s.top());
       elements.push_back(s.top());
       s.pop();
   }
   while(!temp.empty()){
       s.push(temp.top());
       temp.pop();
   }
   int n=elements.size();
   if(n%2==1){
    n--;
   }
   for(int i=0;i<n;i+=2){
       if(elements[i]+1 != elements[i+1] && elements[i]-1 != elements[i+1]){
           ans=false;
           break;
       }
   }
   
   return ans;
}


// STACK DESIGNER
stack<int>_push(int arr[],int n)
{
    stack<int> s;
     for (int i=0;i<n;i++) {
        s.push(arr[i]);
    }
    return s;
}

/* _pop function to print elements of the stack
   remove as well
*/
void _pop(stack<int> s)
{
    
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
}


// DELETE THE MIDDLE ELEMENT OF STACK
class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s, int sizeOfStack) {
        int pos=sizeOfStack/2;
        stack<int> temp;
        for(int i=0;i<pos;i++){
            temp.push(s.top());
            s.pop();
        }
        s.pop();
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
    }
};


// COUNT LENGTH OF LOOP
    int countNodesinLoop(struct Node *head) {
        if (!head) return 0;  // If the list is empty, return 0
        
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                int count = 1;
                Node* temp = slow;
                
                while (temp->next != slow) {
                    count++;
                    temp = temp->next;
                }
                
                return count; 
            }
        }
        return 0;
    }


// SMALLEST POSITIVE MISSING NUMBER
    int missingNumber(int arr[], int n) 
    { 
           for (int i = 0; i < n; i++) {
            while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        
        // Step 2: Find the first index which doesn't have the correct element
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        
        // Step 3: If all elements are in their correct positions
        return n + 1;
    } 


// REMOVE DUPLICATE IN UNSORTED LINKED LIST
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
class Solution {
  public:
    Node *removeDuplicates(Node *head) {
           if (!head) return head; // If the list is empty, return immediately.

        std::unordered_set<int> seen; // Set to store already seen values.
        Node *current = head;
        Node *prev = nullptr;

        while (current != nullptr) {
            if (seen.find(current->data) != seen.end()) {
                // If current node's data is already seen, skip it.
                prev->next = current->next;
                delete current; // Optional: Free the memory of the duplicate node.
                current = prev->next; // Move to the next node.
            } else {
                // If the current node's data is not seen, add it to the set.
                seen.insert(current->data);
                prev = current;
                current = current->next;
            }
        }

        return head;
    }
};


// VALID EXPRESSION FOR THE PARENTHESIS
bool valid(string s)
{
    stack<char> stk;
    for(char ch:s){
         if(ch=='(' || ch=='[' ||ch=='{'){
             stk.push(ch);
         }
         else {
             if(stk.empty()) return false;
             
             char top=stk.top();
             if((ch==')' && top=='(') || (ch==']' && top=='[') || (ch=='}' && top=='{' )){
                 stk.pop();
             }
             else{
                 return false;
             }
         }
    }
    return (stk.empty());
}


//CHECK IF THE ELEMENT IS IN THE SERIES
    int inSequence(int A, int B, int C){
        //A first term, C common difference, B find if this term present;
        if(A==B) return 1;
        if(C==0) return 0;
        if((B-A)%C==0 && (B-A)/C >=0) return 1;
        return 0;
    }

