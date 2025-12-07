void bfs(int start) { 
int i; 
struct Node* temp; 
for (i = 0; i < n; i++) 
visited[i] = 0; 
enqueue(start); 
visited[start] = 1; 
printf("\nBFS Traversal: "); 
while (front <= rear) { 
int node = dequeue(); 
printf("%d ", node); 
for (temp = adj[node]; temp != NULL; temp = temp->next) { 
int v = temp->vertex; 
if (!visited[v]) { 
enqueue(v); 
visited[v] = 1; 
} 
} 
} 
printf("\n"); 
}