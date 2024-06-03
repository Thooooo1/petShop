BTNode* lastLeftChild(BTNode *t) {
    BTNode *p = t;
    while (p->left != NULL) {
        p = p->left;
    }
    return p;
}


void removeBST(BTNode **t, int num) {
    if (*t == NULL) {
        return; // N?u c�y r?ng, kh�ng c� g? �? x�a
    }

    if ((*t)->item > num) {
        removeBST(&((*t)->left), num); // N?u gi� tr? n�t hi?n t?i l?n h�n num, ti?p t?c t?m trong c�y con tr�i
    } else if ((*t)->item < num) {
        removeBST(&((*t)->right), num); // N?u gi� tr? n�t hi?n t?i nh? h�n num, ti?p t?c t?m trong c�y con ph?i
    } else { // (*t)->item == num
        if ((*t)->left == NULL) {
            BTNode *r = *t;
            *t = (*t)->right; // TH2/TH1: N�t c?n x�a kh�ng c� c�y con tr�i
            free(r);
        } else if ((*t)->right == NULL) {
            BTNode *r = *t;
            *t = (*t)->left; // TH2/TH1: N�t c?n x�a kh�ng c� c�y con ph?i
            free(r);
        } else { // TH3: N�t c?n x�a c� c? c�y con tr�i v� c�y con ph?i
            BTNode *p = lastLeftChild((*t)->right); // T?m n�t tr�i nh?t trong c�y con ph?i
            (*t)->item = p->item; // G�n gi� tr? c?a n�t tr�i nh?t v�o n�t c?n x�a
            removeBST(&((*t)->right), p->item); // X�a n�t tr�i nh?t
        }
    }
}




void TreeTraversal_InOrder2(BTNode *cur) {
    if (cur == NULL)
        return;

    TreeTraversal_InOrder2(cur->left);  // Duy?t c�y con tr�i

    // Th?c hi?n c�c thao t�c tr�n n�t hi?n t?i ? ��y
    printf("%d ", cur->item);

    TreeTraversal_InOrder2(cur->right); // Duy?t c�y con ph?i
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
