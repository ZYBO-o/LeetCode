# 排序积累与总结















## 七.堆排序

### 1.基本概念

堆排序是利用**堆**这种数据结构而设计的一种排序算法，堆排序是一种**选择排序，**它的最坏，最好，平均时间复杂度均为O(nlogn)，它也是不稳定排序。首先简单了解下堆结构。

**堆是具有以下性质的完全二叉树：每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆；或者每个结点的值都小于或等于其左右孩子结点的值，称为小顶堆。如下图：**

<div align = center><img src="../images/Sort1.png" width="800px" /></div>

同时，我们对堆中的结点按层进行编号，将这种逻辑结构映射到数组中就是下面这个样子

<div align = center><img src="../images/Sort2.png" width="500px" /></div>

该数组从逻辑上讲就是一个堆结构，我们用简单的公式来描述一下堆的定义就是：

**大顶堆：arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]**  

**小顶堆：arr[i] <= arr[2i+1] && arr[i] <= arr[2i+2]**  

了解了这些定义。接下来看看堆排序的基本思想及基本步骤：

### 2.堆排序基本思想及步骤

**堆排序的基本思想：**

+ **将待排序序列构造成一个大顶堆，此时，整个序列的最大值就是堆顶的根节点。将其与末尾元素进行交换，此时末尾就为最大值。然后将剩余n-1个元素重新构造成一个堆，这样会得到n个元素的次小值。如此反复执行，便能得到一个有序序列了**

**步骤一 构造初始堆。将给定无序序列构造成一个大顶堆（一般升序采用大顶堆，降序采用小顶堆)。**

+ 假设给定无序序列结构如下

  <div align = center><img src="../images/Sort3.png" width="400px" /></div>

+ 此时我们从最后一个非叶子结点开始（叶结点自然不用调整，第一个非叶子结点 arr.size()/2 - 1=5/2-1=1，也就是下面的6结点），从左至右，从下至上进行调整。

  <div align = center><img src="../images/Sort4.png" width="700px" /></div>

+ 找到第二个非叶节点4，由于[4,9,8]中9元素最大，4和9交换。

  <div align = center><img src="../images/Sort5.png" width="700px" /></div>

+ 这时，交换导致了子根[4,5,6]结构混乱，继续调整，[4,5,6]中6最大，交换4和6。

  <div align = center><img src="../images/Sort6.png" width="700px" /></div>

+ 此时，我们就将一个无需序列构造成了一个大顶堆。

**步骤二 将堆顶元素与末尾元素进行交换，使末尾元素最大。然后继续调整堆，再将堆顶元素与末尾元素交换，得到第二大元素。如此反复进行交换、重建、交换。**

+ 将堆顶元素9和末尾元素4进行交换

  <div align = center><img src="../images/Sort7.png" width="700px" /></div>

+ 重新调整结构，使其继续满足堆定义

  <div align = center><img src="../images/Sort8.png" width="700px" /></div>

+ 再将堆顶元素8与末尾元素5进行交换，得到第二大元素8.

  <div align = center><img src="../images/Sort9.png" width="700px" /></div>

+ 后续过程，继续进行调整，交换，如此反复进行，最终使得整个序列有序

  <div align = center><img src="../images/Sort10.png" width="400px" /></div>

再简单总结下堆排序的基本思路：

　　**a.将无需序列构建成一个堆，根据升序降序需求选择大顶堆或小顶堆;**

　　**b.将堆顶元素与末尾元素交换，将最大元素"沉"到数组末端;**

　　**c.重新调整结构，使其满足堆定义，然后继续交换堆顶元素与当前末尾元素，反复执行调整+交换步骤，直到整个序列有序。**

**代码实现：**

```c++
template<typename T>
class MaxHeap {
private:
    T *data;
    int count;
    int capacity;

    //向下进行移动
    void shiftDown(int k) {
        //只要有左孩子，那就肯定还有孩子
        while(2 * k <= count) {
            //在此轮循环中，data[k]和data[j]交换位置
            int j = 2 * k;
            //如果有右孩子而且右孩子的值比左孩子大，那就和右孩子进行交换
            if(j + 1 <= count && data[j + 1] > data[j]) 
                j += 1;
            //如果比自己的孩子大，那就不需要进行交换
            if(data[k] >= data[j]) 
                break;
            //否则进行交换
            swap(data[k], data[j]);
            k = j;
        }
    }
public:
    //初始化构建最大堆
    MaxHeap(vector<T>& nums) {
        data = new T[nums.size() + 1];
        capacity = nums.size();
        for(int i = 0; i < nums.size(); ++i) {
            data[i + 1] = nums[i];
        }
        count = nums.size();
        //将非叶子结点进行重构，构建最大堆
        //其中，非叶子结点的下标就是1 - count/2
        for (int i = count / 2; i >= 1 ; --i) {
            shiftDown(i);
        }
    }
    //取出最大值的元素,然后进行重构
    T extractMax() {
        assert(count > 0);
        T item = data[1];
        //将第一个元素和最后一个元素进行交换
        swap(data[1], data[count]);
        --count;
        //进行重构最大堆，将第一个元素向下移
        shiftDown(1);
        return item;
    }
    ~MaxHeap() {
        delete[] data;
    }
};

template<typename T>
void HeapSort(vector<T>& nums) {
    //步骤一：无需序列构建成一个最大堆
    MaxHeap<T> maxHeap = MaxHeap<T>(nums);
    //步骤二：
    //将堆顶元素与末尾元素交换，将最大元素"沉"到数组末端。
    //重新调整结构，使其满足堆定义，然后继续交换堆顶元素与当前末尾元素
    //反复执行调整+交换步骤，直到整个序列有序
    for (int i = nums.size() - 1; i >= 0 ; --i) 
        nums[i] = maxHeap.extractMax();
    for (auto i : nums) 
        cout << i << " ";
    cout << endl;
}
```



## 八.计数排序

### 1.基本概念

像快排、堆排、归并等排序算法都是基于比较的排序算法，时间复杂度最好情况也只能降到O(nlogn)。而计数排序是一种线性排序算法，不需要进行比较，时间复杂度为O(n)。

**计数排序的核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数。**

### 2.计数排序基本思想及其步骤

当输入的元素是 n 个 0 到 k 之间的整数时，它的运行时间是 Θ(n + k)。 **计数排序不是比较排序，排序的速度快于任何比较排序算法。**

由于用来计数的数组C的长度取决于待排序数组中数据的范围（等于待排序数组的最大值与最小值的差加上1），这使得计数排序对于数据范围很大的数组，需要大量时间和内存。例如：计数排序是用来排序0到100之间的数字的最好的算法，但是它不适合按字母顺序排序人名。但是，计数排序可以用在基数排序中的算法来排序数据范围很大的数组。

通俗地理解，例如有 10 个年龄不同的人，统计出有 8 个人的年龄比 A 小，那 A 的年龄就排在第 9 位,用这个方法可以得到其他每个人的位置,也就排好了序。当然，年龄有重复时需要特殊处理（保证稳定性），这就是为什么最后要反向填充目标数组，以及将每个数字的统计减去 1 的原因。

**算法的步骤如下：**

1. 找出待排序的数组中最大和最小的元素
2. 统计数组中每个值为 i 的元素出现的次数，存入数组 C 的第 i 项
3. 对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
4. 反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1

<div align = center><img src="../images/Sort11.gif" width="800px" /></div>

```C++
void CountSort(vector<int>& nums) {
    int n = nums.size();
    if (!n) return ;

    //1.找出待排序的数组中最大和最小的元素
    int min_num = *min_element(nums.begin(), nums.end());
    int max_num = *max_element(nums.begin(), nums.end());

    int length = max_num - min_num + 1;

    //2.统计数组中每个值为 i 的元素出现的次数，存入数组 C 的第 i 项
    vector<int> count(length, 0);

    //3.对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
    for (int i = 0; i < n; ++i) {
        ++ count[nums[i] - min_num];
    }

    //反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < count[i]; ++j) {
            cout << i + min_num << " ";
        }
    }

    cout << endl;
}
```



















