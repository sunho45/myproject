#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    node* left;
    node* right;
    node* parent;
    int* num;

    node(int* num) {
        this->num = num;
        left = right = parent = nullptr;
    }
};

class heap {
private:
    node* root;
    queue<node*> q;

public:
    heap() : root(nullptr) {}

    bool isempty() {
        return root == nullptr;
    }

    void pushmin(int* num) {
        node* newnode = new node(num);
        if (isempty()) {
            root = newnode;
            q.push(root);
        } else {
            node* current = q.front();
            if (!current->left) {
                current->left = newnode;
                newnode->parent = current;
                q.push(newnode);
                heapupmin(newnode);
            } else if (!current->right) {
                current->right = newnode;
                newnode->parent = current;
                q.push(newnode);
                heapupmin(newnode);
                q.pop(); // 자식 둘 다 찼으므로 제거
            }
        }
    }

    void heapupmin(node* current) {
        while (current->parent && current->num && current->parent->num &&
               *(current->num) < *(current->parent->num)) {
            swap(current->num, current->parent->num);
            current = current->parent;
        }
    }

    void heapdown() {
        node* current = root;
        if (!current || !current->num) return;

        while (true) {
            node* smallest = current;

            if (current->left && current->left->num && *(current->left->num) < *(smallest->num))
                smallest = current->left;

            if (current->right && current->right->num && *(current->right->num) < *(smallest->num))
                smallest = current->right;

            if (smallest == current) break;

            swap(current->num, smallest->num);
            current = smallest;
        }
    }

    int pop() {
        if (!root || !root->num) return -1;

        int result = *(root->num);
        node* last = getlastnode();

        if (last == root) {
            delete root->num;
            delete root;
            root = nullptr;
            return result;
        }

        root->num = last->num;

        if (last->parent) {
            if (last->parent->left == last)
                last->parent->left = nullptr;
            else if (last->parent->right == last)
                last->parent->right = nullptr;
        }

        delete last;
        heapdown();
        return result;
    }

    node* getlastnode() {
        if (!root) return nullptr;

        queue<node*> temp;
        temp.push(root);
        node* current = nullptr;

        while (!temp.empty()) {
            current = temp.front();
            temp.pop();

            if (current->left) temp.push(current->left);
            if (current->right) temp.push(current->right);
        }
        return current;
    }

    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapsort(int* arr, int size) {
        // 힙에 넣기
        for (int i = 0; i < size; i++) {
            int* p = new int(arr[i]); // 안전한 복사
            pushmin(p);
        }

        // 힙에서 꺼내기
        for (int i = 0; i < size; i++) {
            arr[i] = pop();
        }

        // 결과 출력
        for (int i = 0; i < size; i++) {
            cout << arr[i] << endl;
        }

        clear(root); // 동적 메모리 해제
        root = nullptr;
        q = queue<node*>();
    }

    void clear(node* current) {
        if (!current) return;
        clear(current->left);
        clear(current->right);
        if (current->num) delete current->num;
        delete current;
    }

    ~heap() {
        clear(root);
    }
};

int main() {
    heap* hp = new heap();
    int arr[5] = {5, 7, 15, 9, 12};

    hp->heapsort(arr, 5);

    delete hp;
    return 0;
}