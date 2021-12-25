#include<iostream>
#include<stdio.h>
using namespace std;

class Node
{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class Queue
{
    private:
        int front;
        int rear;
        int size;
        Node **Q;
    public:
        Queue(){front=rear=-1;size=10;Q=new Node*[size];};
        Queue(int size){front=rear=-1;this->size=size;Q=new Node*[this->size];}
        void enqueue(Node* x);
        Node* dequeue();
        int isEmpty(){return front==rear;}
        void Display();
};

void Queue::enqueue(Node* x)
{
    if(rear==size-1)
        cout<<"Queue is Full"<< endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::dequeue()
{
    Node* x = NULL;
    if(front==rear)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        x = Q[front+1];
        front++;
    }
    return x;
}

void Queue::Display()
{
    for(int i=front+1;i<=rear;i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
}

class Tree
{
        Node *root; //Now Private
    public:
        Tree(){root=NULL;}
        void CreateTree();
        void preorder(){preorder(root);}
        void preorder(Node *p);
        void postorder(){postorder(root);}
        void postorder(Node *p);
        void inorder(){inorder(root);}
        void inorder(Node *p);
        void Levelorder(){Levelorder(root);}
        void Levelorder(Node *p);
        int Height(){return Height(root);}
        int Height(Node *root);
};

void Tree::CreateTree()
{
    Node *p,*t;
    int x;
    Queue q(100);
    
    printf("Enter Root Value : ");
    scanf("%d",&x);
    root = new Node;
    root->data = x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);
    
    while(!q.isEmpty())
    {
        p = q.dequeue();
        printf("Enter Left Child of %d : ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t= new Node;
            t->data = x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        
        printf("Enter Right Child of %d : ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t= new Node;
            t->data = x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
        
        
    }
    
}

void Tree::preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Tree::inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void Tree::postorder(struct Node *p)
{
    if(p)
    {
        
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void Tree::Levelorder(struct Node *root)
{
    Queue q(100);
    printf("%d ",root->data);
    q.enqueue(root);
    while (!q.isEmpty())
    {
        root = q.dequeue();
        if(root->lchild)
        {
            printf("%d ",root->lchild->data);
            q.enqueue(root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ",root->rchild->data);
            q.enqueue(root->rchild);
        }
    }
    
}

int Tree::Height(struct Node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if(x>y)
        return x+1;
    else
    {
        return y+1;
    }
}


int main()
{
    Tree t;
    t.CreateTree();
    
    cout << "Pre-Order   : ";
    t.preorder();
    cout << endl;
    cout << "In-Order    : ";
    t.inorder();
    cout << endl;
    cout << "Post-Order  : ";
    t.postorder();
    cout << endl;
    cout << "Level-Order : ";
    t.Levelorder();
    cout << endl;
    cout << "Height : " << t.Height() << endl;

    
    return 0;
}