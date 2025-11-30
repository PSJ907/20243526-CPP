// 깃허브 STL Labs 문제
// Vector class




// 1. 다음과 같이 int형 vector 클래스의 객체를 선언하고
// 객체에 새로운 데이터를 push_back() 을 여러번 호출하도록 코드를 수정하라.
// push_back() 함수를 호출할 때 마다 객체에 대해
// size와 capacity를 구해서 값의 변화를 분석하라

/*
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const* argv[])
{
  vector <int> v1;

  for (int i = 10; i <= 50; i += 10) {
    v1.push_back(i);

    cout << "v1 : " << i << endl <<
      "v1 size : " << v1.size() << endl <<
      "v1 capacity : " << v1.capacity() << endl <<
      "=================================" << endl;    // 구분선
  }

}
*/


// push_back() : vector의 가장 마지막에 새로운 원소를 추가하기 위해 사용하는 함수 (임시 객체를 생성 후, 복사한 값을 vector에 저장)
// size : vector에 실제로 저장되어 있는 원소의 개수 (배열이 사용 중인 크기)
// capacity : vector가 다른 할당없이 저장할 수 있는 원소의 최대 개수 (실제 배열의 크기)
// size는 저장되어 있는 원소의 개수로, v1이 10씩 증가할 때마다 1씩 증가하지만,
// 5번째 배열부터는 capacity가 6으로 갑작스레 오르게 되는데,
// 이는 capacity는 배열의 저장공간이므로 데이터를 저장할 공간이 부족할 때마다 1.5씩 증가하기 때문이다. 






// 2. 클래스 템플릿 vector를 사용한 프로그램이다.
// 프로그램 수행 결과를 예측하고 실행 결과의 비교하고 vector 분석하라.
/*
#include <vector>
#include <iostream>
using namespace std;
int main()
{
  vector<int> v1, v2, v3;

  v1.push_back(10);
  v1.push_back(20);
  v1.push_back(30);
  v1.push_back(40);
  v1.push_back(50);

  cout << "v1 = ";
  for (auto& v : v1){
     cout << v << " ";
  }
  cout << endl;
  // 예측 : >> v1 = 10 20 30 40 50 << 이 출력될 것이다.


  v2.assign(v1.begin(), v1.end());
  cout << "v2 = ";
  for (auto& v : v2){
     cout << v << " ";
  }
   cout << endl;
  // 예측 : >> v2 = 10 20 30 40 50 << 이 출력될 것이다.


   v3.assign(3, 6);
   cout << "v3 = ";
   for (auto& v : v3){
       cout << v << " ";
   }
   cout << endl;
  // 예측 : >> v3 = 6 6 6 << 이 출력될 것이다.


   v3.assign({ 5, 6, 7 });
   for (auto& v : v3){
      cout << v << " ";
  }
  cout << endl;
  // 예측 : >> 5, 6, 7 << 이 출력될 것이다.


  int &i = v1.at(0);

  cout << "v1 첫 번째 원소의 값:  " << i << endl;

  if(v1 == v2) cout << "v1과 v2는 같다." << endl;
  else cout << "v1과 v2는 다르다" << endl;
  // v1 과 v2에 저장되어 있는 값은 같으므로 "v1과 v2는 같다."가 출력될 것이다.
  // 대신, v1과 v2는 같은 저장공간을 공유하는 것이 아니다. assign으로 v2를 새로 만들어,
  // 기존 요소를 지우고 새 값들로 채웠으므로 v1 원소의 값이 바뀌어도 v2에는 영향을 끼치지 않는다.


  i = 80;
  const int &j = v1.at(0);

  cout << "값을 변경 후 v1 첫 번째 원소의 값:  " << j << endl;
  // v1의 첫 번째 원소의 값이 10 -> 80으로 변경되었다.

  if(v1 == v2) cout << "v1과 v2는 같다." << endl;
  else cout << "v1과 v2는 다르다" << endl;
  // v1 = 80 20 30 40 50 / v2 = 10 20 30 40 50 이므로 다르다.
}

*/


// assign : 기존의 데이터는 삭제되고, 새로운 값들로 저장하는 함수.
// How : assign(x, y) / 크기는 x, 모든 값을 y로 저장
// 범위 복사의 기능도 가능하다. (반복자(iterator) 범위.)







// 3. 사각형을 표현하는 클래스를 정의하고 클래스를 vector를
// 이용하여 저쟝하고 처리하는 프로그램을 작성하라.
/*
#include <vector>
#include <iostream>
using namespace std;

class square {
  int width, length, area;
public:
  square(int w, int l) : width(w), length(l) {
    area = w * l;
  }

  int getArea() const { return area;  }

  void show() const {
    cout << "가로 : " << width << ", 세로 : " << length << endl <<
      "사각형의 넓이 : " << area << endl <<
      "==========================" << endl ;
  }
};
// class square에서 사각형의 가로, 세로, 넓이의 변수 선언을 해준 후,
// getArea로 main 에서 넓이 비교 시에 area를 호출할 수 있도록 하였다.


int main() {
  // vector에 여러 사각형 저장
  vector<square> squares;
  squares.push_back(square(20, 30)); // S1
  squares.push_back(square(10, 10)); // S2

  // 모든 사각형 출력
  for (size_t i = 0; i < squares.size(); ++i) {
    cout << "< S" << i + 1 << " 사각형 >" << endl;
    squares[i].show();
  }

  // 넓이 비교
  if (squares[0].getArea() > squares[1].getArea()) {
    cout << "S1 사각형의 넓이가 더 넓다." << endl;
  }
  else if (squares[0].getArea() < squares[1].getArea()) {
    cout << "S2 사각형의 넓이가 더 넓다." << endl;
  }
  else {
    cout << "두 사각형의 넓이는 같다." << endl;
  }

  return 0;

}*/





// 4. 다음 프로그램의 실행 결과를 분석하라.

/*
#include <vector>
#include <iostream>
using namespace std;
int main()
{
  vector<int> v1(5);
  v1.push_back(3);

  cout << v1.capacity() << endl;
  cout << v1.size() << endl;

}*/

// vector<int> v1(5); 줄에서 원소 5개를 가진 백터가 만들어져서 초기 size는 5이고 capacity는 적어도 5이다.
// 그 상태에서 v1.push_back(3)을 호출하면 현재 백터가 전부 찼기 때문에
// 백터는 새로운 백터를 할당하고 기존 요소들을 옮긴 뒤 새로운 원소를 추가하게 된다.
// 이 때문에 size는 6이 되고, capacity는 최대용량으로 넉넉하게 7이 된다.






// 5. 4번의 프로그램에서 3 저장되는 위치는?
// v1 백터는 0~4까지 총 5개의 기본값을 갖게 된다.
// push_back을 호출하며 백터의 가장 끝에 3이 추가된다.
// 그러므로 3의 저장위치는 인덱스 5이다.





// 6. 4의 프로그램에서 첫 번째 위치에 데이터 10을 저장하는 프로그램을 작성하라.

/*

#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> v1(5);
    v1.push_back(3);

    cout << v1.capacity() << endl;
    cout << v1.size() << endl;

    v1[0] = 10;


}*/






// 7. 아래의 링크를 참조하여 vector 클래스의 다른 멤버 함수와 연산자를 활용한 프로그램을 작성하라.
// https://learn.microsoft.com/ko-kr/cpp/standard-library/vector-operators?view=msvc-170
/*

#include <vector>
#include <iostream>
using namespace std;


// 백터 내의 인덱스를 보여주는 정적 함수 show
void show(const vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}


int main()
{
    vector<int> v1 = { 1, 2, 3 };
    vector<int> v2;

    // = 연산자로 복사 인덱스 복사
    v2 = v1;

    // push_back, insert, erase
    v2.push_back(4);
    v2.insert(v2.begin(), 10);
    v2.erase(v2.begin() + 2);


    // show 호출
    cout << "v1 = ";
    show(v1);

    cout << "v2 = ";
    show(v2);


    // 비교 연산자 사용
    if (v1 == v2)
        cout << "v1과 v2는 같다" << endl;
    else
        cout << "v1과 v2는 다르다" << endl;

    return 0;
}
*/




// 8. SampleCodes/STL 디렉토리의 vector_sample.cc 파일을 기반으로 vector 클래스의 멤버 함수를 검증하는 함수를 작성하라.

#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v;

    // push_back
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout << "현재 v 내용: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // size, capacity
    cout << "size = " << v.size() << endl;
    cout << "capacity = " << v.capacity() << endl;

    // insert
    v.insert(v.begin() + 1, 99);

    cout << "insert 후: ";
    for (int x : v) cout << x << " ";
    cout << endl;


    // erase
    v.erase(v.begin());

    cout << "erase 후: ";
    for (int x : v) cout << x << " ";
    cout << endl;



    // clear
    v.clear();
    cout << "clear 후 size = " << v.size() << endl;

    return 0;
}

