BTNode* lastLeftChild(BTNode *t) {
    BTNode *p = t;
    while (p->left != NULL) {
        p = p->left;
    }
    return p;
}


void removeBST(BTNode **t, int num) {
    if (*t == NULL) {
        return; // N?u cây r?ng, không có g? ð? xóa
    }

    if ((*t)->item > num) {
        removeBST(&((*t)->left), num); // N?u giá tr? nút hi?n t?i l?n hõn num, ti?p t?c t?m trong cây con trái
    } else if ((*t)->item < num) {
        removeBST(&((*t)->right), num); // N?u giá tr? nút hi?n t?i nh? hõn num, ti?p t?c t?m trong cây con ph?i
    } else { // (*t)->item == num
        if ((*t)->left == NULL) {
            BTNode *r = *t;
            *t = (*t)->right; // TH2/TH1: Nút c?n xóa không có cây con trái
            free(r);
        } else if ((*t)->right == NULL) {
            BTNode *r = *t;
            *t = (*t)->left; // TH2/TH1: Nút c?n xóa không có cây con ph?i
            free(r);
        } else { // TH3: Nút c?n xóa có c? cây con trái và cây con ph?i
            BTNode *p = lastLeftChild((*t)->right); // T?m nút trái nh?t trong cây con ph?i
            (*t)->item = p->item; // Gán giá tr? c?a nút trái nh?t vào nút c?n xóa
            removeBST(&((*t)->right), p->item); // Xóa nút trái nh?t
        }
    }
}




void TreeTraversal_InOrder2(BTNode *cur) {
    if (cur == NULL)
        return;

    TreeTraversal_InOrder2(cur->left);  // Duy?t cây con trái

    // Th?c hi?n các thao tác trên nút hi?n t?i ? ðây
    printf("%d ", cur->item);

    TreeTraversal_InOrder2(cur->right); // Duy?t cây con ph?i
}





#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode {
    char data;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

BTNode *createNode(char data) {
    BTNode *newNode = (BTNode *)malloc(sizeof(BTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNodeBST(BTNode **root, char data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    if (data < (*root)->data) {
        insertNodeBST(&(*root)->left, data);
    } else {
        insertNodeBST(&(*root)->right, data);
    }
}

BTNode *findMinNode(BTNode *root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

BTNode *removeBST(BTNode *root, char data) {
    if (root == NULL)
        return root;

    if (data < root->data) {
        root->left = removeBST(root->left, data);
    } else if (data > root->data) {
        root->right = removeBST(root->right, data);
    } else {
        if (root->left == NULL) {
            BTNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BTNode *temp = root->left;
            free(root);
            return temp;
        }

        BTNode *temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = removeBST(root->right, temp->data);
    }
    return root;
}

void TreeTraversal_InOrder2(BTNode *cur) {
    if (cur == NULL)
        return;

    TreeTraversal_InOrder2(cur->left);
    printf("%c ", cur->data);
    TreeTraversal_InOrder2(cur->right);
}

int main() {
    BTNode *t = NULL;
    char s[200] = "HEBACDFGLJIKM";
    int n = strlen(s);
    int i;
    for (i = 0; i < n; i++) {
        insertNodeBST(&t, s[i]);
    }

    printf("\nKet qua duyet cay theo thu tu giua:\n");
    TreeTraversal_InOrder2(t);
    printf("\n");

    char c = 'H';
    t = removeBST(t, c);

    printf("\nKet qua duyet cay (sau khi xoa) theo thu tu giua:\n");
    TreeTraversal_InOrder2(t);

    return 0;
}
