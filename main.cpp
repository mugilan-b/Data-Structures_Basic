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
    LLNode BaseNode;
    LLNode* final;

    int numEle;

    LinkedList(int d)
    {
        numEle = 1;
        BaseNode.data = d;
        BaseNode.NodePointer = NULL;
        final = &BaseNode;
    };

    int Read(int pos)
    {
        if(pos >= numEle)
        {
            return 0;
        }
        int i = 0;
        LLNode* temp = BaseNode.NodePointer;
        while(temp != NULL && i < pos - 1)
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
        else
        {
            int i = 0;
            LLNode* temp = BaseNode.NodePointer;
            while(temp != NULL && i < pos - 2)
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
        numEle++;
    }

    bool Set(int d, int pos)
    {
        if(pos >= numEle)
        {
            return false;
        }
        int i = 0;
        LLNode* temp = BaseNode.NodePointer;
        while(temp != NULL && i < pos - 1)
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
        int i = 0;
        LLNode* temp = BaseNode.NodePointer;
        while(temp != NULL && i < pos - 2)
        {
            temp = temp->NodePointer;
            i++;
        }
        LLNode* prev = temp;
        temp = temp->NodePointer;
        if(pos < numEle - 1)
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
        return true;
    }

    string PrintArray()
    {
        int i = 0;
        string pr = "";
        pr.append(to_string(BaseNode.data));
        pr.append(", ");
        LLNode* temp = BaseNode.NodePointer;
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

int main()
{
    IntDynArray dArr;
    dArr.TestArray();
    cout<<"-------------------"<<endl;
    LinkedList llist(1);
    llist.TestLL();
    return 0;
}