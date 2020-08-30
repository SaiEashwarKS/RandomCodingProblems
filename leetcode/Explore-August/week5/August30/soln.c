int find_max(int* arr, int ASize)
{
    int max = arr[0];
    for(int i = 1; i < ASize; ++i)
    {
        max = arr[i] > max ? arr[i] : max;
    }
    return max;
}

int find(int* arr, int x)
{
    if(arr[x] != x)
    {
        arr[x] = find(arr, arr[x]);
    }
    return arr[x];
}

void unionn(int* arr, int x, int y)
{
    arr[find(arr, x)] = arr[find(arr, y)];
}

int maximum(int x, int y)
{
    return x > y ? x : y;
}

int largestComponentSize(int* A, int ASize)
{
    int max = find_max(A, ASize);
    int* relationships = (int*)malloc((max+1) * sizeof(int));
    for(int i = 0; i < max+1; ++i)
    {
        relationships[i] = i;
    }
    int num;
    for(int i = 0; i < ASize; ++i)
    {
        num = A[i];
        for(int j = 2; j <= sqrt(num); ++j)
        {
            if(num % j == 0)
            {
                unionn(relationships, num, j);
                unionn(relationships, num, num/j);
            }
        }
    }
    //the value at res_dict[i] denotes the number of nodes which have relationship with i
    int* res_dict = (int*)calloc(max+1, sizeof(int));
    int prime_num;
    int res = 0;
    for(int i = 0; i < ASize; ++i)
    {
        prime_num = find(relationships, A[i]);
        ++res_dict[prime_num];
        res = maximum(res, res_dict[prime_num]);
    }
    return res;
}



//OWN ATTEMPT : EXCEEDED TIME LIMIT AFTER BEING SUCCESSFUL FOR 74/100 TEST CASES
/*int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
}


int** construct_graph(int* A, int ASize) //construct a graph (adjacency matrix) with the given constraints
{
    int** graph = (int**)malloc(ASize * sizeof(int*));
    for(int i = 0; i < ASize; ++i)
    {
        graph[i] = (int*)malloc(ASize * sizeof(int));
    }
    for(int i = 0; i < ASize; ++i)
    {
        for(int j = i+1; j < ASize; ++j)
        {
            if(gcd(A[i], A[j]) != 1)
            {
                graph[i][j] = graph[j][i] = 1;
            }
            else
            {
                graph[i][j] = graph[j][i] = 0;
            }
        }
    }
    return graph;
}


struct stack{
    int* arr;
    int top;
    int capacity;
};

typedef struct stack stack;

stack* init_stack(int capacity)
{
    stack* st = (stack*)malloc(sizeof(stack));
    st -> top = -1;
    st -> capacity = capacity;
    st -> arr = (int*)malloc(capacity * sizeof(int));
    return st;
}

int is_Full(stack* st)
{
    return st -> top == st -> capacity -1;
}

int is_Empty(stack* st)
{
    return st -> top == -1;
}

void push(stack* st, int key)
{
    if(!is_Full(st))
        st -> arr[++st -> top] = key;
}

int pop(stack* st)
{
    if(!is_Empty(st))
        return st -> arr[st->top--];
    return -1;
}

int find_length(int* A, int ASize, int** graph, int key_index, int* visited)
{
    int count = 0;
    stack* st = init_stack(ASize);
    int* inStack = (int*)calloc(ASize, sizeof(int));
    int node_index = key_index;
    push(st, node_index);
    inStack[node_index] = 1;
    while(!is_Empty(st))
    {
        node_index = pop(st);
        ++count;
        visited[node_index] = 1;
        for(int i = 0; i < ASize; ++i)
        {
            if(graph[node_index][i] && visited[i] == 0 && !inStack[i])
            {
                push(st, i);
                inStack[i] = 1;
            }
        }
    }
    return count;
}

int largestComponentSize(int* A, int ASize){
    int** graph = construct_graph(A, ASize);
    int* visited = (int*)calloc(ASize, sizeof(int));
    int res = 0;
    int sub_graph_length;
    for(int i = 0; i < ASize; ++i)
    {
        if(visited[i] == 0)
        {
            sub_graph_length = find_length(A, ASize, graph, i, visited);
            if(sub_graph_length > res)
                res = sub_graph_length;
        }
    }
    return res;
}*/
