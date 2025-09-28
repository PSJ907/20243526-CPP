// 자식 클래스 예제
/*
#include <iostream>
using namespace std;

class Vehicle
{
private:
    int person = 0;    // 탑승인원
    int baggage = 0;   // 화물 무게
public:
    void ride()  // 탑승
    {
        person++;
    }
    void load(int weight) { baggage += weight; }   // 짐 싣기 (클래스 내부에서 정의)
    void getOff() { if (person > 0) person--; }    // 하차 (클래스 내부에서 정의)
    int getPerson()  // 탑승인원 확인
    {
        return person;
    }
};

class Cruise :public Vehicle
{
private:
    int room;
public:
    void setRoom(int r) { room = r; }    // 크루즈의 방 수 설정 (클래스 내부에서 정의)
    void countPerson()
    {
        cout << Vehicle::getPerson() << endl;     // 부모클래스 호출
    }
};

class AirPlane :public Vehicle
{
private:
    int seat;
public:
    void setSeat(int s) { seat = s; }    // 자리 수 설정 (클래스 내부에서 정의)
    void countPerson()    // 탑승인원 확인
    {
        cout << Vehicle::getPerson() << endl;     // 부모클래스 호출
    }
};

int main(int argc, char const* argv[])
{
    Cruise dolphin;
    dolphin.ride();    // 부모클래스 멤버함수  접근
    dolphin.load(10);  // 부모클래스 멤버함수  접근
    dolphin.countPerson();     // 자식클래스 멤버함수 호출

    AirPlane cppAir;
    cppAir.ride();    // 부모클래스의 멤버함수 접근
    cppAir.load(20);  // 부모클래스 멤버함수  접근 
    cppAir.countPerson();     // 자식클래스 멤버함수 호출
    cppAir.ride();      // 탑승 1인 증가
    cppAir.ride();      // 탑승 1인 증가
    cppAir.countPerson();   // 자식클래스 멤버함수 호출 (인원 증가 결과)
}
*/


// 단일 상속
/*
#include <iostream>
#include <string>
using namespace std;

// 부모 클래스 (기반 클래스)
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void introduce() {
        cout << "이름: " << name << ", 나이: " << age << endl;
    }
};

// 자식 클래스 (파생 클래스)
class Student : public Person {
private:
    string major;

public:
    Student(string n, int a, string m) : Person(n, a), major(m) {}

    void study() {
        cout << name << " 학생이 " << major << " 전공 공부 중입니다." << endl;
    }
};

int main() {
    Student s("홍길동", 21, "컴퓨터공학");
    s.introduce();   // 부모 클래스 함수 사용
    s.study();       // 자식 클래스 함수 사용
    return 0;
}
*/



// 다중 상속 (github)

/*
#include <iostream>
using namespace std;

class Teacher {
protected:
    void teach() {  // 교수 클래스 내부에서만 접근 가능
        cout << "강의를 하고 있습니다." << endl;
    }
};

class Researcher {
public:
    void research() {  // 외부에서 접근 가능
        cout << "연구를 하고 있습니다." << endl;
    }
};

// 다중 상속
class Professor : public Teacher, public Researcher {
public:
    void introduce() {  // 교수 소개
        cout << "저는 교수입니다." << endl;
    }

    void teachClass() {   // 부모클래스가 protected이니 자식클래스에서 teach() 호출 가능
        teach();
    }
};



int main() {
    Professor p;
    p.introduce();
    p.teachClass();   // teach()를 호출
    p.research();     // public 함수는 객체를 통해 직접 호출 가능
    return 0;
}

*/



// 오버라이딩
/*
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {  // 가상 함수
        cout << "동물이 소리를 냅니다." << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "멍멍!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "야옹!" << endl;
    }
};

int main() {

    Animal a1;
    Dog a2;
    Cat a3;

    a1.speak();
    a2.speak();
    a3.speak();

    return 0;
}
*/



// 과제 외 프로그램 작성

#include <iostream>
using namespace std;

class Camera {
public:
    void takePhoto() { cout << "사진을 찍습니다." << endl; }
};

class Music {
public:
    void playMusic() { cout << "음악을 재생합니다." << endl; }
};

class SmartPhone : public Camera, public Music {
};

int main() {
    SmartPhone phone;
    phone.takePhoto();  // 사진 찍기
    phone.playMusic();  // 음악 재생

    return 0;
}


