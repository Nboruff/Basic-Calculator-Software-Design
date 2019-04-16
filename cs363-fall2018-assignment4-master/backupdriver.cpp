
Array<int> *arr = new Array<int>(10, 2);
Array<int> *arr2 = new Array<int>(*arr);

Array_Iterator<int> myItr(*arr);
for (myItr; !myItr.is_done(); myItr.advance())
{
    std::cout << *myItr << "\n";
}
arr->find(2);
delete arr;
arr = nullptr;
delete arr2;
arr2 = nullptr;

Queue<int> *q = new Queue<int>();
q->enqueue(4);
Queue<int> *q2 = new Queue<int>(*q);
q2->operator=(*q);
q2->clear();
delete q;
q = nullptr;
delete q2;
q2 = nullptr;

Stack<int> *s = new Stack<int>();
s->push(4);
Stack<int> *s2 = new Stack<int>(*s);

Add_Command add(*s2);
s2->operator=(*s);
delete s;
s = nullptr;
delete s2;
s2 = nullptr;

Fixed_Array<int, 10> *f = new Fixed_Array<int, 10>();
f->fill(4);
Fixed_Array<int, 10> *f2 = new Fixed_Array<int, 10>();
delete f;
f = nullptr;
delete f2;
f2 = nullptr;