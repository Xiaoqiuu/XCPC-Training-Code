#include <stdbool.h>

#define MaxVertexNum 100
#define INF 0x3f3f3f3f

typedef struct {
    char Vex[MaxVertexNum];              // 顶点表
    int Edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵（边表）
    int vexnum, arcnum;                        // 顶点数与边/弧数
} MGraph;