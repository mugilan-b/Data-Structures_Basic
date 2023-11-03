#include <iostream>
#include <string>

using namespace std;
const int ArraySize = 1000;

class IntDynArray
{
private:
    int selfArray[ArraySize];

public:
    int numEle;

    IntDynArray()
    {
        numEle = 0;
        for(int i = 0; i < ArraySize; i++)
        {
            selfArray[i] = 0;
        }
    }

    bool Set(int a, int pos)
    {
        if(pos < numEle)
        {
            selfArray[pos] = a;
            // Set Successfully
            return true;
        }
        else
        {
            // Bad Set
            return false;
        }
    };

    int Read(int pos)
    {
        if(pos < numEle)
        {
            // Read correctly
            return selfArray[pos];
        }
        else
        {
            // Incorrect access
            return 0;
        }
    };

    bool Insert(int b, int pos)
    {
        if (numEle < ArraySize - 1)
        {
            if(pos < numEle)
            {
                for (int i = numEle; i > pos; i--)
                {
                    selfArray[i] = selfArray[i - 1];
                }
                selfArray[pos] = b;
                // Move everything to the right of arr[pos] by 1
                numEle++;
                return true;
            }
            else if(pos == numEle)
            {
                selfArray[pos] = b;
                numEle++;
                return true;
            }
            else
            {
                // Unsuccessful Append
                return false;
            }
        }
        else
        {
            return false;
        }
    };

    bool Remove(int pos)
    {
        if(pos < numEle)
        {
            for(int i = pos; i < numEle; i++)
            {
                selfArray[i] = selfArray[i + 1];
            }
            numEle--;
            return true;
        }
        else
        {
            return false;
        }
    }

    string PrintArray()
    {
        string s = "";
        for(int i = 0; i < numEle; i++)
        {
            s.append(to_string(selfArray[i]));
            s.append(", ");
        }
        s[s.length() - 2] = '.';
        return s;
    }

    void TestArray()
    {
        IntDynArray dynArr;
        for (int i = 0; i < 10; i++)
        {
            dynArr.Insert(i + 1, i);
        }
        cout << "Array of " << dynArr.numEle << " elements: " << dynArr.PrintArray() << endl;
        dynArr.Set(66, 3);
        cout << "Array of " << dynArr.numEle << " elements: " << dynArr.PrintArray() << endl;
        dynArr.Insert(35, 5);
        cout << "Array of " << dynArr.numEle << " elements: " << dynArr.PrintArray() << endl;
        cout << "7th element is: " << dynArr.Read(6) << endl;
        dynArr.Remove(2);
        cout << "Array of " << dynArr.numEle << " elements: " << dynArr.PrintArray() << endl;
    }
};

struct LLNode
{
    int data;
    LLNode* NodePointer;
};

class LinkedList
{
public:
    LLNode* final;
    LLNode* first;
    int numEle;

    LinkedList(int d = 0)
    {
        LLNode* BaseNode = new LLNode();
        numEle = 1;
        BaseNode->data = d;
        BaseNode->NodePointer = NULL;
        final = BaseNode;
        first = BaseNode;
    };

    int Read(int pos)
    {
        if(pos >= numEle)
        {
            return 0;
        }
        if(pos == numEle - 1)
        {
            return final->data;
        }
        int i = 0;
        LLNode* temp = first;
        while(temp != NULL && i < pos)
        {
            temp = temp->NodePointer;
            i++;
        }
        return temp->data;
    }

    void Insert(int d, int pos)
    {
        if(pos >= numEle)
        {
            LLNode* last = new LLNode();
            last->data = d;
            last->NodePointer = NULL;
            final->NodePointer = last;
            final = last;
        }
        else if(pos > 0)
        {
            int i = 0;
            LLNode* temp = first;
            while(temp != NULL && i < pos - 1)
            {
                temp = temp->NodePointer;
                i++;
            }
            LLNode* prev = temp;
            temp = temp->NodePointer;
            LLNode* midNode = new LLNode();
            midNode->data = d;
            midNode->NodePointer = temp;
            prev->NodePointer = midNode;
        }
        else
        {
            LLNode* start = new LLNode();
            start->NodePointer = first;
            start->data = d;
            first = start;
        }
        numEle++;
    }

    bool Set(int d, int pos)
    {
        if(pos >= numEle)
        {
            return false;
        }
        int i = 0;
        LLNode* temp = first;
        while(temp != NULL && i < pos)
        {
            temp = temp->NodePointer;
            i++;
        }
        temp->data = d;
        return true;
    }

    bool Remove(int pos)
    {
        if(pos >= numEle)
        {
            return false;
        }
        else if(pos != 0)
        {
            int i = 0;
            LLNode *temp = first;
            while (temp != NULL && i < pos - 1)
            {
                temp = temp->NodePointer;
                i++;
            }
            LLNode *prev = temp;
            temp = temp->NodePointer;
            if (pos < numEle - 1)
            {
                prev->NodePointer = temp->NodePointer;
                final = prev->NodePointer;
                delete temp;
            }
            else
            {
                prev->NodePointer = NULL;
                final = prev;
                delete temp;
            }
        }
        else
        {
            LLNode* temp = first;
            first = first->NodePointer;
            delete temp;
        }
        return true;
    }

    string PrintArray()
    {
        int i = 0;
        string pr = "";
        pr.append(to_string(first->data));
        pr.append(", ");
        LLNode* temp = first->NodePointer;
        while(temp != NULL)
        {
            //cout<<"chec"<<pr<<endl;
            pr.append(to_string(temp->data));
            pr.append(", ");
            temp = temp->NodePointer;
        }
        pr[pr.length() - 2] = '.';
        return pr;
    }

    void TestLL()
    {
        LinkedList ll(1);
        for(int i = 2; i <= 10; i++)
        {
            ll.Insert(i, i - 1);
        }
        string say = "LL of 10 elements: ";
        cout<<say<<ll.PrintArray()<<endl;
        ll.Set(66, 3);
        cout<<say<<ll.PrintArray()<<endl;
        ll.Insert(35, 5);
        cout<<"LL of "<<ll.numEle<<" elements: "<<ll.PrintArray()<<endl;
        cout<<"7th element is: "<<ll.Read(6)<<endl;
        ll.Remove(2);
        cout<<say<<ll.PrintArray()<<endl;
    }
};

class Stack
{
private:
    LLNode* top;
    LinkedList stackLL;
public:
    int numEle;

    Stack(int d = 0)
    {
        top = stackLL.first;
        top->data = d;
        numEle = 1;
    }

    void Push(int d)
    {
        if(numEle == 0)
        {
            stackLL.first->data = d;
        }
        else
        {
            stackLL.Insert(d, 0);
            top = stackLL.first;
        }
        numEle++;
    }

    int Pop()
    {
        if(numEle > 1)
        {
            int d = 0;
            d = top->data;
            stackLL.Remove(0);
            top = stackLL.first;
            numEle--;
            return d;
        }
        else if(numEle == 1)
        {
            int d = 0;
            d = top->data;
            stackLL.Set(0, 0);
            numEle--;
            return d;
        }
        else
        {
            return 0;
        }
    }

    int Peek()
    {
        return top->data;
    }

    string PrintStack()
    {
        string pr = "(Top) ";
        pr.append(stackLL.PrintArray());
        return pr;
    }

    void TestStack()
    {
        Stack stk(11);
        cout<<"Stack after pushing 6 elements and a 11: "<<endl;
        for(int i = 0; i < 6; i++)
        {
            stk.Push(i * 12);
        }
        cout<<stk.PrintStack()<<endl<<"--------------"<<endl;
        cout<<"Stack after popping 4 times: "<<endl;
        for(int i = 0; i < 4; i++)
        {
            cout<<"Popped: "<<stk.Pop()<<endl;
        }
        cout<<stk.PrintStack()<<endl<<"--------------"<<endl;
        cout<<"Peeking stack: "<<stk.Peek()<<endl;
        cout<<"Stack after popping 5 more times - overflow: "<<endl;
        for(int i = 0; i < 5; i++)
        {
            cout<<stk.numEle;
            cout<<"Popped: "<<stk.Pop()<<endl;
        }
        cout<<"Stack pops return 0 when stack is empty."<<endl;
    }
};

class Queue
{
private:
    LLNode* tail;
    LinkedList qLL;
public:
    int numEle;

    Queue(int d = 0)
    {
        tail = qLL.first;
        numEle = 1;
    }

    void Push(int d)
    {
        if(numEle == 0)
        {
            qLL.first->data = d;
        }
        else
        {
            qLL.Insert(d, 0);
            tail = qLL.first;
        }
        numEle++;
    }

    int Pop()
    {
        int d = 0;
        if(numEle != 0)
        {
            d = qLL.Read(numEle - 1);
            qLL.Remove(numEle - 1);
            numEle--;
        }
        return d;
    }

    int Peek()
    {
        return qLL.Read(numEle - 1);
    }

    string PrintQ()
    {
        string pr = "(Tail) ";
        pr.append(qLL.PrintArray());
        pr.append(" (Head)");
        return pr;
    }

    void TestQ()
    {
        Queue q(1);
        for(int i = 1; i < 5; i++)
        {
            q.Push(2 * i);
        }
        cout<<"Queue is: "<<q.PrintQ()<<endl<<"----------"<<endl;
        for(int i = 0; i < 3; i++)
        {
            cout<<"Popped: "<<q.Pop()<<endl;
        }
        cout<<"Queue after popping 3 times: "<<q.PrintQ()<<endl;
        cout<<"Peeking head: "<<q.Peek()<<endl;
        cout<<"Queue after over-popping: "<<endl;
        for(int i = 0; i < 4; i++)
        {
            cout<<"Popped: "<<q.Pop()<<endl;
        }
        cout<<"Queue pop returns 0 when empty."<<endl;
    }
};

struct BTNode
{
    int data;
    BTNode* left;
    BTNode* right;
};

struct PQNode
{
    BTNode* btp;
    PQNode* NodePointer;
};

class PQueue
{
private:
    PQNode* head;
    PQNode* tail;
    //Push at tail, Pop at head
public:
    int numEle;

    PQueue(BTNode* d)
    {
        numEle = 1;
        head = new PQNode();
        tail = head;
        head->btp = d;
        head->NodePointer = NULL;
    }

    void Push(BTNode* d)
    {
        if(numEle > 0)
        {
            PQNode* temp = new PQNode();
            tail->NodePointer = temp;
            temp->btp = d;
            tail = temp;
        }
        else
        {
            head->btp = d;

        }
        numEle++;
    }

    BTNode* Pop()
    {
        if(numEle > 1)
        {
            BTNode* d = NULL;
            d = head->btp;
            PQNode* temp = head;
            head = head->NodePointer;
            delete temp;
            numEle--;
            return d;
        }
        else if(numEle == 1)
        {
            BTNode* d = NULL;
            d = head->btp;
            head->btp = NULL;
            numEle--;
            return d;
        }
        else
        {
            return NULL;
        }
    }
};

class BinaryTree
{
private:
    BTNode* MinPointer(BTNode* root)
    {
        // Returns address of the minimum element below said root
        BTNode* temp = root;
        //BTNode* temp2_prev = temp2;
        while(temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    BTNode* MaxPointer(BTNode* root)
    {
        // Returns address of the max element below said root
        BTNode* temp = root;
        //BTNode* temp2_prev = temp2;
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp;
    }

public:
    BTNode rootNode;
    int numEle;

    BinaryTree(int d = 0)
    {
        rootNode.data = d;
        rootNode.right = NULL;
        rootNode.left = NULL;
        numEle = 1;
    }

    void Insert(int d)
    {
        BTNode* temp = &rootNode;
        while(true)
        {
            if(d > temp->data)
            {
                if(temp->right == NULL)
                {
                    BTNode* newnode = new BTNode();
                    newnode->data = d;
                    newnode->right = NULL;
                    newnode->left = NULL;
                    temp->right = newnode;
                    numEle++;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                if(temp->left == NULL)
                {
                    BTNode* newnode = new BTNode();
                    newnode->data = d;
                    newnode->right = NULL;
                    newnode->left = NULL;
                    temp->left = newnode;
                    numEle++;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
        }
    }

    void SetRoot(int d)
    {
        rootNode.data = d;
    }

    bool Search(int d, bool retpoit = false, BTNode** searched = NULL, BTNode** prev2 = NULL, bool* wentr = NULL)
    {
        BTNode* temp = &rootNode;
        BTNode* prev = temp;
        bool wentright = false;
        while(true)
        {
            if(d > temp->data)
            {
                if(temp->right == NULL)
                {
                    //Value Absent
                    return false;
                    break;
                }
                else
                {
                    temp = temp->right;
                    wentright = true;
                    if(d == temp->data)
                    {
                        if(retpoit)
                        {
                            *prev2 = prev;
                            *searched = temp;
                            *wentr = wentright;
                        }
                        return true;
                        //Found
                    }
                }
            }
            else if (d < temp->data)
            {
                if(temp->left == NULL)
                {
                    //Value absent
                    return false;
                    break;
                }
                else
                {
                    temp = temp->left;
                    wentright = false;
                    if(d == temp->data)
                    {
                        if(retpoit)
                        {
                            *prev2 = prev;
                            *searched = temp;
                            *wentr = wentright;
                        }
                        return true;
                        //Found
                    }
                }
            }
            else
            {
                return true;
            }
            prev = temp;
        }
    }

    bool Remove(int d)
    {
        BTNode* temp = NULL;
        BTNode* prev = NULL;
        bool wentright = false;
        if(d == rootNode.data)
        {
            return false;
        }
        bool found = Search(d, true, &temp, &prev, &wentright);
        if(!found)
        {
            return false;
        }
        if(temp->right == NULL)
        {
            if(temp->left == NULL)
            {
                //Leaf node
                if(wentright)
                {
                    prev->right = NULL;
                }
                else
                {
                    prev->left = NULL;
                }
                delete temp;
                numEle--;
                return true;
            }
            else
            {
                //Only left subtree present
                BTNode* temp2 = MaxPointer(temp->left);
                float min = temp2->data;
                this->Remove(min);
                temp->data = min;
                numEle--;
                return true;
            }
        }
        else
        {
            //Right subtree present
            BTNode* temp2 = MinPointer(temp->right);
            float min = temp2->data;
            this->Remove(min);
            temp->data = min;
            numEle--;
            return true;
        }
        /*
        BTNode* temp = &rootNode;
        BTNode* prev = temp;
        bool wentright = false;
        while(true)
        {
            if(d > temp->data)
            {
                if(temp->right == NULL)
                {
                    //Value Absent
                    return false;
                    break;
                }
                else
                {
                    prev = temp;
                    temp = temp->right;
                    wentright = true;
                }
            }
            else if (d < temp->data)
            {
                if(temp->left == NULL)
                {
                    //Value absent
                    return false;
                    break;
                }
                else
                {
                    prev = temp;
                    temp = temp->left;
                    wentright = false;
                }
            }
            else
            {
                if(temp->left == NULL)
                {
                    if(temp->right == NULL)
                    {
                        //Leaf node
                        if(wentright)
                        {
                            prev->right = NULL;
                        }
                        else
                        {
                            prev->left = NULL;
                        }
                        //delete temp;
                    }
                    else
                    {
                        //Only Right subtree present
                        BTNode* temp2 = temp->right;
                        BTNode* temp2_prev = temp2;
                        if(temp2->left == NULL)
                        {
                            temp->data = temp2->data;
                            temp->right = NULL;
                            delete temp2;
                            break;
                        }
                        while(true)
                        {
                            temp2 = temp2->left;
                            if(temp2->left == NULL)
                            {
                                //Reached leaf
                                break;
                            }
                            temp2_prev = temp2;
                        }
                        temp->data = temp2->data;
                        temp2_prev->left = NULL;
                        delete temp2;
                    }
                }
                else
                {
                    if(temp->right == NULL)
                    {
                        //Only Left subtree present

                    }
                    else
                    {
                        //Both subtrees present

                        temp->data = temp2->data;
                        temp2_prev->left = NULL;
                        delete temp2;
                    }
                }
                delete temp;
                return true;
                //Found and deleted
            }
        }
        numEle--;
         */
    }

    string PrintTree()
    {
        BTNode* temp = NULL;
        PQueue PQ(&rootNode);
        string str = "(ROOT) ";
        while(PQ.numEle > 0)
        {
            temp = PQ.Pop();
            if(temp->left != NULL)
            {
                PQ.Push(temp->left);
            }
            if(temp->right != NULL)
            {
                PQ.Push(temp->right);
            }
            str.append(to_string(temp->data));
            str.append(", ");
        }
        return str;
    }

    void TestBT()
    {
        BinaryTree BT(15);
        BT.Insert(10);
        BT.Insert(4);
        BT.Insert(12);
        BT.Insert(19);
        BT.Insert(17);
        BT.Insert(21);
        cout<<"Binary tree is: "<<endl;
        cout<<BT.PrintTree();
        cout<<"BT after removing element 10: "<<endl;
        BT.Remove(10);
        cout<<BT.PrintTree();
    }
};

int main()
{
    system("cls");
    return 0;
}