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

// COUNT THE NUMBER OF SETS (1) IN BINARY CONVERSION
    int setBits(int n) {
        int ans=0,i=0,c=0;
        while(n!=0){
            int bit=n&1;
            if(bit==1) c++;
            int ans=(bit * pow(10,i))+ans;
            n=n>>1;
            i++;
        }
        return c;
    }

// MINIMUM OF STACK
#include<climits>
void push(stack<int>& s, int a){
	    s.push(a);
	}

bool isFull(stack<int>& s,int n){
	if(s.size()==n){
	    return true;
	}
	else{
	    false;
	}
}

bool isEmpty(stack<int>& s){
	if(s.size()==0){
	    return true;
	}
	else{
	    return false;
	}
}

int pop(stack<int>& s){
	if(s.size()>=1){
	    s.pop();
	}
}

int getMin(stack<int>& s){
	int min=INT_MAX;
	while(!s.empty()){
	int element=s.top();
	if(element<min){
	    min=element;
	}
	s.pop();
}
	return min;
}


// REMOVE THE ELEMENTS WITH THE DIFFERENT SIGN
class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> result;
       for (int num : arr) {
        if (!result.empty() && (result.back() < 0) != (num < 0)) {
            // If current number and the top of result have different signs, pop from result
            result.pop_back();
        } else {
            // Otherwise, push the current number to result
            result.push_back(num);
        }
    }
        return result;
    }
};


// GIVING THE MINIMUM OF THE STACK
class Solution{
    int minEle;
    stack<int> s;
    public:
    int getMin() {
    if (s.empty()) {
        return -1; // Stack is empty, no minimum element
    }

    int min = INT_MAX;
    stack<int> temp;  
    while (!s.empty()) {
        int element = s.top();
        s.pop();
        if (element < min) {
            min = element;
        }
        temp.push(element);
    }
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }

    return min;
}

       /*returns poped element from stack*/
       int pop(){
           
           if(s.empty()){
               return -1;
           }
          int el=s.top();
          s.pop();
          return el;
       }
       
       /*push element x into the stack*/
       void push(int x){
             s.push(x);
       }
};


// SORT A STACK
void SortedStack :: sort()
{
   stack<int> stk;
   while(!s.empty()){
       int t=s.top();
       s.pop();
   
   while(!stk.empty() && stk.top()<t){
       s.push(stk.top());
       stk.pop();
   }
   stk.push(t);
   }
  while (!stk.empty()) {
        s.push(stk.top());
        stk.pop();
    }
}


// MARK EVEN ODD IN PYTHON

def checkOddEven(x):
    if(x % 2 == 0):
      return True
    else:
        # Complete the statement below
        return False


//  IF ELIF CONDITIONAL STATEMENT
def friends_in_trouble(j_angry, s_angry):
    if j_angry == s_angry:  
        return True
    else:
        return False

// CHECKING STATUS IN PYTHON
def check_status(a, b, flag):
    if ((a >= 0) != (b >= 0)) and not flag:
        return True
    elif a < 0 and b < 0 and flag:
        return True
    else:
        return False

// MULTIPLICATION TABLE IN PYTHON
def multiplicationTable(N):## in is a membership operator that is true if something is a member of sequence
    for i in range(1,11): 
        print(i * N, end=" ") 

// PRINT ALTERNATIVE CHARACTERS OF STRING
def stringJumper(str):
    for i in range(0, len(str) , 2): ## from 0 to length of str and skip 2
        print(str[i], end="")

// CHECK IF STRING STARTS AND ENDS WITH GFG
def gfg(S):
    b = S.lower()
    if(b.startswith("gfg") and b.endswith("gfg")):  
        print ("Yes")
    else:
        print ("No")

// FUNCTIONS
def trim(str):
    return str.strip()

def exists(str, x):
    return str.find(x)

def titleIt(str):
    return str.title()

def casesSwap(str):
    return str.swapcase()


// SQUARES DIFF (1+2)^2 - 1^2+ 2^2 POSITIVE VALUE
class Solution:
    def squaresDiff (self, N):
        sum=0
        s=0
        for i in range(1,N+1):
            sum= sum+i
            s= s+ i*i
        
        sqr=sum*sum
        ans=sqr-s
        absolute_ans = abs(ans)
        return absolute_ans

// OPERATIONS IN SETS IN PYTHON
def insert(S, element):
    S.add(element)
    
def remove_from_set(S, element):
    S.remove(element)
    
def sum_set(S):
    return sum(S)


// PRINT IN DESCENDING ORDER
def printInDecreasing(x):
    # Complete the code below
    while(x >= 0):
        print(x,end=" ")
        x -= 1


// PRIME IN JAVA
class Solution {
    public static String isPrime(int n) {
        int f=-1;
        if(n==1 || n==0) return "No";
        for(int i=2;i<n;i++){
            if(n%i==0){
                f=1;
            }
        }
        if(f==-1)  return "Yes";
        else return "No";
    }
}

// STRONG NUMBER WHERE THE SUM OF FACTORIAL OF DIGITS IS EQUAL TO NUMBER
    int fac(int n){
	        int f=1;
	        if(n==0 || n==1){
	            return 1;
	        }
	        
	        for(int i=1;i<=n;i++){
	            f=f*i;
	        }
	        return f;
	    }
	    
		int is_StrongNumber(int n)
		{
		    int m=n,dig,factorial,sum=0;
		    while(m!=0){
		        dig=m%10;
		        factorial=fac(dig);
		        sum=sum+factorial;
		        m=m/10;
		    }
		   if(sum==n){
		       return 1;
		   }
		   else{
		       return 0;
		   }
		}


// PRIME SUM BETWEEN SPECIFIC RANGE
class Solution {
  public:
  
     bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
    long long getPPS(int a, int b) {
        long long sum=0;
        vector<int> primes;
        for(int i=a;i<=b;i++){
            if(isPrime(i)){
                primes.push_back(i);
            }
        }
        for(int i=0;i<primes.size();i++){
            sum=sum+primes[i];
        }
        return sum;
    }
};


// ZERO CONVERTER PYTHON
def pos(n):
    while(n!=0):
        print(n-1,end=" ")
        n=n-1
        
    
def neg(n):
    while n<=0:
        print(n,end=" ")
        n=n+1


// SUM OF SQUARE OF ODD NUMBERS
long long int sum_of_square_oddNumbers(long long int n)
{		
long long int sum=0;
for(long long int i=1;i<=2*n;i++){
if(i%2!=0){
  sum=sum+ (i*i);
   }
}
return sum;
}


// PRODUCT OF FACTOR OF NUMBER
    def factorProduct(self, N: int) -> int:
        MOD = 10**9 + 7
        product = 1
        
        # Loop to find all factors
        for i in range(1, int(N**0.5) + 1):
            if N % i == 0:
                # i is a factor
                product = (product * i) % MOD
                # N // i is also a factor
                if i != N // i:  # Avoid double counting when i and N // i are the same
                    product = (product * (N // i)) % MOD
        
        return product

// FIBONACCI SERIES
const int MOD=1000000007;
vector<int> Series(int n) {
    vector<int> result;
    if (n == 1) {
        result.push_back(0); // If n == 1, return both 0 and 1
        result.push_back(1);
        return result;
    }
    vector<long long> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    result.push_back(fib[0]);
    result.push_back(fib[1]);

    for (int i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD; // Ensure mod operation
        result.push_back(fib[i]);
    }

    return result;
    }


// MIDDLE OF ELEMENTS
   int middle(int A, int B, int C){
    if ((A <= B && B <= C) || (C <= B && B <= A)) {
        return B;
    }
    if ((B <= A && A <= C) || (C <= A && A <= B)) {
        return A;
    }
    if ((A <= C && C <= B) || (B <= C && C <= A)) {
        return C;
    }
    }


// FIND THE VOLUME OF THE CUBOID USING CLASS
class Cuboid 
{
   protected:
     int l,w,h;
   public:
       void display() {
        cout << l << " " << w << " " << h << endl;
    }
};

class CuboidVol: public Cuboid
{
    public:
     void read_input(int length,int width,int height){
         l=length;
         w=width;
         h=height;
         }
         
     void display() {
        int volume=l*w*h;
        cout<<volume<<endl;
    }
};


// FUNCTION OVERLOADING
void volume(int s)
{
    double v=s*s*s;
    cout<<v<<endl;
}

void volume(int r, int h)
{
    const double pi=3.14159;
    double v= pi*r*r*h;
    cout<<v<<endl;
}

void volume(int l, int b, int h)
{
    double v=l*b*h;
    cout<<v<<endl;
}


// SEARCHING IN MATRIX
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    int ans=0;
	    for(int i=0;i<N;i++){
	        for(int j=0;j<M;j++){
	            if(mat[i][j]==X){
	                ans=1;
	                break;
	            }
	        }
	    }
	    return ans;
	}


// FIND THE ELEMENT APPEARING ONCE IN SORTED ARRAY
    int findOnce(int arr[], int n)
    {
        map<int,int> result;
        for(int i=0;i<n;i++){
            result[arr[i]]++;
        }
        int ans;
        for(auto itr: result){
            if(itr.second==1){
                ans=itr.first;
            }
        }
        return ans;
    }


//  FIRST AND LAST OCCURRENCE OF X
    vector<int> firstAndLast(int x, vector<int> &arr) {
        vector<int> result;
        int f=-1,l=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==x){
                f=i;
                break;
            }
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]==x){
                l=i;
            }
        }
        if(l>=0 && f>=0){
        result.push_back(f);
        result.push_back(l);
        return result;
        }
        else{
        return {-1};
            
        }
    }


// BUILDING FACING SUN
    int countBuildings(vector<int> &height) {
        int c=1;
        int maxh=height[0];
        for(int i=1;i<height.size();i++){
            if(height[i]>maxh){
                c++;
                maxh=height[i];
            }
        }
        return c;
    }


// PRINT RECURSIVELY
    void printGfg(int N) {
    if (N == 0) {
        return;  // Base case to stop recursion
    }
        cout<<"GFG"<<" ";
        printGfg(N-1);
    }


// MINIMUM OF BST
/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

class Solution {
  public:
    int minValue(Node* root) {
       if(root==nullptr){
           return -1;
       }
       while(root->left!=nullptr){
           root=root->left;
       }
       return root->data;
    }
};


// INSERT IN NODE
/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
    public:
        Node* insert(Node* node, int data) {
            if(node==nullptr){
                return new Node(data);
            }
            if(data<node->data){
                node->left=insert(node->left,data);
            }
            if(data>node->data){
                node->right=insert(node->right,data);
            }
            return node;
    }

};


// CHECK FOR BST
      bool isBSTUtil(Node* root, int minVal, int maxVal) {
        if (root == nullptr) {
            return true;
        }

        if (root->data < minVal || root->data > maxVal) {
            return false;
        }

        // Recursively check the left and right subtrees
        return isBSTUtil(root->left, minVal, root->data - 1) && 
               isBSTUtil(root->right, root->data + 1, maxVal);
    }
    bool isBST(Node* root) {
      return isBSTUtil(root, INT_MIN, INT_MAX);
    }


// SEARCH IN BST
bool search(Node* root, int x) {
    if(root==nullptr){
        return false;
    }
    while(root!=nullptr){
        if(x<root->data){
            root=root->left;
        }
        else if(x>root->data){
            root=root->right;
        }
        else{
            return true;
        }
    }
}

// ELEMENT AT PARTICLUAR INDEX
class Solution {
  public:
    int GetNth(Node *head, int index) {
        if(head==nullptr){
            return -1;
        }
        int i=1;
        while(head!=nullptr){
             if(i==index){
                return head->data;
            }
            head=head->next;
            i++;
        }
        return -1;
    }
};


// FIRST REPEATING ELEMENT
    char firstRep (string s)
    {
      map<char,int> result;
      for(char num:s){
          result[num]++;
      }
      
      for(char c:s){
          if(result[c]>1){
              return c;
          }
      }
      return '#';
    }


// MERGE 2 BST TREES
class Solution {
  public:
  
       vector<int> mergeSortedArrays(const vector<int>& list1, const vector<int>& list2) {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < list1.size() && j < list2.size()) {
            if (list1[i] <= list2[j]) {
                merged.push_back(list1[i]);
                i++;
            } else {
                merged.push_back(list2[j]);
                j++;
            }
        }
        // Add remaining elements from list1, if any
        while (i < list1.size()) {
            merged.push_back(list1[i]);
            i++;
        }
        // Add remaining elements from list2, if any
        while (j < list2.size()) {
            merged.push_back(list2[j]);
            j++;
        }
        return merged;
    }
    
       void inorder(Node* root, vector<int>& result) {
        if (root == nullptr)
            return;
        inorder(root->left, result);
        result.push_back(root->data);
        inorder(root->right, result);
    }
    
    
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> list1, list2;
        // Perform inorder traversal of both trees
        inorder(root1, list1);
        inorder(root2, list2);
        // Merge the two sorted lists
        return mergeSortedArrays(list1, list2);
    
    }
};


// MAJORITY VOTE GREATER THEN N/3
  vector<int> findMajority(vector<int>& nums) {
        vector<int> result;
        int n=nums.size();
        map<int,int> r;
    if (n == 0) {
        result.push_back(-1);
        return result;
    }
        for(int i=0;i<n;i++){
            r[nums[i]]++;
        }
        int threshhold=n/3;
        for(auto it : r){
            if(it.second>threshhold){
                result.push_back(it.first);
            }
        }
        
        if(result.empty()){
        result.push_back(-1);
    }

        return result;
    }

// ROTATE AND DELETE
 int rotateDelete(vector<int> &arr) {
    int n=arr.size();  
    int opr=n/2;     

    for (int i=1;i<=opr;i++) {
        int lastElement=arr.back(); 
        arr.pop_back();              
        arr.insert(arr.begin(),lastElement); 
        int delIndex=arr.size()-i;  
        arr.erase(arr.begin()+delIndex);  
    }

    return arr[0];
    }


// MULTIPLY TWO LISTS
#define MOD 1000000007
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long num1=0,num2=0;
        while(first!=nullptr){
              num1=(num1*10+first->data)%MOD;
              first=first->next;
        }
        
         while(second!=nullptr){
              num2=(num2*10+second->data)%MOD;
              second=second->next;
        }
        
        return (num1*num2)%MOD;
    }


// INTERSECTION OF LINKED LIST
class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        Node* dummy=new Node(0);
        Node* tail=dummy;
        
        while(head1!=nullptr && head2!=nullptr){
            if(head1->data==head2->data){
                tail->next=new Node(head1->data);
                tail=tail->next;
                head1=head1->next;
                head2=head2->next;
            }
            
            else if(head1->data<head2->data){
                head1=head1->next;
            }
            
            else{
                head2=head2->next;
            }
        }
        
        return dummy->next;
    }


//  SMALLEST NATURAK NUMBER NOT HAVING SUBSET OF SAME SUM 
    long long findSmallest(vector<int> &arr) {
        long long result=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>result){
                break;
              }
               result=result+arr[i];
        }
        return result;
    }


// MINIMUM NUMBER IN SORTED ARRAY
 int minNumber(int arr[], int low, int high)
    {
        int ans;
        sort(arr+low,arr+high+1); 
        ans=arr[0];
        return ans;
    }


// PAIRSUM OF DISTINCT NUMBERS MAXIMUM
    int pairsum(vector<int> &arr) {
         int ans;
         sort(arr.begin(),arr.end());
         int n1=arr[arr.size()-1];
         int n2=arr[arr.size()-2];
         ans=n1+n2;
         return ans;
    }


// ELEMENTS REPEATED TWO TIMES
   vector<int> twoRepeated(int n, int arr[]) {
       vector<int> result;
       unordered_map<int,int> ans;
       for(int i=0;i<n+2;i++){
           ans[arr[i]]++;
           if(ans[arr[i]]==2){
               result.push_back(arr[i]);
           }
       }
     
       return result;
    }


// MATRIX IN LINKED LIST
struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        if(n==0) {
            return NULL;
        }
        
        vector<vector<Node*>> nodes(n,vector<Node*>(n,NULL));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                nodes[i][j]=new Node(mat[i][j]);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j<n-1){
                    nodes[i][j]->right=nodes[i][j+1];
                }
                if(i<n-1){
                    nodes[i][j]->down=nodes[i+1][j];
                }
            }
        }
        return nodes[0][0];   
    }
};


// MAXIMUM DISTANCE BETWEEN ELEMENTS
    int maxDistance(vector<int> &arr) {
        unordered_map<int,int> result;
       int d=0;
       for(int i=0;i<arr.size();i++){
           if(result.find(arr[i])==result.end()){
               result[arr[i]]=i;
           }
           else{
               int dist=i-result[arr[i]];
               d=max(dist,d);
           }
       }
       return d;
    }


// MODIFY THE ARRAY(Given an array arr. Return the modified array in such a way that 
//if the current and next numbers are valid numbers and are equal then double the current number 
//value and replace the next number with 0. After the modification,
//rearrange the array such that all 0's are shifted to the end.)
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
       vector<int> result;
       for(int i=0;i<arr.size();i++){
           if(arr[i]==arr[i+1]){
               arr[i]=arr[i]*2;
               arr[i+1]=0;
           }
       }
    int n=arr.size();
    int index=0;
    for (int i=0;i<n;i++) {
        if (arr[i]!=0) {
            arr[index++]=arr[i];
        }
    }
    
    while (index<n) {
        arr[index++]=0;
    }
       return arr;
    }

// OCCURENCE OF INTEGER IN LINKED LIST
    int count(struct Node* head, int key) {
        int c=0;
        while(head!=nullptr){
            if(head->data==key){
                c++;
            }
            head=head->next;
        }
        return c;
    }

//SWAP AND FIND MAXIMUM ABSOLUTE SUM
    long long maxSum(vector<int>& arr) {
    long long ans=0;
    int n=arr.size();
    sort(arr.begin(), arr.end());
    vector<int> temp(n);
    int left = 0, right = n - 1;
    
    // Fill the temp array with min-max arrangement
    for (int i=0;i<n;i++) {
        temp[i]=(i%2==0) ? arr[left++] : arr[right--];
    }
    
    // Calculate the maximum sum of absolute differences in circular arrangement
    for (int i=0;i<n-1;i++) {
        ans=ans+abs(temp[i]-temp[i + 1]);
    }
    ans=ans+abs(temp[n - 1]-temp[0]); // To account for the circular nature

    return ans;
    }


// CHECK IF NUMBER IS DUPLICATE AND IT LIES WITHIN THE KTH DISTANCE
class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
    // bool ans=false;
    // unordered_map<int,int> result;
    // for(auto num:arr){
    //     result[num]++;
    // }
    // for(auto i: result){
    //     if(i.second>=2){
    //         for(int j=result.find(i.first);j<k;j++){
    //             if(i.second>=2)
    //               ans=true;
    //         }
    //     }
      
    // }
    // return ans;
    
    unordered_map<int, int> result;  // map to store the last seen index of each element
        bool ans=false;
        for (int i=0;i<arr.size();i++) {
            int num = arr[i];
            if (result.find(num)!=result.end() && i-result[num]<=k) {
                ans=true;
                break;
            }
            result[num]=i;
        }
        return ans;
    }
};

// SUM OF LAST N NODES IN LINKED LIST
    int sumOfLastN_Nodes(struct Node* head ,int n) {
        int sum=0,total=0;
        struct Node* current = head;
        while(current!=nullptr){
            total++;
            current=current->next;
        }
        if(n>total) {
           n=total;
          }
        current=head;
        for (int i=0;i<total-n;i++) {
            current = current->next;
        }
       
        while(current!=nullptr){
            sum=sum+current->data;
            current=current->next;
            
        }
        
        return sum;
    }


//ARRAY TO LINKED LIST
    Node* constructLL(vector<int>& arr) {
        struct Node* head=new Node(arr[0]);
        struct Node* node=head;
        for(int i=1;i<arr.size();i++){
                node->next=new Node(arr[i]);
                node=node->next;
           }
        return head;
    }


// FIND N/KTH TERM IN LINKED LIST
    int fractional_node(struct Node *head, int k) {
        struct Node* current=head;
        int total=0,ans;
        while(current!=nullptr){
            current=current->next;
            total++;
        }
       int pos=(total+k-1)/k;
        current=head;
        for(int i=1;i<pos;i++){
            current=current->next;
        }
        ans=current->data;
        return ans;
    }


//INSERT ELEMENT AT THE STARTING OF LINKED LIST
    Node *insertAtBegining(Node *head, int x) {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data=x;
        newnode->next=head;
        return newnode;
        
    }


// TRIPLETS HAVIND SUM OF 0
    vector<vector<int>> findTriplets(vector<int> &arr) {
       vector<vector<int>> result;
        for (int i=0;i<arr.size()-2;i++) {
        if (i>0 && arr[i]==arTr[i-1]) {
            continue;
        }
        }
       for(int i=0;i<arr.size()-2;i++){
           for(int j=i+1;j<arr.size()-1;j++){
               for(int k=j+1;k<arr.size();k++){
                   if(arr[i]+arr[j]+arr[k]==0){
                       result.push_back({i,j,k});
                   }
               }
           }
       }
       return result;
    }


// WIINER OF THE COTE LEXICOGRAPHICALLY
    vector<string> winner(string arr[],int n)
    {
      vector<string> ans;
      unordered_map<string,int> result;
      for (int i = 0; i < n; i++) {
        result[arr[i]]++;
    }

      int maxi=0,vote;
      string name;
      for(auto i: result){
          if(i.second>maxi  || (i.second==maxi && (name.empty() || i.first<name))){
              maxi=i.second;
              name=i.first;
          }
        //   else if(i.second==maxi &&  i.first<name){
        //       name=i.first;
        //   }
      }
      ans.push_back(name);
      ans.push_back(to_string(maxi));
      return ans;
    }


// UNCOMMON CHARACTERS IN 2 STRINGS USING SET
        string UncommonChars(string A, string B)
        {
            string s="";
            unordered_set<char> seta(A.begin(),A.end());
            unordered_set<char> setb(B.begin(),B.end());
            for(char ch:seta){
                if(setb.find(ch)==setb.end()){
                    s=s+ch;
                }
            }
            
              for(char ch:setb){
                if(seta.find(ch)==seta.end()){
                    s=s+ch;
                }
            }
            sort(s.begin(),s.end());
            if(!s.empty()){
            return s;
            }
            else{
                return "-1";
            }
        }


// ROTATING MATRIX BY 90DEGREE (TAKE TRANSPOSE AND REVERSE THE ROWS)
void rotate(vector<vector<int> >& mat) {
    for(int i=0;i<mat.size();i++){
        for(int j=i;j<mat.size();j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<mat.size();i++){
        reverse(mat[i].begin(),mat[i].end());
    }
}


// FIRST REPEATED CHARACTER

string firstRepChar(string s)
{
    unordered_set<char> seta;
    string ans;
    for(char ch: s){
        if(seta.find(ch)!=seta.end()){
            return string(1,ch);
        }
        seta.insert(ch);
    }
  
        return "-1";
}


// CHECKING FOR FASCINATING NUMBER THE SUM OF NUMBER,NUMBER*2,NUMBER*3 IS CONCATENATED AND SHOULD HAVE ALL NUMBERS FROM 1 TO 9
    bool fascinating(int n) {
        
        int twomul,threemul;
        string sum;
        twomul=n*2;
        threemul=n*3;
        sum=to_string(n)+to_string(twomul)+to_string(threemul);
        sort(sum.begin(),sum.end());
        return sum=="123456789";
    }


// SUM OF ALL THE PATHS TO LEAF NODES(NOT DATA PRESENT)
    int sum(Node *root,int s){
        if(root==nullptr){
            return 0;
        }
        
        s=s*10+root->data;
        if(root->right==nullptr && root->left==nullptr){
            return s;
        }
        int ls=sum(root->left,s);
        int rs=sum(root->right,s);
        return ls+rs;
    }
    int treePathsSum(Node *root) {
        return sum(root,0);
    }


// SPLITING INTO THREE SUBARRAYS
    vector<int> findSplit(vector<int>& arr) {
    int totalSum = 0;
    for (int num : arr) {
        totalSum += num;
    }

    // If total sum is not divisible by 3, return {-1, -1}
    if (totalSum % 3 != 0) {
        return {-1, -1};
    }

    int targetSum = totalSum / 3;
    int currentSum = 0;
    int foundParts = 0;
    int i = -1, j = -1;

    // Traverse the array to find i and j
    for (int k = 0; k < arr.size(); k++) {
        currentSum += arr[k];

        // Check if we found one part with sum = targetSum
        if (currentSum == targetSum) {
            foundParts++;
            currentSum = 0;

            // Assign indices for i and j
            if (foundParts == 1) {
                i = k;
            } else if (foundParts == 2) {
                j = k;
                break;
            }
        }
    }

    // If we found both i and j
    if (foundParts == 2) {
        return {i, j};
    }
    return {-1, -1};
    }

// UNION OF 2 SETS IN ASCENDING ORDER
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int> s1(a.begin(),a.end());
        set<int> s2(b.begin(),b.end());
        vector<int> result;
        set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),back_inserter(result));
        return result;
    }
