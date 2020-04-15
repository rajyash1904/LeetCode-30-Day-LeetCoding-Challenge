/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

1. push(x) -- Push element x onto stack.
2. pop() -- Removes the element on top of the stack.
3. top() -- Get the top element.
4. getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.


   Show Hint #1  
   Consider each node in the stack having a minimum value.
   */
   
   class MinStack
{
public:
    /** initialize your data structure here. */
  stack < int >s1;
    stack < int >s2;
    MinStack ()
  {

  }

  void push (int x)
  {

    if (s2.empty () || s2.top () >= x)
      s2.push (x);
    s1.push (x);
    return;
  }


  void pop ()
  {
    if (s1.top () == s2.top ())
      s2.pop ();
    s1.pop ();
    return;
  }

  int top ()
  {
    return s1.top ();
  }

  int getMin ()
  {
    return s2.top ();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
