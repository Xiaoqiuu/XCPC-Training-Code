import os
import sys

def dfs(graph, vertex, visited=None) :
    visited.add(vertex)
    #遍历所有相邻的顶点
    for neighbor in graph[vertex] :
        if neighbor not in visited :
            dfs(graph, neighbor, visited)

def is_connnected(graph) :
    #获取途中的任意一个顶点作为起始点
    start_vertex = next(iter(graph))
    visited = set()
    #从起始顶点开始进行DFS
    dfs(graph, start_vertex, visited)
    #如果已访问的顶点数量等于图中的顶点数量，则就是连通图
    return len(visited) == len(graph)


#创建图
graph = {
    'A' : ['B', 'C'],
    'B' : ['A', 'D', 'E'],
    'C' : ['A', 'F'],
    'D' : ['B'],
    'E' : ['B', 'F'],
    'F' : ['C', 'E']
}                                                                                
#判断是否连通                                                                    
if is_connnected(graph) :                                                        
    print('Graph is connected')                                                
else :                                                                         
    print('Graph is not connected')