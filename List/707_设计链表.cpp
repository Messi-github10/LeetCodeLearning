#include <iostream>
using namespace std;

class MyLinkedList {
public:
    // 无参构造函数
    MyLinkedList() 
    :_size(0)
    ,_dummyHead(new LinkedNode(0))
    {}

    // 析构函数
    ~MyLinkedList(){
        LinkedNode *cur = _dummyHead->next;
        while(cur != nullptr){
            LinkedNode *temp = cur;
            cur = cur->next;
            delete temp;
        }
        delete _dummyHead;
        _dummyHead = nullptr;
        _size = 0;
    }
    
    // 获取到第index个节点数值
    int get(int index) {
        // 合法性校验
        if(index < 0 || index >= _size){
            return -1;
        }
        LinkedNode *cur = _dummyHead->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    // 头插法
    void addAtHead(int val) {
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    // 尾插法
    void addAtTail(int val) {
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = _dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    // 根据索引添加节点
    void addAtIndex(int index, int val) {
        // 合法性校验
        if(index < 0 || index > _size){
            return;
        }
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = _dummyHead;   // cur是index位置的前一个节点
        while(index--){
            cur = cur->next;    
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    // 根据索引删除节点
    void deleteAtIndex(int index) {
        if(index < 0 || index >= _size){
            return;
        }
        LinkedNode *cur = _dummyHead;
        while(index--){
            cur = cur->next;    // cur是index位置的前一个节点
        }
        LinkedNode *temp = cur->next;
        cur->next = temp->next;
        delete temp;
        temp = nullptr;
        _size--;
    }

private:
    // 定义链表节点
    struct LinkedNode{
        int val;
        LinkedNode *next;

        LinkedNode(int value)
        :val(value)
        ,next(nullptr)
        {}

        ~LinkedNode() = default;
    };

    int _size;  // 链表长度
    LinkedNode *_dummyHead; // 虚拟头节点
};