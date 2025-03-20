#include "pch.h"
#include "CppUnitTest.h"
#include "../№1 Библиотечные реализации алгоритмов и их скорость/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST(LinkedListTest, AddSingleElement) {
            LinkedList list;
            list.append(5);
            ASSERT_EQ(list.size(), 1);
        }

        // Тест на добавление нескольких элементов
        TEST(LinkedListTest, AddMultipleElements) {
            LinkedList list;
            list.append(1);
            list.append(2);
            list.append(3);
            ASSERT_EQ(list.size(), 3);
        }

        // Тест на добавление 1000 элементов
        TEST(LinkedListTest, Add1000Elements) {
            LinkedList list;
            for (int i = 0; i < 1000; ++i) {
                list.append(i);
            }
            ASSERT_EQ(list.size(), 1000);
        }

        int main(int argc, char** argv) {
            ::testing::InitGoogleTest(&argc, argv);
            return RUN_ALL_TESTS();
        }
		{
		}
	};
}
