#include <iostream>
using namespace std;

//Реализация без вложенного списка
struct Queue {
        int value;                                            //обычное число, мы будем вставлять числа
        Queue *next;                                          //указатель на другой элемент списка
        Queue(int _value) : value(_value), next(NULL) {}      //конструктор, используется для инициализации указателей направлением на нулевой адрес
    };

class FIFO
{
private:
 
    Queue *front;                                             //указатель на самый первый элемент списка
    Queue *back;                                              //указатель на последний добавленный элемент списка
 
public:
    FIFO() : front(NULL), back(NULL) {}                       //конструктор используется для инициализации указателей направлением на нулевые адреса
    ~FIFO() {                                                 //деструктор, используется для автоматической зачистки памяти в момент прекращения работы класса
        while (front != NULL)                                
            pop();                                      
    }
    void push(int _value) {                                   //функция добавления в список элемента
        Queue *newNode = new Queue(_value);                   //выделение памяти для нового элемента
        if (front == NULL) front = newNode;                   //если элемент первый, направляем указатель front на него
        else back->next = newNode;                            //в противном случае направляем указатель back->next  на созданный узел
        back = newNode;                                       //и обозначаем, что созданный узел — это последний, хвостовой, элемент списка
    }
    int pop() {
        if (front == NULL) return 0;
        Queue *temp = front;                                  //Объявляем себе указатель и направляем его на начало списка
        front = front->next;                                  //Смещаем указатель на начало списка на следующий элемент
        delete temp;                                          //Высвобождаем память от элемента, который стал уже бывшим первым
        return temp->value;
    }
    void print(){
        Queue *temp = front;                                  //Объявляем себе указатель и направляем его на начало списка
         while (temp != NULL){                                //С помощью цикла обходим весь список
            cout << temp->value << endl;                      //Выводим информацию на экран
            temp = temp->next;                                //Направляем указатель на следующий элемент
         }
    }
};

//Реализация со вложенным списком
struct stek
{
    int value;
    stek(int _value) : value(_value) {}
    struct stek *next;                                      // указатель на следующий элемент списка (стека)
};

class LIFO {
    private:
        stek *T;

    public: 
        LIFO() : T(NULL) {}
        ~LIFO() {                                           //деструктор, используется для автоматической зачистки памяти в момент прекращения работы класса
        while (T != NULL)                                
            pop();                                      
        }
        void push(int value) {
            stek *CurValue = new stek(value);                // объявляем новую динамическую переменную типа stek + записываем значение
            CurValue->next = T;                              // связываем новый элемент стека с предыдущим
            T = CurValue;                                    // новый элемент стека становится его вершиной
        }
        int pop() {
            int temp = T->value;                            // извлекаем в переменную temp значение в вершине стека
            stek *CurValue = T;                              // запоминаем указатель на вершину стека, чтобы затем 
            T = T->next;                                    // вершиной становится предшествующий top элемент
            delete CurValue;                                 // освобождаем память, тем самым удалили вершину
            return temp;
        }
        void print() {
            stek *temp = T;
            while (temp != NULL) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }
};