//THIS PROGRAM WAS CREATED BY DEVIN BROWN 


using namespace std;

int n,a[1000000];

struct node{
    int data;
    struct node *next,*prev;
};

class zDepthList{
public:
    zDepthList();
    zDepthList(int[],int);
    void out(const char = 'f');
    void move(int,int,char = 'f');
    void movefront(int);
    void moveback(int);
    int at(int);
    int addback();
    int addfront();
private:
    node *head;
    node *tail;
    node **arr;
};

zDepthList::zDepthList()			//constructor implemented
{
    head = NULL;
    tail = NULL;
}

zDepthList::zDepthList(int a[],int n)
{
    arr = new node*[n];
    head = NULL;
    for(int i=0;i<n;i++)
    {
        node* new_node = new node;
        new_node->data = a[i];
        arr[a[i]] = new_node;
        
        //Linked List starts here
        if(head==NULL)
        {
            new_node->next=new_node->prev=NULL;
            head=new_node;
            tail=new_node;
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            new_node->next = NULL;
            tail = new_node;
        }
    }
}

void zDepthList::out(char c)
{
    node *temp;
    if(c=='f')
    {
        temp = head;
        while(1)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
            if(temp==NULL)
                break;
        }
    }
    else
    {
        temp=tail;
        while(1)
        {
            cout<<temp->data<<" ";
            temp=temp->prev;
            if(temp==NULL)
                break;
        }
    }
    cout << endl;
}

void zDepthList::move(int idx, int dist, char c) {
    node* temp = arr[idx];
    
    if (temp == head)
    {
        temp->next->prev = NULL;
        head = temp->next;
    }
    else if (temp == NULL)
    {
        temp->prev->next = NULL;
        tail = temp->prev;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    
    node* dest = temp;
    for (int i = 0; i <= dist; i++) {
        if (c == 'f') {
            if (dest->next == NULL) {
                break;
            }
            dest = dest->next;
        }
        else {
            if (dest->prev == NULL) {
                break;
            }
            dest = dest->prev;
        }
    }
    
    if (c == 'f') {
        temp->next = dest->next;
        temp->prev = dest;
        if (dest==tail) tail = temp;
        else dest->next->prev = temp;
        dest->next = temp;
    }
    else {
        temp->prev = dest->prev;
        temp->next = dest;
        if (dest==head) head = temp;
        else dest->prev->next = temp;
        dest->prev = temp;
    }
    return;
}

void zDepthList::movefront(int idx)
{
    node* temp = arr[idx];
    
    //Special case - temp is already head
    if(temp== head){
        return;
    }
    // Special case - temp is tail
    else if(temp==tail){
        
        temp->prev ->next =NULL;
        tail = temp->prev;
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
    }
    //Nonspecial cases
    else{
        temp ->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
    }
    return;
}

void zDepthList::moveback(int idx)
{
    node* temp = arr[idx];
    //Special case - temp is already tail
    if(temp==tail){
        return;
    }
    // Special case - temp is head
    else if(temp==head){
        temp->next->prev = NULL;
        head = temp->next;
        temp->prev = tail;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
    //Nonspecial cases
    else{
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        temp->prev = tail;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
    return;
}

int zDepthList::at(int d)
{
    node *temp;
    temp=head;
    while(d!=0)
    {
        temp=temp->next;
        d--;
    }
    return temp->data;
}

int zDepthList::addback()
{
    int *new_array;
    n+=1;
    new_array=new int[n];
    for(int i=0;i<n;i++)
    {
        new_array[i]=i;
    }
    head=NULL;
    zDepthList(new_array,n);
    return 0;
}

int zDepthList::addfront()
{
    int *new_array;
    n+=1;
    new_array=new int[n];
    for(int i=0;i<n;i++)
    {
        new_array[i]=i;
    }
    head=NULL;
    zDepthList(new_array,n);
    movefront(n);
    return 0;
}
