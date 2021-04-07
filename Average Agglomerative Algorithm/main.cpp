#include <iostream>
#include <vector>
using namespace std;

struct Node{
  int c;
  int k;
  vector<vector<char> > K_c;
}DE[55];

void show_class(vector<vector<int> >&A){
    for(auto i = 0 ; i < A.size() ; i++){
        for(auto j = 0 ; j < A[0].size() ; j++){
                cout << A[i][j] << " ";

            }
            cout << endl;
        }

}

bool average_union_find(vector<int> &res1 , vector<int> &res2,vector<vector<int> >&A,int c){ // 判断两个簇是否能合并；能的话返回true；
    int sum = 0;
    int num = res1.size() * res2.size();
    double avg;
    for(auto i = 0 ; i < res1.size() ; i++){
        for(auto j = 0 ; j < res2.size() ; j++){
            int a = res1[i]-1;
            int b = res2[j]-1;
            sum += A[a][b];
        }
    }
    avg = (sum*1.0) / num;
   // cout << "avg: "<< avg << endl;
    double C = c*1.0;
    if(avg >= C) return true;
    return false;
}

int main()
{
    //输入部分
    int n ;
    cin >> n;
    int D[n];
    for(int i = 0 ; i < n ; i++)
        cin >> D[i];
    vector<vector<int> >A; // 存储通信代价矩阵；
    vector<int> reg_A;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            //reg_A.clear();
            int a;
            cin >> a;
            reg_A.push_back(a);
        }
        A.push_back(reg_A);
        reg_A.clear();
    }

    //show_class(A);
    //输出部分定义
   // cout << A.size() << " " << A[0].size() << endl;
    vector<vector<int> > K_c; //存储簇划分的结果；每划分成功一次就把它存入并输出；
    vector<int> k_c; //临时存储某一次划分的结果；
    for(int i = 0; i < n ; i++){
        k_c.push_back(D[i]);
        K_c.push_back(k_c);
        k_c.clear();
    }

    int k = n;
    int c = A[0][0];
    int num = 1; //表示第num次划分的结果；
    // 初始输出结果
    cout << "````````````````````````" << endl;
    cout << "谱系图结果如下所示：" << endl;
    printf("第%d次划分结果如下所示：\n",num);
    cout << "当前通信代价阈值, "<< "簇的个数, " << "划分的簇" << endl;
    cout << "< " << c <<","<< k << "{";
    for(int i = 0 ; i < k ; i++){
            cout << "{";
            for(int j = 0 ; j < K_c[i].size()-1 ; j++)
              cout << K_c[i][j] << ",";
              cout << K_c[i][K_c[i].size()-1] << "}";
        }

        cout << "}>" << endl;
    // 单连接聚类算法
    int father[n];
    for(auto i = 0 ; i < n ; i++){ //用father来记录每个簇的第一个点，这样就能判断每个点属于哪个簇了；
        father[i] = i;
    }
    while(k > 1){
        --c;
        vector<vector<int> >reg = K_c;
        for(auto i = 0 ; i < reg.size()-1 ; i++){ // 依次读取上一次划分结果的簇，然后寻找合并可能；
            for(auto j = i+1 ; j < reg.size() ; j++){
              //  show_class(A);
                if(average_union_find(K_c[i],reg[j],A,c)){ // 能够合并的话；
                      //   k--;
                    father[j] = father[i];
                    for(auto p = 0 ; p < reg[j].size() ; p++){
                        reg[father[i]].push_back(reg[j][p]);
                    }
                    reg[j].clear();
                    }
                }

            }
        K_c.clear();
        for(int i = 0 ; i < reg.size() ; i++){
            if(reg[i].size() != 0) K_c.push_back(reg[i]);
        }
        k = K_c.size();
        reg.clear();
        printf("第%d次划分结果如下所示：\n",++num);
        cout << "当前通信代价阈值, "<< "簇的个数, " << "划分的簇" << endl;
        cout << "< " << c <<","<< k << "{";
        for(int i = 0 ; i < k ; i++){
            cout << "{";
            for(int j = 0 ; j < K_c[i].size()-1 ; j++)
              cout << K_c[i][j] << ",";
              cout << K_c[i][K_c[i].size()-1] << "}";
        }

        cout << ">" << endl;
    }

    return 0;
}
