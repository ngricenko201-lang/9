

#include "pch.h"                        // якщо шаблон проєкту без pch.h - видаліть цей рядок
#include "CppUnitTest.h"

#include "../Project1/var.cpp"           // глобальні змінні nsVar
#include "../Project1/dod.cpp"           // nsDod::dod()
#include "../Project1/sum.cpp"           // nsSum::sum()

#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab_9_1_Tests
{
    TEST_CLASS(SeriesTests)
    {
    public:

        // dod(): x = 0.5, n = 1, a = x  ->  a = -x^2 / 2 = -0.125
        TEST_METHOD(Dod_SecondTerm)
        {
            nsVar::x = 0.5;
            nsVar::n = 1;
            nsVar::a = nsVar::x;
            nsDod::dod();
            Assert::AreEqual(-0.125, nsVar::a, 1e-12);
        }

        // dod(): n = 2  ->  наступний доданок = x^3 / 3
        TEST_METHOD(Dod_ThirdTerm)
        {
            nsVar::x = 0.5;
            nsVar::a = -0.125;
            nsVar::n = 2;
            nsDod::dod();
            Assert::AreEqual(0.125 / 3, nsVar::a, 1e-12);
        }

        // sum(): x = 0  ->  сума дорівнює 0
        TEST_METHOD(Sum_ZeroArgument)
        {
            nsVar::x = 0;
            nsVar::e = 0.001;
            nsSum::sum();
            Assert::AreEqual(0.0, nsVar::s, 1e-12);
        }

        // sum(): збіжність до log(x + 1), похибка не більша за e
        TEST_METHOD(Sum_MatchesLog_Positive)
        {
            nsVar::x = 0.5;
            nsVar::e = 1e-6;
            nsSum::sum();
            Assert::AreEqual(log(1.5), nsVar::s, 1e-6);
        }

        TEST_METHOD(Sum_MatchesLog_Negative)
        {
            nsVar::x = -0.5;
            nsVar::e = 1e-6;
            nsSum::sum();
            Assert::AreEqual(log(0.5), nsVar::s, 1e-6);
        }

        // менше e  ->  більше доданків
        TEST_METHOD(Sum_SmallerEps_MoreTerms)
        {
            nsVar::x = 0.5;

            nsVar::e = 1e-2;
            nsSum::sum();
            int n1 = nsVar::n;

            nsVar::e = 1e-6;
            nsSum::sum();
            int n2 = nsVar::n;

            Assert::IsTrue(n2 > n1);
        }
    };
}