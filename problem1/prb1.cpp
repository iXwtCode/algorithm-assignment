#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 *随机生成100个数，采用快速排序法进行排序，并输出生成的随机数组和排序后的有序数组。
*/

//打印结果
void print(vector<int> d) {
    int n = d.size();
    for(int i = 0; i < n; ++i) {
        if((i + 1) % 20 == 0) {
            cout << d[i] << '\n';
        }
        else {
            cout << d[i] << " ";
        }
    }
}

//快排类
class QuickSort {
public:
    QuickSort() = default;

    //运行算法
    vector<int> fit(vector<int> d) {
        sort(d, 0, d.size() - 1);
        return d;
    }

private:
    //快排算法
    void sort(vector<int> &, int i, int j);
};

 vector<int> get_random_numbers(const unsigned int rand_max, const unsigned int rand_num = 100) {
    vector<int> data;
    data.clear();
    srand((unsigned int)time(nullptr));
    for(int i = 0; i < rand_num; ++i) {
        data.push_back(rand() % rand_max + 1);
    }
    return data;
 }

int main() {
    auto data = get_random_numbers(1000);
    QuickSort q;
    auto res = q.fit(data);

    cout << "随机数据:\n";
    print(data);
    cout << "已排序数据:\n";
    print(res);
}

void QuickSort::sort(vector<int> &v, int left, int right) {
        if (left < right) {
        int key = v[left];
        int low = left;
        int high = right;
        while (low < high) {
            // high上标位置开始，向左边遍历，查找不大于基准数的元素
            while (low < high && v[high] >= key) {
                high--;
            }
            if (low < high) {// 找到小于准基数key的元素
                v[low] = v[high];// 赋值给low下标位置，low下标位置元素已经与基准数对比过了
                low++;// low下标后移
            } else {// 没有找到比准基数小的元素
                // 说明high位置右边元素都不小于准基数
                break;
            }
            // low下标位置开始，向右边遍历，查找不小于基准数的元素
            while (low < high && v[low] <= key) {
                low++;
            }
            if (low < high) {// 找到比基准数大的元素
                v[high] = v[low];// 赋值给high下标位置，high下标位置元素已经与基准数对比过了
                high--;// high下标前移，
            } else {// 没有找到比基准数小的元素
                // 说明low位置左边元素都不大于基准数
                break;
            }
        }
        v[low] = key;// low下标赋值基准数
        sort(v, left, low - 1);
        sort(v, low + 1, right);
    }

}
