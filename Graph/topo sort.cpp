function topoSort_DFS(graph):
    visited = set()          // or boolean array
    stack = empty list       // or you can use actual stack

    for each vertex v in graph:
        if v not in visited:
            dfs(v)

    // At the end, stack has nodes in reverse topological order
    return reverse(stack)

function dfs(node):
    visited.add(node)
    for each neighbour 'next' of node:
        if next not in visited:
            dfs(next)
    // All neighbours (descendants) processed → safe to add node
    stack.append(node)

