#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
vector<unsigned> bad_rows(const vector<vector<unsigned>>& mat) {
  vector<unsigned> ans;
  for(unsigned i=0;i < mat.size();++i) {
    const vector<unsigned>& v = mat[i];
    if(accumulate(v.begin(),v.end(),0U) % 2 != 0) {
      ans.push_back(i);
    }
  }
  return ans;
}
vector<unsigned> bad_cols(const vector<vector<unsigned>>& mat) {
  vector<unsigned> ans;
  for(unsigned i=0;i < mat.front().size();++i) {
    unsigned sum = 0;
    for (unsigned j = 0; j < mat.size(); ++j) {
      sum += mat[j][i];
    }
    if(sum % 2 != 0) {
      ans.push_back(i);
    }
  }
  return ans;
}
template <typename T>
void print_vector(const vector<T>& v) {
  if(v.empty()) {
    return;
  }
	cout << v.front();
	for (auto it = v.begin()+1;it != v.end();++it) {
		cout << ", " << *it;
	}
  cout << endl;
}
int main() {
    unsigned n;
    cin >> n;
    std::vector<std::vector<unsigned>> mat(n,std::vector<unsigned>(n,0));
    for(auto& v:mat) {
      for(auto& ele:v) {
        cin >> ele;
      }
    }
    auto rs = bad_rows(mat),ls = bad_cols(mat);
    if(rs.size() == 0 && ls.size() == 0) {
      cout << "OK";
    } else if(rs.size() == 1 && ls.size() == 1) {
      cout << rs[0]+1 << ' ' << ls[0]+1;
    } else {
      cout << "Corrupt";
    }
    return 0;
}
