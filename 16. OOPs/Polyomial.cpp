// Question link => https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/274160/offering/3757746

#include <bits/stdc++.h>
using namespace std;

class Polynomial{
    public:
    vector<int> v;

    Polynomial(){
        v = vector<int>(10, 0);
    }

    Polynomial(vector<int> v){
        this->v = v;
    }

    void setCoefficient(int degree, int coeff){
        if(degree >= v.size()){
            v.resize(degree+1, 0);
        }
        v[degree] = coeff;
    }

    Polynomial operator+(Polynomial const &p){
        vector<int> ans(max(v.size(), p.v.size()), 0);
        for(int i=0; i<v.size(); i++){
            ans[i] += v[i];
        }
        for(int i=0; i<p.v.size(); i++){
            ans[i] += p.v[i];
        }
        return Polynomial(ans);
    }

    Polynomial operator-(Polynomial const &p){
        vector<int> ans(max(v.size(), p.v.size()), 0);
        for(int i=0; i<v.size(); i++){
            ans[i] += v[i];
        }
        for(int i=0; i<p.v.size(); i++){
            ans[i] -= p.v[i];
        }
        return Polynomial(ans);
    }

    Polynomial operator*(Polynomial const &p){
        vector<int> ans(v.size()+p.v.size()-1, 0);
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<p.v.size(); j++){
                ans[i+j] += v[i]*p.v[j];
            }
        }
        return Polynomial(ans);
    }

    // Copy assignment operator
    void operator=(Polynomial const &p){
        v = p.v;
    }

    void print(){
        for(int i=0; i<v.size(); i++){
            if(v[i] != 0){
                cout << v[i] << "X" << i << " ";
            }
        }
        cout << endl;
    }
};

int main(){
    int n;
    vector<int> deg(n), coeff(n);
    for(int i=0; i<n; i++){
        cin >> deg[i];
    }
    for(int i=0; i<n; i++){
        cin >> coeff[i];
    }
    Polynomial p1;
    for(int i=0; i<n; i++){
        p1.setCoefficient(deg[i], coeff[i]);
    }
    int m;
    cin >> m;
    vector<int> deg2(m), coeff2(m);
    for(int i=0; i<m; i++){
        cin >> deg2[i];
    }
    for(int i=0; i<m; i++){
        cin >> coeff2[i];
    }
    Polynomial p2;
    for(int i=0; i<m; i++){
        p2.setCoefficient(deg2[i], coeff2[i]);
    }
    int choice;
    cin >> choice;
    Polynomial ans;
    switch(choice){
        case 1:
            ans = p1+p2;
            ans.print();
            break;
        case 2:
            ans = p1-p2;
            ans.print();
            break;
        case 3:
            ans = p1*p2;
            ans.print();
            break;
        case 4:{
            // Copy assignment operator
            Polynomial p3;
            p3 = p2;
            if(p3.v == p2.v){
                cout << "true" << endl;
            }
            else{
                cout << "false" << endl;
            }
            break;
        }
        default:
            return 0;
    }
}