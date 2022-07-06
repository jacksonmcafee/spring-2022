#include <iostream>

class MyClass  {
  private:
    int my_int;
    double my_double;
  public:
    MyClass();
    MyClass(const MyClass &copy);
    friend MyClass &operator=(const MyClass &copy);

    void set_int(int i) { my_int = i; }
    void set_double(double d) { my_double = d; }
    void get_int() { std::cout << my_int << std::endl; }
    void get_double() { std::cout << my_double << std::endl; }
};

MyClass::MyClass() {
    my_int = 1;
    my_double = 1.0;
}

MyClass::MyClass(const MyClass &copy) {
    my_int = copy.my_int;
    my_double = copy.my_double;
}

MyClass &operator=(const MyClass &copy) {
    MyClass return_class;
    return_class.my_int = copy.my_int;
    return_class.my_double = copy.my_double;

    return return_class;
  }

int main() {
  MyClass new_object;
  new_object.set_int(5);
  // copy constructor
  MyClass copy_object(new_object);
  std::cout << "copy constructor works if this says 5" << std::endl;
  copy_object.get_int();

 MyClass op_object = new_object;
 std::cout << "op overload works if this says 5" << std::endl;
 op_object.get_int();
}
