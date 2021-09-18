// Problem link: https://csacademy.com/ieeextreme-practice/task/drawing-rooted-binary-trees/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

const int N=30; // more than the number of letters in the alphabet

// keep track of the column and row of each node
int row[N], col[N];

// keep track of the children of all the nodes (if present)
int leftChild[N], rightChild[N];

// The contents of this array will be printed as is
char answer[N][N];

string infix, prefix;

int main() {
    while(cin >> infix){
        cin >> prefix;
        int n = infix.length();
        
        for(int i=0;i<N;i++) {
            // initialize all left and right children to be absent (-1)
            leftChild[i]  = -1;
            rightChild[i] = -1;
        }
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                // initialize all characters to be printed as spaces
                answer[i][j] = ' ';
            }
        }
        
        for(int i=0;i<n;i++){
            // The nodes in the infix traversal appears the same as the number of the column
            col[infix[i]-'a'] = i+1;
        }
        
        // The root is the first node in the prefix traversal
        int root = prefix[0]-'a';
        row[root] = 1; // the root appears in the first row
        
        for(int i=1; i<n; i++) {
            int current = prefix[i]-'a',
                parent  = root; // initialize the parent to be the root of the tree
            
            while(true) {
                if(col[current] > col[parent]) { // to the right
                    if(rightChild[parent] == -1) {
                        // if no right child to parent node, assign current node to be that child
                        rightChild[parent] = current;
                        row[current] = row[parent] + 1; // directly after the parent node 
                        break;
                    }
                    else{
                        // otherwise, go to the right child and continue the search
                        parent = rightChild[parent];
                    }
                }
                
                else { // to the left
                    if(leftChild[parent] == -1) {
                        // if no left child to parent node, assign current node to be that child
                        leftChild[parent] = current;
                        row[current] = row[parent]+1; // directly after the parent node 
                        break;
                    }
                    else{
                        // otherwise, go to the left child and continue the search
                        parent = leftChild[parent];
                    }
                }
            }
        }
        
        // keep track of the number of rows in the whole tree
        int max_row = 1;
        for(int i=0; i<n; i++) {
            int node = prefix[i] - 'a';
            max_row = max(max_row, row[node]);
            
            // update the position of the node given its row and column
            answer[ row[node] ][ col[node] ] = prefix[i];
        }
        
        for(int i=1; i<=max_row; i++) {
            for(int j=1; j<=n; j++){
                cout << answer[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
