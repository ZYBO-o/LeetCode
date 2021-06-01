//
// Created by 张永斌 on 2021/5/31.
//

#ifndef LEETCODE_HEAPSORT_H
#define LEETCODE_HEAPSORT_H




template<typename T>
class MaxHeap {
private:
    T *data;
    int count;
    int capacity;

    void shiftUp(int k) {
        //交换堆
        while(k > 1 && data[k / 2] < data[k]) {
            swap(data[k / 2], data[k]);
            k = k / 2;
        }
    }

    void shiftDown(int k) {
        //只要有左孩子，那就肯定还有孩子
        while(2 * k <= count) {
            //在此轮循环中，data[k]和data[j]交换位置
            int j = 2 * k;
            //如果有右孩子而且右孩子的值比左孩子大，那就和右孩子进行交换
            if(j + 1 <= count && data[j + 1] > data[j]) {
                j += 1;
            }
            //如果比自己的孩子大，那就不需要进行交换
            if(data[k] >= data[j]) {
                break;
            }
            //否则进行交换
            swap(data[k], data[j]);
            k = j;
        }
    }

public:
    MaxHeap(int capacity){
        //构造函数来构造数组大小，加一是因为下标从1开始
        data = new T[capacity + 1];
        this->capacity = capacity;
        count = 0;
    }

    MaxHeap(vector<T>& nums) {

        data = new T[nums.size() + 1];
        capacity = nums.size();
        for(int i = 0; i < nums.size(); ++i) {
            data[i + 1] = nums[i];
        }
        count = nums.size();

        for (int i = count / 2; i >= 1 ; --i) {
            shiftDown(i);
        }

    }

    //插入一个数
    void insert(T item) {
        //容量能
        assert(count + 1 <= capacity);
        data[count + 1] = item;
        ++ count;
        shiftUp( count);
    }

    //弹出优先级最高的元素
    T extractMax() {
        assert(count > 0);

        T item = data[1];
        //将第一个元素和最后一个元素进行交换
        swap(data[1], data[count]);
        --count;

        shiftDown(1);

        return item;

    }

    ~MaxHeap() {
        delete[] data;
    }
};


template<typename T>
void HeapSort(vector<T>& nums) {
    MaxHeap<T> maxHeap = MaxHeap<T>(nums.size());
    for (auto i : nums) {
        maxHeap.insert(i);
    }

    for (int i = nums.size() - 1; i >= 0 ; --i) {
        nums[i] = maxHeap.extractMax();
    }
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

template<typename T>
void HeapSort1(vector<T>& nums) {
    MaxHeap<T> maxHeap = MaxHeap<T>(nums);

    for (int i = nums.size() - 1; i >= 0 ; --i) {
        nums[i] = maxHeap.extractMax();
    }
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}





#endif //LEETCODE_HEAPSORT_H
