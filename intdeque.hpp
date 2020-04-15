class IntDequeElement {
    int element;
    IntDequeElement* next;
    IntDequeElement* prev;

    public:
    IntDequeElement();
    IntDequeElement(int _element);
    IntDequeElement(int _element, IntDequeElement * _prev, IntDequeElement * _next);

    void SetElement(int _element);
    int GetElement();

    void SetNext(IntDequeElement * _next);
    IntDequeElement * GetNext();
    
    void SetPrev(IntDequeElement * _prev);
    IntDequeElement * GetPrev();
};

class IntDeque {
    protected:
    IntDequeElement * left;
    IntDequeElement * right;
    int buffer;
    IntDequeElement * GetLeft() { return left; }; // Надеюсь, в заголовочном файле допустимо реализовать "getter"...
    IntDequeElement * GetRight() { return right; };

    public:
    IntDeque();
    IntDeque(IntDeque & _deque);

    virtual int * AddLeft(int element);
    virtual int * AddRight(int element);
    int * RemoveLeft();
    int * RemoveRight();
    int GetElement();
    int IsEmpty();

    /* Overloaded Operators */
    
    int* operator -- ();
    int* operator -- (int nothing);

    IntDeque & operator =(IntDeque & _deque); // overloading operator =
    int operator ==(IntDeque & _deque); // overloading operator ==

    /* End of Overloaded Operators */
    ~IntDeque();
};
    int* operator +(IntDeque & _deque, int _element); // overloading operator deque + int
    int* operator +(int _element, IntDeque & _deque); // overloading operator int + deque

