void dfs(int start) { 
struct Node* temp; 
visited[start] = 1; 
printf("%d ", start); 
for (temp = adj[start]; temp != NULL; temp = temp->next) { 
int v = temp->vertex; 
if (!visited[v]) 
dfs(v); 
} 
}