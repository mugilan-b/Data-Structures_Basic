Included are classes of common basic Data structures. Note that they can store only **INTEGERS**. <br>
# Data structures: <br>
## Dynamic array (IntDynArray): <br> 
Not really dynamic per se. It is a normal array with the following operations:

### Public properties: <br>
- int numEle: Number of elements that have been stored.

### Public Methods: <br>
- The constructor: Initializes the array with all elements as 0. <br>
- bool Set(int a, int pos): **Sets** the value at position **pos** to **a**. Note that this can only change already added values and cannot append a value. Returns true if successful. <br>
- int Read(int pos): **Returns** the value at position **pos**. If **pos** is out of bounds, returns 0. <br>
- bool Insert(int b, int pos): **Inserts** the value **b** at position **pos**, shifts successors rightward by 1 index. If **pos >= numEle** then it appends. Returns **false** if array is too large to insert. <br>
- bool Remove(int pos): Removes element at position **pos**. Returns true if **pos < numEle**. <br>
- string PrintArray(): Returns a string of array elements. <br>
- void TestArray(): Does a quick demo of a sample array.

### Limitations, and possible further improvements: <br>
- Maximum elements is given by global var **const int ArraySize**. Set to 1000 by default. Array cannot hold more elements. <br>
- Can add a search function. <br>

## Linked List (LinkedList): <br>
A Linked list with one directional traversing capabilities.

### Public Properties: <br>
- int numEle: Number of elements that have been stored. <br>
- LLNode* final: Pointer pointing to the last node, to have O(1) appends and last element reads. <br>
- LLNode* first: Pointer pointing to root (first) node.

### Public Methods: <br>
- The constructor: Instantiates a linked list with the integer value passed (Pass it always to avoid errors with numEle). <br>
- int Read(int pos): Returns the value at position **pos**. Essentially traverses **pos** times from root node. Returns 0 if **pos >= numEle** <br>
- void Insert(int d, int pos): Inserts a new node with value *d* into position **pos** if pos < numEle. Else, appends. <br>
- bool Set(int d, int pos): Changes existing value at position **pos** to **d**. Cannot append. Returns false if unable to set. <br>
- bool Remove(int pos): Deletes the node at position **pos**. If **pos >= numEle**, then returns false instead. <br>
- string PrintArray(): Returns a string of the elements of the Linked List. <br>
- void TestLL(): Does a quick demo of a sample Linked List.

### Limitations, and possible further improvements: <br>
- Can add a search function.

## Stack (Stack): <br>
A Stack implemented with the aforementioned Linked List.

### Public Properties: <br>
- int numEle: Number of elements that have been stored.

### Public Methods: <br>
- The constructor: Instantiates a stack with the integer value passed (Pass it always to avoid errors with numEle). <br>
- void Push(int d): Pushes the integer **d** into the stack. <br>
- int Pop(): Returns the popped element. Returns 0 if stack is empty. <br>
- int Peek(): Returns the value of the top element without popping. <br>
- string PrintStack(): Returns a string of the elements of the stack. <br>
- void TestStack(): Does a quick demo of a sample Stack.

### Limitations, and possible further improvements: <br>
- None come to mind

## Queue (Queue): <br>
A Queue implemented with the aforementioned Linked List.

### Public Properties: <br>
- int numEle: Number of elements that have been stored.

### Public Methods: <br>
- The constructor: Instantiates a queue with the integer value passed (Pass it always to avoid errors with numEle). <br>
- void Push(int d): Pushes the integer **d** into the queue. <br>
- int Pop(): Returns the popped element. Returns 0 if queue is empty. <br>
- int Peek(): Returns the value of the head element without popping. <br>
- string PrintQ(): Returns a string of the elements of the Queue. <br>
- void TestQ(): Does a quick demo of a sample Queue.

### Limitations, and possible further improvements: <br>
- None come to mind

## Binary Search Tree (BinaryTree): <br>
A Binary Search Tree implemented with an inbuilt Linked List & a custom Node Queue to implement Breadth-first algorithms. Left is smaller, right is larger.

### Public Properties: <br>
- int numEle: Number of elements that have been stored. <br>
- BTNode rootNode: The root node of the tree. Use this directly only with caution.

### Public Methods: <br>
- The constructor: Instantiates a Tree with the integer value passed (Pass it always to avoid errors with numEle). <br>
- void Insert(int d): Inserts **d** into the tree, finding a suitable position. <br>
- void SetRoot(int d): Sets the value of the Root node to **d**. <br>
- bool Search(int d, bool retpoit, BTNode** searched, BTNode** prev2, bool* wentr): Pass ONLY the value of **d**. Returns true if **d** is in the tree, false otherwise. <br>
- bool Remove(int d): Removes **d** from the tree. If **d** is not a leaf node, it will automatically reconnect the tree in such a way that it **PRESERVES** the BST structure. Cannot remove the root node. Returns false if unable to remove/find **d**. <br>
- string PrintTree(): Returns a string of elements in the tree in a breadth-first way, going from left to right. <br>
- void TestBT(): Does a quick demo of a sample Binary Tree.

### Limitations, and possible further improvements: <br>
- A safer search function <br>
- Protect rootNode better <br>
- PrintTree() to add colons when going to the next level of elements. <br>
- Methods to find maximum and minimum elements of the tree. Most of the work is done already. <br>
- Methods to return subtrees.

# To-do: <br>
- Add search function in IntDynArray and LinkedList <br>
- Improve documentation in code <br>
- Make this a header file <br>
- Improve BinaryTree

# Changelog: <br>
- v0.5 - Added more instructions and details in Readme.md <br>
- v0.4 - Added Binary trees and required classes/structures for it <br>
- v0.3 - Added Queues, Improved Stack <br>
- v0.2 - Added Stack and fixed Linked List logic <br>
- v0.1 - Included Linked List and Dynamic Array <br>
