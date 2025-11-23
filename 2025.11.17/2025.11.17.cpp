// 기본적인 Vector와 void print
/*
#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& v)
{
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
}

int main()
{
  vector<int> a;

  a.push_back(10);
  a.push_back(20);
  a.push_back(30);
  a.push_back(40);
  a.push_back(50);

  cout << "size : " << a.size() << endl; // 사이즈 확인
  printVector(a);

}

*/





// 깃허브 STL Lab



// 1. 다음과 같이 int형 vector 클래스의 객체를 선언하고 객체에 새로운 데이터를
// push_back() 을 여러번 호출하도록 코드를 수정하라.
// push_back() 함수를 호출할 때 마다 객체에 대해 size와 capacity를 구해서 값의 변화를 분석하라

/*
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const* argv[])
{
  vector <int> v1;
  cout << "Stantard v1 size : " << v1.size() << endl << endl;

  for (int i = 10; i <= 50; i+=10) {
    v1.push_back(i);

    cout << "v1 : " << i << endl <<
      "v1 size : " << v1.size() << endl <<
      "v1 capacity : " << v1.capacity() << endl << endl;
  }

  cout << "After v1 size : " << v1.size() << endl ;
  }
  */
  




// 2. 다음 함수를 구현하고 테스트하는 프로그램을 작성하라.
// (label 스트링이 비워있으면 출력하지 않고 있으면 출력한 후 vector 내의 값을 출력)
/*

#include <iostream>
#include <vector>
using namespace std;


void print_vec(const vector<int>& v, const string& label = "") {

  if (label != "") {     // label string이 있으면 출력
    cout << label << " ";
  };

  for (int x : v) {   // Vector v 출력
    cout << x << " " ;
  }

  cout << endl;

}


int main(){

  vector<int> v1;

  v1.push_back(1);
  v1.push_back(2);


  print_vec(v1);          // label 없음
  print_vec(v1, "v1:");   // label 있음
}*/







// STL sort (아래는 sort 기본 예시)
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void print_vec(const vector<int>& v) {
  for (int x : v) {   // Vector v 출력
    cout << x << " ";
  }
  cout << endl;
};

int main()
{
  vector<int> v;
  v.push_back(10);

  sort(v.begin(), v.end());
  print_vec(v);
}
*/




// STL sort 응용 (학번, 성적)
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
  int id; //학번
  int score;  // 성적
};


int main()
{

  vector<Student> svec = { { 20243526, 30 }, { 20243535, 60 } , { 20243540, 50 } };


  // 출력 방법 1
  vector<Student>::iterator iter = svec.begin();
  cout << iter->id << " / " << iter->score << endl << endl;


  // 출력 방법 2
  sort(svec.begin(), svec.end(), [](const Student& a, const Student& b) {return a.score > b.score; });

  for (auto a : svec) {
    cout << a.id << " / " << a.score << endl;
  }
  cout << endl;


  // 학번 순서대로도 시도
  sort(svec.begin(), svec.end(), [](const Student& a, const Student& b) {return a.id < b.id; });

  for (auto a : svec) {
    cout << a.id << " / " << a.score << endl;
  }

}
*/






// find 함수 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> v = { 1, 5, 15, 10 };
  sort(v.begin(), v.end());


  // find
  vector<int>::iterator itr = find(v.begin(), v.end(), 5);
  if (itr != v.end()) {
    cout << *itr << " - find 1" << endl;
  }
  // vector<int>::iterrator itr = 이 find 앞에 붙는 이유
  // - Vector 안의 원소를 가리키는 포인터


  // auto를 사용한 find
  auto itr2 = find(v.begin(), v.end(), 5);
  if (itr2 != v.end()) {
    cout << *itr2 << " - find 2" << endl;
  }

  return 0;
}





// 그 외의 5가지 실습



// count
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 2, 4, 2, 5};

    int num = 2;
    int c = count(v.begin(), v.end(), num);

    cout << num << "의 개수 = " << c << endl;
    return 0;
}

*/



// max_element
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {10, 50, 30, 20, 40};

    auto it = max_element(v.begin(), v.end());
    cout << "최댓값 = " << *it << endl;

    return 0;
}

*/



// min_element
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {10, 50, 30, 20, 40};

    auto it = min_element(v.begin(), v.end());
    cout << "최솟값 = " << *it << endl;

    return 0;
}
*/


// accumulate
/*
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};

    int sum = accumulate(v.begin(), v.end(), 0);

    cout << "총합 = " << sum << endl;
    return 0;
}

*/



// for_each
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    cout << "Vector 구성: ";
    for_each(v.begin(), v.end(),
        [](int x) {
            cout << x << " ";
        });

    return 0;
}
*/