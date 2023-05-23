/*
 * Design Pattern - Bridge 橋接模式
 * 
 * 在這個範例中，Implementor 是一個介面，由 ConcreteImplementorA 和 ConcreteImplementorB 兩個類別來實現。
 * Abstraction 是一個抽象類別，維護一個指向 Implementor 物件的參考，並定義了 Operation 方法。
 * RefinedAbstraction 是 Abstraction 的子類別，擴充了 Abstraction 的介面並實現 Operation 方法。
 * Client 可以創建不同的 Implementor 物件並將其傳遞給相應的 Abstraction 物件，
 * 然後呼叫 Abstraction 的 Operation 方法，該方法將委派給 Implementor 物件執行相應的操作。
 * 這樣，Abstraction 和 Implementor 可以獨立地變化，且可以輕鬆地新增更多的 Abstraction 和 ConcreteImplementor，
 * 而不需要修改原有的程式碼。
 */

#include <iostream>

/*
 * Implementor - 定義 Implementor 介面.
*/
class Implementor {
public:
    virtual void OperationImpl() const = 0;
};

/*
 * ConcreteImplementor - 實現 Implementor 介面.
*/
class ConcreteImplementorA : public Implementor {
public:
    void OperationImpl() const override {
        std::cout << "ConcreteImplementorA: Performing operation A." << std::endl;
    }
};

class ConcreteImplementorB : public Implementor {
public:
    void OperationImpl() const override {
        std::cout << "ConcreteImplementorB: Performing operation B." << std::endl;
    }
};

/*
 * Abstraction - 定義 Abstraction 的介面，並維護一個指向 Implementor 物件的參考.
*/
class Abstraction {
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* implementor) : implementor(implementor) {}

    virtual void Operation() const = 0;
};

/*
 * RefinedAbstraction - 擴充 Abstraction 的介面.
*/
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* implementor) : Abstraction(implementor) {}

    void Operation() const override {
        std::cout << "RefinedAbstraction: Performing operation." << std::endl;
        implementor->OperationImpl();
    }
};

/*
 * Client - 使用 Bridge 模式的客戶端.
*/
int main() {
    Implementor* implementorA = new ConcreteImplementorA();
    Abstraction* abstractionA = new RefinedAbstraction(implementorA);
    abstractionA->Operation();

    Implementor* implementorB = new ConcreteImplementorB();
    Abstraction* abstractionB = new RefinedAbstraction(implementorB);
    abstractionB->Operation();

    delete abstractionB;
    delete implementorB;
    delete abstractionA;
    delete implementorA;

    return 0;
}
