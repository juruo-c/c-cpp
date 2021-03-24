//
// Created by 19116 on 2021/3/22.
//

//#include<iostream>
//#include<string>
//#include<new>
//
//using namespace std;
//const int BUF = 512;
//class JustTesting{
//private:
//    string words;
//    int number;
//public:
//    JustTesting(const string& s = "Just Testing",int n = 0){
//        words = s;number = n;cout << words << " constructed\n";
//    }
//    ~JustTesting(){cout << words << " destroyed\n";}
//    void Show()const{ cout << words << ", " << number << endl;}
//};
//
//int main(){
//    char * buffer = new char[BUF];
//
//    JustTesting *pc1, *pc2;
//    pc1 = new(buffer) JustTesting;
//    pc2 = new JustTesting("Heap1",20);
//
//    cout << "Memory contents:\n";
//    cout << pc1 << ": " ;
//    pc1->Show();
//    cout << pc2 << ": ";
//    pc2->Show();
//
//    JustTesting *pc3,*pc4;
//    pc3 = new(buffer) JustTesting("Bad Idea", 6);
//    pc4 = new JustTesting("Heap2",10);
//
//    cout << "Memory contents:\n";
//    cout << pc3 << ": ";
//    pc3->Show();
//    cout << pc4 << ": ";
//    pc4->Show();
//
//    delete pc2;
//    delete pc4;
//
//    delete[] buffer;
//    cout << "Done\n";
//
//    return 0;
//}

#include<iostream>

using namespace std;


class Queue{

private:
    struct Node{
        Item item;
        struct Node* next;
    };
    enum{Q_SIZE = 10};
public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item &item);
    bool dequeue(Item &item);
};
int main(){

    return 0;
}