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

bool complete_union_find(vector<int> &res1 , vector<int> &res2,vector<vector<int> >&A,int c){ // �ж��������Ƿ��ܺϲ����ܵĻ�����true��
    for(auto i = 0 ; i < res1.size() ; i++){
        for(auto j = 0 ; j < res2.size() ; j++){
            int a = res1[i]-1;
            int b = res2[j]-1;
            if(A[a][b] < c) {
            //    cout << A[a][b] << endl;
                return false;
            }
        }
    }
    return true;
}

int main()
{
    //���벿��
    int n ;
    cin >> n;
    int D[n];
    for(int i = 0 ; i < n ; i++)
        cin >> D[i];
    vector<vector<int> >A; // �洢ͨ�Ŵ��۾���
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
    //������ֶ���
   // cout << A.size() << " " << A[0].size() << endl;
    vector<vector<int> > K_c; //�洢�ػ��ֵĽ����ÿ���ֳɹ�һ�ξͰ������벢�����
    vector<int> k_c; //��ʱ�洢ĳһ�λ��ֵĽ����
    for(int i = 0; i < n ; i++){
        k_c.push_back(D[i]);
        K_c.push_back(k_c);
        k_c.clear();
    }

    int k = n;
    int c = A[0][0];
    int num = 1; //��ʾ��num�λ��ֵĽ����
    // ��ʼ������
    cout << "````````````````````````" << endl;
    cout << "��ϵͼ���������ʾ��" << endl;
    printf("��%d�λ��ֽ��������ʾ��\n",num);
    cout << "��ǰͨ�Ŵ�����ֵ, "<< "�صĸ���, " << "���ֵĴ�" << endl;
    cout << "< " << c <<","<< k << "{";
    for(int i = 0 ; i < k ; i++){
            cout << "{";
            for(int j = 0 ; j < K_c[i].size()-1 ; j++)
              cout << K_c[i][j] << ",";
              cout << K_c[i][K_c[i].size()-1] << "}";
        }

        cout << "}>" << endl;
    // �����Ӿ����㷨
    int father[n];
    for(auto i = 0 ; i < n ; i++){ //��father����¼ÿ���صĵ�һ���㣬���������ж�ÿ���������ĸ����ˣ�
        father[i] = i;
    }
    while(k > 1){
        --c;
        vector<vector<int> >reg = K_c;
        for(auto i = 0 ; i < reg.size()-1 ; i++){ // ���ζ�ȡ��һ�λ��ֽ���Ĵأ�Ȼ��Ѱ�Һϲ����ܣ�
            for(auto j = i+1 ; j < reg.size() ; j++){
              //  show_class(A);
                if(complete_union_find(K_c[i],reg[j],A,c)){ // �ܹ��ϲ��Ļ���
                    //k--;
                    father[j] = father[i];      //ʹ�ò��鼯��ֱ�ӽ������ܹ��ϲ��Ľڵ�ϲ����������Ĵ�����
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
        //K_c = reg;
        reg.clear();
        printf("��%d�λ��ֽ��������ʾ��\n",++num);
        cout << "��ǰͨ�Ŵ�����ֵ, "<< "�صĸ���, " << "���ֵĴ�" << endl;
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
