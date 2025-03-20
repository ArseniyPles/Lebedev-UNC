#include "pch.h"
#include "CppUnitTest.h"
#include "../�1 ������������ ���������� ���������� � �� ��������/main.cpp"

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

        // ���� �� ���������� ���������� ���������
        TEST(LinkedListTest, AddMultipleElements) {
            LinkedList list;
            list.append(1);
            list.append(2);
            list.append(3);
            ASSERT_EQ(list.size(), 3);
        }

        // ���� �� ���������� 1000 ���������
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
