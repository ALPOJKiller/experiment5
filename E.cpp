#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
void row_make_zero(vector<vector<unsigned> >& mat,unsigned index) {
  unsigned min_val = *(min_element(mat[index].begin(),mat[index].end()));
  for_each(mat[index].begin(),mat[index].end(),[&](unsigned& n){n-=min_val;});
}
void col_make_zero(vector<vector<unsigned> >& mat,unsigned index) {
  unsigned min_val = UINT_MAX;
  for(auto &v:mat) {
    if(v[index] < min_val) {
      if(v[index] == 0) {
        return;
      } else {
        min_val = v[index];
      }
    }
  }
  for(auto &v:mat) {
      v[index] -= min_val;
  }
}
void remove_row(vector<vector<unsigned> >& mat) {
  mat.erase(mat.begin()+1);
}
void remove_col(vector<vector<unsigned> >& mat) {
  for(auto& v:mat) {
    v.erase(v.begin()+1);
  }
}

unsigned round(vector<vector<unsigned> >& mat) {
  for (size_t i = 0; i < mat.size(); i++) {
    row_make_zero(mat,i);
  }
  for (size_t i = 0; i < mat.front().size(); i++) {
    col_make_zero(mat,i);
  }
  unsigned result = mat[1][1];
  remove_row(mat);
  remove_col(mat);
  return result;
}

int main() {
    unsigned n;
    cin >> n;
    std::vector<std::vector<unsigned> > mat(n,std::vector<unsigned>(n,0));
    for(auto& v:mat) {
      for(auto& ele:v) {
        cin >> ele;
      }
    }
    cout << mat[1][1] << endl;
    for (size_t i = 0; i < n-1; i++) {
      cout << round(mat) << endl;
    }
    return 0;
}
