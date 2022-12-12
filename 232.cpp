class MyQueue
{
public:
    stack<int> qq;
    stack<int> elements;
    MyQueue()
    {
        qq;
        elements;
    }

    void push(int x)
    {
        while (!qq.empty())
        {
            elements.push(qq.top());
            qq.pop();
        }
        elements.push(x);
        while (!elements.empty())
        {
            qq.push(elements.top());
            elements.pop();
        }
    }

    int pop()
    {
        int top = qq.top();
        qq.pop();
        return top;
    }

    int peek()
    {
        return qq.top();
    }

    bool empty()
    {
        return qq.empty();
    }
};