// Раннее и позднее связывание, виртуальные методы
#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "B.h"
#include "D.h"

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 07.07.2021 - раннее и позднее связывание, виртуальные методы");

    // коды команд приложения
    enum Commands {
        CMD_ONE, CMD_TWO, CMD_THREE, CMD_FOUR
    };

    // пункты меню приложения
    const int N_MENU = 5;
    MenuItem items[N_MENU] = {
        MenuItem ("Раннее связывание", CMD_ONE), 
        MenuItem ("Раннее связывание с указателями", CMD_TWO), 
        MenuItem ("Позднее связывание, виртуальные методы", CMD_THREE), 
        MenuItem ("Позднее связывание, виртуальные методы, указатели", CMD_FOUR), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    const int N_PALETTE = 5;
    //                          заголовок       пункт            выбранный пункт  консоль
    short palette[N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});


    while(true) {
        cout << color(palette[Menu::PAL_CONSOLE]) << cls; 
        int cmd = mainMenu.Navigate();
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        if (cmd == Menu::CMD_QUIT) break;
		
		cout << endlm(3) << "    " << items[cmd].text << endlm(3);

        switch (cmd)
        {
        	// раннее связывание
            case CMD_ONE:
	            {
					A a;
					a.f();       // A::a.f() => A::foo()
            				     
		            B b;	     
					b.f();       // B::A::b.f() => A::foo()
					b.foo();     // B::foo()
					b.A::foo();	 // B::A::foo()

					cout << sizeof(A) << ", " << sizeof(B) << "\n";
	            }
            break;    
        
            case CMD_TWO:
	            {
					// раннее связывание с указателями
		            A *a = new A();
					a->foo();
					delete a;

					// подстановка возможна синтаксически, но 
					// из-за раннего связывания вызывется метод
					// класса A
					a = new B();
					a->foo();
					delete a;
            		
					B *b = new B();
					b->foo();
					delete b;
					
	            }
            break;    

        	// Позднее связывание, виртуальные методы
            case CMD_THREE:
	            {
					C c;
					c.f();

		            D d;
					d.f();

					cout << sizeof(C) << ", " << sizeof(D) << "\n";
	            }
            break;

			case CMD_FOUR:
				{
					// позднее связывание
		            C *c = new C();
					c->f();      // C::f() => C::foo()
					delete c;

					c = new D();
					c->f();       // D::C::f() => D::foo()

					// невиртуальный вызов за счет приведения типа
					// указателя к типу производного класса
					((D *)c)->bar();
					delete c;
				}
			break;
        } // switch

        cout << endlm(3);
        getKey("    Нажмите любую клавишу для продолжения...");
    } // while

    cout << cls << pos(0,24);
    getKey();

	return 0;
} // main