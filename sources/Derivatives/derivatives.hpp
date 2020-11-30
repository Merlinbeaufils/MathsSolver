#ifndef DERIVATIVES_HPP
#define DERIVATIVES_HPP

#include <string>
using namespace std;

enum Operation{
    addition = 5,
    subtraction = 4,
    multiplication = 3,
    division = 2,
    composition = 1,
    none = 0
};


string operators = "+-*/^~";
class AbstractFunction {
public:
    AbstractFunction(string our_function);

    template <typename Function1, typename Function2> AbstractFunction(Function1 left, Function2 right, Operation operation){
        this-> left = left;
        this-> right = right;
        this-> operation = operation;
        this->str_label = left->str_label + get_string_operation()  + right->str_label;
    };
    ~AbstractFunction();
    AbstractFunction();

    void op_to_enum(char op,Operation &operation);

    AbstractFunction* get_left();
    void set_left(AbstractFunction *left);
    AbstractFunction* get_right();
    void set_right(AbstractFunction *right);

    Operation get_operation();
    void set_operation(Operation operation);
    string get_string_operation();

    string get_str_label();


    template <typename Function1> Function1 solve();

    template <typename Function1, typename Function2> AbstractFunction add(Function1 function1, Function2 function2);

    template <typename Function1, typename Function2> AbstractFunction subtract(Function1 function1, Function2 function2);

    template <typename Function1, typename Function2> AbstractFunction multiply(Function1 function1, Function2 function2);

    template <typename Function1, typename Function2> AbstractFunction divide(Function1 function1, Function2 function2);

    template <typename Function1, typename Function2> AbstractFunction chain_rule(Function1 function1, Function2 function2);



private:
    Operation operation;
    AbstractFunction *left;
    AbstractFunction *right;
    string str_label;

};




class SinFunction : public AbstractFunction{
public:
    SinFunction();
    template <typename Function1> Function1 solve();
private:
    Operation operation;
    AbstractFunction *left;
    AbstractFunction *right;
    string str_label;
};



class CosFunction : public AbstractFunction{
public:
    CosFunction();
    template <typename Function1> Function1 solve();
private:
    Operation operation;
    AbstractFunction *left;
    AbstractFunction *right;
    string str_label;
};



class ExponentialFunction : public AbstractFunction{
public:
    ExponentialFunction(int base);
    template <typename Function1> Function1 solve();

    int get_base();
private:
    int base;
    Operation operation;
    AbstractFunction *left;
    AbstractFunction *right;
    string str_label;
};



class LogarithmicFunction : public AbstractFunction{
public:
    LogarithmicFunction(int base);
    template <typename Function1> Function1 solve();

    int get_base();
private:
    int base;
    Operation operation;
    AbstractFunction *left;
    AbstractFunction *right;
    string str_label;
};




class PolynomialFunction : public AbstractFunction{
public:
    PolynomialFunction(int exponent);
    template <typename Function1> Function1 solve();

    int get_exponent();
private:
    int exponent;
    Operation operation;
    AbstractFunction *left;
    AbstractFunction *right;
    string str_label;
};



class ConstantFunction : public AbstractFunction{
public:
    ConstantFunction(int c);
    template <typename Function1> Function1 solve();

    int get_c();
private:
    int c;
    Operation operation;
    AbstractFunction *left;
    AbstractFunction *right;
    string str_label;
};


















#endif // DERIVATIVES_HPP
