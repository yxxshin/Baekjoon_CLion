#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> inorder;
vector<int> postorder;

void make_tree(int inorder_start, int inorder_end, int postorder_start, int postorder_end){
    // it isn't a tree : skip
    if(inorder_start > inorder_end || postorder_start > postorder_end)
        return;

    // last number of postorder is "root node"
    int root = postorder[postorder_end];
    int root_place;

    // find root node's place on inorder
    for(int i = inorder_start; i <= inorder_end; i++){
        if(inorder[i] == root) {
            root_place = i;
            break;
        }
    }

    // print root (preorderTraversal)
    printf("%d ", root);

    // make next two trees (left / right based on root_place)
    make_tree(inorder_start, root_place - 1, postorder_start, postorder_start + root_place - inorder_start - 1);
    make_tree(root_place + 1, inorder_end, postorder_start + root_place - inorder_start, postorder_end - 1);
}

int main() {
    // save inputs
    int temp;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        inorder.push_back(temp);
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        postorder.push_back(temp);
    }

    // make tree ( answer printed )
    make_tree(0, N-1, 0, N-1);
}