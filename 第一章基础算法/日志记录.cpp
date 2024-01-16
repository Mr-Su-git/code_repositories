#include <bits/stdc++.h>
using namespace std;
typedef pair<long long , long long>PII ; // <ts , id>为后续按照时间点排序做准备
long long n , d , k ;
int main()
{
  scanf("%lld%lld%lld" , &n , &d , &k) ;
  vector<PII>arr ;
  while(n--){ // 数据输入部分
    long long ts , id ;
    scanf("%lld%lld" , &ts , &id) ;
    arr.push_back({ts , id}) ;
  }
//   sort(arr.begin() , arr.end()) ; // 先按照时间点排序
  // 按照id优先 ts次之的标准排序
  sort(arr.begin() , arr.end() , [](const PII& lhs, const PII& rhs){return lhs.second < rhs.second  || (lhs.second == rhs.second && lhs.first < rhs.first);}) ;
  
//   for(auto it : arr){
    // printf("id:%lld time:%lld \n" ,it.second , it.first) ;
//   }
  // it作为指针遍历arr数组
  auto it = arr.begin();
  while (it != arr.end()) {
      long long id0 = it->second;
      long long ts0 = it->first;
      int cnt = 0;
      // 保持it指向的id不变的情况下
      while (it != arr.end() && it->second == id0) {
          if (it->first - ts0 < d) cnt++; // 判断此时距开始的时间是否足够(问题:判断d长度时间的区间左端不一定要为最开始的ts0)
          ++it;
      }

      if (cnt >= k) printf("%lld\n", (--it)->second);
  }
  return 0 ;
}