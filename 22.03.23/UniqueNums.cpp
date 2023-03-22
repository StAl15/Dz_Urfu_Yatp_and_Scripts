#include "header.h"

void openFile(ifstream &file, string name) {
    file.open(name);
}

void readFile(ifstream &file, LinkedList &nums, int &countN) {
    file >> countN;
//    nums = new int[countN];
    while (!file.eof()) {
        for (int i = 0; i < countN; i++) {
            int c = 0;
            file >> c;
            nums.add_node(c);
        }
    }
    file.close();
}

bool isInList(int elem, num *&nums, int len) {
    for (int i = 0; i < len; i++) {
        if (nums[i].n == elem) return true;
    }
    return false;
}

void setDiffNums(num *&nums, LinkedList &nums_, int countN, int &countN_) {
    int k = 0;
    countN_ = 0;
    nums = new num[countN_];
    for (Node *ptr = nums_.getHead(); ptr != NULL; ptr = ptr->next) {
        int current = ptr->data;
        if (!isInList(current, nums, countN_)) {
            countN_++;
            nums[k].n = current;
            nums[k].countRepeat = 0;
            for (Node *ptr1 = nums_.getHead(); ptr1 != NULL; ptr1 = ptr1->next) {
                if (ptr1->data == current) nums[k].countRepeat++;
            }
        }
        cout << nums[k].n << " cr=" << nums[k].countRepeat << endl;
        k++;

    }
    for (int i = 0; i < countN_; i++) {
        cout << nums[i].n << endl;
    }
}

void writeAnswer(num *nums, int countN) {
    ofstream file;
    file.open("answer.txt");
    for (int i = 0; i < countN; i++) {
        file << "n = " << nums[i].n << " cr = " << nums[i].countRepeat << endl;
    }
    file.close();
}

void sortNums(num *&nums, int countN) {
    for (int i = 0; i < countN; i++) {
        for (int j = 0; j < countN - i - 1; j++) {
            if (nums[j].n > nums[j + 1].n) swap(nums[j], nums[j + 1]);
        }
    }
}

