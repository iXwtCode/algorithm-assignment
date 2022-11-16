#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 *随机生成100个数，采用快速排序法进行排序，并输出生成的随机数组和排序后的有序数组。
*/

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

class QuickSort {
public:
    QuickSort() = default;
    QuickSort(vector<int> &d): data(d) {};
    
    void run_with_random_nums(const unsigned int rand_max, const unsigned int rand_num = 100) {
        set_random_numbers(rand_max, rand_num);
        sort();
    };
    vector<int> get_result() const {
        return sorted_data;
    }
    vector<int> get_resource() const {
        return data;
    }

private:
    
    //待排序数据
    vector<int> data;
    //排序结果
    vector<int> sorted_data;
    //生成随机数
    void set_random_numbers(const unsigned int rand_max, const unsigned int rand_num = 100);
    //快排算法
    void sort();
    //辅助实现递归结构
    void helper(int l, int r);
    //根据关键值将数组分为两部分
    int parition(int l, int r);
    //交换两变量的值
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b =temp;
    }
};

int main() {
    QuickSort q;
    q.run_with_random_nums(1000);
    cout << "随机数:" << endl;
    print(q.get_resource());
    cout << "排序后："  << endl;
    print(q.get_result());
    return 0;
}

void QuickSort::set_random_numbers(const unsigned int rand_max, const unsigned int rand_num) {
    data.clear();
    srand((unsigned int)time(nullptr));
    for(int i = 0; i < rand_num; ++i) {
        data.push_back(rand() % rand_max + 1);
    }
}

void QuickSort::helper(int l, int r) {
    if (l < r){
        //将m移动到排序位置，由此将数组分为两组
        int m = parition(l, r);
        helper(l, m - 1);
        helper(m + 1, r);
    }
}
   

void QuickSort::sort() {
    if(data.empty()) {
        cout << "No data!" << endl;
    }
    else {
        sorted_data.resize(data.size());
        sorted_data = data;
        int n = sorted_data.size();
        helper(0, n - 1);
    }
}

int QuickSort::parition(int l, int r) {
    int m = l;
    for(int i = l + 1; i <= r; i++) {
        if(sorted_data[i] < sorted_data[m]) {
            swap(sorted_data[i], sorted_data[m + 1]);
            swap(sorted_data[m + 1], sorted_data[m]);
            ++m;
        }
    }
    return m;
}