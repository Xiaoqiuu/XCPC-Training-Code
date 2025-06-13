#include<iostream>
#include<cstring>

#include<fstream>
using namespace std;

typedef struct {
    int weight;
    char ch;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;

typedef char** HuffmanCode;

// 计算字符权重
void WeightCulate(string str, int& n) {
    int i = 0, k = 0, flag = 0;
    n = 1;
    char CharOp[27];
    int CharWeight[27];
    
    for (i = 1; i <= 26; i++) {
        CharWeight[i] = 0;
    }
    
    ofstream outfile("权值打印.txt");
    i = 0;
    while (str[i] != '\0') { // 输入一串字符串并统计不重复的字符及其出现次数
        flag = 0;
        if (i == 0) {
            CharOp[n] = str[i];
            CharWeight[n] += 1;
        } else {
            for (k = 1; k <= n; k++) {
                if (str[i] == CharOp[k]) {
                    CharWeight[k] += 1;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                n += 1;
                CharOp[n] = str[i];
                CharWeight[n] += 1;
            }
        }
        i++;
    }
    
    for (i = 1; i <= n; i++) {
        outfile.put(CharOp[i]);
        outfile << " " << CharWeight[i] << endl;
    }
    outfile.close();
}

// 选择权值最小的两个节点
void Select(HuffmanTree& HT, int n, int& s1, int& s2) {
    int min = 0, i = 0;
    
    // 找第一个最小值
    for (i = 1; i <= n; i++) {
        if (HT[i].parent == 0) {
            min = i;
            break;
        }
    }
    for (i = min + 1; i <= n; i++) {
        if (HT[i].parent == 0 && HT[i].weight < HT[min].weight) {
            min = i;
        }
    }
    s1 = min; // 左孩子 s1
    
    // 找第二个最小值
    for (i = 1; i <= n; i++) {
        if (HT[i].parent == 0 && i != s1) {
            min = i;
            break;
        }
    }
    for (i = min + 1; i <= n; i++) {
        if (HT[i].parent == 0 && HT[i].weight < HT[min].weight && i != s1) {
            min = i;
        }
    }
    s2 = min; // 右孩子 s2
}

// 创建霍夫曼树
void CreatHuffmanTree(HuffmanTree& HT, int n, int choose) {
    int m, i, s1, s2;
    if (n <= 1) return;
    
    m = 2 * n - 1;
    HT = new HTNode[m + 1];
    
    for (i = 1; i <= m; i++) {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    
    ifstream file;
    if (choose == 1) {
        file.open("字符权值.txt");
        if (!file) {
            cout << "[---错误！未找到字符权值文件---]" << endl;
            return;
        }
    } else if (choose == 2) {
        file.open("权值打印.txt");
        if (!file) {
            cout << "[---错误！未找到字符权值文件---]" << endl;
            return;
        }
    }
    
    for (i = 1; i <= n; i++) {
        file >> HT[i].ch >> HT[i].weight;
    }
    file.close();
    
    for (i = n + 1; i <= m; ++i) {
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    
    cout << "[---哈夫曼树已成功建立！---]" << endl;
}

// 生成霍夫曼编码
void HuffCoding(HuffmanTree& HT, HuffmanCode& HC, int n) {
    HC = (HuffmanCode)malloc(sizeof(char*) * (n + 1));
    char* code = (char*)malloc(sizeof(char) * n);
    code[n - 1] = '\0';
    
    for (int i = 1; i <= n; i++) {
        int start = n - 1;
        int c = i;
        int p = HT[c].parent;
        
        while (p) {
            if (HT[p].lchild == c) {
                code[--start] = '0';
            } else {
                code[--start] = '1';
            }
            c = p;
            p = HT[c].parent;
        }
        
        HC[i] = (char*)malloc(sizeof(char) * (n - start));
        strcpy(HC[i], &code[start]);
    }
    
    free(code);
    cout << "[---已完成对各字符的编码! ---]" << endl;
}

// 输出编码
void CodeOutput(HuffmanTree& HT, HuffmanCode& HC, int n) {
    for (int i = 1; i <= n; i++) {
        cout << "字符 " << HT[i].ch << " 的编码: " << HC[i] << endl;
    }
}

// 打印霍夫曼树
void PrintHT(HuffmanTree& HT, int n) {
    cout << "索引\t字符\t权重\t父节点\t左孩子\t右孩子" << endl;
    for (int i = 1; i <= 2 * n - 1; i++) {
        cout << i << "\t" << HT[i].ch << "\t" << HT[i].weight << "\t" 
             << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
    }
}

// 字符串编码
void StringCode(HuffmanTree& HT, HuffmanCode& HC, int n, string str) {
    int i = 0, k, flag;
    while (str[i] != '\0') {
        flag = 0;
        for (k = 1; k <= n; k++) {
            if (HT[k].ch == str[i]) {
                if (i == 0) cout << "字符串 " << str << " 的哈夫曼编码为: ";
                cout << HC[k];
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            cout << "字符 " << str[i] << " 编码失败！";
        }
        i++;
    }
    cout << endl;
}

void menu10() {
    cout << "--- 请选择操作！ ---" << endl;
    cout << "1.以字符为 A, B, C, D, E, F, G, H,其相应的权值为7, 19, 2, 6, 32, 3, 21, 10, 开始创建哈夫曼树！" << endl;
    cout << "2.输入一串字符串并计算其权值开始实验！" << endl;
}

void menu20() {
    cout << "--- 请选择操作！ ---" << endl;
    cout << "1.打印哈夫曼树！" << endl;
    cout << "2.对字符串进行编码！" << endl;
    cout << "3.输出各字符及其编码！" << endl;
    cout << "4.输入一串字符串并对其进行编码！" << endl;
    cout << "0.退出程序！" << endl;
}

int main() {
    HuffmanTree HT;
    HuffmanCode HC;
    int n, choose; // 这里的变量i没有被使用过
    string str;
    
    menu10();
    cin >> choose;
    
    if (choose == 1) n = 8;
    if (choose == 2) {
        cout << "--- 开始创建哈夫曼树！ ---" << endl;
        cout << "请输入一串字符串，我们将计算其权值！" << endl;
        cin >> str;
        WeightCulate(str, n);
        cout << "---打印字符及其权值文件完成！ ---" << endl;
    }
    
    CreatHuffmanTree(HT, n, choose);
    menu20();
    cin >> choose;
    
    while (choose) {
        switch (choose) {
            case 1: PrintHT(HT, n); break;
            case 2: HuffCoding(HT, HC, n); break;
            case 3: CodeOutput(HT, HC, n); break;
            case 4: 
                cout << "[---请输入一串字符串！---]" << endl;
                cin >> str;
                cout << "[---已输入！---]" << endl;
                StringCode(HT, HC, n, str); 
                break;
        }
        menu20();
        cin >> choose;
    }
    
    cout << "[---感谢您的使用！---]" << endl;
    return 0;
}