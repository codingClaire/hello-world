#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    for (int i = 0; i < 10; i++){
            v.push_back(i);
    }

    for (vector<int>::size_type ix = 0; ix != v.size(); ix ++){
            cout<<v[ix];
    }
    cout<<endl;

    //�ڿ�ʼ����10
    v.insert(v.begin(), 10);
    for (vector<int>::size_type ix = 0; ix != v.size(); ix ++){
            cout<<v[ix];
    }
    cout<<endl;

    //��10��0֮�����11
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++){
            if (*it == 0){
                    v.insert(it, 11);
                    break;
            }
    }
    for (vector<int>::size_type ix = 0; ix != v.size(); ix ++){
            cout<<v[ix];
    }
    cout<<endl;

    return 0;
}
