// LeetCode146.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 【146】LRU 缓存机制。

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// 时间复杂度较高仍有待优化。
class List
{
private:
    typedef struct Node
    {
        int key;
        struct Node* next;
    }Node;
    Node* head;   // 置换队列。最近使用的放在后面。
    Node* tail;    // 每次使用后直接置换到后面去。

public:
    void Updata(int key);
    void Add(int key);
    int Del();

    void Cout();

    List();
    ~List();
};
void List::Cout()
{
    cout << "node key:";
    Node* move = head;
    while (move)
    {
        cout << move->key << ":";
        move = move->next;
    }
    if (tail)
    {
        cout << "tail:" << tail->key;
    }
    cout << endl;
}
void List::Updata(int key) {
    
    Node* lastmove = head;
    Node* move = head;
    while (move->key != key) // 外层判断保证了一定能找到对应 key。
    {
        lastmove = move;
        move = move->next;
    }

    if (move == head || move == tail) // 两端
    {
        // move == head && move == tail 两端重合 move != head && move == tail
        // 只要 move 在尾部就无须操作。 
        if (move == tail)  
        {
            return;
        }
        else if(move == head) // 头非尾。
        {
            head = head->next;
            move->next = nullptr;
            tail->next = move;
            tail = tail->next;
        }
    }
    else // 在中间时。
    {
        lastmove->next = move->next;
        tail->next = move;
        move->next = nullptr;
        tail = tail->next;
    }
}
void List::Add(int key) {
    if (tail == nullptr || head == nullptr)  // 头结点为 nullptr 则尾节点必为 nullptr。   
    {
        Node* node = new Node{ key, nullptr };
        head = node;
        tail = head;
    }
    else
    {
        Node* node = new Node{ key, nullptr };
        tail->next = node;
        tail = tail->next;
    }
}
int List::Del() {
    int key = head->key;
    Node* move = head;

    head = head->next;
    if (head == nullptr)
    {
        tail = nullptr;
    }

    delete move;
    return key;
}
List::List()
{
    head = nullptr;
    tail = nullptr;
}
List::~List()
{
    while (head)
    {
        Node* buffer = head;
        head = head->next;
        delete buffer;
    }
}

class LRUCache {
public:

    map<int, int> Cache; // 缓存。
    int CacheCapacity; // Cache 容量

    List list; // 最近最少使用队列。

    void Cout() {
        cout << "map:";
        for (auto iter = Cache.begin(); iter != Cache.end(); iter++)
        {
            cout << iter->first << ":";
        }
        cout << endl;
    }

    LRUCache(int capacity) {
        CacheCapacity = capacity; // 缓存容量。
    }

    int get(int key) {
        auto iter = Cache.find(key);
        if (iter != Cache.end()) {

            list.Updata(key); // 队列更新。

            return iter->second;
        }
        else {
            return -1;
        }
    }
    void put(int key, int value) {
        auto iter = Cache.find(key);
        if (iter != Cache.end())
        {
            list.Updata(key); // 队列更新。

            iter->second = value;
        }
        else
        {
            if (Cache.size() + 1 > CacheCapacity)
            {
                int delkey = list.Del(); // 节点删除。

                if (!Cache.empty()) {
                    auto CounterMin = Cache.find(delkey);
                    Cache.erase(CounterMin);
                }
            }

            list.Add(key); // 节点添加。
            Cache.insert(map<int, int>::value_type(key, value));
        }
    }
};


int main()
{
    LRUCache LRU(1);

    // [[1], [2, 1], [2], [3, 2], [2], [3]]
    LRU.Cout();
    LRU.list.Cout();
    LRU.put(2, 1);
    LRU.Cout();
    LRU.list.Cout();
    LRU.get(2);
    LRU.Cout();
    LRU.list.Cout();
    LRU.put(3, 2);
    LRU.Cout();
    LRU.list.Cout();
    LRU.get(2);
    LRU.Cout();
    LRU.list.Cout();
    LRU.get(3);
    LRU.Cout();
    LRU.list.Cout();

    /* [[2], [2, 1], [2, 2], [2], [1, 1], [4, 1], [2]]
    LRU.put(2, 1);
    LRU.put(2, 2);
    LRU.get(2);
    LRU.put(1, 1);
    LRU.put(4, 1);
    LRU.get(2);
    */

    /*
    LRU.Cout();
    LRU.list.Cout();

    cout << 1 << endl;
    LRU.put(1, 1);
    
    LRU.Cout();
    LRU.list.Cout();

    cout << 2 << endl;
    LRU.put(2, 2);

    LRU.Cout();
    LRU.list.Cout();

    cout << 3 << endl;
    LRU.get(1);       // 返回  1

    LRU.Cout();
    LRU.list.Cout();

    cout << 4 << endl;
    LRU.put(3, 3);    // 该操作会使得密钥 2 作废

    LRU.Cout();
    LRU.list.Cout();

    cout << 5 << endl;
    LRU.get(2);       // 返回 -1 (未找到)
    
    LRU.Cout();
    LRU.list.Cout();

    cout << 6 << endl;
    LRU.put(4, 4);    // 该操作会使得密钥 1 作废
    
    LRU.Cout();
    LRU.list.Cout();
    
    cout << 7 << endl;
    LRU.get(1);       // 返回 -1 (未找到)
    
    LRU.Cout();
    LRU.list.Cout();
    
    cout << 8 << endl;
    LRU.get(3);       // 返回  3
    
    LRU.Cout();
    LRU.list.Cout();
    
    cout << 9 << endl;
    LRU.get(4);       // 返回  4

    LRU.Cout();
    LRU.list.Cout();
    */

    system("pause");
    return 0;
}
